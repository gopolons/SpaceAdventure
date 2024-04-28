//
//  MainMenu.hpp
//  Popper
//
//  Created by Georgii Polonskii on 13/03/2024.
//

#ifndef MainMenu_hpp
#define MainMenu_hpp

#include <SFML/Graphics.hpp>

#include "InputDelegate.hpp"
#include "SceneManagerDelegate.hpp"
#include "SceneManager.hpp"
#include "MenuOption.hpp"
#include "MenuPrompt.hpp"
#include <any>

class MainMenu : public InputDelegate, public SceneManagerDelegate {
public:
    MainMenu(sf::RenderWindow& window);
    
    void handleActionButton() override;
    void handleUpButton() override;
    void handleDownButton() override;
    void handleEscapeButton() override;
    
    void setSceneManager(std::any manager) override;
    void run() override;
    void setup(SceneSetupData data) override;
    InputDelegate* getInputDelegate() override;
private:
    MenuPrompt prompt;
    
    int highScore;
    
    void drawTitleMenu();
    void reset();
    
    MenuOption currentOption;
    
    SceneManager* sceneManager;
    
    sf::RenderWindow& window;
    
    sf::Vector2f screenCenter;
};

#endif /* MainMenu_hpp */
