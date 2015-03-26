#ifndef githubDataViz_RepositoryNode_h
#define githubDataViz_RepositoryNode_h

#include <string>
#include <map>

#include "LanguageNode.h"


class RepositoryNode {
public:
    RepositoryNode(std::string, float, float);
    void draw();
    void step();
    void addLanguageWeight(LanguageNode *, float);

    std::string getName() const;
    float getX() const;
    float getY() const;

private:
    std::string name;
    float x;
    float y;
    std::map<LanguageNode *, float> language_weights;
};

#endif