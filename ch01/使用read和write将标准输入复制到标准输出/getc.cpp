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
		fgetc（或者getc）函数返回 EOF 并不一定就表示文件结束，读取文件出错时也会返回 EOF。即 EOF 宏不但能够表示读到了文件结尾这一状态，
		而且还能表示 I/O 操作中的读、写错误以及其他一些关联操作的错误状态。很显然，仅凭返回 EOF(-1) 就认为文件结束显然是不正确的
		也正因为如此，我们需要使用 feof 函数来替换 EOF 宏检测文件是否结束。当然，在用 feof 函数检测文件是否结束的同时，也需要使用 ferror 函数来检测文件读取操作是否出错，
		当 ferror 函数返回为真时就表示有错误发生。在实际的程序中，应该每执行一次文件操作，就用 ferror 函数检测是否出错。
	*/
	if (ferror(stdin))//ferror如果设置了与流关联的错误标识符，该函数返回一个非零值，否则返回一个零值。
		fprintf(stderr, "input error");
	exit(0);
}