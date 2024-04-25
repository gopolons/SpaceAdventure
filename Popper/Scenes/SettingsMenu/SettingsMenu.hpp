//
//  SettingsMenu.hpp
//  Popper
//
//  Created by Georgy Polonskiy on 24/04/2024.
//

#ifndef SettingsMenu_hpp
#define SettingsMenu_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>
#include "InputDelegate.hpp"
#include "SceneManagerDelegate.hpp"
#include "SceneManager.hpp"
#include "SettingsOption.hpp"
#include "SceneSetupData.hpp"
#include "DifficultyLevel.hpp"

class SettingsMenu: public InputDelegate, public SceneManagerDelegate {
public:
    SettingsMenu(sf::RenderWindow& window);
    
    void handleActionButton() override;
    void handleUpButton() override;
    void handleDownButton() override;
    void handleEscapeButton() override;
    
    void setSceneManager(std::any manager) override;
    void run() override;
    void setup(SceneSetupData data) override;
    InputDelegate* getInputDelegate() override;
private:
    DifficultyLevel savedDifficulty;
    DifficultyLevel difficulty;
    DifficultyLevelHelper helper;
    
    bool resetAvailable;
    bool saveAvailable();
    
    void displaySettings();
    void reset();
    
    SettingsOption currentOption;
    
    SceneManager* sceneManager;
    
    sf::RenderWindow& window;
    
    sf::Vector2f screenCenter;
};

#endif /* SettingsMenu_hpp */
