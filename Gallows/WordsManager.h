#pragma once
#include <vector>
#include <string>
#include <fstream>
#include <iostream>

using std::vector;
using std::string;
using std::fstream;
using std::ios;

class WordsManager
{
private:
    vector<string> words;

public:
    WordsManager() {
        Load();
    }

    const vector<string>& GetWords() const {
        return words;
    }

    void Load() {
        words.clear();
        std::fstream input("words.txt", ios::in);
        if (input.is_open()) {
            string word;
            while (std::getline(input, word)) { 
                if (!word.empty()) { 
                    words.emplace_back(word);
                }
            }
            input.close();
        }
        else {
            std::cerr << "Error: file words.txt not found!" << std::endl;
        }
    }

    void Append(const string& word) {
        words.push_back(word);
        Save();
    }

    void Save() {
        std::fstream output("words.txt", ios::out);
        if (output.is_open()) {
            for (const auto& word : words) {
                output << word << std::endl;
            }
            output.close();
        }
    }
};
