#ifndef githubDataViz_Node_h
#define githubDataViz_Node_h

#include <string>

#include "ofMain.h"

#include "Vector.h"


const int DISTANCE_FROM_OTHER_NODES = 20;


class Node
{
public:
    Node(std::string, float, float, float, ofColor);
    Node(std::string, float, float, float);
    Node(std::string, float, float);

    virtual void draw() = 0;
    virtual void step() = 0;

    virtual bool inArea(float, float);

    bool hover;
    bool dragged;
    float size;
    std::string name;
    Vector position;
    Vector velocity;
    Vector acceleration;
    ofColor color;
    void *graph;
};

#endif
