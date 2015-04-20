#ifndef githubDataViz_Graph_h
#define githubDataViz_Graph_h

#include <vector>

class ofApp;

#include "RepositoryNode.h"
#include "LanguageNode.h"

class Graph {
public:
    void addRepositoryNode(RepositoryNode *);
    void addLanguageNode(LanguageNode *);
    void draw();
    void step();
    void setApp(ofApp *);
    ofApp *getApp();

    static Graph buildRandomGraph();
    static Graph buildSimpleGraph();
    static Graph buildProductionGraph();

    std::vector<LanguageNode *> getLanguageNodes() const;
    std::vector<RepositoryNode *> getRepositoryNodes() const;
private:
    std::vector<RepositoryNode *> repository_nodes;
    std::vector<LanguageNode *> language_nodes;
    ofApp *app;
};


#include "ofApp.h"

#endif
