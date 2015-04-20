#include "ofMain.h"

#include "LanguageNode.h"


LanguageNode::LanguageNode(string name, float x, float y, float size)
    : name(name), x(x), y(y), size(size) {}

void LanguageNode::draw(int a, int b, int c)
{
    ofSetColor(a, b, c);
    if (hover) {
        ofSetColor(a + 75, b + 75, c + 75);
    } //Removes this line to remove languageNode highlighting
    ofCircle(x, y, size);
    ofSetColor(a, b, c);
    ofDrawBitmapStringHighlight(name, x, y);
    if (hover) {
        std::ostringstream s;
        s << " %" << (getSize());
        ofDrawBitmapString(s.str(), x, y + getSize() + 20);
    }
}

void LanguageNode::step()
{
    
}

bool LanguageNode::inArea(float other_x, float other_y)
{
    if (other_x < x + size &&
        other_x > x - size &&
        other_y < y + size &&
        other_y > y - size) {
        return true;
    }
    return false;
}

void LanguageNode::setPosition(float x, float y)
{
    this->x = x;
    this->y = y;
}

std::string LanguageNode::getName() const { return name; }
float LanguageNode::getSize() const { return size; }
float LanguageNode::getX() const { return x; }
float LanguageNode::getY() const { return y; }
