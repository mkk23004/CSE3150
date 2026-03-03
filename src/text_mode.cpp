#include "text_mode.h"
#include <iostream>
#include <cctype>
#include <string>

namespace text_mode {
    void run(int argc, char* argv[]) {
        if (argc < 3) return;
        std::string str = argv[2];
        int letters = 0, digits = 0, spaces = 0, punct = 0;

        for (char c : str) {
            if (std::isalpha(c)) letters++;
            else if (std::isdigit(c)) digits++;
            else if (std::isspace(c)) spaces++;
            else if (std::ispunct(c)) punct++;
        }

        std::cout << "Letters " << letters << "\nDigits " << digits 
                  << "\nSpaces " << spaces << "\nPunctuation " << punct << std::endl;

        std::string upper = str;
        for (size_t i = 0; i < upper.length(); ++i) {
            upper[i] = std::toupper(upper[i]);
        }
        std::cout << "Uppercase: " << upper << std::endl;
    }
}
