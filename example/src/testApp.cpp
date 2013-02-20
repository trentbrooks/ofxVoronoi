#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup() {
	
    ofSetVerticalSync(true);
    ofBackgroundHex(0xC5D683);
    
    bounds.set((ofGetWidth()-500)/2, (ofGetHeight()-500)/2, 500, 500);
    voronoi.setBounds(bounds);
    
    int n = 10;
    for(int i=0; i<n; i++) {
        pts.push_back(ofRandomPointInRect(bounds));
    }
    
    generateTheVoronoi();
}

//--------------------------------------------------------------
void testApp::exit() {
}

//--------------------------------------------------------------
void testApp::update() {
   generateTheVoronoi();
}

//--------------------------------------------------------------
void testApp::draw() {
    
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
void testApp::generateTheVoronoi() {
 
    voronoi.clear();
    for(int i=0; i<pts.size(); i++) {
        voronoi.addPoint(pts[i]);
    }
    voronoi.generateVoronoi();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    
    if(key == 'f') ofToggleFullscreen();
    if(key == 'e') {
        ofSaveScreen(ofToString(ofGetUnixTime())+".png");
    }
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
	
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
    if(ofGetFrameNum()%3==0) pts.push_back(ofPoint(x, y));
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    pts.push_back(ofPoint(x, y));
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
	
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){
	
}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){
	
}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 
	
}
