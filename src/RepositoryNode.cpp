#include <cmath>

#include "ofMain.h"

#include "RepositoryNode.h"


bool DEBUG = false;
const int DISTANCE_FROM_OTHER_NODES = 20;


RepositoryNode::RepositoryNode(std::string name, float x, float y)
    : name(name), x(x), y(y),
      velocityX(0), velocityY(0),
      accelerationX(0), accelerationY(0) {}

bool RepositoryNode::inArea(float other_x, float other_y)
{
    int size = 6;
    
    return
    other_x < x + size &&
    other_x > x - size
    && other_y < y + size
    && other_y > y - size;
    
    if (other_x < x + size && //**
        other_x > x - size && //**
        other_y < y + size && //**
        other_y > y - size) { //**
        return true;
    }
    return false;
}

void RepositoryNode::setPosition(float x, float y)
{
    this->x = x;
    this->y = y;
}

void RepositoryNode::draw()
{
    ofPolyline line = ofPolyline();
    int count = 0;
    for (auto lw : language_weights) {
        line.clear();
        LanguageNode *ln = lw.ln;
        ofSetColor(ln->color);
        line.addVertex(x, y);
        line.addVertex(ln->getX(), ln->getY());
        line.draw();
        if (hover) {
            std::ostringstream s;
            ofSetColor(250, 250, 250);
            s << ln->getName() << " - %" << (lw.weight * 100);
            line.addVertex(x, y);
            line.addVertex(ln->getX(), ln->getY());
            line.draw();
            ofDrawBitmapStringHighlight(s.str(), x + 10, y + count * 20);
        }
        count++;
        
        //ofSetColor(255, 0, 0);//sets color of repository node to green
        if (hover) {ofSetColor(255,255,255);}
        ofCircle(x, y, 4);
    }
    if (DEBUG) {
        ofPolyline line = ofPolyline();
        // paint acceleration vector
        line.clear();
        ofSetColor(0, 255, 0);
        line.addVertex(x, y);
        line.addVertex(x + accelerationX, y - accelerationY);
        line.draw();
        // paint velocity vector
        line.clear();
        ofSetColor(0, 0, 255);
        line.addVertex(x, y);
        line.addVertex(x + velocityX, y - velocityY);
        line.draw();
    }
    ofSetColor(255, 255, 255);
    line.close();
}

void RepositoryNode::step()
{
    // compute acceleration
    float _last_positionX = x;
    float _last_positionY = y;
    float _accelerationX = 0;
    float _accelerationY = 0;
    accelerationX = 0;
    accelerationY = 0;
    for (auto lw : language_weights) {
        LanguageNode *ln = lw.ln;
        float weight = lw.weight;
        
        float deltaX = ln->getX() - x;
        float deltaY = -(ln->getY() - y);
        float hypo = sqrt(deltaX * deltaX + deltaY * deltaY);

        float theta = std::atan(std::abs(deltaY) / std::abs(deltaX));
        // fix theta so that it is relative to the positive x-axis
        if (deltaX < 0) {
            if (deltaY < 0) {
                theta = PI + theta;
            } else {
                theta = PI - theta;
            }
        } else {
            if (deltaY < 0) {
                theta = 2 * PI - theta;
            }
        }
        float magnitude = (hypo - ln->getSize() - DISTANCE_FROM_OTHER_NODES) * weight;
        _accelerationX = magnitude * std::cos(theta) - velocityX / 3;
        _accelerationY = magnitude * std::sin(theta) - velocityY / 3;

        if (DEBUG) {
            ofPolyline line = ofPolyline();
            // paint acceleration vector
            ofSetColor(255, 0, 0);
            line.addVertex(_last_positionX, _last_positionY);
            _last_positionX = _last_positionX + _accelerationX;
            _last_positionY = _last_positionY - _accelerationY;
            line.addVertex(_last_positionX, _last_positionY);
            line.draw();
            line.close();
            ofSetColor(255, 255, 255);
        }

        accelerationX += _accelerationX;
        accelerationY += _accelerationY;
    }
    
    // mutate velocity
    velocityX += accelerationX / 5;
    velocityY += accelerationY / 5;

    // mutate position
    x += velocityX / 5;
    y -= velocityY / 5;
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

std::string RepositoryNode::getName() const { return name; }
float RepositoryNode::getX() const { return x; }
float RepositoryNode::getY() const { return y; }
float RepositoryNode::getVelocityX() const { return velocityX; }
float RepositoryNode::getVelocityY() const { return velocityY; }
float RepositoryNode::getAccelerationX() const { return accelerationX; }
float RepositoryNode::getAccelerationY() const { return accelerationY; }
