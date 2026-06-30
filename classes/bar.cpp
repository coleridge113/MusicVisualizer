#include "bar.h"

Bar::Bar(int width, int height)
    : width(width)
    , height(height)
    {}

void Bar::Grow()
{
    height += 5;
}
    
