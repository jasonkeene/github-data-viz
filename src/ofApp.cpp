#include <sstream>

#include "ofApp.h"

#include "LanguageNode.h"


void ofApp::setup() {
    // setup OF stuff
    ofSetCircleResolution(50);

    // build graph
//    graph = Graph::buildSimpleGraph();
//    graph = Graph::buildRandomGraph();
    graph = Graph::buildProductionGraph();

    // backref to app
    graph.setApp(this);

    // initialize pointers
    dragged = NULL;
    repoDragged = NULL;
    hoveredNode = NULL;
}

void ofApp::update() {}

void ofApp::draw() {
    // set background gradient
    ofBackgroundGradient(ofColor(64), ofColor(0));

    // draw graph
    graph.draw();
    graph.step();
}

void ofApp::keyPressed(int key) {}

void ofApp::keyReleased(int key) {}

void ofApp::mouseMoved(int x, int y) {
    for (auto rn : graph.getRepositoryNodes()) {
        if (rn->inArea(x, y)) {
            rn->hover = true;
            hoveredNode = rn;
        }
        else {
            rn->hover = false;
        }
    }

    for (auto ln : graph.getLanguageNodes()) {
        ln->hover = ln->inArea(x, y);
        // TODO: make this polymorphic
        //hoveredNode = rn;
    }
}

void ofApp::mouseDragged(int x, int y, int button) {
    Vector mouse_position(x, y);
    if (dragged != NULL) {
        dragged->position = mouse_position;
    }
    if (repoDragged != NULL) {

        repoDragged->position = mouse_position;
    }
}

void ofApp::mousePressed(int x, int y, int button) {
    std::vector<LanguageNode *> language_nodes = graph.getLanguageNodes();
    for (auto ln : language_nodes) {
        if (ln->inArea(x, y)) {
            dragged = ln;
        }
    }
    std::vector<RepositoryNode *> repository_nodes = graph.getRepositoryNodes(); //*******
    for (auto rn: repository_nodes) {
        if (rn->inArea(x, y)) {
            repoDragged = rn;
        }
    }
}

void ofApp::mouseReleased(int x, int y, int button) {
    dragged = NULL;
    repoDragged = NULL;
    hoveredNode = NULL;
    for (auto rn : graph.getRepositoryNodes()) {
        rn->hover = false;
    }
}

void ofApp::windowResized(int w, int h) {}

void ofApp::gotMessage(ofMessage msg) {}

RepositoryNode *ofApp::getDragged()
{
    return repoDragged;
}

RepositoryNode *ofApp::getHovered()
{
    return hoveredNode;
}

void ofApp::dragEvent(ofDragInfo dragInfo) {}
