#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/msg.h>
#include<errno.h>
#include<unistd.h>

struct msg_st {
	long int msg_type;
	char text[BUFSIZ];
};

int main(int argc, char *argv[]) {
	int msgid = -1;
	struct msg_st data;
	long int msgtype = 0;

	msgid = msgget((key_t)1234, 0666 | IPC_CREAT);
	if (msgid == -1) {
		fprintf(stderr, "msgget failed width error: %d\n", errno);
		exit(EXIT_FAILURE);
	}
	while (1) {
		if(msgrcv(msgid,(void *)&data,BUFSIZ,msgtype,0) == -1)
		{
			fprintf(stderr, "msgrcv failed width erro: %d", errno);
		}
		printf("You wrote: %s\n", data.text);
		// Óöµ½end½áÊø
		if (strncmp(data.text, "end", 3) == 0)
		{
			break;
		}
	}
	if(msgctl(msgid,IPC_RMID,0) == -1)
	{
		fprintf(stderr, "msgctl(IPC_RMID) failed\n");
	}
	exit(EXIT_SUCCESS);
}