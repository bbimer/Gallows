#pragma once
#include "IGameView.h"
#include <iostream>

class ConsoleGameView : public IGameView
{
    int mistakes = 0;
public:
    void DisplayWord(const std::string& word) override
    {
        for (char letter : word)
        {
            if (letter == ' ')
            {
                std::cout << "_ ";
            }
            else {
                std::cout << letter << ' ';
            }
        }
        std::cout << std::endl;
    }

    void DisplayMistakes(int mistakes) override
    {
        std::cout << "Mistakes: (" << mistakes << "/6)" << std::endl;
        DrawHangman(mistakes);
    }

    void DrawHangman(int mistakes)
    {
        switch (mistakes)
        {
        case 0:
            std::cout << "\n";
            std::cout << "  +---+" << std::endl;
            std::cout << "  |   |" << std::endl;
            std::cout << "      |" << std::endl;
            std::cout << "      |" << std::endl;
            std::cout << "      |" << std::endl;
            std::cout << "      |" << std::endl;
            std::cout << "=========" << std::endl;
            break;
        case 1:
            std::cout << "  +---+" << std::endl;
            std::cout << "  |   |" << std::endl;
            std::cout << "  O   |" << std::endl;
            std::cout << "      |" << std::endl;
            std::cout << "      |" << std::endl;
            std::cout << "      |" << std::endl;
            std::cout << "=========" << std::endl;
            break;
        case 2:
            std::cout << "  +---+" << std::endl;
            std::cout << "  |   |" << std::endl;
            std::cout << "  O   |" << std::endl;
            std::cout << "  |   |" << std::endl;
            std::cout << "      |" << std::endl;
            std::cout << "      |" << std::endl;
            std::cout << "=========" << std::endl;
            break;
        case 3:
            std::cout << "  +---+" << std::endl;
            std::cout << "  |   |" << std::endl;
            std::cout << "  O   |" << std::endl;
            std::cout << " /|   |" << std::endl;
            std::cout << "      |" << std::endl;
            std::cout << "      |" << std::endl;
            std::cout << "=========" << std::endl;
            break;
        case 4:
            std::cout << "  +---+" << std::endl;
            std::cout << "  |   |" << std::endl;
            std::cout << "  O   |" << std::endl;
            std::cout << " /|\\  |" << std::endl;
            std::cout << "      |" << std::endl;
            std::cout << "      |" << std::endl;
            std::cout << "=========" << std::endl;
            break;
        case 5:
            std::cout << "  +---+" << std::endl;
            std::cout << "  |   |" << std::endl;
            std::cout << "  O   |" << std::endl;
            std::cout << " /|\\  |" << std::endl;
            std::cout << " /    |" << std::endl;
            std::cout << "      |" << std::endl;
            std::cout << "=========" << std::endl;
            break;
        case 6:
            std::cout << "  +---+" << std::endl;
            std::cout << "  |   |" << std::endl;
            std::cout << "  O   |" << std::endl;
            std::cout << " /|\\  |" << std::endl;
            std::cout << " / \\  |" << std::endl;
            std::cout << "      |" << std::endl;
            std::cout << "=========" << std::endl;
            break;
        }
    }

    virtual void WordGuessed() override
    {
        std::cout << "Word Guessed !!!" << std::endl;
    }

    virtual void GameOver() override
    {
        std::cout << "!!! GameOver !!!\n";
        system("pause");
    }

    virtual bool IsGameContinue() override
    {
        char input;
        while (true)
        {
            std::cout << "Do you want continue? (y/n): ";
            std::cin >> input;
            switch (input)
            {
            case 'y':
            case 'Y':
                return true;
            case 'n':
            case 'N':
                return false;
            default:
                system("cls");
                break;
            }
        }
    }

    void DisplayMessage(const std::string& message) override
    {
        std::cout << "DisplayMessage: " << message << std::endl;
    }

    char GetInputLetter() override
    {
        char input;
        std::cout << "Input the letter: ";
        std::cin >> input;
        return input;
    }
};
