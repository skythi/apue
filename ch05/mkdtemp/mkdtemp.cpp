#include<iostream>
#include<string>
#include<cstdio>

using std::cin;
using std::cout;
using std::cerr;
using std::string;
using std::endl;
int main() {
	char template_[] = { "template-XXXXXX" };
	mkdtemp(template_);
	cout << template_ << endl;
}