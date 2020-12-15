#include<iostream>
#include<string>
#include<cstdio>
#include<sys/stat.h>
#include<cstdio>
#include<cstdlib>
#include<stdio.h>
#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>
using std::cin;
using std::cout;
using std::cerr;
using std::string;
using std::endl;

void make_temp(char *template_);


int main() {
	char good_template[] = { "/tmp/dirXXXXXX "};
	char *bad_template = { "tmp/dirXXXXXX" };

	/*
		两个字符串声明方式的不同带来了不同的运行结果，对于第一个模板，因为使用了数组，名字是在栈上分配的，第二种使用了指针，只有指针自身是再栈上的，编译器把字符串放在了可执行文件的只读段，当
		mkstemp试图修改字符串的时候，出现了段错误
	*/
	cout << "trying to create first temp file" << "\n";
	make_temp(good_template);
	cout << "trying to create first temp file" << "\n";
	make_temp(bad_template);
	exit(0);
}
void make_temp(char *template_) {
	int fd;
	struct stat sbuf;
	if ((fd = mkstemp(template_)) < 0)
		perror("mkstemp");
	cout << template_ << endl;
	close(fd);
	if (stat(template_, &sbuf) < 0) {
		if (errno == ENOENT)
			cout << "file doesn't exist\n";
		else
			cout << "stat failed";
	}
	else
	{
		cout << "file exists" << endl;
		unlink(template_);
	}
}