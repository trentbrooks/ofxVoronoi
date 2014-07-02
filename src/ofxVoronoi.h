#pragma once
#include "ofMain.h"
#include "Voronoi2D.h"

class ofxVoronoiCell {
    
public:
    vector<ofPoint>pts;
    //ofPolyline outline;
};

//--------------------------------------------------------------
class ofxVoronoi {
    
private:
    
    ofPolyline              pts;
    float                   minDistance;
    ofRectangle             bounds;
    
public:
	
    Voronoi2D v2d;
    ofxVoronoi();
    ~ofxVoronoi();
    
    void setup();
    void setup(float x, float y, float w, float h);
    void setup(const ofRectangle &rect);
    
    void clear();
    void setMinDistance(float minDis);
    void generateVoronoi();
    void addPoint(const ofVec2f &pt);
    void addPoint(float x, float y);
    void draw();
    
    vector<ofPoint>& getPoints();
    ofRectangle getBounds();
    
    vector <ofxVoronoiCell> cells;
        
    
};
