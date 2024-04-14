//
//  SceneManager.hpp
//  Popper
//
//  Created by Georgy Polonskiy on 14/04/2024.
//

#ifndef SceneManager_hpp
#define SceneManager_hpp

#include <stdio.h>
#include "SceneManagerDelegate.hpp"
#include "GameScene.hpp"
#include <any>

// SceneManager object controls currently displayed scene & is used
// by other scenes to update the current game state.
class SceneManager {
public:
    SceneManager(SceneManagerDelegate* gameLoop, SceneManagerDelegate* mainMenu);
    
    void runActiveScene();
    
    void goToMenu();
    void goToGame();
    
    std::any getCurrentInputDelegate();
private:
    GameScene scene;
    
    SceneManagerDelegate* gameLoop;
    SceneManagerDelegate* mainMenu;
};

#endif /* SceneManager_hpp */