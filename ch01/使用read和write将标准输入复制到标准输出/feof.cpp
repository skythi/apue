/*
 * int feof(FILE *fp);
 * 函数 feof 只用于检测流文件，当文件内部位置指针指向文件结束时，并未立即置位 FILE 结构中的文件结束标记，只有再执行一次读文件操作，才会置位结束标志，此后调用 feof 才会返回为真
 */


#include<stdio.h>
#include<stdlib.h>
int main(void)
{
    FILE *fp = NULL;
    char c;
    fp = fopen("myfile.txt","r");
    if(fp == NULL)
    {
	printf("不能访问该文件.\n");
	exit(1);
    }
    while(!feof(fp))
    {
	c = fgetc(fp);
	 printf("%c：\t%x\n",c,c);
    }
    fclose(fp);
    fp = NULL;
}
