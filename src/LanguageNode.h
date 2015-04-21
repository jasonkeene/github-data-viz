#ifndef githubDataViz_LanguageNode_h
#define githubDataViz_LanguageNode_h

#include <string>

#include "ofMain.h"

#include "Vector.h"

class LanguageNode {
public:
    LanguageNode(std::string, float, float, float);
    void draw();
    void step();
    bool inArea(float, float);
    bool hover;

    std::string name;
    ofColor color;
    float size;
    Vector position;
};

#endif
