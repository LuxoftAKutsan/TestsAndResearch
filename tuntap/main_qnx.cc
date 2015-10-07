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
#include <net/if_tun.h>
#include <ctype.h>
#include <ifaddrs.h>
#include <linux/fib_rules.h>

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
	return fd;
}

int main() {
	char* iface;
	int d = connman_inet_create_tunnel(&iface);
	printf("iface = %s fd = %d\n", iface, d);
	pause();
}
