#pragma once

#include "ofMain.h"

namespace ofx{
    namespace nvg{
        class Context;
    }
}


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
    //std::shared_ptr<Context> mNanoVG;
    std::shared_ptr<ofx::nvg::Context> mNanoVG;
    std::vector<ofVec2f> mPoints;
    std::vector<ofVec2f> mControlPoints;
    
    ofVec2f pts[5]; // we now need to keep track of the four points of a Bezier segment and the first control point of the next segment
    uint ctr;
    
    std::vector<ofVec2f> bezierPoints;
    uint bezierPathCounter;
    uint drawnBezierPathsCounter;
};
