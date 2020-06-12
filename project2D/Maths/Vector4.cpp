#include "Vector4.h"
#include <cmath>


Vector4::Vector4()
{
	x = 0;
	y = 0;
	z = 0;
	w = 0;
}


Vector4::~Vector4()
{

}

Vector4::Vector4(float X, float Y, float Z, float W)
{
	x = X;
	y = Y;
	z = Z;
	w = W;
}

Vector4 Vector4::cross(Vector4 rhs)
{
	return Vector4((y * rhs.z) - (z * rhs.y), (z * rhs.x) - (x * rhs.z), (x * rhs.y) - (y * rhs.x), 0);
}

float Vector4::magnitude()
{
	return sqrtf(( x * x) + (y * y) + (z * z));
}
float Vector4::magnitudeSq()
{
	return((x * x) + (y * y) + (z * z));
}

void Vector4::normalise()
{
	float mag = magnitude();
	_STL_ASSERT(mag != 0.0f, "Normalise: Divide by Zero");
	if (mag != 0.0f)
	{
		x /= mag;
		y /= mag;
		z /= mag;
	}
}

Vector4 Vector4::Lerp(Vector4 v2Start, Vector4 v2End, float fT)
{
	return v2Start + (fT * (v2End - v2Start));
}
Vector4 Vector4::Normalised()
{
	Vector4 vec = Vector4(x, y, z,w);
	vec.normalise();

	return vec;
}

Vector4 Vector4::Truncate(float fMax)
{
	float sqrMag = magnitudeSq();
	if (sqrMag > (fMax * fMax))
	{
		Vector4 vec = Vector4(x, y, z,w);
		//Calculate value to multiply x and y by
		float mult = fMax / sqrtf(sqrMag);

		vec.x *= mult;
		vec.y *= mult;
		vec.z *= mult;
		vec.w *= mult;
		return vec;
	}

	return *this;
}


float Vector4::dot(const Vector4& rhs)
{
	return ((x * rhs.x) + (y * rhs.y) + (z * rhs.z) + (w * rhs.w) );
}

Vector4::operator float*()
{
	return &x;
}

float & Vector4::operator[](int index)
{
	if (index)
	{
		return y;
	}
	else if (index == 2)
	{
		return z;
	}
	else if (index == 3)
	{
		return w;
	}
	return x;


}

const Vector4 Vector4::operator+(const Vector4 &vec)
{
	return (Vector4(x + vec.x, y + vec.y, (z + vec.z), (w + vec.w)));
}

const Vector4 Vector4::operator-(const Vector4 &vec)
{
	return (Vector4(x - vec.x, y - vec.y, (z - vec.z), (w - vec.w)));
}
const Vector4 Vector4::operator*(const Vector4 &vec)
{
	return (Vector4((x * vec.x), (y * vec.y), (z * vec.z), (w * vec.w)));
}
const Vector4 Vector4::operator/(const Vector4 &vec)
{
	return (Vector4(x / vec.x, y / vec.y, z / vec.z, w / vec.w));
}
const Vector4& Vector4::operator+=(const Vector4 &vec)
{
	x += vec.x; y += vec.y;  z += vec.z; w += vec.w; return *this;
}
const Vector4& Vector4::operator-=(const Vector4 &vec)
{
	x -= vec.x; y -= vec.y; z -= vec.z; w -= vec.w; return *this;
}
const Vector4& Vector4::operator*=(const Vector4 &vec)
{
	x *= vec.x; y *= vec.y; z *= vec.z; w *= vec.w;  return *this;
}
const Vector4& Vector4::operator/=(const Vector4 &vec)
{
	x /= vec.x; y /= vec.y; z /= vec.z; w /= vec.w;  return *this;
}




bool Vector4::operator==(const Vector4 &vec)const
{
	if ((x == vec.x) && (y == vec.y))
		return true;
	else
		return false;
}
bool Vector4::operator!=(const Vector4 &vec)const
{
	if ((x == vec.x) && (y == vec.y) && (z == vec.z) && (w == vec.w))
		return false;
	else
		return true;
}

const Vector4& Vector4::operator+(const float &f)
{
	return (Vector4((float)(x + f), (float)(y + f), (float)(z + f), w));
}
const Vector4& Vector4::operator-(const float &f)
{
	return (Vector4((float)(x - f), (float)(y - f), (float)(z - f), w));
}
const Vector4& Vector4::operator*(const float &f)
{
	return (Vector4((float)(x * f), (float)(y * f), (float)(z * f), w ));
}
const Vector4& Vector4::operator/(const float &f)
{
	return (Vector4((float)(x / f), (float)(y / f), (float)(z / f), w ));
}
const Vector4& Vector4::operator+=(const float &f)
{
	return (Vector4((float)(x += f), (float)(y += f), (float)(z += f), w ));
}
const Vector4& Vector4::operator-=(const float &f)
{
	return (Vector4((float)(x -= f), (float)(y -= f), (float)(z -= f), w ));
}
const Vector4& Vector4::operator*=(const float &f)
{
	return (Vector4((float)(x *= f), (float)(y *= f), (float)(z *= f), w));
}
const Vector4& Vector4::operator/=(const float &f)
{
	return (Vector4((float)(x /= f), (float)(y /= f), (float)(z /= f), w ));
}
const Vector4& Vector4::operator= (const float &f)
{
	return Vector4(f, f, f,f);
}

Vector4 operator+(float lhs, Vector4 rhs)
{
	return (Vector4((float)(rhs.x + lhs), (float)(rhs.y + lhs), (float)(rhs.z + lhs), rhs.w ));
}
Vector4 operator-(float lhs, Vector4 rhs)
{
	return (Vector4((float)(rhs.x - lhs), (float)(rhs.y - lhs), (float)(rhs.z - lhs), rhs.w ));
}
Vector4 operator/(float lhs, Vector4 rhs)
{
	return (Vector4((float)(rhs.x / lhs), (float)(rhs.y / lhs), (float)(rhs.z / lhs), rhs.w ));
}
Vector4 operator*(float lhs, Vector4 rhs)
{
	return (Vector4((float)(rhs.x * lhs), (float)(rhs.y *lhs), (float)(rhs.z * lhs), rhs.w ));
}
