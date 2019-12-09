#include <iostream>
#include <fstream>
#include <vector>
int getOutput(std::vector<int> &nums, int noun, int verb);

int main()
{
        std::ifstream fin("input.txt");//opens filereader
        if (fin.fail()) {
                std::cerr << "File cannot be read, opened, or does not exist.\n";
        exit(1);
        }

        std::string s;
	std::vector<int> nums;

        while(getline(fin, s, ',')) {
                nums.push_back(std::stoi(s));
        }

	for(int i = 0; i < 100; i++)
	{
		for(int j = 0; j < 100; j++)
		{
			if(getOutput(nums, i, j)==19690720)
			{
				std::cout << "noun: " << i << std::endl;
				std::cout << "verb: " << j << std::endl;
				std::cout << 100 * i + j << std::endl;
				i = 100;
				j = 100;
			}
		}
	}
	return 0;
}

int getOutput(std::vector<int> &nums, int noun, int verb)
{
	std::vector<int> temp = nums;
	temp[1] = noun;
	temp[2] = verb;
	for(int i = 0; temp[i] != 99; i += 4)
        {
                if(temp[i]==1)
                {
                        temp[temp[i+3]] = temp[temp[i+1]] + temp[temp[i+2]];
                }
                else //since the only other opcode can only be 2 else should be fine
                {
                        temp[temp[i+3]] = temp[temp[i+1]] * temp[temp[i+2]];
                }
        }
	return temp[0];
}
