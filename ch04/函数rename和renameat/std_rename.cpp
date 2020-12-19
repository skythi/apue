#include<iostream>
#include<fstream>
#include<cstdio>

int main() {
	bool ok{ std::ofstream("from.txt").put('a') };
	if (!ok) {
		std::perror("Error creating from.txt");
		return 1;
	}
	if (std::rename("from.txt", "to.txt")) {
		std::perror("Error renaing");
		return 1;
	}
	std::cout << std::ifstream("to.txt").rdbuf() << '\n';
}