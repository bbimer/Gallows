#pragma once
#include "GameWord.h"
#include "GameWordsBuilder.h"
#include "IGameView.h"
#include <memory>

using std::unique_ptr;

class Game
{
private:
	unique_ptr<GameWord> current_word;
	int mistakes;
	GameWordsBuilder wordsBuilder;
	unique_ptr<IGameView> view;
	const int max_mistakes = 6;

public:
	Game(const shared_ptr<WordsManager>& manager,
		unique_ptr<IGameView> view)
		: wordsBuilder(manager),
		view(std::move(view))
	{
		mistakes = 0;
	}

	void Start() {
		current_word = std::make_unique<GameWord>(wordsBuilder.GetRandomWord());
		view->DisplayWord(current_word->GetExternalWord());
		view->DisplayMistakes(mistakes);
		do
		{
			while (!current_word->IsGuessed() && mistakes < max_mistakes) {
				current_word = std::make_unique<GameWord>(wordsBuilder.GetRandomWord());
				char letter = view->GetInputLetter();
				if (current_word->InputLetter(letter))
				{
					view->DisplayWord(current_word->GetExternalWord());
				}
				else
				{
					view->DisplayMistakes(++mistakes);
				}
				view->WordGuessed();
			}
			if (mistakes < max_mistakes)
			{
				view->WordGuessed();
			}
			else
			{
				view->GameOver();
				break;
			}
			current_word = std::make_unique<GameWord>(wordsBuilder.GetRandomWord());
		} while (!view->IsGameExit());
	}
};