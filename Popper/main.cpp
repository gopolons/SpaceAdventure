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

int main() {
    // Create a window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Popper");

    // Instantiate a main menu object
    MainMenu menu;
    
    // Instantiate a game loop object
    GameLoop game(window);
    
    // Main loop
    while (window.isOpen()) {
        // Handle events
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        
        game.startGame();
        
        // Display the main menu title
        // menu.draw_title(window);
    }

    return 0;
}
