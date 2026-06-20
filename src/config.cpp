#include "include/config.hpp"

Config ParseArguments(int argc, char* argv[]) {
    Config config;

    for (int i = 1; i < argc; i++) {
        std::string argument = argv[i];

        if (argument == "-h" || argument == "--help") {
            config.showHelp = true;
            break;
        } else if (argument == "-o") {
            i++;
            if (i >= argc) {
                config.error = true;
                config.errorMessage = "missing output filename";
                break;
            } else {
                config.outputFile = argv[i];
            }
        } else if (argument == "-O0") {
            config.optimizationLevel = 0;
        } else if (argument == "-O1") {
            config.optimizationLevel = 1;
        } else if (argument == "-O2") {
            config.optimizationLevel = 2;
        } else if (argument == "-O3") {
            config.optimizationLevel = 3;
        } else {
            config.inputFile = argument;
        }
    }

    if (config.inputFile.empty()) {
        config.error = true;
        config.errorMessage = "no input file";
        config.showHelp = true;
    }

    return config;
}
