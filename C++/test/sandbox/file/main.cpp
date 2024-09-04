#include <iostream>
#include <fstream>

int main() {
	std :: ofstream out_file("text.txt");
	if(!out_file.is_open()) {
		std :: cout << "error\n";
	} else {
		out_file << "Hello\n";
	}
	out_file.close();
	return 0;
}
