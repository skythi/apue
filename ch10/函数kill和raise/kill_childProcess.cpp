#include<sys/wait.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
#include<string.h>


int main(void) {
	pid_t	 childpid;
	int status;
	int retval;

	childpid = fork();
	if (-1 == childpid)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (0 == childpid) {
		puts("In child process");
		sleep(100);//休眠子进程
		exit(EXIT_FAILURE);
	}
	else {
		if (0 == (waitpid(childpid, &status, WNOHANG))) { //设置WNOHANG位，与那么该系统调用就是非阻塞的，也就是说会立刻返回而不是等待子进程的状态发生变化
			retval = kill(childpid, SIGKILL);
			if (retval)
			{
				puts("kill failed.");
				perror("kill");
				waitpid(childpid, &status, 0);
			}
			else
			{
				printf("%d killed\n", childpid);
			}
		}
	}
	exit(EXIT_SUCCESS);
}