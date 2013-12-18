#pragma once

class Camera{
private:
	float m_fDistance; //Distance par rapport au centre de la scène
	float m_fAngleX; //Angle de caméra effectué autour de l'axe x
	float m_fAngleY; // et autour de l'axe y
	float x, y, z;

public:
	Camera() : 
		m_fDistance(5), m_fAngleX(0), m_fAngleY(0), x(5), y(5), z(5){}

	void moveFront(float delta);
	void rotateLeft(float degrees);
	void rotateUp(float degrees);

	void draw();
	
};