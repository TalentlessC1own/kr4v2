#include "FileOutputResult.h"
#include <vector>

void FileOutputREsult(std::vector<std::shared_ptr<WordInContext>>& context_case)
{
	std::vector<std::string> temp;
	if (context_case.empty())
	{
		std::cout << "No permutations found." << std::endl;
		system("pause");
		return;
	}
	std::ofstream FileRecorder = CheckFileOutput();
	for (int i = 0; i < context_case.size(); i++)
	{
		temp = context_case[i]->ReturnPermutations();
		if (!temp.empty())
		{
			for (int i = 0; i < temp.size(); i++)
				FileRecorder << temp[i] << std::endl;
			FileRecorder << "Permutations = " << temp.size() - 1 << std::endl;
		}
	}
}
