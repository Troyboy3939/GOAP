#include "Matrix4.h"
#include <cmath>


Matrix4::Matrix4()
{
	for (int i = 0; i < 16; i++)
	{
		m[i] = 0;
	}
	m[0] = 1;
	m[5] = 1;
	m[10] = 1;
	m[15] = 1;
}

Matrix4::Matrix4(float m0, float m1, float m2, float m3, float m4, float m5, float m6, float m7, float m8, float m9, float m10, float m11, float m12, float m13, float m14, float m15)
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
	m[9] = m9;
	m[10] = m10;
	m[11] = m11;
	m[12] = m12;
	m[13] = m13;
	m[14] = m14;
	m[15] = m15;
	
}

Matrix4 Matrix4::operator*(const Matrix4 & rhs)
{
	Matrix4 result;
	//Apply math and store in result
	result.m[0] = (m[0] * rhs.m[0]) + (m[4] * rhs.m[1]) + (m[8] * rhs.m[2]) + (m[12] * rhs.m[3]);
	result.m[1] = (m[1] * rhs.m[0]) + (m[5] * rhs.m[1]) + (m[9] * rhs.m[2]) + (m[13] * rhs.m[3]);
	result.m[2] = (m[2] * rhs.m[0]) + (m[6] * rhs.m[1]) + (m[10] * rhs.m[2]) + (m[14] * rhs.m[3]);
	result.m[3] = (m[3] * rhs.m[0]) + (m[7] * rhs.m[1]) + (m[11] * rhs.m[2]) + (m[15] * rhs.m[3]);

	result.m[4] = (m[0] * rhs.m[4]) + (m[4] * rhs.m[5]) + (m[8] * rhs.m[6]) + (m[12] * rhs.m[7]);
	result.m[5] = (m[1] * rhs.m[4]) + (m[5] * rhs.m[5]) + (m[9] * rhs.m[6]) + (m[13] * rhs.m[7]);
	result.m[6] = (m[2] * rhs.m[4]) + (m[6] * rhs.m[5]) + (m[10] * rhs.m[6]) + (m[14] * rhs.m[7]);
	result.m[7] = (m[3] * rhs.m[4]) + (m[7] * rhs.m[5]) + (m[11] * rhs.m[6]) + (m[15] * rhs.m[7]);

	result.m[8] = (m[0] * rhs.m[8]) + (m[4] * rhs.m[9]) + (m[8] * rhs.m[10]) + (m[12] * rhs.m[11]);
	result.m[9] = (m[1] * rhs.m[8]) + (m[5] * rhs.m[9]) + (m[9] * rhs.m[10]) + (m[13] * rhs.m[11]);
	result.m[10] = (m[2] * rhs.m[8]) + (m[6] * rhs.m[9]) + (m[10] * rhs.m[10]) + (m[14] * rhs.m[11]);
	result.m[11] = (m[3] * rhs.m[8]) + (m[7] * rhs.m[9]) + (m[11] * rhs.m[10]) + (m[15] * rhs.m[11]);

	result.m[12] = (m[0] * rhs.m[12]) + (m[4] * rhs.m[13]) + (m[8] * rhs.m[14]) + (m[12] * rhs.m[15]);
	result.m[13] = (m[1] * rhs.m[12]) + (m[5] * rhs.m[13]) + (m[9] * rhs.m[14]) + (m[13] * rhs.m[15]);
	result.m[14] = (m[2] * rhs.m[12]) + (m[6] * rhs.m[13]) + (m[10] * rhs.m[14]) + (m[14] * rhs.m[15]);
	result.m[15] = (m[3] * rhs.m[12]) + (m[7] * rhs.m[13]) + (m[11] * rhs.m[14]) + (m[15] * rhs.m[15]);

	return result;
}

Vector4 Matrix4::operator*(const Vector4& rhs)
{
	Vector4 result;
	//Apply math and store in result
	result.x = (m[0] * rhs.x) + (m[4] * rhs.y) + (m[8] * rhs.z) + (m[12] * rhs.w);
	result.y = (m[1] * rhs.x) + (m[5] * rhs.y) + (m[9] * rhs.z) + (m[13] * rhs.w);
	result.z = (m[2] * rhs.x) + (m[6] * rhs.y) + (m[10] * rhs.z) + (m[14] * rhs.w);
	result.w = (m[3] * rhs.x) + (m[7] * rhs.y) + (m[11] * rhs.z) + (m[15] * rhs.w);

	return result;
}

Vector4 & Matrix4::operator[](int index)
{
	//Play with memory to return a vector by indexing
	return *((Vector4*)&m[index * 4]);
}

Matrix4::operator float*()
{
	return(float*)this;
}

void Matrix4::setRotateX(float radians)
{
	//Use trigonometry to apply the correct rotation, to the numbers storing the rotation
	m[4] = cosf(radians);
	m[5] = cosf(radians);
	m[6] = sinf(radians);

	m[9] = -m[6];
	m[10] = m[5];
	m_rotation.x = radians;
}

void Matrix4::setRotateY(float radians)
{
	//Use trigonometry to apply the correct rotation, to the numbers storing the rotation
	m[4] = cosf(radians);
	m[0] = cosf(radians);
	m[2] = -sinf(radians);

	m[8] = sinf(radians);
	m[10] = cosf(radians);
	m_rotation.y = radians;

}

void Matrix4::setRotateZ(float radians)
{
	//Use trigonometry to apply the correct rotation, to the numbers storing the rotation
	m[4] = cosf(radians);
	m[0] = cosf(radians);
	m[1] = sinf(radians);

	m[4] = -sinf(radians);
	m[5] = cosf(radians);
	m_rotation.z = radians;
}

void Matrix4::setPosition(float x, float y, float z)
{
	//Set the numbers that store the position to x, y and z
	m[12] = x;
	m[13] = y;
	m[14] = z;
}

void Matrix4::setPosition(Vector3 pos)
{
	//Use overloaded function to allow for passing in vector2 instead of seperate x, y and z
	setPosition(pos.x,pos.y,pos.z);
}

void Matrix4::setScale(float x, float y, float z)
{
	//Set the numbers that store the scale of x, y and z
	m[0] = x;
	m[1] = 0;//Reset rotation
	m[2] = 0;//Reset rotation
	m[4] = 0;//Reset rotation
	m[5] = y;
	m[6] = 0;//Reset rotation
	m[8] = 0;//Reset rotation
	m[9] = 0;//Reset rotation
	m[10] = z;
}

void Matrix4::setScale(Vector3 scale)
{
	//Allow for vector parameter by overloading
	setScale(scale.x,scale.y,scale.z);
}

Vector3 Matrix4::getPosition()
{
	return Vector3(m[12],m[13],m[14]);
}

float Matrix4::getRotationX()
{
	return m_rotation.x;
}

float Matrix4::getRotationY()
{
	return m_rotation.y;
}

float Matrix4::getRotationZ()
{
	return m_rotation.z;
}

Vector3 Matrix4::getRotation()
{
	return m_rotation;
}

Vector3 Matrix4::getScale()
{
	return Vector3(m[0],m[5],m[10]);
}
