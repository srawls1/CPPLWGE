#pragma once
#include "Types.h"

namespace Math
{
	template <class T>
	T min(T a, T b);

	template <class T>
	T max(T a, T b);

	template <class T>
	T clamp(T val, T min, T max);

	f32 sin(f32 theta);
	f64 sin(f64 theta)
	f32 cos(f32 theta);
	f32 tan(f32 theta);
	f32 arcsin(f32 ratio);
	f32 arccos(f32 ratio);
	f32 arctan(f32 ratio);
	f32 arctan2(f32 y, f32 x);

	f32 loge(f32 x);
	f32 log2(f32 x);
	f32 log10(f32 x);

	f32 exp(f32 x);
	f32 pow(f32 base, f32 exponent);
	f32 pow(i32 base, f32 exponent);
	f32 pow(f32 base, u32 exponent);
	i32 pow(i32 base, u32 exponent);

	f32 floor(f32 x);
	f32 ceil(f32 x);
	f32 roundTowardZero(f32 x);
	f32 roundAwayFromZero(f32 x);
	f32 round(f32 x);

	f32 lerp(f32 a, f32 b, f32 t);
	f32 inverseLerp(f32 a, f32 b, f32 result);

	f32 smoothStep(f32 x);

	template <class T>
	T gcd(T a, T b);

	template <class T>
	T lcm(T a, T b);

	template <class T>
	bool isPrime(T n);

	template <class T>
	T factor(T n); // Just returns a single factor for now

	template <class T>
	T mod(T n, T modulus);

	template <class T>
	T inverseMod(T n, T modulus);

	f32 sqrt(f32 x);
	f32 cbrt(f32 x);

	template <class T>
	bool approximatelyEqual(T a, T b);


	f32 PI;
	f32 E;
};


#include "MathDefinitions.h"
