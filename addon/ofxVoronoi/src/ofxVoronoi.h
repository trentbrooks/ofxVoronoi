#pragma once
#include "ofMain.h"
#include "Voronoi2D.h"

class ofxVoronoiCell {
  public:
    vector<ofVec2f>pts;
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
    
    void clear();
    void setMinDistance(float minDis);
    bool generateVoronoi();
    void addPoint(const ofVec2f &pt);
    void addPoint(float x, float y);
    void draw();
    
    vector<ofPoint>& getPoints();
    ofRectangle getBounds();
    void setBounds(float x, float y, float w, float h);
    void setBounds(const ofRectangle &rect);
    
    vector <ofxVoronoiCell> cells;
};
