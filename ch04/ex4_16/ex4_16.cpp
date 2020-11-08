#include<unistd.h>
#include<iostream>
#include<stdlib.h>
#include<fcntl.h>
using namespace std;

int main() {
	system("touch tempfile");
	FILE *fp = fopen("tempfile", "wb");
	fprintf(fp, "hello world");
	if (open("tempfile", O_RDWR) < 0)
		fprintf(stderr, "open error");
	if (unlink("tempfile") < 0)
		fprintf(stderr, "unlink error");
	printf("file unlinked\n");
	sleep(15);
	printf("done\n");
	exit(0);
}
