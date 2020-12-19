#include<iostream>
#include<unistd.h>
#include<sys/stat.h>
int main() {
	const char *c = "/usr/local/temp";
	umask(0);
	mkdir(c, 00775);
}
