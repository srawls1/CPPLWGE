#include "Vector2D.h"


Vector2D::Vector2D(f32 xx = 0.f, f32 yy = 0.f)
	: x(xx), y(yy)
{}

void Vector2D::normalize()
{
	f32 mag = magnitude();
	x /= mag;
	y /= mag;
}

Vector2D Vector2D::unitVector()
{
	return *this / magnitude();
}

f32 Vector2D::magnitude()
{
	return Math::sqrt(magnitudeSquared());
}

f32 Vector2D::magnitudeSquared()
{
	return x * x + y * y;
}

f32 Vector2D::scalarProjection(Vector2D other)
{
	return Vector2D::dotProduct(*this, other) / other.magnitude();
}

Vector2D Vector2D::vectorProjection(Vector2D other)
{
	return scalarProjection(other) * other.unitVector();
}

Vector2D Vector2D::orthogonalProjection(Vector2D other)
{
	return *this - vectorProjection(other);
}

Vector2D Vector2D::reflectedAcross(Vector2D normal)
{
	Vector2D projection = vectorProjection(normal);
	return projection + projection - *this;
}

void Vector2D::operator+=(Vector2D v)
{
	x += v.x;
	y += v.y;
}

void Vector2D::operator-=(Vector2D v)
{
	x -= v.x;
	y -= v.y;
}

void Vector2D::operator*=(f32 scalar)
{
	x *= scalar;
	y *= scalar;
}

void Vector2D::operator/=(f32 scalar)
{
	x /= scalar;
	y /= scalar;
}

Vector2D Vector2D::vectorAdd(Vector2D v1, Vector2D v2)
{
	return Vector2D(v1.x + v2.x, v1.y + v2.y);
}

Vector2D Vector2D::vectorSubtract(Vector2D v1, Vector2D v2)
{
	return Vector2D(v1.x - v2.x, v1.y - v2.y);
}

Vector2D Vector2D::scalarMultiply(f32 scalar, Vector2D v)
{
	return Vector2D(scalar * v.x, scalar * v.y);
}

f32 Vector2D::dotProduct(Vector2D v1, Vector2D v2)
{
	return v1.x * v2.x + v1.y * v2.y;
}

Vector2D Vector2D::scale(Vector2D v1, Vector2D v2)
{
	return Vector2D(v1.x * v2.x, v1.y * v2.y);
}

f32 Vector2D::crossProductScalar(Vector2D v1, Vector2D v2)
{
	return v1.x * v2.y - v1.y * v2.x;
}

Vector2D Vector2D::crossProductVector(Vector2D v)
{
	return Vector2D(v.y, -v.x);
}

f32 Vector2D::distance(Vector2D v1, Vector2D v2)
{
	return vectorSubtract(v1, v2).magnitude();
}

f32 Vector2D::distanceSquared(Vector2D v1, Vector2D v2)
{
	return vectorSubtract(v1, v2).magnitudeSquared();
}

f32 Vector2D::cosAngleBetween(Vector2D v1, Vector2D v2)
{
	return dotProduct(v1, v2) / (v1.magnitude() * v2.magnitude());
}

f32 Vector2D::angleBetween(Vector2D v1, Vector2D v2)
{
	return Math::arccos(cosAngleBetween(v1, v2));
}

Vector2D Vector2D::lerp(Vector2D v1, Vector2D v2, f32 alpha)
{
	return (1 - alpha) * v1 + alpha * v2;
}

Vector2D Vector2D::slerp(Vector2D v1, Vector2D v2, f32 alpha)
{
	f32 angle = angleBetween(v1, v2);
	f32 sina = Math::sin(angle);
	return Math::sin((1 - alpha) * angle) / sina * v1 + Math::sin(alpha * angle) / sina * v2;
}

Vector2D Vector2D::moveTowards(Vector2D from, Vector2D to, f32 maxStep)
{
	Vector2D dif = to - from;
	if (dif.magnitude() < maxStep)
	{
		return to;
	}
	return from + dif.unitVector() * maxStep;
}

Vector2D Vector2D::rotateTowards(Vector2D from, Vector2D to, f32 maxRotateStep, f32 maxMagnitudeStep)
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

Vector2D Vector2D::zero(0.f, 0.f);
Vector2D Vector2D::right(1.f, 0.f);
Vector2D Vector2D::left(-1.f, 0.f);
Vector2D Vector2D::up(0.f, 1.f);
Vector2D Vector2D::down(0.f, -1.f);

Vector2D operator+(Vector2D v1, Vector2D v2)
{
	return Vector2D::vectorAdd(v1, v2);
}

Vector2D operator-(Vector2D v1, Vector2D v2)
{
	return Vector2D::vectorSubtract(v1, v2);
}

Vector2D operator*(f32 scalar, Vector2D v)
{
	return Vector2D::scalarMultiply(scalar, v);
}

Vector2D operator*(Vector2D v, f32 scalar)
{
	return Vector2D::scalarMultiply(scalar, v);
}

Vector2D operator/(Vector2D v, f32 scalarInverse)
{
	return Vector2D::scalarMultiply(1.f / scalarInverse, v);
}

f32 operator*(Vector2D v1, Vector2D v2)
{
	return Vector2D::dotProduct(v1, v2);
}

bool operator==(Vector2D v1, Vector2D v2)
{
	return v1.x == v2.x
		&& v1.y == v2.y;
}