#include<pwd.h>
#include<iostream>

using namespace std;

int main() {
	struct passwd *ptr;
	ptr = getpwnam("root");
	if (ptr != NULL) {
		cout << "uid = " << ptr->pw_uid << "\n";
		cout << "shell : " << ptr->pw_shell << endl;
	}
}