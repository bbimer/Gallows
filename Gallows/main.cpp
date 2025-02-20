#include <iostream>
#include "WordsManager.h"
#include "ConsoleGameView.h"
#include "Game.h"

void ShowMenu(WordsManager& manager);
void StartGame(WordsManager& manager);
void ShowRecords();
void Settings(WordsManager& manager);
void AddWord(WordsManager& manager);

int main() {
    srand(static_cast<unsigned int>(time(0)));
    WordsManager manager;
    ShowMenu(manager);
    return 0;
}

void ShowMenu(WordsManager& manager) {
    int choice;
    do {
        std::cout << "\n--- Main Menu ---\n";
        std::cout << "[1] New Game\n";
        std::cout << "[2] Records\n";
        std::cout << "[3] Settings\n";
        std::cout << "[4] Exit\n";
        std::cout << "your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            StartGame(manager);
            break;
        case 2:
            ShowRecords();
            break;
        case 3:
            Settings(manager);
            break;
        case 4:
            std::cout << "Exiting the game...\n";
            break;
        default:
            std::cout << "Incorrect choice, try again.\n";
        }
    } while (choice != 4);
}

void StartGame(WordsManager& manager) {
    ConsoleGameView consoleView;
    Game game(std::make_shared<WordsManager>(manager), std::make_unique<ConsoleGameView>(consoleView));
    game.Start();
}

void ShowRecords() {
    std::cout << "\n--- Records ---\n";
    std::cout << "The function is not yet implemented.\n";
}

void Settings(WordsManager& manager) {
    int choice;
    do {
        std::cout << "\n--- Settings ---\n";
        std::cout << "1. Add a word\n";
        std::cout << "2. Back\n";
        std::cout << "your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            AddWord(manager);
            break;
        case 2:
            return;
        default:
            std::cout << "Incorrect choice, try again.\n";
        }
    } while (choice != 2);
}

void AddWord(WordsManager& manager) {
    std::string newWord;
    std::cout << "Enter a new word: ";
    std::cin >> newWord;
    manager.Append(newWord);
    std::cout << "Word added!\n";
}
