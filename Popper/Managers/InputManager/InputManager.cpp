//
//  InputManager.cpp
//  Popper
//
//  Created by Georgy Polonskiy on 17/03/2024.
//

#include "InputManager.hpp"

InputManager::InputManager(InputDelegate* delegate) : delegate(delegate) {}

void InputManager::handleEvent(sf::Event event) {
    switch (event.type) {
        case sf::Event::KeyPressed:
            if (event.key.code == sf::Keyboard::Space) delegate->handleActionButton();
            break;
        default:
            break;
    }
}
 
void InputManager::pollInput() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) delegate->handleLeftButton();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) delegate->handleRightButton();
}

void InputManager::updateDelegate(InputDelegate *delegate) {
    delegate = delegate;
}
