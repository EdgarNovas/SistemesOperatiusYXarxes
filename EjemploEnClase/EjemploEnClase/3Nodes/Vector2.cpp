#include "Vector2.h"

Vector2::Vector2()
{
}

Vector2::Vector2(int x, int y)
{
	X = x;
	Y = y;
}

Vector2::Vector2(Vector2* other)
{
	*this = *other;

	X = other->X;
	Y = other->Y;
}



Vector2 Vector2::operator+(Vector2 other)
{
	Vector2 result = *this;

	result.X += other.X;
	result.Y += other.Y;

	return result;
}

Vector2 Vector2::operator+=(Vector2 other)
{
	return (*this + other);
}



Vector2 Vector2::operator-(Vector2 other)
{
	Vector2 result = *this;

	result.X -= other.X;
	result.Y -= other.Y;

	return result;
}

Vector2 Vector2::operator-=(Vector2 other)
{
	return (*this - other);
}


