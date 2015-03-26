#include <cmath>

#include "ofMain.h"

#include "RepositoryNode.h"


RepositoryNode::RepositoryNode(std::string name, float x, float y)
    : name(name), x(x), y(y) {}

void RepositoryNode::draw()
{
    ofCircle(x, y, 3);
    for (auto iterator = language_weights.begin(); iterator != language_weights.end(); iterator++) {
        LanguageNode *ln = iterator->first;
        ofPolyline line = ofPolyline();
        line.addVertex(x, y);
        line.addVertex(ln->getX(), ln->getY());
        line.draw();
    }
}

void RepositoryNode::step()
{
    // compute the next position of language node
    
    // compute force
    float forceX = 0;
    float forceY = 0;
    
    for (auto iterator = language_weights.begin(); iterator != language_weights.end(); iterator++) {
        LanguageNode *ln = iterator->first;
        float weight = iterator->second;
        
        float deltaX = ln->getX() - x;
        float deltaY = ln->getY() - y;
        float hypo = sqrt(deltaX * deltaX + deltaY * deltaY);

        float theta = std::atan(std::abs(deltaY) / std::abs(deltaX));
        if (deltaX < 0) {
            if (deltaY < 0) {
                theta = PI - theta;
            } else {
                theta = PI + theta;
            }
        } else {
            if (deltaY < 0) {
                
            } else {
                theta = 2 * PI - theta;
            }
        }
        float magnitude = hypo * weight / 20;

        forceX += magnitude * std::cos(theta);
        forceY += magnitude * std::sin(theta);
    }
    
    // mutate position
    x = x + forceX;
    y = y - forceY;

    //usleep(1 * 1000 * 1000);
}

void RepositoryNode::addLanguageWeight(LanguageNode *ln, float weight)
{
    language_weights[ln] = weight;
}

std::string RepositoryNode::getName() const { return name; }
float RepositoryNode::getX() const { return x; }
float RepositoryNode::getY() const { return y; }