#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <sys/time.h>
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

	printf("Bye bye, drug\r\n");
	return 0;
}
