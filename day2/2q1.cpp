#include <iostream>
#include <fstream>
#include <vector>

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

	nums[1] = 12;
	nums[2] = 2;

	for(int i = 0; nums[i] != 99; i += 4)
	{
		if(nums[i]==1)
		{
			nums[nums[i+3]] = nums[nums[i+1]] + nums[nums[i+2]];
		}
		else //since the only other opcode can only be 2 else should be fine
		{
			nums[nums[i+3]] = nums[nums[i+1]] * nums[nums[i+2]];
		}
	}
	std::cout << nums[0] << std::endl;

	return 0;
}
