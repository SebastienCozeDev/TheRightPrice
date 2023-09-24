#ifndef UTILS_H_INCLUDED
#define UTILS_H_INCLUDED

#include <iostream>
#include <array>
#include "constants.h"

using TableOfScores = std::array<int, NUMBER_OF_SCORES>;


/**
 * @brief This enumaration enumerate the choice in the start menu.
 */
enum class MenuChoice {
    PLAY = 'p',
    PLAY_EASY = 'e',
    PLAY_THREE_GAMES = 't',
    PRINT_SCORE = 's',
    QUIT = 'q',
    INCORRECT
};

void askSuggestion(int& suggestionNumber);

int playAGame(int numberToGuess);

int launchGame(int maxLimit, int numberOfGames = DEFAULT_GAMES_NUMBER);

void printScores(TableOfScores& scoreTab);

/**
 * @brief This function print the menu.
 */
inline void printMenu() {
    std::cout << "========== THE RIGHT PRICE ==========" << std::endl;
    std::cout << "Welcome in The Right Price!" << std::endl;
    std::cout << static_cast<char>(MenuChoice::PLAY) << "              - Play a game" << std::endl;
    std::cout << static_cast<char>(MenuChoice::PLAY_EASY) << "              - Play a easy game" << std::endl;
    std::cout << static_cast<char>(MenuChoice::PLAY_THREE_GAMES) << "              - Play three games" << std::endl;
    std::cout << static_cast<char>(MenuChoice::PRINT_SCORE) << "              - Print the scores" << std::endl;
    std::cout << static_cast<char>(MenuChoice::QUIT) << "              - Quit" << std::endl;
}

MenuChoice askTheMenuChoice();

#endif // UTILS_H_INCLUDED
