#include "ofxVoronoi.h"

//static int cellColors[10000];
//--------------------------------------------------------------
ofxVoronoi::ofxVoronoi() {
    minDistance = 3;
    //for(int i=0; i<10000; i++) cellColors[i] = ofRandom(255);
}

//--------------------------------------------------------------
ofxVoronoi::~ofxVoronoi() {
    
}


void ofxVoronoi::setup() {
    setup(0,0,ofGetWidth(),ofGetHeight());
}

void ofxVoronoi::setup(const ofRectangle &rect) {
    setup(rect.x, rect.y, rect.width, rect.height);
}

void ofxVoronoi::setup(float x, float y, float w, float h) {
    v2d.setup(x/w,
              x/w+1,
              y/h,
              y/h+1,10,10,16);
    bounds.set(x,y,w,h);
    ofLog() << "settting up thing!";
}



//--------------------------------------------------------------
void ofxVoronoi::clear() {
    cells.clear();
    pts.clear();
    v2d.clear();
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
vector<ofPoint>& ofxVoronoi::getPoints() {
    return pts.getVertices();    
}

//--------------------------------------------------------------
void ofxVoronoi::generateVoronoi() {

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
                    //cells.back().outline.addVertex(x*w,y*h);
                } while(v2d.cellHasEdges());
                //cells.back().outline.close();
            }
        } while(v2d.next());
        
    }
}

//--------------------------------------------------------------
void ofxVoronoi::draw() {
    
    for(int i=0; i<cells.size(); i++) {
        
        ofPolyline p;
        p.addVertices(cells[i].pts);
        p.draw();
    }
  
}