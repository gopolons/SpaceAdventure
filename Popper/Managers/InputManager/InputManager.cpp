//
//  InputManager.cpp
//  Popper
//
//  Created by Georgy Polonskiy on 17/03/2024.
//

#include "InputManager.hpp"

InputManager::InputManager(SceneManager* sceneManager) : sceneManager(sceneManager) {}

void InputManager::handleEvent(sf::Event event) {
    std::any pointer = sceneManager->getCurrentInputDelegate();
    InputDelegate* currentInputDelegate = std::any_cast<InputDelegate*>(pointer);
    switch (event.type) {
        case sf::Event::KeyPressed:
            if (event.key.code == sf::Keyboard::Space) currentInputDelegate->handleActionButton();
            if (event.key.code == sf::Keyboard::Up) currentInputDelegate->handleUpButton();
            if (event.key.code == sf::Keyboard::Down) currentInputDelegate->handleDownButton();
            if (event.key.code == sf::Keyboard::Escape) currentInputDelegate->handleEscapeButton();
            return;
        default:
            return;;
    }
}
 
void InputManager::pollInput() {
    InputDelegate* currentInputDelegate = std::any_cast<InputDelegate*>(sceneManager->getCurrentInputDelegate());
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) currentInputDelegate->handleLeftButton();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) currentInputDelegate->handleRightButton();
}
