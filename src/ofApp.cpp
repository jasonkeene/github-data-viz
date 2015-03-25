#include "ofApp.h"
#include "LanguageNode.h"


//--------------------------------------------------------------
void ofApp::setup(){
    // create mock language nodes
    LanguageNode python("Python", 200, 200, 35);
    LanguageNode lua("Lua", 400, 178, 10);
    LanguageNode go("Go", 370, 289, 15);
    
    // create mock repository nodes
    RepositoryNode test_rn("jasonkeene/test-rn", 210, 333);
    
    // add them all to the graph
    graph.addLanguageNode(python);
    graph.addLanguageNode(lua);
    graph.addLanguageNode(go);
    graph.addRepositoryNode(test_rn);
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
