#include <stdio.h>

int main () {

		int i=0;

		while(1) {
		  fprintf(stderr, "Hello from %d .. %d\n", getpid(), i++);
		  sleep(1);
		}
}
