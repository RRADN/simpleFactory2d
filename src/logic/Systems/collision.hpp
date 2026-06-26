#pragma once 

class Collision {
public:
    Collision();
    Collision(int x, int y, int width, int height);
    ~Collision();

    int getX() const { return x; }
    int getY() const { return y; }

    int getWidth() const { return width; }
    int getHeight() const { return height; }

    void setXYPosition(int x, int y);
    void setXPosition(int x);
    void setYPosition(int y);

private:
    float x;
    float y;
    float width;
    float height;

};