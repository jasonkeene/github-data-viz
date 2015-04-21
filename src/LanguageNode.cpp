#include "ofMain.h"

#include "LanguageNode.h"

#include <math.h>


LanguageNode::LanguageNode(string name, float x, float y, float size)
    : name(name), position(x, y), size(size) {
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
    ofCircle(position.x, position.y, size);
    //ofDrawBitmapString(name, x - 10, y);
//    if (hover) {
//        std::ostringstream s;
//        s << " %" << (getSize());
//        ofDrawBitmapString(s.str(), x - 20, y + getSize() + 15);
//    }
    ofSetColor(255,255,255);
    ofDrawBitmapString(name, position.x - name.length() * 4, position.y + 4);
}

void LanguageNode::step()
{
    float dist_form_center = sqrt(pow((position.x - ofGetWindowWidth() / 2), 2) + pow((position.y - ofGetWindowHeight() / 2), 2));
    float force = (1 / pow(dist_form_center, 2.1f)) * 200;
    float vectorX = abs(position.x - ofGetWindowWidth() / 2);
    float vectorY = abs(position.y - ofGetWindowHeight() / 2);
    
    if (position.x <= (ofGetWindowWidth() / 2) and dist_form_center < 300) { // moving left
        position.x -= (position.x * (force * (vectorX / 100)));
    }
    else if (position.x > (ofGetWindowWidth() / 2) and dist_form_center < 300) { // moving right
        position.x += (position.x * (force * (vectorX / 100)));
    }
    
    if (position.y <= (ofGetWindowHeight() / 2) and dist_form_center < 300) { // move down
        position.y -= (position.y * (force * (vectorY / 100)));
    }
    else if (position.y > (ofGetWindowHeight() / 2) and dist_form_center < 300){ // move up
        position.y += (position.y * (force * (vectorY / 100)));
    }

}

bool LanguageNode::inArea(float other_x, float other_y)
{
    return other_x < position.x + size &&
           other_x > position.x - size &&
           other_y < position.y + size &&
           other_y > position.y - size;
}
