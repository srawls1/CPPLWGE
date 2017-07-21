#include "Vector3D.h"
#include "Vector2D.h"


Vector3D::Vector3D(f32 xx = 0.f, f32 yy = 0.f, f32 zz = 0.f)
	: x(xx), y(yy), z(zz)
{}

Vector2D Vector3D::xy()
{
	return Vector2D(x, y);
}

Vector2D Vector3D::xz()
{
	return Vector2D(x, z);
}

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
	return Math::sqrt(magnitudeSquared());
}

f32 Vector3D::magnitudeSquared()
{
	return x * x + y * y + z * z;
}

f32 Vector3D::scalarProjection(Vector3D other)
{
	return dotProduct(*this, other) / other.magnitude();
}

Vector3D Vector3D::vectorProjection(Vector3D other)
{
	return scalarProjection(other) * other.unitVector();
}

Vector3D Vector3D::orthogonalProjection(Vector3D other)
{
	return *this - vectorProjection(other);
}

Vector3D Vector3D::reflectedAcross(Vector3D normal)
{
	Vector3D projection = vectorProjection(normal);
	return projection + projection - *this;
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

f32 Vector3D::distanceSquared(Vector3D v1, Vector3D v2)
{
	return vectorSubtract(v1, v2).magnitudeSquared();
}

f32 Vector3D::cosAngleBetween(Vector3D v1, Vector3D v2)
{
	return dotProduct(v1, v2) / (v1.magnitude() * v2.magnitude());
}

f32 Vector3D::angleBetween(Vector3D v1, Vector3D v2)
{
	return Math::arccos(cosAngleBetween(v1, v2));
}

Vector3D Vector3D::lerp(Vector3D v1, Vector3D v2, f32 alpha)
{
	return v1 * (1 - alpha) + v2 * alpha;
}

Vector3D Vector3D::slerp(Vector3D v1, Vector3D v2, f32 alpha)
{
	f32 angle = angleBetween(v1, v2);
	f32 sina = Math::sin(angle);
	return Math::sin((1 - alpha) * angle) / sina * v1 + Math::sin(alpha * angle) / sina * v2;
}

Vector3D Vector3D::moveTowards(Vector3D from, Vector3D to, f32 maxStep)
{
	Vector3D dif = to - from;
	if (dif.magnitude() < maxStep)
	{
		return to;
	}
	return from + dif.unitVector() * maxStep;
}

Vector3D Vector3D::rotateTowards(Vector3D from, Vector3D to, f32 maxRotateStep, f32 maxMagnitudeStep)
{
	f32 fromMagnitude = from.magnitude();
	f32 toMagnitude = to.magnitude();
	f32 magDif = toMagnitude - fromMagnitude;
	f32 retMag = Math::abs(magDif) < maxMagnitudeStep ? fromMagnitude + maxMagnitudeStep : toMagnitude;
	
	from.normalize();
	to.normalize();
	f32 angle = dotProduct(from, to);
	f32 alpha = Math::min(1.f, angle / maxRotateStep);
	return retMag * slerp(from, to, alpha);
}

bool Vector3D::approximatelyEqual(Vector3D v1, Vector3D v2)
{
	return Math::approximatelyEqual(v1.x, v2.x)
		&& Math::approximatelyEqual(v1.y, v2.y)
		&& Math::approximatelyEqual(v1.z, v2.z);
}


Vector3D Vector3D::zero(0.f, 0.f, 0.f);
Vector3D Vector3D::right(1.f, 0.f, 0.f);
Vector3D Vector3D::left(-1.f, 0.f, 0.f);
Vector3D Vector3D::up(0.f, 1.f, 0.f);
Vector3D Vector3D::down(0.f, -1.f, 0.f);
Vector3D Vector3D::forward(0.f, 0.f, -1.f);
Vector3D Vector3D::backward(0.f, 0.f, 1.f);


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

