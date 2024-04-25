//
//  SettingsMenu.cpp
//  Popper
//
//  Created by Georgy Polonskiy on 24/04/2024.
//

#include "SettingsMenu.hpp"
#include "ResourceContainer.hpp"

SettingsMenu::SettingsMenu(sf::RenderWindow& window) : window(window) {
    sf::Vector2u windowCenter = window.getSize();
    screenCenter = sf::Vector2f((windowCenter.x / 2), (windowCenter.y / 2));
    
    currentOption = SettingsOption::Difficulty;
    difficulty = DifficultyLevel::Easy;
}

void SettingsMenu::handleActionButton() {
    switch (currentOption) {
        case SettingsOption::Difficulty:
            switch (difficulty) {
                case DifficultyLevel::Easy: {
                    difficulty = DifficultyLevel::Medium;
                    return;
                }
                case DifficultyLevel::Medium: {
                    difficulty = DifficultyLevel::Hard;
                    return;
                }
                case DifficultyLevel::Hard: {
                    difficulty = DifficultyLevel::Easy;
                    return;
                }
            }
        case SettingsOption::Reset: {
            SceneSetupData data { 0, false, difficulty, true };
            sceneManager->saveSettings(data);
            reset();
        }
        case SettingsOption::Save: {
            SceneSetupData data { 0, false, difficulty, false };
            sceneManager->saveSettings(data);
            reset();
        }
    }
}

void SettingsMenu::handleUpButton() {
    switch (currentOption) {
        case SettingsOption::Difficulty:
            if (saveAvailable()) {
                currentOption = SettingsOption::Save;
                return;
            } else if (resetAvailable) {
                currentOption = SettingsOption::Reset;
                return;
            } else {
                return;
            }
        case SettingsOption::Reset:
            currentOption = SettingsOption::Difficulty;
            return;
        case SettingsOption::Save:
            if (resetAvailable) {
                currentOption = SettingsOption::Reset;
                return;
            } else {
                currentOption = SettingsOption::Difficulty;
                return;
            }
    }
}

void SettingsMenu::handleDownButton() {
    switch (currentOption) {
        case SettingsOption::Difficulty:
            if (resetAvailable) {
                currentOption = SettingsOption::Reset;
                return;
            } else if (saveAvailable()) {
                currentOption = SettingsOption::Save;
                return;
            } else {
                return;
            }
        case SettingsOption::Reset:
            if (saveAvailable()) {
                currentOption = SettingsOption::Save;
                return;
            } else {
                currentOption = SettingsOption::Difficulty;
                return;
            }
        case SettingsOption::Save:
            currentOption = SettingsOption::Difficulty;
            return;
    }
}

void SettingsMenu::handleEscapeButton() {
    reset();
    sceneManager->goToMenu();
}

void SettingsMenu::setSceneManager(std::any manager) {
    sceneManager = std::any_cast<SceneManager*>(manager);
}

void SettingsMenu::run() {
    displaySettings();
}

void SettingsMenu::setup(SceneSetupData data) {
    difficulty = data.difficulty;
    savedDifficulty = data.difficulty;
    resetAvailable = !(data.score == 0);
}

InputDelegate* SettingsMenu::getInputDelegate() {
    return (this);
}

