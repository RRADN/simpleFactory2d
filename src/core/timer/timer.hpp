#pragma once 

#include <chrono>

class Timer {
public:
    Timer();
    ~Timer() = default;

    void update();

    void restart();

    void pause();
    void resume();

    float getDeltaTime() const;
    float getElapsed() const;

    bool hasElapsed(float seconds);

private:
    using Clock = std::chrono::steady_clock;

    Clock::time_point previous;
    Clock::time_point start;

    float deltaTime;
    bool paused;
};