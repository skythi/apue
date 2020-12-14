#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
int main(void) {
	int c;
	while ((c = fgetc(stdin)) != EOF)
		if (putc(c, stdout) == EOF)
			fprintf(stderr, "putc failed");
	/*
		fgetc������getc���������� EOF ����һ���ͱ�ʾ�ļ���������ȡ�ļ�����ʱҲ�᷵�� EOF���� EOF �겻���ܹ���ʾ�������ļ���β��һ״̬��
		���һ��ܱ�ʾ I/O �����еĶ���д�����Լ�����һЩ���������Ĵ���״̬������Ȼ����ƾ���� EOF(-1) ����Ϊ�ļ�������Ȼ�ǲ���ȷ��
		Ҳ����Ϊ��ˣ�������Ҫʹ�� feof �������滻 EOF �����ļ��Ƿ��������Ȼ������ feof ��������ļ��Ƿ������ͬʱ��Ҳ��Ҫʹ�� ferror ����������ļ���ȡ�����Ƿ����
		�� ferror ��������Ϊ��ʱ�ͱ�ʾ�д���������ʵ�ʵĳ����У�Ӧ��ÿִ��һ���ļ����������� ferror ��������Ƿ����
	*/
	if (ferror(stdin))//ferror������������������Ĵ����ʶ�����ú�������һ������ֵ�����򷵻�һ����ֵ��
		fprintf(stderr, "input error");
	exit(0);
}