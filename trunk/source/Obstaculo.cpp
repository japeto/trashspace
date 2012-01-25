#include "Obstaculo.h"
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <GL/glut.h>

#include "defConstantes.h"     	//Definiciones globales y constantes
#include "objLoader/glm.h"		//Carga de archivos .obj
#include "imageloader.h"

using namespace std;
//modelos que se cargaran
GLMmodel *pmodels[8];

void drawA(void){
	
    if (!pmodels[0]) {
        pmodels[0] = glmReadOBJ("obj/vaisseau/vaisseau.obj");
        if (!pmodels[0]) exit(0);
        //cerr<<"#$$ drawA19 ";
        glmUnitize(pmodels[0]);
        glmFacetNormals(pmodels[0]);
        glmVertexNormals(pmodels[0], 90.0);
    }
    glmDraw(pmodels[0], GLM_SMOOTH | GLM_MATERIAL );
        glDisable(GL_TEXTURE_2D);
        glEnable(GL_COLOR_MATERIAL);
}

void drawB(void){

    if (!pmodels[1]) {
        pmodels[1] = glmReadOBJ("obj/Gemini/GeminiSuit.obj");
        if (!pmodels[1]) exit(0);
        //cerr<<"#$$ drawB34 ";
        glmUnitize(pmodels[1]);
        glmFacetNormals(pmodels[1]);
        glmVertexNormals(pmodels[1], 90.0);
    }
    glmDraw(pmodels[1], GLM_SMOOTH | GLM_MATERIAL );
        glDisable(GL_TEXTURE_2D);
        glEnable(GL_COLOR_MATERIAL);
}

void drawC(void){
    if (!pmodels[2]) {
        pmodels[2] = glmReadOBJ("obj/HEspacial1/MKIII.obj");
        if (!pmodels[2]) exit(0);
        //cerr<<"#$$ drawC48 ";
        glmUnitize(pmodels[2]);
        glmFacetNormals(pmodels[2]);
        glmVertexNormals(pmodels[2], 90.0);
    }
    glmDraw(pmodels[2], GLM_SMOOTH | GLM_MATERIAL );
        glDisable(GL_TEXTURE_2D);
        glEnable(GL_COLOR_MATERIAL);	
}
void drawD(void){
    if (!pmodels[3]) {
        pmodels[3] = glmReadOBJ("obj/HEspacial2/acesjustforroomshow.obj");
        if (!pmodels[3]) exit(0);
        //cerr<<"#$$ drawC61 ";
        glmUnitize(pmodels[3]);
        glmFacetNormals(pmodels[3]);
        glmVertexNormals(pmodels[3], 90.0);
    }
    glmDraw(pmodels[3], GLM_SMOOTH | GLM_MATERIAL );
        glDisable(GL_TEXTURE_2D);
        glEnable(GL_COLOR_MATERIAL);	
}
void drawE(void){
    if (!pmodels[4]) {
        pmodels[4] = glmReadOBJ("obj/HEspacial3/EMU.obj");
        if (!pmodels[4]) exit(0);
        //cerr<<"#$$ drawE74 ";
        glmUnitize(pmodels[4]);
        glmFacetNormals(pmodels[4]);
        glmVertexNormals(pmodels[4], 90.0);
    }
    glmDraw(pmodels[4], GLM_SMOOTH | GLM_MATERIAL );
        glDisable(GL_TEXTURE_2D);
        glEnable(GL_COLOR_MATERIAL);		
}
void drawF(void){
    if (!pmodels[4]) {
        pmodels[4] = glmReadOBJ("obj/Mercury/Mercury.obj");
        if (!pmodels[4]) exit(0);
       // cerr<<"#$$ drawE74 ";
        glmUnitize(pmodels[4]);
        glmFacetNormals(pmodels[4]);
        glmVertexNormals(pmodels[4], 90.0);
    }
    glmDraw(pmodels[4], GLM_SMOOTH | GLM_MATERIAL );
        glDisable(GL_TEXTURE_2D);
        glEnable(GL_COLOR_MATERIAL);		
}
// default constructor added
Obstaculo::Obstaculo(){
    crash = false;
	objtype = NAVECOBRA;
	xAxis = rand() % 2;
	yAxis = rand() % 2;
	if (xAxis == 0 && yAxis == 0)
		zAxis = 1;
	else
		zAxis = rand() % 2;
	spinAngle = 0.0;
	colorGen = rand() % 360;
	sunNum= 0;
	objScaler= rand() %100;
	objRad=0;
	
    objSize = 2.0;
}


Obstaculo::Obstaculo(float x, float y, float z , Obstaculo* nextnode){
    crash = false;
	xPos = x;
	yPos = y;
	zPos = z;
	xAxis = rand() % 2;
	yAxis = rand() % 2;
	if (xAxis == 0 && yAxis == 0)
		zAxis = 1;
	else
		zAxis = rand() % 2;
	spinAngle = 0.0;
	colorGen = rand() % 360;
	next = nextnode;
	objtype = NAVECOBRA;
	sunNum= 0;
	objScaler= rand() %100;
	objRad=0;

    objSize = 2.0;
}

