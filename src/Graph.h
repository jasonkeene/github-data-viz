#ifndef githubDataViz_Graph_h
#define githubDataViz_Graph_h

#include <vector>

#ifndef githubDataViz_ofApp_h
class ofApp;
#endif
#ifndef githubDataViz_Node_h
class Node;
#endif

#include "RepositoryNode.h"
#include "LanguageNode.h"

class Graph {
public:
    Graph() : center(true) {}
    void addRepositoryNode(RepositoryNode *);
    void addLanguageNode(LanguageNode *);
    void draw();
    void step();
    void setApp(ofApp *);
    ofApp *getApp();

    static Graph *buildRandomGraph();
    static Graph *buildSimpleGraph();
    static Graph *buildProductionGraph();

    std::vector<Node *> getNodesNearMe(Node *) const;
    std::vector<LanguageNode *> getLanguageNodes() const;
    std::vector<RepositoryNode *> getRepositoryNodes() const;
    bool center;
private:
    std::vector<RepositoryNode *> repository_nodes;
    std::vector<LanguageNode *> language_nodes;
    ofApp *app;
};

#include "ofApp.h"
#include "Node.h"

#endif
