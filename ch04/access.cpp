#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>

int main(int argc, char *argv[]) {
	if (argc != 2)
		fprintf(stderr, "error usage");
	if (access(argv[1], R_OK) < 0)
		fprintf(stderr, "error access");
	else
		printf("read access ok\n");
	if (open(argv[1], O_RDONLY) < 0)
		fprintf(stderr, "open error");
	else
		printf("open for reading OK\n");
	exit(0);
}