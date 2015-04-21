#ifndef githubDataViz_RepositoryNode_h
#define githubDataViz_RepositoryNode_h

#include <string>
#include <map>

#include "LanguageNode.h"
#include "Vector.h"

typedef struct {
    LanguageNode* ln;
    float weight;
} LanguageWeight;

class RepositoryNode {
public:
    RepositoryNode(std::string, float, float);

    void draw();
    void step();

    void addLanguageWeight(LanguageNode *, float);
    float totalWeight();
    bool inArea(float, float);

    bool hover;
    std::string name;
    Vector position;
    Vector velocity;
    Vector acceleration;
    float size;
    std::vector<LanguageWeight> language_weights;
};

#endif
