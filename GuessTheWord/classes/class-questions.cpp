#include <fstream>
#include <iostream>

class Questions {
    private:
        const char *datafile;

        int getLinesInFile() {
            int countLines = 1;
            std::string line;
            std::ifstream file(datafile);
            while(std::getline(file, line)) {
                ++countLines;
            }
            return countLines;
        }
        std::string getNextQuestion(int pInputIndex) {
            std::string line;
            std::ifstream file(datafile);
            for(int i=0; i<pInputIndex; ++i) {
                std::getline(file, line);
            }
            return line;
        }
    public:
        std::string getQuestion(int pIndex, std::string pDatafile) {
            const char *readyDatafile = pDatafile.c_str();
            datafile = readyDatafile;
            std::string result = getNextQuestion(pIndex);
            return result;
        }
};
