#pragma once
#include "Types.h"

struct Vector4D
{
	f32 x;
	f32 y;
	f32 z;
	f32 w;

	Vector4D(f32 xx = 0.f, f32 yy = 0.f, f32 zz = 0.f, f32 ww = 0.f);

	struct Vector3D xyz();
	struct Vector2D xy();
	struct Vector2D zw();

	inline void normalize();
	inline Vector4D unitVector();
	inline f32 magnitude();
	inline f32 magnitudeSquared();

	inline f32 scalarProjection(Vector4D other);
	inline Vector4D vectorProjection(Vector4D other);
	inline Vector4D orthogonalProjection(Vector4D other);
	inline Vector4D reflectedAcross(Vector4D normal);

	inline void operator+=(Vector4D v2);
	inline void operator-=(Vector4D v2);
	inline void operator*=(f32 scalar);
	inline void operator/=(f32 scalar);

	static inline Vector4D vectorAdd(Vector4D v1, Vector4D v2);
	static inline Vector4D vectorSubtract(Vector4D v1, Vector4D v2);
	static inline Vector4D scalarMultiply(f32 scalar, Vector4D vector);
	static inline f32 dotProduct(Vector4D v1, Vector4D v2);
	static inline Vector4D scale(Vector4D v1, Vector4D v2);
	static inline f32 distance(Vector4D v1, Vector4D v2);
	static inline f32 distanceSquared(Vector4D v1, Vector4D v2);
	static inline f32 cosAngleBetween(Vector4D v1, Vector4D v2);
	static inline f32 angleBetween(Vector4D v1, Vector4D v2);

	static inline Vector4D lerp(Vector4D v1, Vector4D v2, f32 alpha);
	static inline Vector4D slerp(Vector4D v1, Vector4D v2, f32 alpha);
	static inline Vector4D moveTowards(Vector4D from, Vector4D to, f32 maxStep);
	static inline Vector4D rotateTowards(Vector4D from, Vector4D to, f32 maxRotateStep, f32 maxMagnitudeStep);

	static inline bool approximatelyEqual(Vector4D v1, Vector4D v2);
};

inline Vector4D operator+(Vector4D v1, Vector4D v2);
inline Vector4D operator-(Vector4D v1, Vector4D v2);
inline Vector4D operator*(f32 scalar, Vector4D v);
inline Vector4D operator*(Vector4D v, f32 scalar);
inline Vector4D operator/(Vector4D v, f32 scalarInverse);
inline f32 operator*(Vector4D v1, Vector4D v2);

inline bool operator==(Vector4D v1, Vector4D v2);

