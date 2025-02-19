#include <iostream>
#include "ConsoleGameView.h"
#include "WordsManager.h"
#include "Game.h"

int main() {
    auto managerPtr = std::make_shared<WordsManager>();
    auto viewPtr = std::make_unique<ConsoleGameView>();

    Game game(managerPtr, std::move(viewPtr));
    game.Start();

    return 0;
}
