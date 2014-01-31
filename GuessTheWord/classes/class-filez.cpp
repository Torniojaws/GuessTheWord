#include <fstream>

class Filez {
    private:
        int countLines;
    public:
        int getRowCount(const char *pFile) {
            countLines = 0;
            std::string line;
            std::ifstream file(pFile);
            while(std::getline(file, line)) {
                if(line != "") {
                    ++countLines;
                }
            }
            return countLines;
        }

        bool fileExists(const char *pFile) {
            std::ifstream infile(pFile);
            return infile.good();
        }

};
