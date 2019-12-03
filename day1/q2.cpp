#include <iostream>
#include <fstream>
#include <string>
int getTotalFuel(int);

int main()
{
	std::ifstream fin("input.txt");//opens filereader
        if (fin.fail()) {
                std::cerr << "File cannot be read, opened, or does not exist.\n";
        exit(1);
        }

	std::string s;
	int fuel = 0;

        while(getline(fin, s)) {
		fuel += getTotalFuel(std::stoi(s));
	}
        fin.close();
	std::cout << fuel << std::endl;

	return 0;
}

int getTotalFuel(int a)
{
	int total = 0;
	int fuel = a;
	int mass = a;
	while(fuel / 3 > 0)
	{
		fuel = fuel / 3 - 2;
		if (fuel < 0)
			fuel = 0;
		total += fuel;
	}
	return total;
}
