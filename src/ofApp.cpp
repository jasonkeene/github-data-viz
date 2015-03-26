#include "ofApp.h"
#include "LanguageNode.h"


//--------------------------------------------------------------
void ofApp::setup(){
    // create mock language nodes
    vector<LanguageNode *> mock_languages;
    mock_languages.push_back(new LanguageNode("Python", rand() % (ofGetWindowWidth()-200) + 100, rand() % (ofGetWindowHeight()-200) + 100, rand() % 40 + 10));
    mock_languages.push_back(new LanguageNode("Lua", rand() % (ofGetWindowWidth()-200) + 100, rand() % (ofGetWindowHeight()-200) + 100, rand() % 40 + 10));
    mock_languages.push_back(new LanguageNode("Go", rand() % (ofGetWindowWidth()-200) + 100, rand() % (ofGetWindowHeight()-200) + 100, rand() % 40 + 10));
    mock_languages.push_back(new LanguageNode("Haskell", rand() % (ofGetWindowWidth()-200) + 100, rand() % (ofGetWindowHeight()-200) + 100, rand() % 40 + 10));
    mock_languages.push_back(new LanguageNode("C", rand() % (ofGetWindowWidth()-200) + 100, rand() % (ofGetWindowHeight()-200) + 100, rand() % 40 + 10));
    
    for (auto ln : mock_languages) {
        graph.addLanguageNode(ln);
    }

    // create mock repository nodes
    for (int i=0; i < 30; i++) {
        RepositoryNode *test_rn = new RepositoryNode("jasonkeene/test-rn", rand() % (ofGetWindowWidth()-200) + 100, rand() % (ofGetWindowHeight()-200) + 100);
        int language_count = rand() % mock_languages.size() + 1;
        
        int remaining_percent = 100;
        int percent = 0;
        for (int i=0; i<language_count; i++) {
            if (i+1 == language_count) {
                percent = remaining_percent;
            } else {
                percent = rand() % remaining_percent;
            }
            
            test_rn->addLanguageWeight(mock_languages[rand() % mock_languages.size()], percent / 100.0);
            remaining_percent -= percent;
        }
        graph.addRepositoryNode(test_rn);
    }
    
    // set dragged
    dragged = NULL;
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){
    // set background gradient
    ofBackgroundGradient(ofColor(64), ofColor(0));
    
    // draw graph
    graph.draw();
    graph.step();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    if (dragged != NULL) {
        dragged->setPosition(x, y);
    }
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    std::vector<LanguageNode *> language_nodes = graph.getLanguageNodes();
    for (auto ln : language_nodes) {
        if (ln->inArea(x, y)) {
            dragged = ln;
        }
    }
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    dragged = NULL;
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
