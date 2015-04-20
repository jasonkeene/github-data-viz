#include <sstream>

#include "ofApp.h"

#include "LanguageNode.h"


void ofApp::setup() {
    // create mock language nodes
    vector<LanguageNode *> mock_languages;
    
    //ofLight light;
    //light.enable();
    //ofEnableLighting();

    mock_languages.push_back(new LanguageNode("Python", rand() % (ofGetWindowWidth()-200) + 100, rand() % (ofGetWindowHeight()-200) + 100, rand() % 40 + 10));
    mock_languages.push_back(new LanguageNode("Lua", rand() % (ofGetWindowWidth()-200) + 100, rand() % (ofGetWindowHeight()-200) + 100, rand() % 40 + 10));
    mock_languages.push_back(new LanguageNode("Go", rand() % (ofGetWindowWidth()-200) + 100, rand() % (ofGetWindowHeight()-200) + 100, rand() % 40 + 10));
    mock_languages.push_back(new LanguageNode("Haskell", rand() % (ofGetWindowWidth()-200) + 100, rand() % (ofGetWindowHeight()-200) + 100, rand() % 40 + 10));
    mock_languages.push_back(new LanguageNode("C", rand() % (ofGetWindowWidth()-200) + 100, rand() % (ofGetWindowHeight()-200) + 100, rand() % 40 + 10));

//    mock_languages.push_back(new LanguageNode("Go", 400, 200, 10));
//    mock_languages.push_back(new LanguageNode("Python", 400, 600, 10));

    for (auto ln : mock_languages) {
        graph.addLanguageNode(ln);
    }

    // create mock repository nodes

//    RepositoryNode *test_rn = new RepositoryNode("jasonkeene/test-rn", 100, 400);
//    test_rn->addLanguageWeight(mock_languages[0], 0.5);
//    test_rn->addLanguageWeight(mock_languages[1], 0.5);
//    graph.addRepositoryNode(test_rn);

    for (int i=0; i < 30; i++) {
        // generate repo name
        std::stringstream s;
        s << "jasonkeene/test-rn-";
        s << i;
        string repo_name = s.str();

        RepositoryNode *test_rn = new RepositoryNode(repo_name, rand() % (ofGetWindowWidth()-200) + 100, rand() % (ofGetWindowHeight()-200) + 100);
        int language_count = rand() % mock_languages.size() + 1;
        std::vector<int> languages_used;
        int remaining_percent = 100;
        int percent = 0;

        for (int i = 0; i < language_count; ++i) {
            if (i == language_count - 1) {
                // last language node
                percent = remaining_percent;
            } else {
                percent = rand() % remaining_percent;
            }
            // find random language that isn't used
            LanguageNode *lang;
        find_lang:
            int index = rand() % mock_languages.size();
            for (auto tst : languages_used) {
                if (tst == index) {
                    // index is already used, generate a new one
                    goto find_lang;
                }
            }
            // index hasn't been used yet
            lang = mock_languages[index];
            languages_used.push_back(index);
            test_rn->addLanguageWeight(lang, float(percent) / 100.0);
            remaining_percent -= percent;
        }
        graph.addRepositoryNode(test_rn);
    }

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
    if (dragged != NULL) {
        dragged->setPosition(x, y);
    }
    if (repoDragged != NULL) {
        repoDragged->setPosition(x, y);
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
