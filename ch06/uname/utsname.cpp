#include<pwd.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/utsname.h>
using namespace std;

int main() {

	struct utsname *name;
	int fb = 0;
	fb = uname(name);
	if (name != NULL) {
		printf(" sysname:%s\n nodename:%s\n release:%s\n version:%s\n machine:%s\n \n ", \
			name->sysname, \
			name->nodename, \
			name->release, \
			name->version, \
			name->machine);
	}
}
