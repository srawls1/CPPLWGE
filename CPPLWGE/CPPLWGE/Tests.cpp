#include "Types.h"
#include "Assert.h"
#include <iostream>

// include other classes being tested here
#include "Math.h"

#define assertApprox(calc, expected) Assert(Math::approximatelyEqual(calc, expected))

int main()
{
	// assert tests here
	Assert(Math::min(1, 2) == 1);
	Assert(Math::min(3, 2) == 2);
	Assert(Math::min(1.2, 2.3) == 1.2);
	Assert(Math::min(3.2f, 2.3f) == 2.3f);

	Assert(Math::max(1, 2) == 2);
	Assert(Math::max(3, 2) == 3);
	Assert(Math::max(1.2, 2.3) == 2.3);
	Assert(Math::max(3.2f, 2.3f) == 3.2f);

	Assert(Math::clamp(1, 0, 2) == 1);
	Assert(Math::clamp(-1, 0, 2) == 0);
	Assert(Math::clamp(2, 0, 2) == 2);
	Assert(Math::clamp(0.f, 0.f, 1.f) == 0.f);
	Assert(Math::clamp(1.2f, 0.f, 1.f) == 1.f);
	Assert(Math::clamp(0.5f, 0.f, 1.f) == 0.5f);

	assertApprox(Math::sin(0.f), 0.f);
	assertApprox(Math::sin(Math::PI / 6), 0.5f);
	assertApprox(Math::sin(Math::PI / 4), .7071f);
	assertApprox(Math::sin(Math::PI / 3), .866f);
	assertApprox(Math::sin(Math::PI / 2), 1.f);
	assertApprox(Math::sin(2 * Math::PI / 3), .866f);
	assertApprox(Math::sin(3 * Math::PI / 4), .7071f);
	assertApprox(Math::sin(5 * Math::PI / 6), 0.5f);
	assertApprox(Math::sin(Math::PI), 0.f);
	assertApprox(Math::sin(7 * Math::PI / 6), -0.5f);
	assertApprox(Math::sin(5 * Math::PI / 4), -.7071f);
	assertApprox(Math::sin(4 * Math::PI / 3), -.866f);
	assertApprox(Math::sin(3 * Math::PI / 2), -1.f);
	assertApprox(Math::sin(5 * Math::PI / 3), -.866f);
	assertApprox(Math::sin(7 * Math::PI / 4), -.7071f);
	assertApprox(Math::sin(11 * Math::PI / 6), -0.5f);
	assertApprox(Math::sin(2 * Math::PI), 0.f);
	assertApprox(Math::sin(-Math::PI / 6), -0.5f);
	assertApprox(Math::sin(-Math::PI / 4), -.7071f);
	assertApprox(Math::sin(-Math::PI / 3), -.866f);
	assertApprox(Math::sin(-Math::PI / 2), -1.f);
	assertApprox(Math::sin(-2 * Math::PI / 3), -.866f);
	assertApprox(Math::sin(-3 * Math::PI / 4), -.7071f);
	assertApprox(Math::sin(-5 * Math::PI / 6), -0.5f);
	assertApprox(Math::sin(-Math::PI), 0.f);
	assertApprox(Math::sin(-7 * Math::PI / 6), 0.5f);
	assertApprox(Math::sin(-5 * Math::PI / 4), .7071f);
	assertApprox(Math::sin(-4 * Math::PI / 3), .866f);
	assertApprox(Math::sin(-3 * Math::PI / 2), 1.f);
	assertApprox(Math::sin(-5 * Math::PI / 3), .866f);
	assertApprox(Math::sin(-7 * Math::PI / 4), .7071f);
	assertApprox(Math::sin(-11 * Math::PI / 6), 0.5f);
	assertApprox(Math::sin(-2 * Math::PI), -0.f);

	assertApprox(Math::cos(0.f), 1.f));
	assertApprox(Math::cos(Math::PI / 6), .866f));
	assertApprox(Math::cos(Math::PI / 4), .7071f));
	assertApprox(Math::cos(Math::PI / 3), .5f));
	assertApprox(Math::cos(Math::PI / 2), 0.f));
	assertApprox(Math::cos(2 * Math::PI / 3), -.5f);
	assertApprox(Math::cos(3 * Math::PI / 4), -.7071f);
	assertApprox(Math::cos(5 * Math::PI / 6), -.866f);
	assertApprox(Math::cos(Math::PI), -1.f);
	assertApprox(Math::cos(7 * Math::PI / 6), -.866f));
	assertApprox(Math::cos(5 * Math::PI / 4), -.7071f));
	assertApprox(Math::cos(4 * Math::PI / 3), -.5f));
	assertApprox(Math::cos(3 * Math::PI / 2), 0.f));
	assertApprox(Math::cos(5 * Math::PI / 3), .5f);
	assertApprox(Math::cos(7 * Math::PI / 4), .7071f);
	assertApprox(Math::cos(11 * Math::PI / 6), .866f);
	assertApprox(Math::cos(2 * Math::PI), 1.f);
	assertApprox(Math::cos(-Math::PI / 6), .866f));
	assertApprox(Math::cos(-Math::PI / 4), .7071f));
	assertApprox(Math::cos(-Math::PI / 3), .5f));
	assertApprox(Math::cos(-Math::PI / 2), 0.f));
	assertApprox(Math::cos(-2 * Math::PI / 3), -.5f);
	assertApprox(Math::cos(-3 * Math::PI / 4), -.7071f);
	assertApprox(Math::cos(-5 * Math::PI / 6), -.866f);
	assertApprox(Math::cos(-Math::PI), -1.f);
	assertApprox(Math::cos(-7 * Math::PI / 6), -.866f));
	assertApprox(Math::cos(-5 * Math::PI / 4), -.7071f));
	assertApprox(Math::cos(-4 * Math::PI / 3), -.5f));
	assertApprox(Math::cos(-3 * Math::PI / 2), 0.f));
	assertApprox(Math::cos(-5 * Math::PI / 3), .5f);
	assertApprox(Math::cos(-7 * Math::PI / 4), .7071f);
	assertApprox(Math::cos(-11 * Math::PI / 6), .866f);
	assertApprox(Math::cos(-2 * Math::PI), 1.f);

	assertApprox(Math::tan(0.f), 0.f);
	assertApprox(Math::tan(Math::PI / 6), .5774f);
	assertApprox(Math::tan(Math::PI / 4), 1.f);
	assertApprox(Math::tan(Math::PI / 3), 1.7321f);
	assertApprox(Math::tan(2 * Math::PI / 3), -1.7321f);
	assertApprox(Math::tan(3 * Math::PI / 4), -1.f);
	assertApprox(Math::tan(5 * Math::PI / 6), -.5774f);
	assertApprox(Math::tan(Math::PI), 0.f);
	assertApprox(Math::tan(7 * Math::PI / 6), .5774f);
	assertApprox(Math::tan(5 * Math::PI / 4), 1.f);
	assertApprox(Math::tan(4 * Math::PI / 3), 1.7321f);
	assertApprox(Math::tan(5 * Math::PI / 3), -1.7321f);
	assertApprox(Math::tan(7 * Math::PI / 4), -1.f);
	assertApprox(Math::tan(11 * Math::PI / 6), -.5774f);
	assertApprox(Math::tan(2 * Math::PI), 0.f);
	assertApprox(Math::tan(-Math::PI / 6), -.5774f);
	assertApprox(Math::tan(-Math::PI / 4), -1.f);
	assertApprox(Math::tan(-Math::PI / 3), -1.7321f);
	assertApprox(Math::tan(-2 * Math::PI / 3), 1.7321f);
	assertApprox(Math::tan(-3 * Math::PI / 4), 1.f);
	assertApprox(Math::tan(-5 * Math::PI / 6), .5774f);
	assertApprox(Math::tan(-Math::PI), 0.f);
	assertApprox(Math::tan(-7 * Math::PI / 6), -.5774f);
	assertApprox(Math::tan(-5 * Math::PI / 4), -1.f);
	assertApprox(Math::tan(-4 * Math::PI / 3), -1.7321f);
	assertApprox(Math::tan(-5 * Math::PI / 3), 1.7321f);
	assertApprox(Math::tan(-7 * Math::PI / 4), 1.f);
	assertApprox(Math::tan(-11 * Math::PI / 6), .5774f);
	assertApprox(Math::tan(-2 * Math::PI), -0.f);
}
