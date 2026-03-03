#include "text_mode.h"
#include "add_mode.h"
#include "stats_mode.h"
#include <iostream>
#include <string>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Usage: ./analyzer <mode> [arguments]" << std::endl;
        return 1;
    }

    std::string modeStr = argv[1];
    int mode = 0;
    if (modeStr == "text") mode = 1;
    else if (modeStr == "add") mode = 2;
    else if (modeStr == "stats") mode = 3;

    switch (mode) {
        case 1: text_mode::run(argc, argv); break;
        case 2: add_mode::run(argc, argv); break;
        case 3: stats_mode::run(argc, argv); break;
        default:
            std::cout << "Invalid mode" << std::endl;
            return 1;
    }
    return 0;
}
