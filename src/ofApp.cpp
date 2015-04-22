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
    graph->setApp(this);
}

void ofApp::update() {}

void ofApp::draw() {
    // set background gradient
    ofBackgroundGradient(ofColor(64), ofColor(0));

    // draw graph
    graph->draw();
    graph->step();
}

void ofApp::keyPressed(int key) {}

void ofApp::keyReleased(int key) {}

void ofApp::mouseMoved(int x, int y) {
    // set center gravity
    if (x < 10) {
        graph->center = false;
    } else if (x > ofGetWindowWidth() - 10) {
        graph->center = true;
    }

    for (auto rn : graph->getRepositoryNodes()) {
        if (rn->inArea(x, y)) {
            rn->hover = true;
        }
        else {
            rn->hover = false;
        }
    }

    for (auto ln : graph->getLanguageNodes()) {
        ln->hover = ln->inArea(x, y);
    }
}

void ofApp::mouseDragged(int x, int y, int button) {
    Vector mouse_position(x, y);
    for (auto ln : graph->getLanguageNodes()) {
        if (ln->dragged) {
            ln->position = mouse_position;
            return;
        }
    }
    for (auto rn: graph->getRepositoryNodes()) {
        if (rn->dragged) {
            rn->position = mouse_position;
            return;
        }
    }
}

void ofApp::mousePressed(int x, int y, int button) {
    for (auto ln : graph->getLanguageNodes()) {
        if (ln->inArea(x, y)) {
            ln->dragged = true;
            return;
        }
    }
    for (auto rn: graph->getRepositoryNodes()) {
        if (rn->inArea(x, y)) {
            rn->dragged = true;
            return;
        }
    }
}

void ofApp::mouseReleased(int x, int y, int button) {
    for (auto ln : graph->getLanguageNodes()) {
        ln->dragged = false;
    }
    for (auto rn : graph->getRepositoryNodes()) {
        rn->dragged = false;
    }
}

void ofApp::windowResized(int w, int h) {}

void ofApp::gotMessage(ofMessage msg) {}

void ofApp::dragEvent(ofDragInfo dragInfo) {}
