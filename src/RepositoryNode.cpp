#include "Vector.h"
#include "RepositoryNode.h"
#include "Graph.h"


RepositoryNode::RepositoryNode(string name, float x, float y, float size, ofColor color)
    : Node(name, x, y, size, color) {}

RepositoryNode::RepositoryNode(string name, float x, float y, float size)
    : Node(name, x, y, size) {}

RepositoryNode::RepositoryNode(string name, float x, float y)
    : Node(name, x, y) {}

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
    acceleration.x = 0;
    acceleration.y = 0;

    // move towards language nodes
    for (auto lw : language_weights) {
        LanguageNode *ln = lw.ln;
        float weight = lw.weight;

        Vector towards_language = ln->position - position;
        float magnitude = (towards_language.magnitude() - ln->size - DISTANCE_FROM_OTHER_NODES) * weight;
        float theta = towards_language.normalizedAngle();

        Vector new_acceleration(magnitude, theta, true);
        new_acceleration -= velocity / 3;

        acceleration += new_acceleration;
    }

    // move away from repo nodes
    for (auto node : ((Graph *)graph)->getRepositoryNodes()) {
        if (node == this) {
            continue;
        }
        Vector goaway = position - node->position;
        goaway.setMagnitude(1 / (goaway.magnitude() / 500));
        acceleration += goaway;
    }

    // mutate velocity
    velocity += acceleration / 5;

    // mutate position
    position += velocity / 5;
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
