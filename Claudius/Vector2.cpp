#include "Vector2.h"
#include <cmath>

Vector2::Vector2() noexcept : x(0), y(0)
{
}

Vector2::Vector2(const Vector2& rhs) noexcept : x(rhs.x), y(rhs.y)
{
}

Vector2::Vector2(const int x, const int y) noexcept : x(x), y(y)
{
}




Vector2& Vector2::operator=(const Vector2& rhs) noexcept
{ 
	x = rhs.x; 
	y = rhs.y; 
	return *this; 
};

Vector2 Vector2::operator+(const Vector2& rhs) const noexcept
{
	return Vector2(x + rhs.x, y + rhs.y);
}

Vector2 Vector2::operator-(const Vector2& rhs) const noexcept
{
	return Vector2(x - rhs.x, y - rhs.y);
}

Vector2 Vector2::operator*(const Vector2& rhs) const noexcept
{
	return Vector2(x * rhs.x, y * rhs.y);
}

Vector2 Vector2::operator/(const Vector2& rhs) const noexcept
{
	return Vector2(x / rhs.x, y / rhs.y);
}


bool Vector2::operator==(const Vector2& rhs) const noexcept
{
	return (this->x == rhs.x && this->y == rhs.y);
}