void SettingsMenu::displaySettings() {
    // Clear any existing content on the window
    window.clear(sf::Color::White);
    
    // Create a font
    sf::Font font;
    if (!font.loadFromFile(FONT_PATH)) {
        std::cerr << "Failed to load font!" << std::endl;
        return;
    }
    
    // Create a subtitle display
    std::string subtitleString = "Settings";
    sf::Color gray = sf::Color::Black;
    gray.a = 100;
    sf::Text subtitleText;
    subtitleText.setFont(font);
    subtitleText.setString(subtitleString);
    subtitleText.setCharacterSize(24);
    subtitleText.setFillColor(gray);
    
    // Position the text in the middle of local bounds
    sf::FloatRect subtitleCenter = subtitleText.getLocalBounds();
    subtitleText.setOrigin(sf::Vector2f((subtitleCenter.width / 2), (subtitleCenter.height / 2)));

    // Create a title
    sf::Text title;
    title.setFont(font);
    title.setString("Asteroider");
    title.setCharacterSize(50);
    title.setFillColor(sf::Color::Black);
    
    // Position the text in the middle of local bounds
    sf::FloatRect titleCenter = title.getLocalBounds();
    title.setOrigin(sf::Vector2f((titleCenter.width / 2), (titleCenter.height / 2)));
    
    // Create a difficulty switch
    sf::Text difficultySwitch;
    std::string difficultyString = "Difficulty: ";
    std::string dstr = helper.difficultyToString(difficulty);
    if (currentOption == SettingsOption::Difficulty) dstr = "< " + dstr + " >";
    difficultyString = difficultyString + dstr;
    
    difficultySwitch.setFont(font);
    difficultySwitch.setString(difficultyString);
    difficultySwitch.setCharacterSize(24);
    difficultySwitch.setFillColor(sf::Color::Black);
    
    // Position the text in the middle of local bounds
    sf::FloatRect difficultyCenter = difficultySwitch.getLocalBounds();
    difficultySwitch.setOrigin(sf::Vector2f((difficultyCenter.width / 2), (difficultyCenter.height / 2)));
    
    // Create a reset button
    sf::Text resetButton;
    resetButton.setFont(font);
    resetButton.setString("Reset");
    resetButton.setCharacterSize(24);
    resetButton.setFillColor(resetAvailable ? sf::Color::Black : gray);
    
    // Position the text in the middle of local bounds
    sf::FloatRect resetCenter = resetButton.getLocalBounds();
    resetButton.setOrigin(sf::Vector2f((resetCenter.width / 2), (resetCenter.height / 2)));
    
    // Create a save button
    sf::Text saveButton;
    saveButton.setFont(font);
    saveButton.setString("Save");
    saveButton.setCharacterSize(24);
    saveButton.setFillColor(saveAvailable() ? sf::Color::Black : gray);

    // Position the text in the middle of local bounds
    sf::FloatRect saveCenter = saveButton.getLocalBounds();
    saveButton.setOrigin(sf::Vector2f((saveCenter.width / 2), (saveCenter.height / 2)));
    
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
    float subtitleYPos = window.getSize().y/3;
    float difficultyYPos = window.getSize().y/2 + 45;
    float resetButtonYPos = window.getSize().y/2 + (45 * 2);
    float saveButtonYPos = window.getSize().y/2 + (45 * 3);
    float indicatorYPos;
    float indicatorXPos = screenCenter.x + 150;
    
    // Position the text
    title.setPosition(screenCenter.x, titleYPos);
    subtitleText.setPosition(screenCenter.x, subtitleYPos);
    difficultySwitch.setPosition(screenCenter.x, difficultyYPos);
    resetButton.setPosition(screenCenter.x, resetButtonYPos);
    saveButton.setPosition(screenCenter.x, saveButtonYPos);
    
    // Position the indicator
    switch (currentOption) {
        case (SettingsOption::Difficulty):
            indicatorYPos = difficultyYPos;
            break;
        case (SettingsOption::Reset):
            indicatorYPos = resetButtonYPos;
            break;
        case (SettingsOption::Save):
            indicatorYPos = saveButtonYPos;
            break;
    }
    
    indicator.setPosition(indicatorXPos, indicatorYPos);
    
    // Draw the text
    window.draw(title);
    window.draw(subtitleText);
    window.draw(difficultySwitch);
    window.draw(resetButton);
    window.draw(saveButton);
    if (currentOption != SettingsOption::Difficulty) window.draw(indicator);
    
    // Display the window contents
    window.display();
}

bool SettingsMenu::saveAvailable() {
    if (difficulty == savedDifficulty) {
        return false;
    } else {
        return true;
    }
}

void SettingsMenu::reset() {
    currentOption = SettingsOption::Difficulty;
    difficulty = DifficultyLevel::Easy;
    savedDifficulty = DifficultyLevel::Easy;
    resetAvailable = false;
}
