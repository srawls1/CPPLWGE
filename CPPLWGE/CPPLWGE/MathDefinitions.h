#pragma once
#include "Math.h"
#define _USE_MATH_DEFINES
#include <cmath>

namespace Math
{
	template <class T>
	T min(T a, T b)
	{
		return (a < b) ? a : b;
	}

	template <class T>
	T max(T a, T b)
	{
		return (a < b) ? b : a;
	}

    template <class T>
    T clamp(T val, T min, T max)
    {
        return (val < min) ? min : ((val > max) ? max : val);
    }

    // TODO Read "Computer Approximations" by Hart and Cheney
    f32 sin(f32 theta)
    {
        return ::sin(theta);
    }

    f64 sin(f64 theta)
    {
        return ::sin(theta);
    }

    f32 cos(f32 theta)
    {
        return ::cos(theta);
    }

    f64 cos(f64 theta)
    {
        return ::cos(theta);
    }

    f32 tan(f32 theta)
    {
        return ::tan(theta);
    }

    f64 tan(f64 theta)
    {
        return ::tan(theta);
    }

    f32 loge(f32 x) = 0;
    f32 log2(f32 x) = 0;
    f32 log10(f32 x) = 0;

    f32 exp(f32 x) = 0;
	f32 pow(f32 base, f32 exponent) = 0;
	f32 pow(i32 base, f32 exponent) = 0;
	f32 pow(f32 base, u32 exponent) = 0;
	i32 pow(i32 base, u32 exponent) = 0;

	f32 floor(f32 x) = 0;
	f32 ceil(f32 x) = 0;
	f32 roundTowardZero(f32 x) = 0;
	f32 roundAwayFromZero(f32 x) = 0;
	f32 round(f32 x) = 0;

	f32 lerp(f32 a, f32 b, f32 t) = 0;
	f32 inverseLerp(f32 a, f32 b, f32 result) = 0;

	f32 smoothStep(f32 x) = 0;

    template <class T>
	T gcd(T a, T b) = 0;

	template <class T>
	T lcm(T a, T b) = 0;

	template <class T>
	bool isPrime(T n) = 0;

	template <class T>
	T factor(T n) = 0; // Just returns a single factor for now

	template <class T>
	T mod(T n, T modulus) = 0;

	template <class T>
	T inverseMod(T n, T modulus) = 0;

	f32 sqrt(f32 x) = 0;
	f32 cbrt(f32 x) = 0;

	template <class T>
	bool approximatelyEqual(T a, T b) = 0;


	PI = M_PI;
	f32 E = M_E;
}
