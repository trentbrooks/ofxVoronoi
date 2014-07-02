#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    //ofSetVerticalSync(true);
    ofSetFrameRate(60);
    ofBackgroundHex(0xC5D683);
    
    bounds.set((ofGetWidth()-500)/2, (ofGetHeight()-500)/2, 500, 500);
    voronoi.setup(bounds);
    
    
    int n = 10;
    for(int i=0; i<n; i++) {
        ofPoint pt(bounds.x + ofRandom(bounds.width), bounds.y + ofRandom(bounds.height));// ofRandomWidth(), ofRandomHeight());
        pts.push_back(pt);
    }
    
    //generateTheVoronoi();
}

//--------------------------------------------------------------
void ofApp::update(){
    
    voronoi.clear();
    for(int i=0; i<pts.size(); i++) {
        voronoi.addPoint(pts[i]);
    }
    voronoi.generateVoronoi();
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    // the bounds of all the points
    ofSetColor(90);
    ofNoFill();
    ofRect(bounds);
    
    
    // draw the raw points
    for(int i=0; i<pts.size(); i++) {
        ofSetColor(0);
        ofCircle(pts[i], 2);
    }
    
    
    voronoi.draw();
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
    
    if(ofGetFrameNum()%3==0) {
        pts.erase(pts.begin());
        pts.push_back(ofPoint(x, y));
    }
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
    pts.erase(pts.begin());
    pts.push_back(ofPoint(x, y));
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
