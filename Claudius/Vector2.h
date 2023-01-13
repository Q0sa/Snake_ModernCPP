#pragma once

struct Vector2
{
	int x {}; 
	int y {};

	Vector2() noexcept;
	Vector2(const Vector2& rhs) noexcept;
	Vector2(const int x, const int y) noexcept;

	Vector2& operator=(const Vector2& rhs) noexcept;
	Vector2 operator+(const Vector2& rhs) const noexcept;		 
	Vector2 operator-(const Vector2& rhs) const noexcept;		 
	Vector2 operator*(const Vector2& rhs) const noexcept;	
	Vector2 operator/(const Vector2& rhs) const noexcept;
	

	bool operator==(const Vector2& rhs) const noexcept;

};