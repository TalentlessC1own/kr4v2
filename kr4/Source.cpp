#include "InputText.h"
#include <clocale>
#include "SplitIntoWords.h"
#include "WordInContext.h"
#include "FindSameContextWords.h"
#include <vector>
#include "Check.h"
#include "FileOutputResult.h"
#include "FIleOutputText.h"
#include "FileInput.h"

enum class Type
{
	console = 1,
	file,
	none
};
enum class Menu
{
	input = 1,
	output,
	out,
	none
};

enum class InfoType
{
	text = 1,
	result,
	none
};

int main()
{
	std::vector < std::shared_ptr<WordInContext>> context_case;
	setlocale(LC_ALL, "ru_RU.cp1251");
	std::string text = "";
	std::vector <std::string> words;
	Menu menu_item = Menu::none;
	Type type = Type::none;
	InfoType info_type = InfoType::none;
	while (true)
	{

		system("cls");
		std::cout << "Ershov Alex 415 var 9 kr 2 " << std::endl;
		std::cout << "Text:\n"  << text <<"\n" << std::endl;
		std::cout << "Permutations :" << std::endl;
		for (int i = 0; i < context_case.size(); i++)
			context_case[i]->Show();
		std::cout << "\n1 - Input" << std::endl
			<< "2 - File output" << std::endl
			<< "3 - Exit" << std::endl;
		menu_item = static_cast<Menu>(CheckMenu(4));
		switch (menu_item)
		{
		case Menu::input:
			text.clear();
			std::cout << "1 - console\n2 - file" << std::endl;
			type = static_cast<Type>(CheckMenu(2));
			switch (type)
			{
			case Type::console:
				InputText(&text);
				break;
			case Type::file:
				FileInput(&text);
				break;
			}
			break;
		case Menu::output:
			std::cout << "1 - Text\n2 - Result" << std::endl;
			info_type = static_cast<InfoType>(CheckMenu(2));
			switch (info_type)
			{
			case InfoType::text:
				FileOutputText(text);
				break;
			case InfoType::result:
				FileOutputREsult(context_case);
				break;
			}
			break;
		case Menu::out:
			return 0;
		}
		if(!text.empty())
			words = SplitIntoWords(text);
		context_case.clear();
		if (!words.empty())
		{
			FindSameContextWords(context_case, words);
			for (int i = 0; i < context_case.size();i++)
				context_case[i]->FindPermutaionsAdapt();
		}

	}
}

