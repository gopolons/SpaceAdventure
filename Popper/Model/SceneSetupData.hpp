//
//  SceneSetupData.hpp
//  Popper
//
//  Created by Georgy Polonskiy on 20/04/2024.
//

#ifndef SceneSetupData_hpp
#define SceneSetupData_hpp

#import "DifficultyLevel.hpp"

class SceneSetupData {
public:
    int score;
    bool isHighScore;
    
    DifficultyLevel difficulty;
    bool reset;
};

#endif /* SceneSetupData_hpp */
