#include<stdio.h>
#include<signal.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>
#include<string.h>
#include<pwd.h>
static void my_alarm(int signo) {
	struct passwd *rootptr;
	printf("in signal handler\n");
	if ((rootptr = getpwnam("root")) == NULL)
		fprintf(stderr, "getpwnam error");
	alarm(1);
}

int main(void) {
	struct passwd *ptr;
	signal(SIGALRM, my_alarm);
	alarm(1);
	for (;;) {
		if ((ptr = getpwnam("mysql")) == NULL)
			fprintf(stderr, "getpwname error");
		if (strcmp(ptr->pw_name, "mysql") != 0)
			printf("return value corrupted!,pw_name = %s\n", ptr->pw_name);
	}
}
