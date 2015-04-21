

#include "RepositoryNode.h"


const int DISTANCE_FROM_OTHER_NODES = 20;


RepositoryNode::RepositoryNode(std::string name, float x, float y)
    : name(name), position(x, y), size(4) {}

bool RepositoryNode::inArea(float other_x, float other_y)
{
    return other_x < position.x + size &&
           other_x > position.x - size &&
           other_y < position.y + size &&
           other_y > position.y - size;
}

void RepositoryNode::draw()
{
    ofPolyline line = ofPolyline();

    // draw lines
    for (auto lw : language_weights) {
        // figure out color of line
        if (hover) {
            // draw all lines as white when hovering over repo node
            ofSetColor(255, 255, 255);
        } else if (lw.ln->hover) {
            // highlight this ine when hovering over it's language node
            ofColor brighter = lw.ln->color;
            brighter.setBrightness(brighter.getBrightness() + 100);
            ofSetColor(brighter);
        } else {
            // set color to just be the color of the language node
            ofSetColor(lw.ln->color);
        }

        // draw the line
        line.clear();
        line.addVertex(position.x, position.y);
        line.addVertex(lw.ln->position.x, lw.ln->position.y);
        line.draw();
    }

    // draw additional stuff when hovering over repo node
    if (hover) {
        // offset counter
        int count = 0;

        // draw name first
        ofDrawBitmapStringHighlight(name, position.x + 10, position.y + count * 20);
        count++;

        // draw all the percentages
        for (auto lw : language_weights) {
            ofSetColor(250, 250, 250);

            // compose string
            std::ostringstream s;
            s << lw.ln->name << " - %" << (lw.weight * 100);

            // draw it
            ofDrawBitmapStringHighlight(s.str(), position.x + 10, position.y + count * 20);
            count++;
        }
    }

    // draw node
    if (hover) {
        ofSetColor(255, 255, 255);
    }
    ofSetColor(255, 255, 255);
    ofCircle(position.x, position.y, size);

    // cleanum
    line.close();
}

void RepositoryNode::step()
{
    // compute acceleration
    Vector last_position = position;
    Vector new_acceleration(0, 0);
    acceleration.x = 0;
    acceleration.y = 0;

    for (auto lw : language_weights) {
        LanguageNode *ln = lw.ln;
        float weight = lw.weight;

        float deltaX = ln->position.x - position.x;
        float deltaY = -(ln->position.y - position.y); // invert since our axis are inverted
        Vector towards_language(deltaX, deltaY);

        float magnitude = (towards_language.magnitude() - ln->size - DISTANCE_FROM_OTHER_NODES) * weight;
        float theta = towards_language.normalizedAngle();

        new_acceleration.x = magnitude * std::cos(theta) - velocity.x / 3;
        new_acceleration.y = magnitude * std::sin(theta) - velocity.y / 3;

        acceleration += new_acceleration;
    }
    
    // mutate velocity
    velocity.x += acceleration.x / 5;
    velocity.y += acceleration.y / 5;

    // mutate position
    position.x += velocity.x / 5;
    position.y -= velocity.y / 5;
}

void RepositoryNode::addLanguageWeight(LanguageNode *ln, float weight)
{
    LanguageWeight lw = {ln, weight};
    language_weights.push_back(lw);
}

float RepositoryNode::totalWeight()
{
    float total = 0;
    for (auto lw : language_weights) {
        total += lw.weight;
    }
    return total;
}
