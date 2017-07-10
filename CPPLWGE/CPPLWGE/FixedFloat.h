#pragma once

template <int B, int P>
class FixedFloat
{
	int base : B;
	int power : P;
public:
	FixedFloat(double f);
	FixedFloat(int b, int p);

	double asNativeFloat();

	FixedFloat<int B, int P> operator+(FixedFloat<B, P> other);
	FixedFloat<int B, int P> operator-(FixedFloat<B, P> other);
	FixedFloat<int B, int P> operator*(FixedFloat<B, P> other);
	FixedFloat<int B, int P> operator/(FixedFloat<B, P> other);
};

template <int B, int P>
FixedFloat<B, P>::FixedFloat(double f)
{
	// TODO
}

template <int B, int P>
FixedFloat::FixedFloat(int b, int p)
	: base(b), power(p)
{}

template<int B, int P>
double FixedFloat::asNativeFloat()
{
	// TODO
	return 0.f;
}

template <int B, int P>
FixedFloat<B, P> FixedFloat<B, P>::operator+(FixedFloat<B, P> other)
{
	// TODO
	return 0.f;
}

template <int B, int P>
FixedFloat<B, P> FixedFloat<B, P>::operator-(FixedFloat<B, P> other)
{
	// TODO
	return 0.f;
}

template <int B, int P>
FixedFloat<B, P> FixedFloat<B, P>::operator*(FixedFloat<B, P> other)
{
	// TODO
	return 0.f;
}

template <int B, int P>
FixedFloat<B, P> FixedFloat<B, P>::operator/(FixedFloat<B, P> other)
{
	// TODO
	return 0.f;
}