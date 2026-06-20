#include "include/config.hpp"

Config ParseArguments(int argc, char* argv[]) {
    Config config;

    if (argc < 2) {
        config.error = true;
        config.errorMessage = "no input files";
        config.showHelp = true;
    }

    for (int i = 1; i < argc; i++) {
        std::string argument = argv[i];

        if (argument == "-h" || argument == "--help") {
            config.showHelp = true;
            break;
        } else {
            config.inputFile = argument;
        }
    }

    return config;
}
