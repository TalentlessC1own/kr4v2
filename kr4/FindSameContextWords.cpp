#include "FindSameContextWords.h"

void FindSameContextWords(std::vector<std::shared_ptr<WordInContext>>& context_case, std::vector<std::string> words)
{
	bool find_context = false;
	for (int i = 1; i < words.size() - 1; i++)
	{
		find_context = false;
		for(int j = 0;j < context_case.size();j++)
			if (context_case[j]->CompareContext(words[i - 1], words[i + 1]))
			{
				context_case[j]->AddPermutation(words[i]);
				find_context = true;
					break;
			}
		if (!find_context)
			context_case.emplace_back(std::make_shared<WordInContext>(words[i - 1], words[i], words[i + 1]));
	}
}
