#pragma once

#include "ofMain.h"
#include "GeometryUtils.h"
#include "Utils.h"
#include "ofxVoronoi.h"

class Slider : public ofRectangle {
    public:
    Slider() {
        bDown = false;
        pct   = 0.1;
    }
    void draw() {
        bDown ? ofSetHexColor(0x29596E) : ofSetHexColor(0x3A7E9C);
        ofFill();
        ofRect(*this);
        ofSetHexColor(0x96C1D4);
        ofRect(x, y, width*pct, height);
        ofSetColor(90);
        ofDrawBitmapString(name+" "+ofToString((int)getValue()), x+width+10, y+height/1.5);
    }
    float getValue() { return ofMap(pct, 0, 1, min, max, true); }
    bool        bDown;
    int         min, max;
    float       pct;
    string      name;
};

class testApp : public ofBaseApp{
	
public:
	void setup();
	void update();
	void draw();
	
	void exit();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y );
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);		

    ofxVoronoi voronoi;
    
    // simple sliders
    bool   bHideGUI;
    bool   bMove;
    Slider pointSlider;
    Slider minDisSlider;
};

