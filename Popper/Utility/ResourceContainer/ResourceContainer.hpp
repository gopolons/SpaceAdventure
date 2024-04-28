//
//  ResourceContainer.hpp
//  Popper
//
//  Created by Georgii Polonskii on 13/03/2024.
//

#include <iostream>

#ifndef ResourceContainer_hpp
#define ResourceContainer_hpp

extern std::string FONT_PATH;
extern std::string SPACESHIP_PATH;
extern std::string ASTEROID_PATH;
extern std::string HIGHSCORE_FILE_NAME;
extern std::string SETTINGS_FILE_NAME;
extern std::string PROMPT_FILE_NAME;

void updateResourcePaths(std::string basePath);

#endif /* ResourceContainer_hpp */
