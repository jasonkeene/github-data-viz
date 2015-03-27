#ifndef githubDataViz_RepositoryNode_h
#define githubDataViz_RepositoryNode_h

#include <string>
#include <map>

#include "LanguageNode.h"

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

    std::string getName() const;
    float getX() const;
    float getY() const;
    float getVelocityX() const;
    float getVelocityY() const;
    float getAccelerationX() const;
    float getAccelerationY() const;

private:
    std::string name;
    float x;
    float y;
    float velocityX;
    float velocityY;
    float accelerationX;
    float accelerationY;
    std::vector<LanguageWeight> language_weights;
};

#endif
