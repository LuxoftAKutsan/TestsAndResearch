#include <unistd.h>
#include "lib.h"
#include <dlfcn.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char** argv) {
	void *dl_handle;
	char *error;
	void (*StackAdress)();
	void (*HeapAdress)();
	void (*Init)();
	void (*SetI)(int);
	int (*GetI)();
	printf("HI\n");
	dl_handle = dlopen( argv[1] , RTLD_LAZY );
	if (!dl_handle) {
		    printf( "!!! %s\n", dlerror() );
		        return 1;
	}
	error = dlerror();
	if (error != NULL) {
	      printf( "!!! %s\n", error );
	      return 2;
	}

        *(void **) (&StackAdress) = dlsym( dl_handle, "StackAdress" );
	error = dlerror();
	if (error != NULL) {
	      printf( "!!! %s\n", error );
	      return 3;
	 }
       *(void **) (&HeapAdress) = dlsym( dl_handle, "HeapAdress" );
	error = dlerror();
	if (error != NULL) {
	      printf( "!!! %s\n", error );
	      return 4;
	}

        *(void **) (&Init) = dlsym( dl_handle, "Init" );
	error = dlerror();
	if (error != NULL) {
	      printf( "!!! %s\n", error );
	      return 3;
	 }
       *(void **) (&SetI) = dlsym( dl_handle, "SetI" );
	error = dlerror();
	if (error != NULL) {
	      printf( "!!! %s\n", error );
	      return 4;
	}
        *(void **) (&GetI) = dlsym( dl_handle, "GetI" );
	error = dlerror();
	if (error != NULL) {
	      printf( "!!! %s\n", error );
	      return 4;
	}
	printf("All OK\n");
	//Init();
	//printf("I = %d \n", GetI());
	//fflush(stdout);
	//sleep(20);
	SetI(5);
	printf("I = %d \n", GetI());
	//fflush(stdout);
	//StackAdress();
	//HeapAdress();

	return 0;
}
