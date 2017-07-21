#include "Vector4D.h"
#include "Vector3D.h"
#include "Vector2D.h"


Vector4D::Vector4D(f32 xx = 0.f, f32 yy = 0.f, f32 zz = 0.f, f32 ww = 0.f)
	: x(xx), y(yy), z(zz), w(ww)
{}

Vector3D Vector4D::xyz()
{
	return Vector3D(x, y, z);
}

Vector2D Vector4D::xy()
{
	return Vector2D(x, y);
}

Vector2D Vector4D::zw()
{
	return Vector2D(z, w);
}

void Vector4D::normalize()
{
	f32 mag = magnitude();
	x /= mag;
	y /= mag;
	z /= mag;
	w /= mag;
}

Vector4D Vector4D::unitVector()
{
	return *this / magnitude();
}

f32 Vector4D::magnitude()
{
	return Math::sqrt(magnitudeSquared());
}

f32 Vector4D::magnitudeSquared()
{
	return x * x + y * y + z * z + w * w;
}

f32 Vector4D::scalarProjection(Vector4D other)
{
	return dotProduct(*this, other) / other.magnitude();
}

Vector4D Vector4D::vectorProjection(Vector4D other)
{
	return scalarProjection(other) * other.unitVector();
}

Vector4D Vector4D::orthogonalProjection(Vector4D other)
{
	return *this - vectorProjection(other);
}

Vector4D Vector4D::reflectedAcross(Vector4D normal)
{
	Vector4D projection = vectorProjection(normal);
	return  projection + projection - *this;
}

void Vector4D::operator+=(Vector4D v)
{
	x += v.x;
	y += v.y;
	z += v.z;
	w += v.w;
}

void Vector4D::operator-=(Vector4D v)
{
	x -= v.x;
	y -= v.y;
	z -= v.z;
	w -= v.w;
}

void Vector4D::operator*=(f32 scalar)
{
	x *= scalar;
	y *= scalar;
	z *= scalar;
	w *= scalar;
}

void Vector4D::operator/=(f32 scalar)
{
	x /= scalar;
	y /= scalar;
	z /= scalar;
	w /= scalar;
}

Vector4D Vector4D::vectorAdd(Vector4D v1, Vector4D v2)
{
	return Vector4D(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z, v1.w + v2.w);
}

Vector4D Vector4D::vectorSubtract(Vector4D v1, Vector4D v2)
{
	return Vector4D(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z, v1.w - v2.w);
}

Vector4D Vector4D::scalarMultiply(f32 scalar, Vector4D v)
{
	return Vector4D(scalar * v.x, scalar * v.y, scalar * v.z, scalar * v.w);
}

f32 Vector4D::dotProduct(Vector4D v1, Vector4D v2)
{
	return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z + v1.w * v2.w;
}

Vector4D Vector4D::scale(Vector4D v1, Vector4D v2)
{
	return Vector4D(v1.x * v2.x, v1.y * v2.y, v1.z * v2.z, v1.w * v2.w);
}

f32 Vector4D::distance(Vector4D v1, Vector4D v2)
{
	return vectorSubtract(v1, v2).magnitude();
}

f32 Vector4D::distanceSquared(Vector4D v1, Vector4D v2)
{
	return vectorSubtract(v1, v2).magnitudeSquared();
}

f32 Vector4D::cosAngleBetween(Vector4D v1, Vector4D v2)
{
	return dotProduct(v1, v2) / (v1.magnitude() * v2.magnitude());
}

f32 Vector4D::angleBetween(Vector4D v1, Vector4D v2)
{
	return Math::arccos(cosAngleBetween(v1, v2));
}

Vector4D Vector4D::lerp(Vector4D v1, Vector4D v2, f32 alpha)
{
	return v1 * (1 - alpha) + v2 * alpha;
}

Vector4D Vector4D::slerp(Vector4D v1, Vector4D v2, f32 alpha)
{
	f32 angle = angleBetween(v1, v2);
	f32 sina = Math::sin(angle);
	return Math::sin((1 - alpha) * angle) / sina * v1 + Math::sin(alpha * angle) / sina * v2;
}

Vector4D Vector4D::moveTowards(Vector4D from, Vector4D to, f32 maxStep)
{
	Vector4D dif = to - from;
	if (dif.magnitude() < maxStep)
	{
		return to;
	}
	return from + dif.unitVector() * maxStep;
}

Vector4D Vector4D::rotateTowards(Vector4D from, Vector4D to, f32 maxRotateStep, f32 maxMagnitudeStep)
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

bool Vector4D::approximatelyEqual(Vector4D v1, Vector4D v2)
{
	return Math::approximatelyEqual(v1.x, v2.x)
		&& Math::approximatelyEqual(v1.y, v2.y)
		&& Math::approximatelyEqual(v1.z, v2.z)
		&& Math::approximatelyEqual(v1.w, v2.w);
}


Vector4D operator+(Vector4D v1, Vector4D v2)
{
	return Vector4D::vectorAdd(v1, v2);
}

Vector4D operator-(Vector4D v1, Vector4D v2)
{
	return Vector4D::vectorSubtract(v1, v2);
}

Vector4D operator*(f32 scalar, Vector4D v)
{
	return Vector4D::scalarMultiply(scalar, v);
}

Vector4D operator*(Vector4D v, f32 scalar)
{
	return Vector4D::scalarMultiply(scalar, v);
}

Vector4D operator/(Vector4D v, f32 scalarInverse)
{
	return Vector4D::scalarMultiply(1.f / scalarInverse, v);
}

f32 operator*(Vector4D v1, Vector4D v2)
{
	return Vector4D::dotProduct(v1, v2);
}

bool operator==(Vector4D v1, Vector4D v2)
{
	return v1.x == v2.x
		&& v1.y == v2.y
		&& v1.z == v2.z
		&& v1.w == v2.w;
}
