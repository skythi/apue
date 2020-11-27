#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<sys/resource.h>
#include<errno.h>
#include<string.h>
#include<sys/ipc.h>

#define MAXLINE 1024
int main() {
	int n;
	int fd[2];
	pid_t pid;
	char line[MAXLINE];

	if (pipe(fd) < 0)
		perror("pipe error");
	if ((pid = fork()) < 0) {
		fprintf(stderr, "fork failed");
	}
	else if (pid > 0)
	{
		close(fd[0]);
		write(fd[1], "hello world", 12);
	}
	else
	{
		close(fd[1]);
		n = read(fd[0], line, MAXLINE);
		write(STDOUT_FILENO, line,n);
	}
	exit(0);
}