#include <iostream>
#include <ctime>
#include <stdlib.h>
#include "class-questions.cpp"
#include "class-answers.cpp"
#include "class-filez.cpp"
#include "class-player.cpp"

class Game {
    private:

    public:
        const char *questionsData;
        const char *answersData;
        std::string input;
        int roundCounter;
        Player player;
        Filez data;
        Questions quiz;

        int getRandomNumber() {
            int lineCount = data.getRowCount(questionsData);
            srand(time(NULL));
            return rand() % lineCount + 1; // random row number between 1...rows in the file
        }

        void start(const char *qDatafile, const char *aDatafile) {
            if(data.fileExists(qDatafile) && data.fileExists(aDatafile)) {
                std::cout << "> Datafiles are ok!" << std::endl;
                questionsData = qDatafile;
                answersData = aDatafile;
            } else {
                std::cout << "> Some Datafiles are missing! That\'s it folks!" << std::endl;
                exit(1);
            }
            roundCounter = 0;
            std::cout << "> Let the games begin!" << std::endl;
        }

        void stop() {
            std::cout << "> Game over, man!" << std::endl;
            exit(0);
        }

        void askQuestion(int pAskIndex) {
            ++roundCounter;
            std::cout << "> Round " << roundCounter << " begins. " << std::endl;
            std::cout << "DEBUG: Using index: " << pAskIndex << " and file: " << questionsData << std::endl;
            std::cout << quiz.getQuestion(pAskIndex, questionsData) << std::endl;
            std::cin >> input;
        }

        bool answerIsCorrect(int pAnsIndex) {
            Answers answers(answersData);
            if(input == answers.toIndex(pAnsIndex)) {
                std::cout << "Answer is correct! +1 point!" << std::endl;
                return true;
            } else {
                std::cout << "Answer is wrong! -1 point..." << std::endl;
                return false;
            }
        }

        void playRound() {
            int indexOfCurrentQuestion = this->getRandomNumber();
            this->askQuestion(indexOfCurrentQuestion);
            if(this->answerIsCorrect(indexOfCurrentQuestion)) {
                player.addPoint();
            } else {
                player.decreasePoint();
            }
            this->gameStatus();
        }

        void gameStatus() {
            std::cout << player.getName() << " now has " << player.getCurrentPoints() << " points! " << std::endl;
            if(player.getCurrentPoints() <= 0) {
                this->stop();
            }
        }
};
