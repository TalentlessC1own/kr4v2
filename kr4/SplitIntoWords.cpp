#include "SplitIntoWords.h"

std::vector<std::string> SplitIntoWords(std::string text)
{
    std::vector <std::string> words;
    for (std::string::iterator i = text.begin(); i != text.end(); i++)
        if (ispunct(static_cast<unsigned char>(*i)))
            *i = ' ';
    std::istringstream ist(text);
    std::string buffer;
    while (ist >> buffer)
        words.push_back(buffer);
    return words;
}
