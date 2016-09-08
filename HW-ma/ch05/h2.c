#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define BUF_SIZE 0x500000

int
main (int argc, char *argv[]){

	int rc = 0;
	char *buf = (char *)malloc(BUF_SIZE);
	int fd = open("h2.txt",  O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
	if (fd < 0) {
		fprintf(stderr, "open failed.\n");
		exit(-1);
	}

	rc = fork();
	if (rc < 0) {
		fprintf(stderr, "fork failed.\n");
		exit(-1);
	} else if (rc == 0) {
		//sprintf(buf, "Hello, I am child (pid:%d)\n", getpid());
		memset(buf, 0x41, BUF_SIZE);
	} else {
		//sprintf(buf, "Hello, I am parent of %d (pid:%d)\n", rc, (int)getpid());
		memset(buf, 0x42, BUF_SIZE);
	}

	write (fd, buf, strlen(buf));
	free(buf);
	close (fd);
	return 0;

}
