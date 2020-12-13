#include<sys/wait.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
#include<string.h>

int main() {
	int status, retval;
	pid_t pid;
	if ((pid = fork()) < 0)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid = 0)//child
	{
		printf("raise !!");
		raise(SIGINT);
	}
	else {
		waitpid(pid, &status, WNOHANG);
	}
	exit(EXIT_SUCCESS);
}