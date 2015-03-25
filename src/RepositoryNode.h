#ifndef githubDataViz_RepositoryNode_h
#define githubDataViz_RepositoryNode_h

#include <string>

class RepositoryNode {
public:
    RepositoryNode(std::string, float, float);
    void draw();

private:
    std::string name;
    float x;
    float y;
};

#endif