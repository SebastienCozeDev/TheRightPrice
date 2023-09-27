#include <iostream>
#include <array>
#include "constants.h"
#include "utils.h"

using namespace std;


/**
 * @brief This function is the main function.
 *
 * @return The exit code.
 */
int main() {
    MenuChoice choice;
    bool run = true;
    TableOfScores scoreTab = {0, 0, 0};
    int currentIndex = 0;
    while (run) {
        printMenu();
        choice = askTheMenuChoice();
        switch (choice) {
            case MenuChoice::PLAY:
                scoreTab[currentIndex] = launchGame(MAX_LIMIT, 1);
                currentIndex = (currentIndex + 1) % NUMBER_OF_SCORES;
                break;
            case MenuChoice::PLAY_EASY:
                scoreTab[currentIndex] = launchGame(MAX_LIMIT_FOR_EASY, 1);
                currentIndex = (currentIndex + 1) % NUMBER_OF_SCORES;
                break;
            case MenuChoice::PLAY_THREE_GAMES:
                scoreTab[currentIndex] = launchGame(MAX_LIMIT);
                currentIndex = (currentIndex + 1) % NUMBER_OF_SCORES;
                break;
            case MenuChoice::PRINT_SCORE:
                printScores(scoreTab);
                break;
            case MenuChoice::QUIT:
                run = false;
                break;
            case MenuChoice::INCORRECT:
            default:
                cout << "Bye!" << endl;
                return EXIT_FAILURE;
        }
    }
    return EXIT_SUCCESS;
}
