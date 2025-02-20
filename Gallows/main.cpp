#include <iostream>
#include "ConsoleGameView.h"
#include "WordsManager.h"
#include "Game.h"

int main()
{
	srand(time(0));
	WordsManager manager;
	ConsoleGameView consoleView;


	Game game(std::make_shared<WordsManager>(manager), std::make_unique<ConsoleGameView>(consoleView));
	game.Start();

	return 0;
}