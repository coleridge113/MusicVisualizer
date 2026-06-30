#include "bar.h"
#include "../utils/constants.h"
#include <raylib.h>

Bar::Bar(float posX, float posY, int width, int height)
    : posX(posX)
    , posY(posY)
    , width(width)
    , height(height)
    {}

void Bar::Draw() const
{
    DrawRectangle(posX, posY - height, width, height, WHITE);
}

void Bar::Grow()
{
    if (height <= windowHeight)
        height += 100;
}
    
void Bar::Shrink()
{
    if (height != 0)
        height -= 20;
}
