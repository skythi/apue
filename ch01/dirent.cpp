#include<iostream>
#include<cstdlib>
#include<dirent.h>
#include<sys/types.h>
#include<errno.h>
#include<cstdio>
#define errMsg(str) \
{	\
perror(str);\
abort();\
}

using std::cin;
using std::cout;
using std::endl;
int main(int argc, char *argv[]) {
	DIR *dp;
	struct dirent *dirp;
	if (argc != 2)
		errMsg("usage error");
	if ((dp = opendir(argv[1])) == NULL)
		errMsg("can't open dir");
	while ((dirp = readdir(dp)) != NULL)
		cout << dirp->d_name << endl;
	closedir(dp);
	exit(0);
}
