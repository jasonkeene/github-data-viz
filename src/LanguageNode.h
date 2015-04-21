#ifndef githubDataViz_LanguageNode_h
#define githubDataViz_LanguageNode_h

#include <string>

#include "ofMain.h"

#include "Vector.h"
#include "Node.h"

class LanguageNode : public Node {
public:
    LanguageNode(std::string, float, float, float, ofColor);
    LanguageNode(std::string, float, float, float);
    LanguageNode(std::string, float, float);

    void draw();
    void step();
};

#endif
