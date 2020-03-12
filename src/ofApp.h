#pragma once

#include "ofMain.h"
#include "ofxZmq.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);

		ofxZmqSubscriber kinect0;
		ofxZmqSubscriber kinect1;
		ofxZmqSubscriber kinect2;
		ofxZmqSubscriber kinect3;
		std::vector<ofVboMesh> meshs;
		std::vector<ofBuffer> buffers;

		ofEasyCam cam;
		int cloudDensity = 2;
};
