//
//  DifficultyLevel.hpp
//  Popper
//
//  Created by Georgy Polonskiy on 24/04/2024.
//

#ifndef DifficultyLevel_hpp
#define DifficultyLevel_hpp

#include <iostream>

enum class DifficultyLevel {
    Easy,
    Medium,
    Hard
};

class DifficultyLevelHelper {
public:
    static std::string difficultyToString(DifficultyLevel difficulty) {
        switch (difficulty) {
            case (DifficultyLevel::Easy): return "easy";
            case (DifficultyLevel::Medium): return "medium";
            case (DifficultyLevel::Hard): return "hard";
        }
    }
    
    static DifficultyLevel stringToDifficulty(std::string difficulty) {
        std::string result;
        for (char c : difficulty) {
            if (std::isalpha(c)) { // Check if the character is alphabetic
                result += c; // Add the character to the result string
            }
        }
        
        if (result == "easy") {
            return DifficultyLevel::Easy;
        } else if (result == "medium") {
            return DifficultyLevel::Medium;
        } else {
            return DifficultyLevel::Hard;
        }
    }
};

#endif /* DifficultyLevel_hpp */
