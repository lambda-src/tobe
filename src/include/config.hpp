#pragma once
#include <string>

struct Config {
    std::string inputFile;
    bool showHelp = false;

    std::string errorMessage;
    bool error = false;
};

Config ParseArguments(int argc, char* argv[]);
