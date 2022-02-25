#include "ScoreController.h"

ScoreController& ScoreController::getInstance() {
    static ScoreController* singleton = new ScoreController();
    return *singleton;
}

void ScoreController::addScore(int scoreToAdd) {
    if (scoreToAdd <= 0) return;
    gameScore += scoreToAdd;
}

int ScoreController::getScore() {
    return gameScore;
}
