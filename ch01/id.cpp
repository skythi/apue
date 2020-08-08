#include<iostream>
#include<cstdlib>
#include<unistd.h>
#include<pwd.h>

using std::cin;
using std::cout;
using std::endl;

int main() {
	struct passwd *pwd;
	pwd = getpwuid(geteuid());
	cout << "username=" << pwd->pw_name << endl;
	return 0;
}
