#pragma once
#include "Types.h"
#include "Assert.h"

namespace Math
{
    // TODO a numBits function

	template <class T>
	T min(T a, T b);

	template <class T>
	T max(T a, T b);

	template <class T>
	T clamp(T val, T min, T max);

    template <class T>
    T repeat(T val, T min, T max);

    template <class T>
    T pingPong(T val, T min, T max);

    template <class T>
    T abs(T val);

	f32 sin(f32 theta);
	f64 sin(f64 theta);
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
	f32 pow(f32 base, u32 exponent);
	i32 pow(i32 base, u32 exponent);
    f32 pow(f32 base, i32 exponent);
    f32 pow(i32 base, i32 exponent);
    u32 nextPowerOf2(u32 start);
    u64 nextPowerOf2(u64 start);
    u32 logKnownPowOf2(u32 num);

	i32 floor(f32 x);
	i32 ceil(f32 x);
	i32 roundTowardZero(f32 x);
	i32 roundAwayFromZero(f32 x);
	i32 round(f32 x);

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


	extern f32 PI;
	extern f32 E;
};

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

    template <class T>
    T repeat(T val, T min, T max)
    {
        return mod(val - min, max - min) + min;
    }

    template <class T>
    T pingPong(T val, T min, T max)
    {
        T relativeVal = val - min;
        T range = max - min;
        i32 divide = (i32)(relativeVal / range);
        relativeVal -= divide * range;
        return (divide % 2) ? (max - relativeVal) : (min + relativeVal);
    }

    template <class T>
    T abs(T val)
    {
        return (val >= 0) ? val : -val;
    }

    template <class T>
    T gcd(T a, T b)
    {
        T lower = min(a, b);
        T upper = max(a, b);
        while (lower > 0)
        {
            T r = upper % lower;
            upper = lower;
            lower = r;
        }
        return upper;
    }

    template <class T>
    T lcm(T a, T b)
    {
        T g = gcd(a, b);
        return a * b / g;
    }

    template <class T>
    bool isPrime(T n)
    {
        // TODO
        return false;
    }

    template <class T>
    T factor(T n)
    {
        // TODO
        return 0;
    }

    template <class T>
    T mod(T n, T modulus)
    {
        Assert(modulus > 0);
        i32 q = (i32)(n / modulus);
        T ret = n - q * modulus;
        ret += ret < 0 ? modulus : 0;
        Assert (0 <= ret && ret < modulus);
        return ret;
    }

    template <class T>
    T inverseMod(T n, T modulus)
    {
        Assert(gcd(n, modulus) == 1);
        T lower = mod(n, modulus);
        T upper = modulus;
        T xPrev = 0;
        T x = 1;
        while (lower > 1)
        {
            Assert(mod(x * n, modulus) == lower);
            T q = upper / lower;
            T r = upper % lower;
            upper = lower;
            lower = r;
            T temp = x;
            x = xPrev - q * x;
            xPrev = temp;
        }
        T ret = mod(x, modulus);
        Assert(mod(n * ret, modulus) == 1);
        return ret;
    }

    template <class T>
    bool approximatelyEqual(T a, T b)
    {
        return abs(a - b) < 0.0001;
    }
};
