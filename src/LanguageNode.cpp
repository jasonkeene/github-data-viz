#include "Graph.h"
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
    // compute acceleration
    Vector last_position = position;
    acceleration.x = 0;
    acceleration.y = 0;

    // move away from walls
    int bounce_factor = 10;
    int bounce_distance = 20;
    if (position.x - size < bounce_distance) {
        Vector bounce(bounce_factor, 0);
        acceleration += bounce;
    } else if (position.x + size > ofGetWindowWidth() - bounce_distance) {
        Vector bounce(-bounce_factor, 0);
        acceleration += bounce;
    }
    if (position.y - size < bounce_distance) {
        Vector bounce(0, bounce_factor);
        acceleration += bounce;
    } else if (position.y + size > ofGetWindowHeight() - bounce_distance) {
        Vector bounce(0, -bounce_factor);
        acceleration += bounce;
    }

    // move towards the center
    if (((Graph *)graph)->center) {
        Vector center(ofGetWindowWidth()/2, ofGetWindowHeight()/2);
        acceleration += (center - position) * size / 3000;
    }

    // move away from language nodes
    for (auto node : ((Graph *)graph)->getLanguageNodes()) {
        if (node == this) {
            continue;
        }
        Vector goaway = position - node->position;
        float magnitude = node->size / goaway.magnitude();
        float theta = goaway.normalizedAngle();

        Vector new_acceleration(magnitude, theta, true);

        ofPolyline line = ofPolyline();
        ofSetColor(255, 0, 0);
        line.clear();
        line.addVertex(position.x, position.y);
        line.addVertex(position.x + new_acceleration.x, position.y + new_acceleration.y);
        line.draw();

        acceleration += new_acceleration;
    }

    // mutate velocity
    velocity.x /= 1.01;
    velocity.y /= 1.01;
    velocity += acceleration / 5;

    // mutate position
    position += velocity / 5;



//    float dist_form_center = sqrt(pow((position.x - ofGetWindowWidth() / 2), 2) + pow((position.y - ofGetWindowHeight() / 2), 2));
//    float force = (1 / pow(dist_form_center, 2.1f)) * 200;
//    float vectorX = abs(position.x - ofGetWindowWidth() / 2);
//    float vectorY = abs(position.y - ofGetWindowHeight() / 2);
//
//    if (position.x <= (ofGetWindowWidth() / 2) and dist_form_center < 300) { // moving left
//        position.x -= (position.x * (force * (vectorX / 100)));
//    }
//    else if (position.x > (ofGetWindowWidth() / 2) and dist_form_center < 300) { // moving right
//        position.x += (position.x * (force * (vectorX / 100)));
//    }
//
//    if (position.y <= (ofGetWindowHeight() / 2) and dist_form_center < 300) { // move down
//        position.y -= (position.y * (force * (vectorY / 100)));
//    }
//    else if (position.y > (ofGetWindowHeight() / 2) and dist_form_center < 300){ // move up
//        position.y += (position.y * (force * (vectorY / 100)));
//    }

}
