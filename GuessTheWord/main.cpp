#include <iostream>
#include "classes/class-game.cpp"

int main()
{
    std::cout << "Guess the Word! v1.0" << std::endl;
    std::cout << "--------------------" << std::endl;
    std::cout << "Correct answer = 1 point\nWrong answer = -1 point\n0 points = Game over" << std::endl;
    std::cout << "q = quit" << std::endl;
    std::cout << "Good luck!\n" << std::endl;

    // Init
    Game game;
    const char *questionsDatafile = "questions.txt";
    const char *answersDatafile = "answers.txt";

    // Start
    game.start(questionsDatafile, answersDatafile);
    while(game.input != "q") {
        game.playRound();
    }
    game.stop();
}
