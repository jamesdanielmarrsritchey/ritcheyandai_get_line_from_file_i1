#include <fstream>
#include <iostream>
#include <cstdlib>

int main(int argc, char *argv[]) {
    std::string filename;
    int targetLineNum = 0;

    // Parse command line arguments
    for (int i = 1; i < argc; i++) {
        std::string arg = argv[i];
        if (arg == "--file") {
            if (i + 1 < argc) { // Make sure we haven't reached the end of argv
                filename = argv[++i]; // Increment 'i' so we don't get the argument as the next argv[i].
            } else { // Uh-oh, these two arguments were not followed by another argument.
                std::cerr << "--file option requires one argument." << std::endl;
                return 1;
            }  
        } else if (arg == "--line_number") {
            if (i + 1 < argc) { // Make sure we haven't reached the end of argv
                targetLineNum = std::stoi(argv[++i]); // Increment 'i' so we don't get the argument as the next argv[i].
            } else { // Uh-oh, these two arguments were not followed by another argument.
                std::cerr << "--line_number option requires one argument." << std::endl;
                return 1;
            }  
        }
    }

    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Could not open file: " << filename << std::endl;
        exit(1);
    }

    std::string line;
    int lineNum = 0;
    while (std::getline(file, line)) {
        lineNum++;
        if (lineNum == targetLineNum) {
            std::cout << line << std::endl;
            exit(0);
        }
    }

    std::cerr << "Line number out of range" << std::endl;
    exit(1);
}