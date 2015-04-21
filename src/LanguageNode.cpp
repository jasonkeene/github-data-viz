#include "ofMain.h"

#include "LanguageNode.h"

#include <math.h>


LanguageNode::LanguageNode(string name, float x, float y, float size)
    : name(name), x(x), y(y), size(size) {
        color = ofColor(rand() % 170 + 50, rand() % 170 + 50, rand() % 170 + 50);
        color.setSaturation(75);
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
//    if (hover) {
//        std::ostringstream s;
//        s << " %" << (getSize());
//        ofDrawBitmapString(s.str(), x - 20, y + getSize() + 15);
//    }
    ofSetColor(255,255,255);
    ofDrawBitmapString(name, x - name.length() * 4, y + 4);
}

void LanguageNode::step()
{
    float dist_form_center = sqrt(pow((getX() - ofGetWindowWidth() / 2), 2) + pow((getY() - ofGetWindowHeight() / 2), 2));
    float force = (1 / pow(dist_form_center, 2.1f)) * 200;
    float vectorX = abs(getX() - ofGetWindowWidth() / 2);
    float vectorY = abs(getY() - ofGetWindowHeight() / 2);
    
    if (getX() <= (ofGetWindowWidth() / 2) and dist_form_center < 300) { // moving left
        x = x - (getX() * (force * (vectorX / 100)));
    }
    else if (getX() > (ofGetWindowWidth() / 2) and dist_form_center < 300) { // moving right
        x = x + (getX() * (force * (vectorX / 100)));
    }
    
    if (getY() <= (ofGetWindowHeight() / 2) and dist_form_center < 300) { // move down
        y = y - (getY() * (force * (vectorY / 100)));
    }
    else if (getY() > (ofGetWindowHeight() / 2) and dist_form_center < 300){ // move up
        y = y + (getY() * (force * (vectorY / 100)));
    }

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
