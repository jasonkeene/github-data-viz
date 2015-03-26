#include "ofMain.h"

#include "LanguageNode.h"


LanguageNode::LanguageNode(string name, float x, float y, float size)
    : name(name), x(x), y(y), size(size) {}

void LanguageNode::draw()
{
    ofCircle(x, y, size);
    ofDrawBitmapStringHighlight(name, x, y);
}

void LanguageNode::step()
{
    
}

bool LanguageNode::operator<(const LanguageNode other) const
{
    return x < other.getX();
}

std::string LanguageNode::getName() const { return name; }
float LanguageNode::getSize() const { return size; }
float LanguageNode::getX() const { return x; }
float LanguageNode::getY() const { return y; }