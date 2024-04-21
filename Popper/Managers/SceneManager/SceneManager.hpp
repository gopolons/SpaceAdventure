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
#include "ScoreManager.hpp"
#include <any>

// SceneManager object controls currently displayed scene & is used
// by other scenes to update the current game state.
class SceneManager {
public:
    SceneManager(SceneManagerDelegate* gameLoop, SceneManagerDelegate* mainMenu, SceneManagerDelegate* gameOver);
    
    void runActiveScene();
    
    void goToMenu();
    void goToGame();
    void goToGameOver(int score);
    
    std::any getCurrentInputDelegate();
private:
    ScoreManager scoreManager;
    
    GameScene scene;
    
    SceneManagerDelegate* gameLoop;
    SceneManagerDelegate* mainMenu;
    SceneManagerDelegate* gameOver;
};

#endif /* SceneManager_hpp */
