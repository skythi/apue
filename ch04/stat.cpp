#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<unistd.h>
#include<sys/stat.h>

int main(int argc, char *argv[]) {
	int i;
	struct stat buf;
	char *ptr;

	for (int i; i < argc; i++) {
		printf("%s:", argv[i]);
		if (stat(argv[i], &buf) < 0) {
			fprintf(stderr, "error stat file");
			continue;
		}
		if (S_ISREG(buf.st_mode))
			ptr = "regular";
		else if (S_ISDIR(buf.st_mode))
			ptr = "dir";
		else if (S_ISCHR(buf.st_mode))
			ptr = "characet specia;";
		else if (S_ISBLK(buf.st_mode))
			ptr = "block special";
		else if (S_ISFIFO(buf.st_mode))
			ptr = "fifo";
		else if (S_ISLNK(buf.st_mode))
			ptr = "symbolic link";
		else if (S_ISSOCK(buf.st_mode))
			ptr = "socket";
		else
			ptr = "** unknown mode **";
		printf("%s\n", ptr);
	}
	exit(0);
}