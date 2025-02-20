#pragma once
#include "GameWord.h"
#include "GameWordsBuilder.h"
#include "IGameView.h"
#include <memory>

using std::unique_ptr;

class Game
{
private:
	GameWordsBuilder wordsBuilder;
	unique_ptr<GameWord> current_word;
	int mistakes;
	unique_ptr<IGameView> view;
	const int MAX_MISTAKES = 6;
public:
	Game(shared_ptr<WordsManager> manager,
		unique_ptr<IGameView> view)
		: wordsBuilder(manager),
		view(std::move(view))
	{
		mistakes = 0;
	}

	void Start()
	{
		do
		{
			current_word = std::make_unique<GameWord>(wordsBuilder.GetRandomWord());
			view->DisplayWord(current_word->GetExternalWord());
			view->DisplayMistakes(mistakes);
			while (!current_word->IsGuessed() && mistakes < MAX_MISTAKES)
			{
				char letter = view->GetInputLetter();
				if (current_word->InputLetter(letter))
					view->DisplayWord(current_word->GetExternalWord());
				else
					++mistakes;
				view->DisplayMistakes(mistakes);
			}
			if (mistakes < MAX_MISTAKES)
				view->WordGuessed();
			else {
				view->GameOver();
				// TODO: збререгти статистику до таблиці лідерів
			}
			current_word = std::make_unique<GameWord>(wordsBuilder.GetRandomWord());
		} while (view->IsGameContinue());
	}
};

