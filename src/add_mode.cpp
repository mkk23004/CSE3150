#include "add_mode.h"
#include <iostream>
#include <string>

namespace add_mode {
    int add(int a, int b) { return a + b; }
    double add(double a, double b) { return a + b; }
    std::string add(std::string a, std::string b) { return a + b; }

    void run(int argc, char* argv[]) {
        if (argc < 4) return;
        std::string s1 = argv[2];
        std::string s2 = argv[3];

        if (s1.find('.') != std::string::npos || s2.find('.') != std::string::npos) {
            std::cout << "Result " << add(std::stod(s1), std::stod(s2)) << std::endl;
        } else {
            try {
                std::cout << "Result " << add(std::stoi(s1), std::stoi(s2)) << std::endl;
            } catch (...) {
                std::cout << "Result " << add(s1, s2) << std::endl;
            }
        }
    }
}
