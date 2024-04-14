//
//  InputManager.hpp
//  Popper
//
//  Created by Georgy Polonskiy on 17/03/2024.
//

#ifndef InputManager_hpp
#define InputManager_hpp

#include <SFML/Graphics.hpp>

#include "SceneManager.hpp"
#include "InputDelegate.hpp"

class InputManager {
public:
    InputManager(SceneManager* sceneManager);
    
    void handleEvent(sf::Event event);
    void pollInput();
private:
    SceneManager* sceneManager;
};

#endif /* InputManager_hpp */
