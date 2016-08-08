#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>

#include "server.hpp"

static void sig_handler(int signo){
	switch(signo){
		case SIGINT: printf("sig_handler:SIGINT\r\n"); break;
		default: printf("sig_handler:Udefined signal\r\n"); break;
		case SIGQUIT: printf("sig_handler:SIGQUIT\r\n"); break;
		case SIGTERM: printf("sig_handler:SIGTERM\r\n"); break;
		}
		writeRestMessages();
		exit(EXIT_SUCCESS);
}

int main(int argc, char **argv){
	if(argc != 3){
		printf( "Wrong usage of demon\r\n");
		printf( "./bin portnumber bufferlength\r\n");
		return -1;
	}
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

	startServer(std::stoi(argv[1]), std::stoi(argv[2]));

	printf("Bye bye, drug\r\n");
	return 0;
}
