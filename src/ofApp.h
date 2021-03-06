#ifndef githubDataViz_ofApp_h
#define githubDataViz_ofApp_h

#include "ofMain.h"

#ifndef githubDataViz_Graph_h
class Graph;
#endif

#include "RepositoryNode.h"
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
private:
    Graph *graph;
};

#include "graph.h"

#endif