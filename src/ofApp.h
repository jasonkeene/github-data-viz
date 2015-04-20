#ifndef githubDataViz_ofApp_h
#define githubDataViz_ofApp_h

#include "ofMain.h"

class Graph;
#ifndef githubDataViz_Graph_h
#include "graph.h"
#endif

#include "LanguageNode.h"


class ofApp : public ofBaseApp {
public:
    void setup();
    void update();
    void draw();

    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    RepositoryNode *getDragged();
private:
    Graph graph;
    LanguageNode *dragged;
    RepositoryNode *repoDragged;
};

#endif