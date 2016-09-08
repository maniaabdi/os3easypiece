#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int
main (int argc, char *argv[]){

	printf("Hello world. (pid:%d)\n", (int)getpid());

	int value = 100;
	int rc = fork();
	if (rc < 0) {
		fprintf(stderr, "fork failed.\n");
		exit(-1);
	} else if (rc == 0) {
		value = 200;
		printf("Hello, I am child (pid:%d), (value:%d)\n", getpid(), value);
	} else {
		printf("Hello, I am parent of %d (pid:%d), (value:%d)\n", rc, (int)getpid(), value);
	}

	printf ("Goodbye world. (pid:%d), (value:%d)\n", (int)getpid(), value);

	return 0;

}
