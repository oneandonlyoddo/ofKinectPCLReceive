#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	kinect0.connect("tcp://localhost:13000");
	kinect1.connect("tcp://localhost:13100");
	//kinect2.connect("tcp://localhost:13200");
	kinect3.connect("tcp://localhost:13300");

	kinect0.setReceiveHighWaterMark(1);
	kinect1.setReceiveHighWaterMark(1);
	//kinect2.setReceiveHighWaterMark(1);
	kinect3.setReceiveHighWaterMark(1);
	
	buffers.resize(4);
	meshs.resize(4);
	for (int i = 0; i < meshs.size(); i++){
		for (int j = 0; j < (512/ cloudDensity) * (424/ cloudDensity); j++) {
			meshs[i].addVertex(ofVec3f(0, 0, 0));
			meshs[i].addColor(ofFloatColor(1));
		}
	}
}

//--------------------------------------------------------------
void ofApp::update(){
	while (kinect0.hasWaitingMessage())
	{
		ofBuffer buffer;
		kinect0.getNextMessage(buffer);
		buffers[0] = buffer;
	}
	
		while (kinect1.hasWaitingMessage())
		{
			ofBuffer buffer;
			kinect1.getNextMessage(buffer);
			buffers[1] = buffer;
		}
		/*
		while (kinect2.hasWaitingMessage())
		{
			ofBuffer buffer;
			kinect2.getNextMessage(buffer);
			buffers[2] = buffer;
		}
		*/
		while (kinect3.hasWaitingMessage())
		{
			ofBuffer buffer;
			kinect3.getNextMessage(buffer);
			buffers[3] = buffer;
		}

		
		
		for (int i = 0; i < buffers.size(); i++) {

			float *data = (float *)buffers[i].getData();

			int size = buffers[i].size() / sizeof(float);

			int index = 0;
			for (int j = 0; j < size; j += 3) {
				meshs[i].setVertex(j / 3, ofVec3f(data[j], data[j + 1], data[j + 2]));
			}
		}
	

}

//--------------------------------------------------------------
void ofApp::draw(){
	cam.begin();
	ofPushMatrix();
	ofScale(100, -100, -100);
	for (int i = 0; i < meshs.size(); i++) {
		ofPushMatrix();
		ofRotateYDeg(i * 90);
		meshs[i].drawVertices();
		ofPopMatrix();
	}
	ofDrawAxis(10.f);
	ofPopMatrix();
	cam.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}
