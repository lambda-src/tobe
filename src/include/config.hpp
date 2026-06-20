#pragma once
#include <string>

struct Config {
    std::string inputFile;
    std::string outputFile = "a.out";
    int optimizationLevel = 0;
    bool showHelp = false;

    std::string errorMessage;
    bool error = false;
};

Config ParseArguments(int argc, char* argv[]);
