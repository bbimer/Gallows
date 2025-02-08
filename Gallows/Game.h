#pragma once
#include "GameWord.h"
#include "GameWordsBuilder.h"
#include <memory>

using std::unique_ptr;

class Game
{
private:
	unique_ptr<GameWord> current_word;
	int mistakes;
	GameWordsBuilder wordsBuilder;

public:
	Game(const shared_ptr<WordsManager>& manager) : wordsBuilder(manager) 
	{ 
		mistakes = 6;
		current_word = std::make_unique<GameWord>(wordsBuilder.GetRandomWord());
	}

	void Start() {
		while (!current_word->IsGuessed() && mistakes < 6) {
			current_word = std::make_unique<GameWord>(wordsBuilder.GetRandomWord());
			char letter;
			std::cout << "Enter letter: ";
			std::cin >> letter;
			if (current_word->InputLetter(letter))
			{
				std::cout << "Guessed!" << std::endl;
			}
			else
			{
				std::cout << "No Guessed!" << std::endl;
				mistakes++;
			}
		}
	}

	void End() {}

};

