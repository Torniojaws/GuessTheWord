#include <iostream>

class Player {
    private:
        std::string name;
        int points;
    public:
        std::string inName;
        Player() {
            std::cout << "What is thy name?" << std::endl;
            std::cin >> inName;
            name = inName;
            points = 0;
        }
        void addPoint() {
            ++points;
        }
        void decreasePoint() {
            --points;
        }
        int getCurrentPoints() {
            return points;
        }
        std::string getName() {
            return name;
        }
};
