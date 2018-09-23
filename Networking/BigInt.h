#include "Assert.h"
#include "Types.h"
#include "Array.h"

class BigInt : private Array<u32>
{
private:
    bool negative;
    u64 numBits;

    BigInt inner_add();
    BigInt inner_subtract();

    inline void copy(const BigInt& other);
    inline void move(BigInt&& other);

public:
    BigInt(const BigInt& other);
    BigInt(BigInt&& other);
    BigInt& operator=(const BigInt& other);

    BigInt operator+(const BigInt& other) const;
    BigInt operator-(const BigInt& other) const;
    BigInt operator*(const BigInt& other) const;
    BigInt operator/(const BigInt& other) const;
    BigInt operator%(const BigInt& other) const;
    BigInt operator<<(i64 shift) const;
    BigInt operator>>(i64 shift) const;
    BigInt operator&(const BigInt& other) const;
    BigInt operator|(const BigInt& other) const;
    BigInt operator^(const BigInt& other) const;
    BitInt& operator++();
    BigInt operator++(int);

    bool operator==(const BigInt& other) const;
    bool operator!=(const BigInt& other) const
    { return !(operator==(other)); }
    bool operator<(const BigInt& other) const;
    bool operator>(const BigInt& other) const;
    bool operator<=(const BigInt& other) const;
    bool operator>=(const BigInt& other) const;
};
