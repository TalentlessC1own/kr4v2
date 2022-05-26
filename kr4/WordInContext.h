#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "VectorEqual.h"
class WordInContext 
{
private:
	std::string word_1;
	std::vector<std::string> words_2;
	std::string word_3;
	std::vector <std::string> permutations;

public:
	WordInContext(std::string word1, std::string word2, std::string word3)
		: word_1(word1), word_3(word3)
	{
		words_2.push_back(word2);
	}

	void FindPermutations(std::string pref,int n, int size);
	int GetNUmberOfPermutations();

	bool  CompareContext(std::string word1, std::string word3);

	void AddPermutation(std::string word2);

	void FindPermutaionsAdapt();

	void Show();

	std::vector <std::string> ReturnPermutations();
	
	~WordInContext () = default;

};

