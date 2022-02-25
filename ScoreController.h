#pragma once

#ifndef ScoreController_H
#define ScoreController_H

class ScoreController {
public:
    static ScoreController& getInstance();
    void addScore(int scoreToAdd);
    int getScore();

private:
    int gameScore;

private:
    ScoreController() = default;
    ScoreController(const ScoreController&) = delete;
    ScoreController& operator=(const ScoreController&) = delete;
    ScoreController(ScoreController&&) = delete;
    ScoreController& operator=(ScoreController&&) = delete;
};

#endif
