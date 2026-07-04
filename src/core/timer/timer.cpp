#include "timer.hpp"

Timer::Timer() :
    previous(Clock::now()),
    start(Clock::now()),
    deltaTime(0.f),
    paused(false)
{}

void Timer::update() {
    if (paused)
    {
        deltaTime = 0.f;
        return;
    }

    auto now = Clock::now();

    deltaTime =
        std::chrono::duration<float>(now - previous).count();

    previous = now;
}

float Timer::getDeltaTime() const {
    return deltaTime;
}

float Timer::getElapsed() const {
    return std::chrono::duration<float>( Clock::now() - start).count();
}

void Timer::restart() {
    start = Clock::now();
}

void Timer::pause() {
    paused = true;
}

void Timer::resume() {
    previous = Clock::now();
    paused = false;
}