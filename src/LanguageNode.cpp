#include "ofMain.h"

#include "LanguageNode.h"


LanguageNode::LanguageNode(string name, float x, float y, float size)
    : name(name), x(x), y(y), size(size) {
        color = ofColor(rand() % 170 + 50, rand() % 170 + 50, rand() % 170 + 50);
        color.setSaturation(200);
        //color.setBrightness(3000);
}

void LanguageNode::draw()
{
    ofSetColor(color);
    if (hover) {
        ofColor brighter = color;
        brighter.setBrightness(brighter.getBrightness() + 150);
        ofSetColor(brighter);
    }
    ofCircle(x, y, size);
    //ofDrawBitmapString(name, x - 10, y);
    if (hover) {
        std::ostringstream s;
        s << " %" << (getSize());
        ofDrawBitmapString(s.str(), x - 20, y + getSize() + 15);
    }
    ofSetColor(255,255,255);
    ofDrawBitmapString(name, x - name.length() * 4, y + 4);
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

void LanguageNode::setSize(float size)
{
    this->size = size;
}

std::string LanguageNode::getName() const { return name; }
float LanguageNode::getSize() const { return size; }
float LanguageNode::getX() const { return x; }
float LanguageNode::getY() const { return y; }
