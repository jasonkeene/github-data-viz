#ifndef githubDataViz_LanguageNode_h
#define githubDataViz_LanguageNode_h

#include "ofMain.h"

#include <string>

class LanguageNode {
public:
    LanguageNode(std::string, float, float, float);
    void draw();
    void step();
    bool inArea(float, float);
    bool hover;

    void setPosition(float, float);
    void setSize(float);
    
    std::string getName() const;
    float getSize() const;
    float getX() const;
    float getY() const;
    
    ofColor color;

private:
    std::string name;
    float size;
    float x;
    float y;
};

#endif
