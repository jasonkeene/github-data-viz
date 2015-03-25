#ifndef __githubDataViz__LanguageNode__
#define __githubDataViz__LanguageNode__

#include <string>

class LanguageNode {
public:
    LanguageNode(std::string, float, float, float);
    void draw();

private:
    std::string name;
    float size;
    float x;
    float y;
};

#endif