#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>

static void sig_handler(int signo){
	switch(signo){
		case SIGINT: printf("sig_handler:SIGINT\r\n"); break;
		case SIGQUIT: printf("sig_handler:SIGQUIT\r\n"); /*exit(EXIT_SUCCESS);*/ break;
		case SIGTERM: printf("sig_handler:SIGTERM\r\n"); break;
		default: printf("sig_handler:Udefined signal\r\n"); break;
	}
}

int main(int argc, char **argv){
	printf( "Hello, drug!\r\n");

	if(signal(SIGINT, sig_handler) == SIG_ERR){
		fprintf( stderr, "Cant handle signals INT\r\n");
		exit(EXIT_FAILURE);
	}	

	if(signal(SIGQUIT, sig_handler) == SIG_ERR){
		fprintf( stderr, "Cant handle signals QUIT\r\n");
		exit(EXIT_FAILURE);
	}

	if(signal(SIGTERM, sig_handler) == SIG_ERR){
		fprintf( stderr, "Cant handle signals TERM\r\n");
		exit(EXIT_FAILURE);
	}

	raise(SIGINT);
	raise(SIGTERM);
	raise(SIGQUIT);

	time_t t = time(NULL);
	struct tm tm = *localtime(&t);

	printf("now: %d-%d-%d %d:%d:%d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
	
	pid_t cpid = getpid();
	printf("Current PID:%jd\r\n", cpid);
	char buf[32];
	uint size = snprintf(buf, sizeof(buf), "%jd", cpid);

	// Creating PID file
	int fd = open("PID", O_CREAT | O_SYNC | O_TRUNC | O_WRONLY);
	if(fd == -1){
		perror("Create PID file");
	}
	
	ssize_t wm;
	wm = write(fd, buf, size);
	if(wm == -1){
		perror("Writing PID to the PID file");
	}

	if(close(fd) == -1){
		perror("Closing PID file");
	}
	printf("Bye bye, drug\r\n");
	return 0;
}
