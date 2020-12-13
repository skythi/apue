#include<sys/wait.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
#include<string.h>

static void sig_alarm(int);

#define MAXLINE 1024
int main(void) {
	int n;
	char line[MAXLINE];

	if (signal(SIGALRM, sig_alarm) == SIG_ERR)
		printf("signal failed");
	alarm(10);
	if ((n == read(STDIN_FILENO, line, MAXLINE)) < 0)
		printf("read failed");
	alarm(0);

	write(STDOUT_FILENO, line, n);
	exit(0);
}

static void sig_alarm(int sign0) {
	printf("alarm !!!");
}