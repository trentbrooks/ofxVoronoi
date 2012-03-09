#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup() {
	
    ofSetVerticalSync(true);
    ofBackgroundHex(0xC5D683);
    
    
    bHideGUI    = false;
    bMove       = false;
    
    pointSlider.set(20, 20, 255, 20);
    pointSlider.min = 1;
    pointSlider.max = 5000;
    pointSlider.name = "max random points";
    
    minDisSlider.set(20, 45, 255, 20);
    minDisSlider.min = 1;
    minDisSlider.max = 100;
    minDisSlider.name = "min voronoi dis";
}

//--------------------------------------------------------------
void testApp::exit() {
}

//--------------------------------------------------------------
void testApp::update() {
}

//--------------------------------------------------------------
void testApp::draw() {
    
    if(!bHideGUI) {
       
        // slider
        pointSlider.draw();
        minDisSlider.draw();  
        
        // instructions
        ofSetColor(90);
        ofDrawBitmapString("press space to make points\npress v to make vonios", 20, 100);
    }
    
    
    
    // the bounds of all the points
    ofSetColor(90);
    ofNoFill();
    ofRect(voronoi.getBounds());
    
    
    
    
    if(voronoi.getPoints().size() > 0) {
    
        // draw the points
        vector <ofPoint> &pts = voronoi.getPoints();
        
        for (int i=0; i<pts.size(); i++) {
            
            if(bMove) {
                
                float div = 6000.0;
                pts[i].x += ofSignedNoise(ofGetElapsedTimef()*0.1, pts[i].y/div) * 10;
                pts[i].y += ofSignedNoise(pts[i].x/div, ofGetElapsedTimef()*0.1) * 10;
                
                if(pts[i].x > ofGetWidth())  pts[i].x = 0;
                if(pts[i].x < 0)             pts[i].x = ofGetWidth();
                if(pts[i].y > ofGetHeight()) pts[i].y = 0;
                if(pts[i].y < 0)             pts[i].y = ofGetHeight();
            }
            
            ofCircle(pts[i], 1);
            
        }
        
        // set the min
        voronoi.setMinDistance(minDisSlider.getValue());
        
        bool bMade = voronoi.generateVoronoi();
        for(int i=0; i<voronoi.edges.size(); i++) {
            
            ofVec2f a = voronoi.edges[i].a;
            ofVec2f b = voronoi.edges[i].b;
            
            ofLine(a, b);
        }
    }
    
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    
    if(key == ' ') {
        
        // This is a crazy algorituh to try and fit points in a rectangle
        // that are a set distance away from eachother.
        voronoi.clear();
        int nPts = pointSlider.getValue();
        int minDistToOthes = 10;
        for (int i=0; i<nPts; i++) {
            ofVec2f newPts(ofGetWidth()/2, ofGetHeight()/2);
            newPts.x += ofRandom(-300, 300);
            newPts.y += ofRandom(-300, 300);
            
            if(voronoi.getPoints().size() == 0) {
                voronoi.addPoint(newPts);    
            }
            else {
                bool bFarEnough = false;
                int nCycles = 0;
                while (!bFarEnough) {
                    
                    newPts.set(ofGetWidth()/2, ofGetHeight()/2);
                    newPts.x += ofRandom(-300, 300);
                    newPts.y += ofRandom(-300, 300);
                    bool bNotNearOthers = true;
                    for (int j=0; j<voronoi.getPoints().size(); j++) {
                        float dis = voronoi.getPoints()[j].distance(newPts);
                        if(dis < minDistToOthes) bNotNearOthers = false;
                    }    
                    
                    if(bNotNearOthers) {
                        bFarEnough = true;
                        printf("Found in  %i\n", nCycles);
                    }
                    if(nCycles > 1000) {
                        printf("Tried Hard Fuck it! %i\n", nCycles);
                        bFarEnough = true;
                    }
                    nCycles ++;
                }
                voronoi.addPoint(newPts);    
            }            
        }
        
        
    }
    
    if(key == 'f') ofToggleFullscreen();
    if(key == 'g') bHideGUI = !bHideGUI;
    if(key == 'm') bMove    = !bMove;
    
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
    if(pointSlider.bDown) {
        pointSlider.pct = ofMap(x, pointSlider.x, pointSlider.width+pointSlider.x, 0.0, 1.0, true);
    }
    if(minDisSlider.bDown) {
        minDisSlider.pct = ofMap(x, minDisSlider.x, minDisSlider.width+minDisSlider.x, 0.0, 1.0, true);
    }
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    pointSlider.bDown  = pointSlider.inside(x, y);
    minDisSlider.bDown = minDisSlider.inside(x, y);
    
    if(!pointSlider.bDown && !minDisSlider.bDown) {
        voronoi.addPoint(x, y);    
    }

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
