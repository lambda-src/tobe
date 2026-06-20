#include <llvm/Support/raw_ostream.h>
#include <iostream>

#include "include/config.hpp"

// TODO: Meowwowowowow

int main(int argc, char* argv[]) {
    Config config = ParseArguments(argc, argv);
    int return_value = 0;

    if (config.error) {
        std::cout << "Error: " << config.errorMessage << "\n";
        return_value = 1;
    }

    if (config.showHelp) {
        std::cout << "Usage: tobe [options] [file]\n\n"
                  << "Options:\n"
                  << "  -h, --help      Display this information.\n"
                  << "  -o <file>       Place the output into <file>.\n"
                  << "  -O0             No optimization (default).\n"
                  << "  -O1             Optimization.\n"
                  << "  -O2             More optimization.\n"
                  << "  -O3             Even more optimization.\n";
        return return_value;
    }

    llvm::outs() << "LLVM should be functioning\n";
    return return_value;
}
