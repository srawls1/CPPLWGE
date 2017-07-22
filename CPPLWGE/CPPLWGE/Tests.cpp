#include "Types.h"
#include "Assert.h"
#include <iostream>

// include other classes being tested here
#include "Math.h"

int main()
{
	// assert tests here
	Assert(Math::min(1, 2) == 1, "Test failed for min(1, 2)");
	Assert(Math::min(3, 2) == 2, "Test failed for min(3, 2)");
	Assert(Math::min(1.2, 2.3) == 1.2, "Test failed for min(1.2, 2.3)");
	Assert(Math::min(3.2f, 2.3f) == 2.3f, "Test failed for min(3.2, 2.3)");
	
	Assert(Math::max(1, 2) == 2, "Test failed for max(1, 2)");
	Assert(Math::max(3, 2) == 3, "Test failed for max(3, 2)");
	Assert(Math::max(1.2, 2.3) == 2.3, "Test failed for max(1.2, 2.3)");
	Assert(Math::max(3.2f, 2.3f) == 3.2f, "Test failed for max(3.2, 2.3)");

	Assert(Math::clamp(1, 0, 2) == 1, "Test failed for clamp(1, 0, 2)");
	Assert(Math::clamp(-1, 0, 2) == 0, "Test failed for clamp(-1, 0, 2)");
	Assert(Math::clamp(2, 0, 2) == 2, "Test failed for clamp(3, 0, 2)");
	Assert(Math::clamp(0.f, 0.f, 1.f) == 0.f, "Test failed for clamp(0, 0, 1)");
	Assert(Math::clamp(1.2f, 0.f, 1.f) == 1.f, "Test failed for clamp(1.2, 0, 1)");
	Assert(Math::clamp(0.5f, 0.f, 1.f) == 0.5f, "Test failed for clamp(0.5, 0, 1)");

	Assert(Math::approximatelyEqual(Math::sin(0.f), 0.f), "Test failed for sin(0)");
	Assert(Math::approximatelyEqual(Math::sin(Math::PI / 6), 0.5f), "Test failed for sin(pi/6)");
	Assert(Math::approximatelyEqual(Math::sin(Math::PI / 4), .7071f), "Test failed for sin(pi/4)");
	Assert(Math::approximatelyEqual(Math::sin(Math::PI / 3), .866f), "Test failed for sin(pi/3)");
	Assert(Math::approximatelyEqual(Math::sin(Math::PI / 2), 1.f), "Test failed for sin(pi/2)");

	Assert(Math::approximatelyEqual(Math::cos(0.f), 1.f), "Test failed for cos(0)");
	Assert(Math::approximatelyEqual(Math::cos(Math::PI / 6), .866f), "Test failed for cos(pi/6)");
	Assert(Math::approximatelyEqual(Math::cos(Math::PI / 4), .7071f), "Test failed for cos(pi/4)");
	Assert(Math::approximatelyEqual(Math::cos(Math::PI / 3), .5f), "Test failed for cos(pi/3)");
	Assert(Math::approximatelyEqual(Math::cos(Math::PI / 2), 0.f), "Test failed for cos(pi/2)");


	Assert(Math::approximatelyEqual(Math::tan(0.f), 0.f), "Test failed for tan(0)");
	Assert(Math::approximatelyEqual(Math::tan(Math::PI / 6), .5774f), "Test failed for tan(pi/6)");
	Assert(Math::approximatelyEqual(Math::tan(Math::PI / 4), 1.f), "Test failed for tan(pi/4)");
	Assert(Math::approximatelyEqual(Math::tan(Math::PI / 3), 1.7321f), "Test failed for tan(pi/3)");
}