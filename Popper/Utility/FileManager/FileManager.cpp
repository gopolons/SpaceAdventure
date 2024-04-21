//
//  FileManager.cpp
//  Popper
//
//  Created by Georgy Polonskiy on 20/04/2024.
//

#include "FileManager.hpp"
#include <iostream>
#include <fstream>

// function that rewrites a file of a provided name with the provided data
void FileManager::rewriteFile(std::string fileName, std::string content) {
    std::ofstream file(fileName);
    if (!file.is_open()) {
        std::cerr << "Error: Unable to open file for writing!" << std::endl;
        return;
    }

    file << content; // Write new data to file
    file.close();    // Close the file
}

// function that opens a file with the provided name and tries to read from it
std::string FileManager::readFromFile(std::string fileName) {
    std::ifstream file(fileName);
    std::string content;

    if (!file.is_open()) {
        std::cerr << "Error: Unable to open file " << fileName << " for reading!" << std::endl;
        return "";
    }

    std::string line;
    while (std::getline(file, line)) {
        content += line + "\n";
    }

    file.close();
    return content;
}
