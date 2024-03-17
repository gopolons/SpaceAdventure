//
//  main.cpp
//  Popper
//
//  Created by Georgii Polonskii on 13/03/2024.
//

#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdlib.h>

#include "MainMenu.hpp"
#include "GameLoop.hpp"
#include "InputManager.hpp"

int main() {
    // Create a window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Popper");
    
    // Instantiate a main menu object
    MainMenu menu(window);
    
    // Instantiate a game loop object
    GameLoop game(window);
    
    // Instantiate an input manager object
    InputManager inputManager(&game);
    
    // Main loop
    while (window.isOpen()) {
        // Handle events
        sf::Event event;
        while (window.pollEvent(event)) {
            switch(event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
                default:
                    inputManager.handleEvent(event);
                    break;
            }
        }
        
        inputManager.pollInput();
        game.startGame();
    }

    return 0;
}
