#include <iostream>
#include <fstream>

class Answers {
    public:
        Answers(const char *pDatafile) {
            answersData = pDatafile;
        }
        std::string toIndex(int index) {
            return getAnswer(index);
        }
    private:
        const char* answersData;

        std::string getAnswer(int pIndex) {
            std::string line;
            std::ifstream file(answersData);
            for(int i=0; i<pIndex; ++i) {
                std::getline(file, line);
            }
            return line;
        }
};
