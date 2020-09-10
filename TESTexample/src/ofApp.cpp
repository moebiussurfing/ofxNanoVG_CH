#include "ofApp.h"
#include <memory>
#include "nanoVG.hpp"

//--------------------------------------------------------------
void ofApp::setup() {
	ofSetFrameRate(60);
	ofSetBackgroundAuto(false);
	ofBackground(0);
	mNanoVG = std::shared_ptr<ofx::nvg::Context>(new ofx::nvg::Context(true, false));

	red = ofFloatColor(1, 0, 0, 1);
	green = ofFloatColor(0, 1, 0, 1);
	white = ofFloatColor(1, 1, 1, 1);
	cyan = ofFloatColor(0, 1, 1, 1);
	blue = ofFloatColor(0, 0, 1, 1);

	mCanvasSize = ofVec2f(ofGetWidth(), ofGetHeight());
	//mCanvasSize = ofVec2f(900, 900);

	ofFbo::Settings settings;
	settings.wrapModeVertical = true;
	settings.useStencil = true;
	settings.numSamples = 16;
	settings.width = mCanvasSize.x;
	settings.height = mCanvasSize.y;
	settings.internalformat = GL_RGBA;
	mFbo.allocate(settings);
	//mFbo.allocate(mCanvasSize.x, mCanvasSize.y);

	mFbo.bind();
	clear();
	mFbo.unbind();

	//ofToggleFullscreen();
}

//--------------------------------------------------------------
void ofApp::update() {
	mFbo.bind();
	drawScene();
	//mNanoVG->beginFrame(mCanvasSize.x, mCanvasSize.y, 1);
	//mNanoVG->beginPath();
	//mNanoVG->circle(100, 100, 100);
	//stroke(1, ofFloatColor(ofColor::red), 4);
	//mNanoVG->endFrame();
	mFbo.unbind();
}

//--------------------------------------------------------------
void ofApp::draw() {
	ofClear(100);

	//mFbo.draw(0, 0);
	mFbo.draw(0, mFbo.getHeight(), mFbo.getWidth(), -mFbo.getHeight());
	//mFbo.draw(ofGetMouseX(), ofGetMouseY());
}

//--------------------------------------------------------------
void ofApp::drawScene() {
	ofClear(0);

	ofPushStyle();
	ofNoFill();
	ofSetColor(ofColor::orange);
	ofSetLineWidth(5);
	ofDrawRectRounded(0, 0, 500, 500, 50);
	ofPopStyle();

	//ofPushStyle();
	//ofNoFill();
	//ofSetColor(ofColor::red);
	//ofSetPolyMode(OF_POLY_WINDING_ODD);	// this is the normal mode
	////stroke(20, ofFloatColor(ofColor::red), 20);
	//ofBeginShape();
	//int x = 100;
	//int y = 100;
	//int w = 100;
	//int h = 100;
	//ofVertex(x, y);
	//ofVertex(x + w, y);
	//ofVertex(x + w, y + h);
	//ofVertex(x, y + h);
	//ofVertex(x, y);
	//ofEndShape();
	//ofPopStyle();

	float x = 100;
	float y = 100;

	x += 100;
	y += 100;

	mNanoVG->beginFrame(mCanvasSize.x, mCanvasSize.y, 1);
	mNanoVG->beginPath();
	mNanoVG->strokeColor(ofFloatColor(ofColor::red));
	mNanoVG->circle(300, 300, 20);
	mNanoVG->moveTo(200, 200);
	mNanoVG->lineTo(100, 200);
	mNanoVG->moveTo(500, 500);
	mNanoVG->strokeColor(ofFloatColor(ofColor::yellowGreen));
	mNanoVG->roundedRect(500, 500, 100, 100, 10);
	mNanoVG->moveTo(50, 50);
	mNanoVG->circle(50, 50, 50);
	stroke(0, cyan, 5);//call befor end
	mNanoVG->endFrame();

	mNanoVG->beginFrame(mCanvasSize.x, mCanvasSize.y, 1);
	mNanoVG->beginPath();
	mNanoVG->circle(300, 300, 20);
	stroke(1, red, 2);//call befor end
	mNanoVG->endFrame();

	//mNanoVG->beginFrame(mCanvasSize.x, mCanvasSize.y, 1);
	//mNanoVG->beginPath();
	//mBezier[3] = ofVec2f((mBezier[2].x + mBezier[4].x) / 2.0,
	//	(mBezier[2].y + mBezier[4].y) / 2.0);
	//mNanoVG->moveTo(mBezier[0]);
	//mNanoVG->bezierTo(mBezier[1],
	//	mBezier[2],
	//	mBezier[3]);
	//stroke(1, ofFloatColor(ofColor::green), 5);
	//mNanoVG->endFrame();

	mNanoVG->beginFrame(mCanvasSize.x, mCanvasSize.y, 1);
	mNanoVG->beginPath();
	mNanoVG->ellipse(500, 500, 500, 700);
	//mNanoVG->stroke(1.0, 1.0, 0.0, 1.0, 3);
	stroke(3, blue, 2);//call befor end
	mNanoVG->endFrame();

}

void ofApp::stroke(int cap, ofFloatColor color, int width)
{
	mNanoVG->lineCap(cap);
	mNanoVG->strokeColor(color);
	mNanoVG->strokeWidth(width);
	mNanoVG->stroke();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}
