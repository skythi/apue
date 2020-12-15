#include<iostream>
#include<string>
#include<cstdio>

using std::cin;
using std::cout;
using std::cerr;
using std::string;
using std::endl;
int main() {
	string name1 = tmpnam(nullptr);
	cout << "temporary file name" << name1 << endl;
	char name2[L_tmpnam];
	if (tmpnam(name2)) {
		std::cout << "temporary file name: " << name2 << '\n';
	}
}