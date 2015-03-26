#ifndef __githubDataViz__Graph__
#define __githubDataViz__Graph__

#include <vector>

#include "RepositoryNode.h"
#include "LanguageNode.h"

class Graph {
public:
    void addRepositoryNode(RepositoryNode *);
    void addLanguageNode(LanguageNode *);
    void draw();
    void step();
    
    std::vector<LanguageNode *> getLanguageNodes() const;

private:
    std::vector<RepositoryNode *> repository_nodes;
    std::vector<LanguageNode *> language_nodes;
};

#endif