#include "Types.h"
#include "Assert.h"

// include other classes being tested here
#include "Math.h"
#include "BitPacker.h"

#define assertApprox(calc, expected) Assert(Math::approximatelyEqual(calc, expected))

int main()
{
    // Test change
	// assert tests here
    assertApprox(1, 1);
    assertApprox(1.20001, 1.20002);
    assertApprox(1.2f, 1.2f);
    //assertApprox(1.2, 1.3); // This one should fail
    //assertApprox(1, 3); // This one should fail

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

    Assert(Math::abs(3) == 3);
    Assert(Math::abs(-2) == 2);
    Assert(Math::abs(1.5) == 1.5);
    Assert(Math::abs(-4.2f) == 4.2f);

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

	assertApprox(Math::cos(0.f), 1.f);
	assertApprox(Math::cos(Math::PI / 6), .866f);
	assertApprox(Math::cos(Math::PI / 4), .7071f);
	assertApprox(Math::cos(Math::PI / 3), .5f);
	assertApprox(Math::cos(Math::PI / 2), 0.f);
	assertApprox(Math::cos(2 * Math::PI / 3), -.5f);
	assertApprox(Math::cos(3 * Math::PI / 4), -.7071f);
	assertApprox(Math::cos(5 * Math::PI / 6), -.866f);
	assertApprox(Math::cos(Math::PI), -1.f);
	assertApprox(Math::cos(7 * Math::PI / 6), -.866f);
	assertApprox(Math::cos(5 * Math::PI / 4), -.7071f);
	assertApprox(Math::cos(4 * Math::PI / 3), -.5f);
	assertApprox(Math::cos(3 * Math::PI / 2), 0.f);
	assertApprox(Math::cos(5 * Math::PI / 3), .5f);
	assertApprox(Math::cos(7 * Math::PI / 4), .7071f);
	assertApprox(Math::cos(11 * Math::PI / 6), .866f);
	assertApprox(Math::cos(2 * Math::PI), 1.f);
	assertApprox(Math::cos(-Math::PI / 6), .866f);
	assertApprox(Math::cos(-Math::PI / 4), .7071f);
	assertApprox(Math::cos(-Math::PI / 3), .5f);
	assertApprox(Math::cos(-Math::PI / 2), 0.f);
	assertApprox(Math::cos(-2 * Math::PI / 3), -.5f);
	assertApprox(Math::cos(-3 * Math::PI / 4), -.7071f);
	assertApprox(Math::cos(-5 * Math::PI / 6), -.866f);
	assertApprox(Math::cos(-Math::PI), -1.f);
	assertApprox(Math::cos(-7 * Math::PI / 6), -.866f);
	assertApprox(Math::cos(-5 * Math::PI / 4), -.7071f);
	assertApprox(Math::cos(-4 * Math::PI / 3), -.5f);
	assertApprox(Math::cos(-3 * Math::PI / 2), 0.f);
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

    assertApprox(Math::sqrt(1), 1.f);
    assertApprox(Math::sqrt(2), 1.4142f);
    assertApprox(Math::sqrt(3), 1.73205f);
    assertApprox(Math::sqrt(4), 2.f);

    Assert(Math::floor(1.2) == 1);
    Assert(Math::floor(-1.2) == -2);
    Assert(Math::floor(1.0) == 1);
    Assert(Math::floor(1.99) == 1);

    Assert(Math::ceil(1.2) == 2);
    Assert(Math::ceil(-1.2) == -1);
    Assert(Math::ceil(1.0) == 1);
    Assert(Math::ceil(1.99) == 2);

    Assert(Math::roundTowardZero(1.2) == 1);
    Assert(Math::roundTowardZero(-1.2) == -1);
    Assert(Math::roundTowardZero(1.0) == 1);
    Assert(Math::roundTowardZero(1.99) == 1);

    Assert(Math::roundAwayFromZero(1.2) == 2);
    Assert(Math::roundAwayFromZero(-1.2) == -2);
    Assert(Math::roundAwayFromZero(1.0) == 1);
    Assert(Math::roundAwayFromZero(1.99) == 2);

    Assert(Math::round(1) == 1);
    Assert(Math::round(2.4) == 2);
    Assert(Math::round(4.5f) == 5);
    Assert(Math::round(9.9f) == 10);

    Assert(Math::mod(1, 3) == 1);
    assertApprox(Math::mod(1.3, 2.4), 1.3);
    assertApprox(Math::mod(-.3, 2.4), 2.1);
    Assert(Math::mod(5, 3) == 2);
    Assert(Math::mod(-1, 3) == 2);
    Assert(Math::mod(-2, 3) == 1);

    Assert(Math::gcd(21, 28) == 7);
    Assert(Math::gcd(9, 18) == 9);
    Assert(Math::gcd(17, 23) == 1);

    Assert(Math::lcm(21, 28) == 84);
    Assert(Math::lcm(9, 18) == 18);
    Assert(Math::lcm(17, 23) == 391);

    Assert(Math::inverseMod(2, 3) == 2);
    Assert(Math::inverseMod(17, 23) == 19);

    BitPacker packer;
    for (i32 i = 0; i < 50; ++i)
    {
        packer.writeInt(i, 0, 50);
    }
    for (f32 f = 0.f; f < 1.f; f += 0.02f)
    {
        packer.writeFloat(f, 0.f, 1.f, 0.02f);
    }
    packer.flush();
    for (i32 i = 0; i < 50; ++i)
    {
        //std::cout << packer.readInt(0, 50) << std::endl;
        Assert(packer.readInt(0, 50) == i);
    }
    for (f32 f = 0.f; f < 1.f; f += 0.02f)
    {
        //std::cout << packer.readFloat(0.f, 1.f, 0.02f) << std::endl;
        assertApprox(packer.readFloat(0.f, 1.f, 0.02f), f);
    }
}
