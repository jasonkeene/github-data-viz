#ifndef githubDataViz_RepositoryNode_h
#define githubDataViz_RepositoryNode_h

#include <string>
#include <map>

#include "Node.h"
#include "LanguageNode.h"

typedef struct {
    LanguageNode* ln;
    float weight;
} LanguageWeight;

class RepositoryNode : public Node {
public:
    RepositoryNode(std::string, float, float, float, ofColor);
    RepositoryNode(std::string, float, float, float);
    RepositoryNode(std::string, float, float);

    void draw();
    void step();

    void addLanguageWeight(LanguageNode *, float);
    float totalWeight();
    std::vector<LanguageWeight> language_weights;
};

#endif
