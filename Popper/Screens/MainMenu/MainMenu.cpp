//
//  MainMenu.cpp
//  Popper
//
//  Created by Georgii Polonskii on 13/03/2024.
//

#include <SFML/Graphics.hpp>
#include <iostream>

#include "ResourceContainer.hpp"
#include "MainMenu.hpp"

void MainMenu::drawTitle(sf::RenderWindow& window) {
    // Clear any existing content on the window
    window.clear(sf::Color::Black);
    
    // Create a font
    sf::Font font;
    if (!font.loadFromFile(FONT_PATH)) {
        std::cerr << "Failed to load font!" << std::endl;
        return;
    }

    // Create a text
    sf::Text title;
    title.setFont(font);
    title.setString("Popper");
    title.setCharacterSize(24);
    title.setFillColor(sf::Color::White);

    // Position the text
    title.setPosition(0, 0);
    
    // Draw the text
    window.draw(title);
    
    // Display the window contents
    window.display();
}
