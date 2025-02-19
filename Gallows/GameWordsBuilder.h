#pragma once
#include "WordsManager.h"
#include "GameWord.h"
#include <vector>

using std::shared_ptr;

class GameWordsBuilder
{
private:
	vector<string> buffer;
	shared_ptr<WordsManager> manager;

public:
	GameWordsBuilder(const shared_ptr<WordsManager>& manager) : manager(manager)
	{
		buffer = manager->GetWords();
	}

	GameWord GetRandomWord() {
		if (buffer.empty()) {
			throw std::runtime_error("No words available in buffer!");
		}

		auto word = buffer.front();
		buffer.erase(buffer.begin());
		return GameWord(word);
	}
};