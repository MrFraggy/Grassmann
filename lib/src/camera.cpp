#include <camera.hpp>
#include <cmath>
#include <GL/glu.h>

void Camera::moveFront(float delta){
	m_fDistance += delta;
}

void Camera::rotateLeft(float degrees){
	m_fAngleY += degrees;
}

void Camera::rotateUp(float degrees){
	m_fAngleX += degrees;
}

void Camera::draw(){
	x = m_fDistance * sin(m_fAngleY*M_PI/180.f)*cos(m_fAngleX*M_PI/180.f);
	y = m_fDistance * sin(m_fAngleX*M_PI/180.f);
	z = m_fDistance * cos(m_fAngleY*M_PI/180.f)*cos(m_fAngleX*M_PI/180.f);

	gluLookAt(x,y,z, 0,0,0, 0,1,0);
}
