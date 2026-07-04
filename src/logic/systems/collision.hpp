#pragma once 

class Collision {
public:
    Collision();
    Collision(int x, int y, int width, int height);
    ~Collision() = default;

    float getX() const { return x; }
    float getY() const { return y; }

    int getWidth() const { return width; }
    int getHeight() const { return height; }

    void setXYPosition(int x, int y);
    void setXPosition(float x);
    void setYPosition(float y);

private:
    float x;
    float y;
    int width;
    int height;

};