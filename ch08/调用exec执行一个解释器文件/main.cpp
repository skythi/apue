#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>
#include<wait.h>
int main() {
	pid_t pid;
	if ((pid = fork()) < 0)
		fprintf(stderr, "fork error");
	else
		if (pid == 0) {
			if (execl("/usr/bin/date", "date", (char *)0) < 0)
				fprintf(stderr, "execl error");
		}
	if (waitpid(pid, NULL, 0) < 0)
		fprintf(stderr, "waitpid error");
	exit(0);
}