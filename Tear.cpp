#include "Tear.h"

Tear::Tear() : Tear(ofVec3f(0, 0, 0)) {
}

Tear::Tear(ofVec3f location){
	this->location = location;

	this->a = 5;
	this->r = 50;
	this->speed = ofRandom(1, 3);
	this->body_color_value = ofRandom(255);
}

Tear::~Tear() {

}

void Tear::update() {
	this->location = this->location - ofVec3f(0, speed, 0);

	if (this->location.y < -ofGetHeight() / 2 - this->r) {
		this->location.y = ofGetHeight() / 2;
	}
}

void Tear::draw() {
	ofPushMatrix();
	ofTranslate(this->location);
	ofRotateZ(90);

	ofColor c;
	c.setHsb(this->body_color_value, 255, 255);
	ofSetColor(c);

	ofBeginShape();
	for (int theta = 0; theta < 360; theta++) {
		float r = 1 / (this->a * sin(theta * DEG_TO_RAD / 2) + 1);
		ofVertex(ofVec3f(this->r * r * cos(theta * DEG_TO_RAD), this->r * r * sin(theta * DEG_TO_RAD), 0));
	}
	ofEndShape(true);

	ofPopMatrix();
}