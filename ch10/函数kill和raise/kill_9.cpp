#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<signal.h>
int main() {
	pid_t pid;
	int retval;
	printf("input pid%d\n");
	scanf("%d", &pid);
	retval  = kill(pid, 9);
	if (retval) {
		puts("kill failed");
		perror("kill");
	}
	else
	{
		printf("%d killed\n", pid);
	}
}