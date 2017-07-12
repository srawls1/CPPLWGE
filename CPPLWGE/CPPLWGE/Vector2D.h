#pragma once
#include "Types.h"

struct Vector2D
{
	f32 x;
	f32 y;

	Vector2D(f32 xx = 0.f, f32 yy = 0.f);

	inline void normalize();
	inline Vector2D unitVector();
	inline f32 magnitude();
	inline f32 magnitudeSquared();

	inline f32 scalarProjection(Vector2D other);
	inline Vector2D vectorProjection(Vector2D other);
	inline Vector2D orthogonalProjection(Vector2D other);
	inline Vector2D reflectedAcross(Vector2D normal);

	inline void operator+=(Vector2D v);
	inline void operator-=(Vector2D v);
	inline void operator*=(f32 scalar);
	inline void operator/=(f32 scalar);

	static inline Vector2D vectorAdd(Vector2D v1, Vector2D v2);
	static inline Vector2D vectorSubtract(Vector2D v1, Vector2D v2);
	static inline Vector2D scalarMultiply(f32 scalar, Vector2D v);
	static inline f32 dotProduct(Vector2D v1, Vector2D v2);
	static inline Vector2D scale(Vector2D v1, Vector2D v2);
	static inline f32 crossProductScalar(Vector2D v1, Vector2D v2);
	static inline Vector2D crossProductVector(Vector2D v);
	static inline f32 distance(Vector2D v1, Vector2D v2);
	static inline f32 distanceSquared(Vector2D v1, Vector2D v2);
	static inline f32 cosAngleBetween(Vector2D v1, Vector2D v2);
	static inline f32 angleBetween(Vector2D v1, Vector2D v2);

	static inline Vector2D lerp(Vector2D v1, Vector2D v2, f32 alpha);
	static inline Vector2D slerp(Vector2D v1, Vector2D v2, f32 alpha);
	static inline Vector2D moveTowards(Vector2D from, Vector2D to, f32 maxStep);
	static inline Vector2D rotateTowards(Vector2D from, Vector2D to, f32 maxRotateStep, f32 maxMagnitudeStep);

	static Vector2D zero;
	static Vector2D right;
	static Vector2D left;
	static Vector2D up;
	static Vector2D down;
};

inline Vector2D operator+(Vector2D v1, Vector2D v2);
inline Vector2D operator-(Vector2D v1, Vector2D v2);
inline Vector2D operator*(f32 scalar, Vector2D v);
inline Vector2D operator*(Vector2D v, f32 scalar);
inline Vector2D operator/(Vector2D v, f32 scalarInverse);
inline f32 operator*(Vector2D v1, Vector2D v2);

inline bool operator==(Vector2D v1, Vector2D v2);