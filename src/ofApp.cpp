#include "ofApp.h"

ofPoint t;
ofPoint p0, p1;
ofFbo fbo;
float rX, rY, rZ;

//--------------------------------------------------------------
void ofApp::setup(){
    p0 = ofPoint(-20, 0);
    p1 = ofPoint( 20, 0);
    t = ofPoint(ofGetWidth()/2, ofGetHeight()/2, 0);
    
    fbo.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA32F);
    
    fbo.begin();
    ofClear(255,255,255, 0);
    fbo.end();
    
    ofSetBackgroundColor(0);

}

//--------------------------------------------------------------
void ofApp::update(){
    float time = ofGetElapsedTimef();
    
    rX = ofSignedNoise(time * 0.5) * 180.0;
    rY = ofSignedNoise(time * 0.3) * 180.0;
    rZ = ofSignedNoise(time * 0.9) * 180.0;
    
    
    float x = ofMap(ofSignedNoise(time * 0.2), -1, 1, 0, ofGetWidth());
    float y = ofMap(ofSignedNoise(time * 0.4), -1, 1, 0, ofGetHeight());
    float z = ofMap(ofSignedNoise(time * 0.6), -1, 1, -800, 800);
    
    t = ofPoint(x, y, z);


}

//--------------------------------------------------------------
void ofApp::draw(){
    fbo.begin();
    ofPushStyle();
    ofSetColor(0,0,0,1);  // alpha fade it
    ofDrawRectangle(0,0,ofGetWidth(),ofGetHeight());
    ofPopStyle();
    
    ofPushMatrix();
    ofTranslate(t);
    
    ofRotateX(rX);
    ofRotateY(rY);
    ofRotateZ(rZ);
    
    ofPushStyle();
    ofSetColor(80, 200, 120);
    ofDrawLine(p0, p1);
    ofPopStyle();
    ofPopMatrix();
    fbo.end();
    
    fbo.draw(0,0);
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
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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
