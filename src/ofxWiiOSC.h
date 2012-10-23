/*
 *  ofxWiiOSC.h
 *  ofxOpenNIPainter
 *
 *  Created by Patricio González Vivo on 24/02/11.
 *  Copyright 2011 PatricioGonzalezVivo.com. All rights reserved.
 *
 */
#ifndef _OFXWIIOSC
#define _OFXWIIOSC

#include "ofxOsc.h"

typedef struct {
	float x,y,z;
	float speedX;
	float speedY;
	float speedZ;
} Acceleration;

typedef struct {
	float x,y,s;
} IRdata;

class ofxWiiOSC {
public:
	static const int IN_PORT;
	static const int OUT_PORT;
	static const std::string OUT_HOST;
	
	IRdata ir[4];
	Acceleration acc;
	Acceleration nAcc;
	
	float	x,y;
	float	nX, nY;
	float	pNx, pNy;
	float	roll, pitch;
	float	nRoll, nPitch;
	float	batterylevel;
	bool	buttonA, buttonB, buttonUp, buttonDown, buttonLeft, buttonRight;
	bool	buttonOne, buttonTwo, buttonMinus, buttonPlus, buttonHome, buttonC, buttonZ;
	bool	isConnected, mouseMode, isNunchuck;
	
	ofxWiiOSC();
	
	void update();
	
	void requestBatteryLevel();
	void setLed(int n1, int n2, int n3, int n4);
	
	void draw(ofPoint pos);
	
private:
	ofxOscSender sender;
	ofxOscReceiver receiver;
};

#endif /* ! _OFXWIIOSC */
