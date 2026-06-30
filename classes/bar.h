#pragma once

class Bar
{
    public:
        Bar(float posX, float posY, int width, int height);
        void Draw() const;
        void Grow(float& factor);
        void Shrink();
    
    private:
        float posX;
        float posY;
        int width;
        int height;
};
