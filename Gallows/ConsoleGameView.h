#pragma once
#include "IGameView.h"
#include <iostream>

class ConsoleGameView : public IGameView
{
	int mistakes = 0;
public:
	virtual void DisplayWord(const std::string& word) override {
		for (wchar_t letter : word)
		{
			if (letter == ' ')
			{
				std::cout << "_ ";
			}
			else
			{
				std::cout << letter << ' ';
			}
		}
		std::cout << std::endl;
	}

	virtual void InitialMistakes(int mistakes) override {
		this->mistakes = mistakes;
		std::cout << "Mistakes: " << this->mistakes << std::endl;
	}

	virtual void DisplayMistakes(int mistakes) override {
		if (mistakes > this->mistakes)
		{
			this->mistakes = mistakes;
			std::cout << "Mistakes: " << this->mistakes << std::endl;
		}
	}
	//virtual void GuessedLetter(bool value) override {
	//
	//}

	virtual void WordGuessed() override {
		std::cout << "Word Guessed!!!" << std::endl;
		system("pause");
	}
	virtual void GameOver() override {
		std::cout << "Game Over!" << std::endl;
		system("pause");
	}
	virtual bool IsGameExit() override {
		char input;
		while (true) {
			std::cout << "Do you want exit to main menu? (y/n): ";
			std::cin >> input;
			switch (input)
			{
			case 'y':
			case 'Y':
				return true;
				break;

			case 'n':
			case 'N':
				return false;
			default:

				break;
			}
		}
	}

	virtual void DisplayMessage(const std::string& message) override {
		std::cout << "DisplayMessage: " << message << std::endl;
	}

	virtual char GetInputLetter() override
	{
		char input;
		std::cout << "Input the letter: " << std::endl;
		std::cin >> input;
		return input;
	}
};