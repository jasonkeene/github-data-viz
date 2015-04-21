#include "Node.h"


ofColor generateRandomColor()
{
    ofColor color(rand() % 170 + 50, rand() % 170 + 50, rand() % 170 + 50);
    color.setSaturation(75);
    return color;
}


Node::Node(string name, float x, float y, float size, ofColor color)
    : name(name), position(x, y), size(size), color(color) {}

Node::Node(string name, float x, float y, float size)
    : name(name), position(x, y), size(size)
{
    color = generateRandomColor();
}

Node::Node(string name, float x, float y)
    : name(name), position(x, y), size(4)
{
    color = generateRandomColor();
}

bool Node::inArea(float other_x, float other_y)
{
    return other_x < position.x + size &&
           other_x > position.x - size &&
           other_y < position.y + size &&
           other_y > position.y - size;
}
