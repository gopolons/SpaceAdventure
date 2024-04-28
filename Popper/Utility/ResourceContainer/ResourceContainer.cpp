//
//  ResourceContainer.cpp
//  Popper
//
//  Created by Georgy Polonskiy on 27/04/2024.
//

#include <stdio.h>
#include "ResourceContainer.hpp"

std::string FONT_PATH = "gohu.ttf";
std::string SPACESHIP_PATH = "spaceship.png";
std::string ASTEROID_PATH = "asteroid.png";
std::string HIGHSCORE_FILE_NAME = "highscore.txt";
std::string SETTINGS_FILE_NAME = "settings.txt";
std::string PROMPT_FILE_NAME = "prompts.txt";

// Function for removing the executable name from the resource path
std::string removeExecutableFromPath(std::string fullPath) {
    // Find the last occurrence of "/"
    size_t lastSlashPos = fullPath.find_last_of("/");
    
    if (lastSlashPos != std::string::npos) {
        // Truncate the string up to the last occurrence of "/"
        return fullPath.substr(0, lastSlashPos + 1);
    } else {
        // Return the original string if "/" is not found
        return fullPath;
    }
}

void updateResourcePaths(std::string basePath) {
    std::string BASE_PATH = removeExecutableFromPath(basePath);
    
    FONT_PATH = BASE_PATH + FONT_PATH;
    SPACESHIP_PATH = BASE_PATH + SPACESHIP_PATH;
    ASTEROID_PATH = BASE_PATH + ASTEROID_PATH;
    HIGHSCORE_FILE_NAME = BASE_PATH + HIGHSCORE_FILE_NAME;
    SETTINGS_FILE_NAME = BASE_PATH + SETTINGS_FILE_NAME;
    PROMPT_FILE_NAME = BASE_PATH + PROMPT_FILE_NAME;
}
