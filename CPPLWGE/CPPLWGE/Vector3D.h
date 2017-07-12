#pragma once
#include "Types.h"

struct Vector3D
{
	f32 x;
	f32 y;
	f32 z;

	Vector3D(f32 xx = 0.f, f32 yy = 0.f, f32 zz = 0.f);

	inline void normalize();
	inline Vector3D unitVector();
	inline f32 magnitude();
	inline f32 magnitudeSquared();

	inline f32 scalarProjection(Vector3D other);
	inline Vector3D vectorProjection(Vector3D other);
	inline Vector3D orthogonalProjection(Vector3D other);
	inline Vector3D reflectedAcross(Vector3D normal);

	inline void operator+=(Vector3D v2);
	inline void operator-=(Vector3D v2);
	inline void operator*=(f32 scalar);
	inline void operator/=(f32 scalar);

	static inline Vector3D vectorAdd(Vector3D v1, Vector3D v2);
	static inline Vector3D vectorSubtract(Vector3D v1, Vector3D v2);
	static inline Vector3D scalarMultiply(f32 scalar, Vector3D vector);
	static inline f32 dotProduct(Vector3D v1, Vector3D v2);
	static inline Vector3D scale(Vector3D v1, Vector3D v2);
	static inline Vector3D crossProduct(Vector3D v1, Vector3D v2);
	static inline f32 distance(Vector3D v1, Vector3D v2);
	static inline f32 distanceSquared(Vector3D v1, Vector3D v2);
	static inline f32 cosAngleBetween(Vector3D v1, Vector3D v2);
	static inline f32 angleBetween(Vector3D v1, Vector3D v2);

	static inline Vector3D lerp(Vector3D v1, Vector3D v2, f32 alpha);
	static inline Vector3D slerp(Vector3D v1, Vector3D v2, f32 alpha);
	static inline Vector3D moveTowards(Vector3D from, Vector3D to, f32 maxStep);
	static inline Vector3D rotateTowards(Vector3D from, Vector3D to, f32 maxRotateStep, f32 maxMagnitudeStep);

	static Vector3D zero;
	static Vector3D right;
	static Vector3D left;
	static Vector3D up;
	static Vector3D down;
	static Vector3D forward;
	static Vector3D backward;
};

inline Vector3D operator+(Vector3D v1, Vector3D v2);
inline Vector3D operator-(Vector3D v1, Vector3D v2);
inline Vector3D operator*(f32 scalar, Vector3D v);
inline Vector3D operator*(Vector3D v, f32 scalar);
inline Vector3D operator/(Vector3D v, f32 scalarInverse);
inline f32 operator*(Vector3D v1, Vector3D v2);

inline bool operator==(Vector3D v1, Vector3D v2);