Obstaculo::Obstaculo(float x,float y,float z,Obstaculo* nextnode, objType objT){
    crash = false;
	xPos = x;
	yPos = y;
	zPos = z;
	xAxis = rand() % 2;
	yAxis = rand() % 2;
	if (xAxis == 0 && yAxis == 0)
		zAxis = 1;
	else
		zAxis = rand() % 2;
	spinAngle = 0.0;
	colorGen = rand() % 360;
	next = nextnode;
	objtype = objT;
	//sunNum= 0;
	objScaler= rand() %100;
	objRad=0;

    objSize = 2.0;
}

void Obstaculo::setXPos(float x){
	xPos = x;
}

void Obstaculo::setYPos(float y){
	yPos = y;
}

void Obstaculo::setZPos(float z){
	zPos = z;
}

float Obstaculo::getXPos(){
	return xPos;
}

float Obstaculo::getYPos(){
	return yPos;
}

float Obstaculo::getZPos(){
	return zPos;
}

void Obstaculo::setNext(Obstaculo* nextnode){
	next = nextnode;
}

Obstaculo* Obstaculo::getNext(){
	return next;
}

void Obstaculo::setObjType(objType objT){
	//cout<<"\n#Obstaculo@144 "<<objT;
	objtype= objT;
}

objType Obstaculo::getObjType(){
	return objtype;
}

void Obstaculo::setCrash(bool state){
    crash = state;
}

bool Obstaculo::getCrash(){
    return crash;
}

void Obstaculo::setObjSize(int size){
    objSize = size;
}

int Obstaculo::getObjSize(){
    return objSize;
}

void Obstaculo::setObjRad(float rad){
	objRad= rad;
}

float Obstaculo::getObjRad(){
	return objRad;
}

void Obstaculo::setLevel(int level){
	level= level;
}

void Obstaculo::putOut(){
	if(xPos>205-objRad)
		xPos=205-objRad;
	if(xPos<-5+objRad)
		xPos=objRad-5;
	if(yPos<-5+objRad)
		yPos=objRad-5;
	if(yPos>205-objRad)
		yPos=205-objRad;
}

void Obstaculo::draw(int level, bool testMode){
	if(level!=0)objScaler+=1;
    glPushMatrix();
    
    glTranslatef( getXPos(), getYPos(), getZPos() );
	if(objRad!=0) putOut();
	switch(objtype){
		case NAVECOBRA:
			if(!crash){
				glScalef(20,20,20);
				glRotatef(180,0,1,0);
				objScaler+=4;
				glRotatef(objScaler,1,0,0);
				//drawA();
				setObjRad(18.0);
				if(testMode)	
					glutWireSphere(.9,10,10);
			}else{}
        break;
		case TRAJEGEMINI:
			if(!crash){
				glScalef(20,20,20);
				glRotatef(180,0,1,0);
				objScaler+=4;
				glRotatef(objScaler,1,0,0);
				drawB();
				setObjRad(18.0);
				if(testMode)	
					glutWireSphere(.9,10,10);
			}else{}
        break;     
		case HombreEspacial1:
			if(!crash){
				glScalef(20,20,20);
				glRotatef(180,0,1,0);
				objScaler+=4;
				glRotatef(objScaler,1,0,0);
				drawC();
				setObjRad(18.0);
				if(testMode)	
					glutWireSphere(.9,10,10);
			}else{}
        break;   
		case HombreEspacial2:
			if(!crash){
				glScalef(20,20,20);
				glRotatef(180,0,1,0);
				objScaler+=4;
				glRotatef(objScaler,1,0,0);
				drawD();
				setObjRad(18.0);
				if(testMode)	
					glutWireSphere(.9,10,10);
			}else{}
        break; 
		case HombreEspacial3:
			if(!crash){
				glScalef(20,20,20);
				glRotatef(180,0,1,0);
				objScaler+=4;
				glRotatef(objScaler,1,0,0);
				drawE();
				setObjRad(18.0);
				if(testMode)	
					glutWireSphere(.9,10,10);
			}else{}
        break;  
		case MERCURY:
			if(!crash){
				glScalef(20,20,20);
				glRotatef(180,0,1,0);
				objScaler+=4;
				glRotatef(objScaler,1,0,0);
				drawF();
				setObjRad(18.0);
				if(testMode)	
					glutWireSphere(.9,10,10);
			}else{}
        break;                  
	}
    glPopMatrix();
	if (level != 0) spinAngle += 5.0;  
}

void Obstaculo::move(int level)
{
    zPos += MOVE_BY*level;
}

void Obstaculo::explode()
{
    crash = true;
}
