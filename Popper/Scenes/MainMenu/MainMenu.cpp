//
//  MainMenu.cpp
//  Popper
//
//  Created by Georgii Polonskii on 13/03/2024.
//

#include <iostream>

#include "ResourceContainer.hpp"
#include "MainMenu.hpp"

MainMenu::MainMenu(sf::RenderWindow& window) : window(window) {
    sf::Vector2u windowCenter = window.getSize();
    screenCenter = sf::Vector2f((windowCenter.x / 2), (windowCenter.y / 2));
    
    currentOption = MenuOption::Play;
}

void MainMenu::drawTitleMenu() {
    // Clear any existing content on the window
    window.clear(sf::Color::White);
    
    // Create a font
    sf::Font font;
    if (!font.loadFromFile(FONT_PATH)) {
        std::cerr << "Failed to load font!" << std::endl;
        return;
    }
    
    // Create a highscore display
    std::string highScoreString = "High score: " + std::to_string(highScore);
    sf::Color gray = sf::Color::Black;
    gray.a = 100;
    sf::Text highScoreText;
    highScoreText.setFont(font);
    highScoreText.setString(highScoreString);
    highScoreText.setCharacterSize(24);
    highScoreText.setFillColor(gray);
    
    // Position the text in the middle of local bounds
    sf::FloatRect highScoreCenter = highScoreText.getLocalBounds();
    highScoreText.setOrigin(sf::Vector2f((highScoreCenter.width / 2), (highScoreCenter.height / 2)));

    // Create a title
    sf::Text title;
    title.setFont(font);
    title.setString("Asteroider");
    title.setCharacterSize(50);
    title.setFillColor(sf::Color::Black);
    
    // Position the text in the middle of local bounds
    sf::FloatRect titleCenter = title.getLocalBounds();
    title.setOrigin(sf::Vector2f((titleCenter.width / 2), (titleCenter.height / 2)));
    
    // Create a game button
    sf::Text playButton;
    playButton.setFont(font);
    playButton.setString("Play");
    playButton.setCharacterSize(24);
    playButton.setFillColor(sf::Color::Black);
    
    // Position the text in the middle of local bounds
    sf::FloatRect playCenter = playButton.getLocalBounds();
    playButton.setOrigin(sf::Vector2f((playCenter.width / 2), (playCenter.height / 2)));
    
    // Create an exit button
    sf::Text exitButton;
    exitButton.setFont(font);
    exitButton.setString("Exit");
    exitButton.setCharacterSize(24);
    exitButton.setFillColor(sf::Color::Black);
    
    // Position the text in the middle of local bounds
    sf::FloatRect exitCenter = exitButton.getLocalBounds();
    exitButton.setOrigin(sf::Vector2f((exitCenter.width / 2), (exitCenter.height / 2)));
    
    // Create an options button
    sf::Text optionsButton;
    optionsButton.setFont(font);
    optionsButton.setString("Options");
    optionsButton.setCharacterSize(24);
    optionsButton.setFillColor(sf::Color::Black);

    // Position the text in the middle of local bounds
    sf::FloatRect optionsCenter = optionsButton.getLocalBounds();
    optionsButton.setOrigin(sf::Vector2f((optionsCenter.width / 2), (optionsCenter.height / 2)));
    
    // Create a selection indicator
    sf::Text indicator;
    indicator.setFont(font);
    indicator.setString("<");
    indicator.setCharacterSize(24);
    indicator.setFillColor(sf::Color::Black);
    
    // Position the text in the middle of local bounds
    sf::FloatRect selectorCenter = indicator.getLocalBounds();
    indicator.setOrigin(sf::Vector2f((selectorCenter.width / 2), (selectorCenter.height / 2)));
    
    // Get menu elements height
    float titleYPos = window.getSize().y/4;
    float highScoreYPos = window.getSize().y/3;
    float playButtonYPos = window.getSize().y/2 + 45;
    float optionsButtonYPos = window.getSize().y/2 + (45 * 2);
    float exitButtonYPos = window.getSize().y/2 + (45 * 3);
    float indicatorYPos;
    float indicatorXPos = screenCenter.x + 65;
    
    // Position the text
    title.setPosition(screenCenter.x, titleYPos);
    playButton.setPosition(screenCenter.x, playButtonYPos);
    optionsButton.setPosition(screenCenter.x, optionsButtonYPos);
    exitButton.setPosition(screenCenter.x, exitButtonYPos);
    highScoreText.setPosition(screenCenter.x, highScoreYPos);
    
    // Position the indicator
    switch (currentOption) {
        case (MenuOption::Play):
            indicatorYPos = playButtonYPos;
            break;
        case (MenuOption::Options):
            indicatorYPos = optionsButtonYPos;
            break;
        case (MenuOption::Exit):
            indicatorYPos = exitButtonYPos;
            break;
    }
    
    indicator.setPosition(indicatorXPos, indicatorYPos);
    
    // Draw the text
    window.draw(title);
    window.draw(playButton);
    window.draw(optionsButton);
    window.draw(exitButton);
    window.draw(indicator);
    
    if (highScore > 0) window.draw(highScoreText);
    
    // Display the window contents
    window.display();
}

void MainMenu::setSceneManager(std::any manager) {
    sceneManager = std::any_cast<SceneManager*>(manager);
}

void MainMenu::run() {
    drawTitleMenu();
}

InputDelegate* MainMenu::getInputDelegate() {
    return (this);
}

void MainMenu::handleActionButton() {
    switch (currentOption) {
        case (MenuOption::Play):
            sceneManager->goToGame();
            reset();
            return;
        case (MenuOption::Options):
            // FIXME: IMPLEMENT OPTIONS MENU NAVIGATION
            return;
        case (MenuOption::Exit):
            window.close();
            return;
    }
}

void MainMenu::handleUpButton() {
    switch (currentOption) {
        case (MenuOption::Play):
            currentOption = MenuOption::Exit;
            return;
        case (MenuOption::Options):
            currentOption = MenuOption::Play;
            return;
        case (MenuOption::Exit):
            currentOption = MenuOption::Options;
            return;
    }
}

void MainMenu::handleDownButton() {
    switch (currentOption) {
        case (MenuOption::Play):
            currentOption = MenuOption::Options;
            return;
        case (MenuOption::Options):
            currentOption = MenuOption::Exit;
            return;
        case (MenuOption::Exit):
            currentOption = MenuOption::Play;
            return;
    }
}

void MainMenu::handleEscapeButton() {
    window.close();
}

void MainMenu::setup(SceneSetupData data) {
    highScore = data.score;
}

void MainMenu::reset() {
    highScore = 0;
    currentOption = MenuOption::Play;
}
