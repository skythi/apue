#include<iostream>
#include<pwd.h>
using std::cin;
using std::cout;
using std::endl;
using std::cerr;

/*
	getpwuid()������һ��������uid ָ�����û�ʶ����, �ҵ�ʱ�㽫���û��������Խṹ���ؽṹ��ο������û���������passwd �ṹ����
*/
int main(void) {
	struct passwd *pd;
	pd = getpwuid(27);
	if (pd != NULL)
	{
		cout<<"name:"<<pd->pw_name<<"\n";;
		cout<<"uid:"<<pd->pw_uid<<"\n"<<endl;
	}
}

