#include "utils.h"

#include <iostream>
#include <chrono>
#include <random>
#include "constants.h"

using namespace std;

using CDuration = std::chrono::duration<double>;


/**
 * @brief This function launch the game.
 *
 * @param maxLimit The maximum limit.
 * @param numberOfGames The number of games.
 *
 * @return 0.
 */
int launchGame(int maxLimit, int numberOfGames) {
    auto randomGenerator = std::random_device{};
    auto generator = mt19937{randomGenerator()};
    auto distribution = std::uniform_int_distribution{MIN_LIMIT, maxLimit};
    int score = 0;
    cout << "Let's go!" << endl;
    for (int i = 0; i < numberOfGames; i++) {
        score += playAGame(distribution(generator));
    }
    return score;
}


/**
 * @brief This function play one game.
 *
 * @param numberToGuess The number to guess.
 */
int playAGame(int numberToGuess) {
    int suggestionNumber;
    int attemptsNumber = 0;
    auto startGameTime = std::chrono::system_clock::now();
    do {
        askSuggestion(suggestionNumber);
        if (suggestionNumber >= MIN_LIMIT && suggestionNumber < MAX_LIMIT) {
            attemptsNumber++;
            if (suggestionNumber < 0) {
                cout << "The negatif number are forbidden." << endl;
            } else if (suggestionNumber < numberToGuess) {
                if (suggestionNumber + DIFFERENCE_FOR_MANY < numberToGuess) {
                    cout << "The number to guess is much larger." << endl;
                } else {
                    cout << "The number to guess is greater." << endl;
                }
            } else if (suggestionNumber > numberToGuess) {
                if (suggestionNumber >= numberToGuess + DIFFERENCE_FOR_MANY) {
                    cout << "The number to guess is much smaller." << endl;
                } else {
                    cout << "The number to guess is smaller." << endl;
                }
            }
        } else {
            cout << "The number to guess is between " << MIN_LIMIT << " and " << MAX_LIMIT << "." << endl;
        }
    } while (suggestionNumber != numberToGuess);
    auto endGameTime = std::chrono::system_clock::now();
    auto timeOfGame = std::chrono::duration_cast<CDuration>(endGameTime - startGameTime);
    cout << "Well done! You won with " << attemptsNumber << " attemps!" << endl;
    cout << "Duration of this game: " << timeOfGame.count() << "seconds" << endl;
    return attemptsNumber;
}


/**
 * @brief This function ask to the user a suggestion number.
 *
 * @param suggestionNumber Reference of the suggestion number.
 */
void askSuggestion(int& suggestionNumber) {
    cout << "Suggest a number: ";
    cin >> suggestionNumber;
}


/**
 * @brief This function ask to the user the choice in the start menu.
 *
 * @return The choice of the MenuChoice.
 */
MenuChoice askTheMenuChoice() {
    char choiceEnrty;
    cout << "Your choice: ";
    cin >> choiceEnrty;
    if (choiceEnrty == static_cast<char>(MenuChoice::PLAY) || choiceEnrty == static_cast<char>(MenuChoice::QUIT) || choiceEnrty == static_cast<char>(MenuChoice::PLAY_EASY) || choiceEnrty == static_cast<char>(MenuChoice::PLAY_THREE_GAMES) || choiceEnrty == static_cast<char>(MenuChoice::PRINT_SCORE)) {
        return static_cast<MenuChoice>(choiceEnrty);
    } else {
        return MenuChoice::INCORRECT;
    }
}

void printScores(TableOfScores& scoreTab) {
    for (int score: scoreTab) {
        if (score == 0) {
            cout << '-' << endl;
        } else if (score == 1) {
            cout << score << " tentative" << endl;
        } else {
            cout << score << " tentatives" << endl;
        }
    }
}
