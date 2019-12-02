#include <iostream>
#include <fstream>
#include <string>
int main()
{
	std::ifstream fin("input.txt");//opens filereader
        if (fin.fail()) {
                std::cerr << "File cannot be read, opened, or does not exist.\n";
        exit(1);
        }

	int mass = 0;
	std::string s;
	int fuel = 0;

        while(getline(fin, s)) {
		mass = std::stoi(s);
		fuel += mass / 3 - 2; //mass divided by 3 which would round down by itself because it is an int then minus 2
        }
        fin.close();
	std::cout << fuel << std::endl;

	return 0;
}
