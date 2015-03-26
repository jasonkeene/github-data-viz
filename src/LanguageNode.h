#ifndef __githubDataViz__LanguageNode__
#define __githubDataViz__LanguageNode__

#include <string>

class LanguageNode {
public:
    LanguageNode(std::string, float, float, float);
    void draw();
    void step();
    bool inArea(float, float);

    bool operator<(LanguageNode const) const;

    void setPosition(float, float);
    
    std::string getName() const;
    float getSize() const;
    float getX() const;
    float getY() const;

private:
    std::string name;
    float size;
    float x;
    float y;
};

#endif