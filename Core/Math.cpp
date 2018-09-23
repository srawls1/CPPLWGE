#include "Math.h"
#include "Assert.h"
#define _USE_MATH_DEFINES
#include <cmath>

namespace Math
{
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

    f32 loge(f32 x)
    {
        Assert(x > 0);
        return ::log(x);
    }

    f32 log2(f32 x)
    {
        Assert(x > 0);
        return ::log2(x);
    }

    f32 log10(f32 x)
    {
        Assert(x > 0);
        return ::log10(x);
    }

    f32 exp(f32 x)
    {
        f32 ret = ::exp(x);
        Assert(ret > 0);
        return ret;
    }

	f32 pow(f32 base, f32 exponent)
    {
        return ::pow(base, exponent);
    }

	f32 pow(f32 base, u32 exponent)
    {
        f32 result = 1.f;
        f32 current = base;
        while (exponent > 0)
        {
            if (exponent & 1)
            {
                result *= current;
            }
            current *= current;
            exponent >>= 1;
        }
        return result;
    }

	i32 pow(i32 base, u32 exponent)
    {
        i32 result = 1;
        i32 current = base;
        while (exponent > 0)
        {
            if (exponent & 1)
            {
                result *= current;
            }
            current *= current;
            exponent >>= 1;
        }
        return result;
    }

    f32 pow(f32 base, i32 exponent)
    {
        f32 intermediate = pow(base, (u32)abs(exponent));
        if (exponent < 0)
        {
            return 1.f / intermediate;
        }
        return intermediate;
    }

    u32 nextPowerOf2(register u32 start)
    {
        start |= start >> 1;
        start |= start >> 2;
        start |= start >> 4;
        start |= start >> 8;
        start |= start >> 16;
        return ++start;
    }

    u64 nextPowerOf2(register u64 start)
    {
        start |= start >> 1;
        start |= start >> 2;
        start |= start >> 4;
        start |= start >> 8;
        start |= start >> 16;
        start |= start >> 32;
        return ++start;
    }

    u32 logKnownPowOf2(register u32 num)
    {
        register u32 r = (v & 0xAAAAAAAA) != 0;
        r |= ((v & 0xCCCCCCCC) != 0) << 1;
        r |= ((v & 0xF0F0F0F0) != 0) << 2;
        r |= ((v & 0xFF00FF00) != 0) << 3;
        r |= ((v & 0xFFFF0000) != 0) << 4;

        return r;
    }

	i32 floor(f32 x)
    {
        i32 ret = (x >= 0) ? roundTowardZero(x) : roundAwayFromZero(x);
        Assert(ret <= x);
        if (ret > x)
            std::cout << "floor(" << x << ") = " << ret << std::endl;
        return ret;
    }

	i32 ceil(f32 x)
    {
        i32 ret = (x >= 0) ? roundAwayFromZero(x) : roundTowardZero(x);
        Assert(ret >= x);
        return ret;
    }

	i32 roundTowardZero(f32 x)
    {
        i32 ret = (i32)x;
        Assert(abs(ret) <= abs(x));
        return ret;
    }

	i32 roundAwayFromZero(f32 x)
    {
        i32 y = (i32)x;
        i32 ret = y + ((y == x) ? 0 : (x > 0) ? 1 : -1);
        Assert(abs(ret) >= abs(x));
        return ret;
    }

	i32 round(f32 x)
    {
        i32 ret = floor(x + 0.5f);
        Assert(abs(ret - x) <= 0.5f);
        return ret;
    }

	f32 lerp(f32 a, f32 b, f32 t)
    {
        return a + (b - a) * t;
    }

	f32 inverseLerp(f32 a, f32 b, f32 result)
    {
        f32 t = (result - a) / (b - a);
        Assert(approximatelyEqual(lerp(a, b, t), result));
        return t;
    }

	f32 smoothStep(f32 x)
    {
        f32 xSquared = x * x;
        return 3 * xSquared - 2 * xSquared * x;
    }

	f32 sqrt(f32 x)
    {
        Assert(x >= 0);
        return ::sqrt(x);
    }

	f32 cbrt(f32 x)
    {
        return ::cbrt(x);
    }

	f32 PI = M_PI;
	f32 E = M_E;
}
