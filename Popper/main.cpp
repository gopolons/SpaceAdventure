//
//  main.cpp
//  Popper
//
//  Created by Georgii Polonskii on 13/03/2024.
//

#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdlib.h>

#include "ScoreManager.hpp"
#include "MainMenu.hpp"
#include "GameLoop.hpp"
#include "SceneManager.hpp"
#include "InputManager.hpp"
#include "GameOver.hpp"
#include "SettingsMenu.hpp"

int main() {
    // Create a window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Popper");
    
    // Instantiate a settings object
    SettingsMenu settings(window);
    
    // Instantiate a main menu object
    MainMenu menu(window);
    
    // Instantiate a game loop object
    GameLoop game(window);
    
    // Instantiate a game over object
    GameOver gameOver(window);
    
    // Instantiate a scene manager
    SceneManager sceneManager(&game, &menu, &gameOver, &settings);
    sceneManager.goToMenu();
    
    // Instantiate an input manager object
    InputManager inputManager(&sceneManager);
    
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
        sceneManager.runActiveScene();
    }

    return 0;
}
