#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>
#include <sys/types.h>
#include <signal.h>

int
main (int argc, char *argv[]){

	int rc = fork();
	if (rc < 0) {
		fprintf(stderr, "fork failed.\n");
		exit(-1);
	} else if (rc == 0) {
		/*get HOME enviromental variable and print it */
		printf("Hello\nHOME:%s, My name is %s %s\n", getenv("HOME"), getenv("NAME"), getenv("LOGNAME"));
	} else { 
		/*another way to wait for a process is to check whether its pid is exist! Take a look ;-) */
		int exist = 0;
		do {
			waitpid(rc, &exist, WUNTRACED | WCONTINUED);
		} while (!WIFEXITED(exist) && !WIFSIGNALED(exist));

		printf("Goodbye\n");
	}

	return 0;
}
