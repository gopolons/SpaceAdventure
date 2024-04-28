//
//  MenuPrompt.cpp
//  Popper
//
//  Created by Georgy Polonskiy on 27/04/2024.
//

#include "MenuPrompt.hpp"
#include "FileManager.hpp"
#include "ResourceContainer.hpp"
#include <sstream>

std::string getRandomSubstring() {
    FileManager fm;
    
    std::string input = fm.readFromFile(PROMPT_FILE_NAME);
    std::vector<std::string> substrings;
    std::istringstream iss(input);
    std::string line;

    while (std::getline(iss, line, '\n')) {
        substrings.push_back(line);
    }
    
    if (substrings.empty()) {
        return ""; // Return an empty string if the input vector is empty
    }

    // Generate a random index within the range of the vector size
    int randomIndex = std::rand() % substrings.size();
    return substrings[randomIndex];
}

MenuPrompt::MenuPrompt() {
    text = getRandomSubstring();
    
    sf::Color gray = sf::Color::Red;
    gray.a = 100;
    color = gray;
    
    isGettingBigger = false;
    zoom = 0.5;
}

float MenuPrompt::getZoomValue() {
    if (isGettingBigger) {
        zoom += 0.0005;
    } else {
        zoom -= 0.0005;
    }
    
    if (zoom <= 0.5) {
        zoom = 0.5;
        isGettingBigger = true;
    } else if (zoom >= 1) {
        zoom = 1;
        isGettingBigger = false;
    }
    
    return zoom;
}
