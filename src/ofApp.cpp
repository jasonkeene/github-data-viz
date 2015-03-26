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
        float total = 0.0;
        for (int i=0; i<language_count; i++) {
            if (i+1 == language_count) {
                percent = remaining_percent;
            } else {
                percent = rand() % remaining_percent;
            }
            
            test_rn->addLanguageWeight(mock_languages[rand() % mock_languages.size()], percent / 100.0);
            total = total + percent / 100.0;
            remaining_percent -= percent;
        }
        if (total != 1.0) {
            std::cout << total << ", ";
        }
        graph.addRepositoryNode(test_rn);
    }
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

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

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
