#include<iostream>
#include<pwd.h>
using std::cin;
using std::cout;
using std::endl;
using std::cerr;

/*
	getpwuid()用来逐一搜索参数uid 指定的用户识别码, 找到时便将该用户的数据以结构返回结构请参考将该用户的数据以passwd 结构返回
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

