#include "point.h"
#include "gameConfig.h"  // Include the enum here
#include "utils.h"
#include <iostream>
#include <Windows.h>
using namespace std;

void Point::checkSign() {
    // Cast the char sign to the corresponding EntitySigns enum from the GameConfig
    GameConfig::EntitySigns entitySign = static_cast<GameConfig::EntitySigns>(sign);

    // Switch based on the enum value
    switch (entitySign) {
    case GameConfig::EntitySigns::LADDER:  // If the sign is a ladder ('H')
        isLadder = true;        // Set isLadder to true
        isWall = false;         // Ensure isWall is false
        isFloor = true;
        break;
    case GameConfig::EntitySigns::WALL:   // If the sign corresponds to 'Q'
        isWall = true;         // Set isWall to true
        isLadder = false;      // Ensure isLadder is false
        break;
    case GameConfig::EntitySigns::FLOOR2:   // If the sign corresponds to '<'
    case GameConfig::EntitySigns::FLOOR3:   // If the sign corresponds to '>'
    case GameConfig::EntitySigns::FLOOR1:   // If the sign corresponds to '='

        isFloor = true;
        isWall = true;         // Set isWall to true
        isLadder = false;      // Ensure isLadder is false
        break;

    default:
        // Reset both flags if the sign doesn't match any predefined values
        isLadder = false;
        isWall = false;
        isFloor = false;
        break;
    }
}