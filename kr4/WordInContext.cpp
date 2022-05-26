#include "WordInContext.h"
#include "SplitIntoWords.h"

void WordInContext::FindPermutations(std::string pref ,int n, int size)
{
    std::vector <std::string> prefs;
    std::string buf;
    if (size == 1)
    {

        for (int j = 0; j < n; j++)
        {
            prefs = SplitIntoWords(pref);
            for (int i = 0; i < prefs.size(); i++)
            {
                buf += word_1 + "\t" + prefs[i] + "\t" + word_3 + "\t";
            }
            buf += word_1 + "\t" + words_2[j] + "\t" + word_3;

            permutations.push_back(buf);
            buf.clear();
        }
           

    }

    else

    {



        for (int i = 0; i < n; i++)
        {
            FindPermutations(pref + "\t" + words_2[i], n, size - 1);
        }


    }
   
}





int WordInContext::GetNUmberOfPermutations()
{
    return static_cast<int>(permutations.size()) - 1;
}

bool WordInContext::CompareContext(std::string word1, std::string word3)
{
    return word_1 == word1 && word3 == word_3;
}

void WordInContext::AddPermutation(std::string word2)
{
    words_2.push_back(word2);
}

void WordInContext::FindPermutaionsAdapt()
{
    FindPermutations("", words_2.size(), words_2.size());
}



void WordInContext::Show()
{
    if (words_2.size() < 2)
        return;
    for (int i = 0; i < permutations.size(); i++)
    {
        std::cout << permutations[i] << std::endl;
    }
    std::cout << "Permutation count = " << permutations.size() - 1 << std::endl;
}

std::vector<std::string> WordInContext::ReturnPermutations()
{
    std::vector <std::string> empty;
    if (words_2.size() < 2)
        return empty;
    return permutations;
}
