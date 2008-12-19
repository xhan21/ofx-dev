/***********************************************************************
 
 Copyright (c) 2008, Memo Akten, www.memo.tv
 
 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program.  If not, see <http://www.gnu.org/licenses/>.
 
 ***********************************************************************/

#pragma once

#define OF_ADDON_USING_OFXOBJCPOINTER
#include "ofMain.h"
#include "ofAddons.h"

#include "ofxMSAParticle.h"


/********************* Particle drawer class *************************/
class ofxMSAParticleDrawer : public ofxObjCPointer  {
public:
	ofxMSAParticleDrawer() {
		setClassName("ofxMSAParticleDrawer");
	}
	
	virtual void draw(ofxMSAParticle* p) {
		glPushMatrix();
		glTranslatef(p->x, p->y, p->z);
		glutSolidSphere(10, 10, 10);
		glPopMatrix();
	};
};




/********************* Base class for drawable class *************************/
class ofxMSAParticleDrawable {
public:
	ofxMSAParticleDrawable() {
		_drawer = NULL;
	}
	
	virtual ~ofxMSAParticleDrawable() {
		if(_drawer) _drawer->release();
	}
	
	
	void draw(ofxMSAParticle* particle) {
		if(_drawer) draw(particle);
	}
	
	
protected:
	ofxMSAParticleDrawer *_drawer;
};

