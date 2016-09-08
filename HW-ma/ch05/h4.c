#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>


#define VECTOR 0x8
#define PATH   0x4
#define ENV    0x2

void usage(){

	printf("h4 [parameters]\n\t--help\t\tprint usage\n\t--with-vector\trun program with vector arguments\n\t--with-syspath\tthe program execulable could be found in path system variable\n\t--with-env-var\tan enviromental variable is printed inside child\n");
}


int _execl(){

	int rc = fork();
	if (rc < 0) {
		fprintf(stderr, "fork failed.\n");
		exit(-1);
	} else if (rc == 0) {
		//printf("Hello, I am child (pd:%d)\n", (int)getpid());
		//char *env[] = { "HOME=/home/mania/Northeastern/os3easypiece/HW-ma/ch05/", "LOGNAME=home", (char *)0 };
		char *_argvp[3];
		_argvp[0] = strdup("/bin/ls");
		//       _argvp[1] = strdup("ls");
		_argvp[1] = strdup("-l");
		_argvp[2] = NULL;

		//      execvp(_argvp[0], _argvp);

		//      execl(_argvp[0], _argvp[1], _argvp[2]);

		//              _argvp[0] = strdup("ls"); 
		//              execlp(_argvp[0], _argvp[2], _argvp[3]);
		//              execle(_argvp[0],  _argvp[1],  _argvp[2],  _argvp[3], env);

		//_argvp[0] = strdup("h3");
		execl(_argvp[0], _argvp[1], _argvp[2]);
		printf("this shouldn't printout\n");
	} else {
		int wc = wait(NULL);
		printf("Hello, I am parent of %d (/bin/ls:%d), (pid:%d)\n",
				rc, wc, (int)getpid());
	}

	return 0;
}

int _execle(){

	int rc = fork();
	if (rc < 0) {
		fprintf(stderr, "fork failed.\n");
		exit(-1);
	} else if (rc == 0) {
		char *env[] = { "NAME=Mania", "LOGNAME=Abdi", (char *)0 };
		char *_argvp[2];
		_argvp[0] = strdup("h3");
		_argvp[1] = NULL;

		execle(_argvp[0], _argvp[1], env);
		printf("this shouldn't printout\n");
	} else {
		int wc = wait(NULL);
		printf("Hello, I am parent of %d (/bin/ls:%d), (pid:%d)\n",
				rc, wc, (int)getpid());
	}


	return 0;
}

int _execlp(){

        int rc = fork();
        if (rc < 0) {
                fprintf(stderr, "fork failed.\n");
                exit(-1);
        } else if (rc == 0) {
                char *_argvp[2];
                _argvp[0] = strdup("ls");
                _argvp[1] = NULL;
                execlp(_argvp[0], _argvp[1]);
                printf("this shouldn't printout\n");
        } else {
                int wc = wait(NULL);
                printf("Hello, I am parent of %d (/bin/ls:%d), (pid:%d)\n",
                                rc, wc, (int)getpid());
        }

	return 0;
}

int _execv(){

        int rc = fork();
        if (rc < 0) {
                fprintf(stderr, "fork failed.\n");
                exit(-1);
        } else if (rc == 0) {
                char *_argvp[3];
                _argvp[0] = strdup("/bin/ls");
		_argvp[1] = strdup("-S");
                _argvp[2] = NULL;
                execv(_argvp[0], &_argvp[1]);
                printf("this shouldn't printout\n");
        } else {
                int wc = wait(NULL);
                printf("Hello, I am parent of %d (/bin/ls:%d), (pid:%d)\n",
                                rc, wc, (int)getpid());
        }

	return 0;
}

int _execvp(){

        int rc = fork();
        if (rc < 0) {
                fprintf(stderr, "fork failed.\n");
                exit(-1);
        } else if (rc == 0) {
                char *_argvp[3];
                _argvp[0] = strdup("ls");
		_argvp[1] = strdup("-S");
                _argvp[2] = NULL;
                execvp(_argvp[0], &_argvp[1]);
                printf("this shouldn't printout\n");
        } else {
                int wc = wait(NULL);
                printf("Hello, I am parent of %d (/bin/ls:%d), (pid:%d)\n",
                                rc, wc, (int)getpid());
        }

	return 0;
}

int _execvpe(){

        int rc = fork();
        if (rc < 0) {
                fprintf(stderr, "fork failed.\n");
                exit(-1);
        } else if (rc == 0) {
                char *env[] = { "NAME=Mania", "LOGNAME=Abdi", (char *)0 };
                char *_argvp[2];
                _argvp[0] = strdup("h3");
                _argvp[1] = NULL;

                execvpe(_argvp[0], &_argvp[1], env);
                printf("this shouldn't printout\n");
        } else {
                int wc = wait(NULL);
                printf("Hello, I am parent of %d (/bin/ls:%d), (pid:%d)\n",
                                rc, wc, (int)getpid());
        }

	return 0;
}


int
main (int argc, char *argv[]){

	int flag = 0; 
	if (argc == 1) {
		printf("Now execl 'ls' on /bin\n");
		return _execl();
	}

	if (!strcmp(argv[1], "--help")){
		usage();
		return -1;
	} 

	for (int i = 1; i < argc; i++) {

		if (!strcmp(argv[i], "--with-vector")) {
			flag |= VECTOR;
		} else if (!strcmp(argv[i], "--with-syspath")) {
			flag |= PATH;
		} else if (!strcmp(argv[i], "--with-env-var")) {
			flag |= ENV;
		}
	}

	switch (flag) {
	case 0x2:
		printf("Now execle 'h3 \n");
		return _execle();
	case 0x4:
		printf("Now execlp 'ls' on PATH\n");
		return _execlp();
	case 0x8:
		printf("Now execv 'ls' on /bin\n");
		return _execv();
	case 0xC:
		printf("Now execl 'ls' on PATH\n");
		return _execvp();
	case 0xE:
		printf("Now execvpe 'h3' on PATH\n");
		return _execvpe();
	default:
		printf("Now execl 'ls' on /bin\n");
		return _execl();
	}
}
