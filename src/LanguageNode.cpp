#include "LanguageNode.h"


LanguageNode::LanguageNode(string name, float x, float y, float size, ofColor color)
    : Node(name, x, y, size, color) {}

LanguageNode::LanguageNode(string name, float x, float y, float size)
    : Node(name, x, y, size) {}

LanguageNode::LanguageNode(string name, float x, float y)
    : Node(name, x, y) {}

void LanguageNode::draw()
{
    ofSetColor(color);
    if (hover) {
        ofColor brighter = color;
        brighter.setBrightness(brighter.getBrightness() + 150);
        ofSetColor(brighter);
    }
    ofCircle(position.x, position.y, size);
    ofSetColor(255, 255, 255);
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
