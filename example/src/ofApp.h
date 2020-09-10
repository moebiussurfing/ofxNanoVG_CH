#pragma once

#include "ofMain.h"

namespace ofx{
    namespace nvg{
        class Context;
    }
}

class NVGLUframebuffer;

class ofApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();
		
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
protected:
    void clear() { ofClear(0, 0, 0, 0); };
    void stroke( int cap, ofFloatColor color, int width );
    
    ofColor red;
    ofColor green;
    ofColor white;
    ofColor cyan;
    ofColor blue;
    
    std::shared_ptr<ofx::nvg::Context> mNanoVG;
    ofVec2f mCanvasSize;
    ofVec2f mBezier[ 5 ]; // we now need to keep track of the four points of a Bezier segment and the first control point of the next segment
    int mPositionCount;
    ofFbo mFbo;
    ofFbo mTempFbo;
    ofPolyline mLine;
};
