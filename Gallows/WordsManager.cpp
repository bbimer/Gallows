#pragma once
#include <vector>
#include <string>
#include <fstream>

using std::vector;
using std::string;
using std::fstream;
using std::ios;

class WordsManager
{
private:
	vector<string> words;

	void Save()
	{

	}

public:
	WordsManager() {
		Load();
	}

	const vector<string>& GetWords() const
	{
		return words;
	}

	void Load()
	{
		std::fstream input("words.txt", ios::in);
		if (input.is_open())
		{
			string word;
			while (input.good()) {
				input >> word;
				words.emplace_back(word);
			}
		}
	}

	void Append(std::string& word)
	{
	}
};

