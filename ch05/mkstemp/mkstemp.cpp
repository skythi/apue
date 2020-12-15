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
		�����ַ���������ʽ�Ĳ�ͬ�����˲�ͬ�����н�������ڵ�һ��ģ�壬��Ϊʹ�������飬��������ջ�Ϸ���ģ��ڶ���ʹ����ָ�룬ֻ��ָ����������ջ�ϵģ����������ַ��������˿�ִ���ļ���ֻ���Σ���
		mkstemp��ͼ�޸��ַ�����ʱ�򣬳����˶δ���
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