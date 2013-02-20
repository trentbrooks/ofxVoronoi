#include "ofxVoronoi.h"

static int cellColors[10000];
//--------------------------------------------------------------
ofxVoronoi::ofxVoronoi() {
    minDistance = 3;
    for(int i=0; i<10000; i++) cellColors[i] = ofRandom(255);
}

//--------------------------------------------------------------
ofxVoronoi::~ofxVoronoi() {
    
}

//--------------------------------------------------------------
void ofxVoronoi::clear() {
    cells.clear();
    pts.clear();
}

//--------------------------------------------------------------
void ofxVoronoi::setMinDistance(float minDis) {
    minDistance = minDis;
}

//--------------------------------------------------------------
void ofxVoronoi::addPoint(float x, float y) {
    pts.addVertex(x/bounds.width, y/bounds.height);
}

//--------------------------------------------------------------
void ofxVoronoi::addPoint(const ofVec2f &pt) {
    addPoint(pt.x, pt.y);    
}

//--------------------------------------------------------------
ofRectangle ofxVoronoi::getBounds() {
    return pts.getBoundingBox();
}

//--------------------------------------------------------------
void ofxVoronoi::setBounds(const ofRectangle &rect) {
    setBounds(rect.x, rect.y, rect.width, rect.height);
}

//--------------------------------------------------------------
void ofxVoronoi::setBounds(float x, float y, float w, float h) {
    bounds.set(x, y, w, h);
}

//--------------------------------------------------------------
vector<ofPoint>& ofxVoronoi::getPoints() {
    return pts.getVertices();    
}

//--------------------------------------------------------------
bool ofxVoronoi::generateVoronoi() {
   
    cells.clear();
    v2d.setup(bounds.x/bounds.width,
              bounds.x/bounds.width+1,
              bounds.y/bounds.height,
              bounds.y/bounds.height+1,10,10,16);

    for (int i=0; i<pts.size(); i++) {
        v2d.put(i, pts[i].x, pts[i].y);
    }
    
    float x = 0;
    float y = 0;
    float w = bounds.width;
    float h = bounds.height;
        
    if(v2d.start()) {
        do {
            if(v2d.computeCell()) {
                cells.push_back(ofxVoronoiCell());
                do {
                    v2d.getCellPoint(x,y);
                    cells.back().pts.push_back(ofVec2f(x*w,y*h));
                } while(v2d.cellHasEdges());
            }
        } while(v2d.next());
    }
}

//--------------------------------------------------------------
void ofxVoronoi::draw() {
    
    for(int i=0; i<cells.size(); i++) {
        ofPath path;
        path.setFillColor(cellColors[i]);
        path.setStrokeColor(ofColor(255, 255, 0));
        path.setStrokeWidth(1);
        for(int j=0; j<cells[i].pts.size(); j++) {
            path.lineTo(cells[i].pts[j]);
        }
        path.draw();
    }
  
}