//
//  GameOver.cpp
//  Popper
//
//  Created by Georgy Polonskiy on 19/04/2024.
//

#include "GameOver.hpp"
#include "ResourceContainer.hpp"
#include <iostream>

GameOver::GameOver(sf::RenderWindow& window) : window(window) {
    sf::Vector2u windowCenter = window.getSize();
    screenCenter = sf::Vector2f((windowCenter.x / 2), (windowCenter.y / 2));
}

void GameOver::showEndGameScreen() {
    // Clear any existing content on the window
    window.clear(sf::Color::White);
    
    // Create a font
    sf::Font font;
    if (!font.loadFromFile(FONT_PATH)) {
        std::cerr << "Failed to load font!" << std::endl;
        return;
    }

    // Create a title
    sf::Text title;
    title.setFont(font);
    title.setString("Game Over!");
    title.setCharacterSize(50);
    title.setFillColor(sf::Color::Black);
    
    // Position the text in the middle of local bounds
    sf::FloatRect titleCenter = title.getLocalBounds();
    title.setOrigin(sf::Vector2f((titleCenter.width / 2), (titleCenter.height / 2)));
    
    sf::Text cta;
    cta.setFont(font);
    cta.setString("Press action button");
    cta.setCharacterSize(24);
    sf::Color gray = sf::Color::Black;
    gray.a = 100;
    cta.setFillColor(gray);
    
    // Position the text in the middle of local bounds
    sf::FloatRect ctaCenter = cta.getLocalBounds();
    cta.setOrigin(sf::Vector2f((ctaCenter.width / 2), (ctaCenter.height / 2)));
    
    float titleYPos = window.getSize().y/4;
    float ctaYPos = window.getSize().y/3 + 45;
    
    title.setPosition(screenCenter.x, titleYPos);
    cta.setPosition(screenCenter.x, ctaYPos);
    
    window.draw(title);
    window.draw(cta);
    
    window.display();
}

void GameOver::run() {
    showEndGameScreen();
}

void GameOver::setSceneManager(std::any manager) {
    sceneManager = std::any_cast<SceneManager*>(manager);
}

void GameOver::handleActionButton() {
    sceneManager->goToMenu();
}

InputDelegate* GameOver::getInputDelegate() {
    return (this);
}
