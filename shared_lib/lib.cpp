#include <stdio.h>
#include "lib.h"

void Init() {
	i_ = 0;
}

	void SetI(int i) {
		i_ = 5;
	}

	int GetI() {
		return i_;
	}


	void StackAdress() {
		int i = 0;
		printf("Adress of i: %p\n", &i);

	}
	void  HeapAdress() {
		int* i = new int(5);
		printf("Adress of i: %p\n", i);
	}
/*
int main() {
	StackAdress();
	HeapAdress();
	return 0;
}
 */
