#include "Vector3D.h"


Vector3D::Vector3D(f32 xx = 0.f, f32 yy = 0.f, f32 zz = 0.f)
	: x(xx), y(yy), z(zz)
{}

void Vector3D::normalize()
{
	f32 mag = magnitude();
	x /= mag;
	y /= mag;
	z /= mag;
}

Vector3D Vector3D::unitVector()
{
	return *this / magnitude();
}

f32 Vector3D::magnitude()
{
	// Math functions are not implemented yet
	//return Math::sqrt(x * x + y * y + z * z);
	return 1.f;
}

f32 Vector3D::projectOntoMagnitude(Vector3D other)
{
	return dotProduct(*this, other) / other.magnitude();
}

Vector3D Vector3D::projectOnto(Vector3D other)
{
	return projectOntoMagnitude(other) * other.unitVector();
}

Vector3D Vector3D::othogonalProjectionOnto(Vector3D other)
{
	return *this - projectOnto(other);
}

void Vector3D::operator+=(Vector3D v)
{
	x += v.x;
	y += v.y;
	z += v.z;
}

void Vector3D::operator-=(Vector3D v)
{
	x -= v.x;
	y -= v.y;
	z -= v.z;
}

void Vector3D::operator*=(f32 scalar)
{
	x *= scalar;
	y *= scalar;
	z *= scalar;
}

void Vector3D::operator/=(f32 scalar)
{
	x /= scalar;
	y /= scalar;
	z /= scalar;
}

Vector3D Vector3D::vectorAdd(Vector3D v1, Vector3D v2)
{
	return Vector3D(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
}

Vector3D Vector3D::vectorSubtract(Vector3D v1, Vector3D v2)
{
	return Vector3D(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);
}

Vector3D Vector3D::scalarMultiply(f32 scalar, Vector3D v)
{
	return Vector3D(scalar * v.x, scalar * v.y, scalar * v.z);
}

f32 Vector3D::dotProduct(Vector3D v1, Vector3D v2)
{
	return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

Vector3D Vector3D::scale(Vector3D v1, Vector3D v2)
{
	return Vector3D(v1.x * v2.x, v1.y * v2.y, v1.z * v2.z);
}

Vector3D Vector3D::crossProduct(Vector3D v1, Vector3D v2)
{
	return Vector3D(v1.y * v2.z - v1.z * v2.y,
					v1.z * v2.x - v1.x * v2.z,
					v1.x * v2.y - v1.y * v2.x);
}

f32 Vector3D::distance(Vector3D v1, Vector3D v2)
{
	return vectorSubtract(v1, v2).magnitude();
}

f32 Vector3D::cosAngleBetween(Vector3D v1, Vector3D v2)
{
	return dotProduct(v1, v2) / (v1.magnitude() * v2.magnitude());
}

f32 Vector3D::angleBetween(Vector3D v1, Vector3D v2)
{
	//return Math::arccos(cosAngleBetween(v1, v2));
	return 1.f;
}

Vector3D operator+(Vector3D v1, Vector3D v2)
{
	return Vector3D::vectorAdd(v1, v2);
}

Vector3D operator-(Vector3D v1, Vector3D v2)
{
	return Vector3D::vectorSubtract(v1, v2);
}

Vector3D operator*(f32 scalar, Vector3D v)
{
	return Vector3D::scalarMultiply(scalar, v);
}

Vector3D operator*(Vector3D v, f32 scalar)
{
	return Vector3D::scalarMultiply(scalar, v);
}

Vector3D operator/(Vector3D v, f32 scalarInverse)
{
	return Vector3D::scalarMultiply(1.f / scalarInverse, v);
}

f32 operator*(Vector3D v1, Vector3D v2)
{
	return Vector3D::dotProduct(v1, v2);
}

bool operator==(Vector3D v1, Vector3D v2)
{
	return v1.x == v2.x
		&& v1.y == v2.y
		&& v1.z == v2.z;
}