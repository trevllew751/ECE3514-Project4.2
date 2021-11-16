//
//  ExpConvDriver.cpp
//
//

#include "PalindromeFinder.hpp"
#include <sstream>
#include <fstream>
#include <iostream>
#include <string.h>

int interactivePalindromeFinder(std::string mode);

int fileReadPalindromeFinder(std::string fileName, std::string mode);

void processLine(std::string line, bool recursive);

int main(int argc, char *argv[]) {
    if (argc == 2) {
        if (strcmp(argv[1], "-r") == 0 || strcmp(argv[1], "-n") == 0) {
            return interactivePalindromeFinder(argv[1]);
        } else {
            std::cout << "Invalid arguments!" << std::endl;
            std::cout << "Usage: ./finder -n or -r [-f <filename>]" << std::endl;
            return EXIT_FAILURE;
        }
    } else if (argc == 4) {
        if ((strcmp(argv[1], "-r") == 0 || strcmp(argv[1], "-n") == 0) && (strcmp(argv[2], "-f") == 0)) {
            return fileReadPalindromeFinder(argv[3], argv[1]);
        } else {
            std::cout << "Invalid arguments!" << std::endl;
            std::cout << "Usage: ./finder -n or -r [-f <filename>]" << std::endl;
            return EXIT_FAILURE;
        }
    } else {
        std::cout << "Invalid arguments!" << std::endl;
        std::cout << "Usage: ./finder -n or -r [-f <filename>]" << std::endl;
        return EXIT_FAILURE;
    }
}

int interactivePalindromeFinder(std::string mode) {
    PalindromeFinder f;
    bool recursive = (mode == "-r");
    std::string line;
    while (true) {
        std::cout << "Enter a sring:" << std::endl;
        getline(std::cin, line);
        if (line == "exit") {
            std::cout << "Bye!" << std::endl;
            break;
        }
        processLine(line, recursive);
    }
    return EXIT_SUCCESS;
}

int fileReadPalindromeFinder(std::string fileName, std::string mode) {
    PalindromeFinder f;
    bool recursive = (mode == "-r");
    std::string line;
    std::fstream file(fileName);
    if (file.is_open()) {
        while (getline(file, line)) {
            std::cout << line << std::endl;
            processLine(line, recursive);
        }
    } else {
        std::cout << "Input file cannot be read. Exit!" << std::endl;
        return EXIT_FAILURE;
    }
    file.close();
    return EXIT_SUCCESS;
}

void processLine(std::string line, bool recursive) {
    PalindromeFinder f;
    bool isPalindrome;
    std::string message;
    if (f.processString(line) == "duplicated") {
        message = f.printResult(line, "has duplicated word(s)!");
    } else {
        isPalindrome = recursive ? f.isPalindrome(line) : f.checkPalindrome(line);
        message = isPalindrome
                  ? f.printResult(line, "is a Palindrome!")
                  : f.printResult(line, "is not a Palindrome!");
    }
    std::cout << message << std::endl << std::endl;
}