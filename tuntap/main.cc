#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <linux/sockios.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <net/route.h>
#include <net/ethernet.h>
#include <net/if.h>
#include <net/if_arp.h>
#include <netinet/icmp6.h>
#include <fcntl.h>
#include <linux/if_tun.h>
#include <ctype.h>
#include <ifaddrs.h>
#include <linux/fib_rules.h>
#include <glib.h>
#include <errno.h>

int connman_inet_create_tunnel(char **iface)
{
	struct ifreq ifr;
	int i, fd;

	fd = open("/dev/net/tun", O_RDWR | O_CLOEXEC);
	if (fd < 0) {
		i = -errno;
		printf("ERROR %d \n", i);
		return i;
	}

	memset(&ifr, 0, sizeof(ifr));
	ifr.ifr_flags = IFF_TUN | IFF_NO_PI;

	for (i = 0; i < 256; i++) {
		sprintf(ifr.ifr_name, "tun%d", i);

		if (!ioctl(fd, TUNSETIFF, (void *)&ifr))
			break;
	}

	if (i == 256) {
		printf("Failed to find available tun device\n");
		close(fd);
		return -ENODEV;
	}

	*iface = g_strdup(ifr.ifr_name);
//	*iface = ifr.ifr_name;
	return fd;
}

int main() {
	char* iface;
	if (fork()) {
		int d = connman_inet_create_tunnel(&iface);
		printf("iface = %s fd = %d\n", iface, d);
		printf("Alice work\n");
		const char * msg_to_send = "Hello BOB";
		int n = write(d, msg_to_send, sizeof(msg_to_send)/sizeof(char));
		printf("ALice send %s %d \n", msg_to_send, n);
		char * msg_to_receive = static_cast<char*>(malloc(100));
		read(d, msg_to_receive, 5);
		printf("Alice receive : %s \n", msg_to_receive);
		close(d);
	} else  {
		sleep(1);
		int d = open("/dev/net/tun", O_RDWR | O_CLOEXEC);
		if (d < 0) { printf("ERROR %d \n", errno); }
		printf("Bob work\n");
		char * msg_to_receive = static_cast<char*>(malloc(100));
		int n = read(d, msg_to_receive, 5);
		printf("Bob receive : %s %d \n", msg_to_receive, n);
		const  char * msg_to_send = "Hello Alice";
		write(d, msg_to_send, sizeof(msg_to_send)/sizeof(char));
		printf("Bob send %s\n", msg_to_send);
		close(d);
	}
	pause();
}
