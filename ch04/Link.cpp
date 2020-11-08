#include<unistd.h>
#include<iostream>
#include<stdlib.h>
using namespace std;

int main() {
	const char *existingpath = "test.txt";
	const char *newpath = "1.txt";
	system("touch test.txt");
	FILE *fp = fopen("test.txt","wb");
	if (fp == nullptr)
		return -1;
	fprintf(fp, "This is testing for fprintf...\n");
	fclose(fp);
	link(existingpath, newpath);
	return 0;
}
