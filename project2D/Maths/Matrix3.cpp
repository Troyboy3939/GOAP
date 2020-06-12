#include "Matrix3.h"
#include <cmath>


Matrix3::Matrix3()
{

	for (int i = 0; i < 9; i++)
	{
		m[i] = 0;
	}
	m[0] = 1;
	m[4] = 1;
	m[8] = 1;
}

Matrix3::Matrix3(float m0, float m1, float m2, 
				 float m3, float m4, float m5, 
				 float m6, float m7, float m8)
{
	m[0] = m0;
	m[1] = m1;
	m[2] = m2;
	m[3] = m3;
	m[4] = m4;
	m[5] = m5;
	m[6] = m6;
	m[7] = m7;
	m[8] = m8;
}

Matrix3 Matrix3::operator*(const Matrix3& rhs)
{
	//Create Matrix to return
	Matrix3 result;


	//Do the matrix3 * matrix3 math, and store it in result
	result.m[0] = (m[0] * rhs.m[0]) + (m[3] * rhs.m[1]) + (m[6] * rhs.m[2]);
	result.m[1] = (m[1] * rhs.m[0]) + (m[4] * rhs.m[1]) + (m[7] * rhs.m[2]);
	result.m[2] = (m[2] * rhs.m[0]) + (m[5] * rhs.m[1]) + (m[8] * rhs.m[2]);

	result.m[3] = (m[0] * rhs.m[3]) + (m[3] * rhs.m[4]) + (m[6] * rhs.m[5]);
	result.m[4] = (m[1] * rhs.m[3]) + (m[4] * rhs.m[4]) + (m[7] * rhs.m[5]);
	result.m[5] = (m[2] * rhs.m[3]) + (m[5] * rhs.m[4]) + (m[8] * rhs.m[5]);

	result.m[6] = (m[0] * rhs.m[6]) + (m[3] * rhs.m[7]) + (m[6] * rhs.m[8]);
	result.m[7] = (m[1] * rhs.m[6]) + (m[4] * rhs.m[7]) + (m[7] * rhs.m[8]);
	result.m[8] = (m[2] * rhs.m[6]) + (m[5] * rhs.m[7]) + (m[8] * rhs.m[8]);



	//Return the result of the multiplication
	return result;
}

Vector3 Matrix3::operator*(const Vector3& rhs)
{
	//Create Vector to return
	Vector3 result;
	//Multiply the matrix by rhs vector, and store it in result
	result.x = (m[0] * rhs.x) + (m[3] * rhs.y) + (m[6] * rhs.z);
	result.y = (m[1] * rhs.x) + (m[4] * rhs.y) + (m[7] * rhs.z);
	result.z = (m[2] * rhs.x) + (m[5] * rhs.y) + (m[8] * rhs.z);

	//return result
	return result;
}

Vector3& Matrix3::operator[](int index)
{
	//Play with memory to return a vector by indexing
	return *((Vector3*)&m[index * 3]);
}

Matrix3::operator float*()
{
	return(float*)this;
}

void Matrix3::setRotateX(float radians)
{
	//Use trigonometry to apply the correct rotation, to the numbers storing the rotation
	m[4] = cosf(radians);
	m[5] = sinf(radians);

	m[7] = -(sinf(radians));
	m[8] = cosf(radians);

}

void Matrix3::setRotateY(float radians)
{
	//Use trigonometry to apply the correct rotation, to the numbers storing the rotation
	m[0] = cosf(radians);
	m[2] = -sinf(radians);

	m[6] = (sinf(radians));
	m[8] = (cosf(radians));
}

void Matrix3::setRotateZ(float radians)
{
	//Use trigonometry to apply the correct rotation, to the numbers storing the rotation
	m[0] = cosf(radians);
	m[1] = sinf(radians);

	m[3] = -(sinf(radians));
	m[4] = (cosf(radians));
	m_fRotation = radians;
}


void Matrix3::setPosition(float x, float y)
{
	//Set the numbers that store the position to x and y
	m[6] = x;
	m[7] = y;
}
void Matrix3::setPosition(Vector2 pos)
{
	//Use overloaded function to allow for passing in vector2 instead of seperate x and y
	setPosition(pos.x,pos.y);
}
void Matrix3::setScale(float x, float y)
{
	//Set the numbers that store the scale of x and y 
	m[0] = x;
	m[1] = 0;//Reset rotation
	m[3] = 0;//Reset rotation
	m[4] = y;

	//Store x and y in m_vScale
	m_vScale.x = x;
	m_vScale.y = y;
}
void Matrix3::setScale(Vector2 scale)
{
	//Allow for vector parameter by overloading
	setScale(scale.x,scale.y);
}

Vector2 Matrix3::getPosition()
{
	return Vector2(m[6], m[7]);
}

float Matrix3::getRotationZ()
{
	return m_fRotation;
}

Vector2 Matrix3::getScale()
{
	return m_vScale;
}
