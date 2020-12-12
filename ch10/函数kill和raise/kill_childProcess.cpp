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
		sleep(100);//�����ӽ���
		exit(EXIT_FAILURE);
	}
	else {
		if (0 == (waitpid(childpid, &status, WNOHANG))) { //����WNOHANGλ������ô��ϵͳ���þ��Ƿ������ģ�Ҳ����˵�����̷��ض����ǵȴ��ӽ��̵�״̬�����仯
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