#include "stats_mode.h"
#include <iostream>
#include <string>
#include <set>
#include <algorithm>

namespace stats_mode {
    void run(int argc, char* argv[]) {
        if (argc < 3) return;
        std::string str = argv[2];
        std::cout << "Length " << str.length() << std::endl;

        std::set<char> unique_chars(str.begin(), str.end());
        std::cout << "Unique " << unique_chars.size() << std::endl;

        bool alnum = true;
        for (char c : str) if (!std::isalnum(c)) alnum = false;
        std::cout << "Alphanumeric " << (alnum ? "Yes" : "No") << std::endl;

        std::string rev = str;
        std::reverse(rev.begin(), rev.end());
        
        std::string clean = "";
        for (char c : str) if (c != ' ') clean += std::tolower(c);
        std::string rev_clean = clean;
        std::reverse(rev_clean.begin(), rev_clean.end());
        
        std::cout << "Palindrome " << (clean == rev_clean ? "Yes" : "No") << std::endl;
    }
}
