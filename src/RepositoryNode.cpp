#include "ofMain.h"

#include "RepositoryNode.h"


RepositoryNode::RepositoryNode(std::string name, float x, float y)
    : name(name), x(x), y(y) {}

void RepositoryNode::draw()
{
    ofCircle(x, y, 3);
}