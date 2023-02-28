#pragma once

struct Vector2Int {

	int x{};
	int y{};


	inline Vector2Int operator+(const Vector2Int& rhs) noexcept { return Vector2Int(x + rhs.x, y + rhs.y); };
	inline Vector2Int operator-(const Vector2Int& rhs) noexcept { return Vector2Int(x - rhs.x, y - rhs.y); };
	inline Vector2Int operator*(const Vector2Int& rhs) noexcept { return Vector2Int(x * rhs.x, y * rhs.y); };
	inline Vector2Int operator/(const Vector2Int& rhs) noexcept { return Vector2Int(x / rhs.x, y / rhs.y); };

	inline Vector2Int& operator+=(const Vector2Int& rhs) noexcept {
		x += rhs.x;
		y += rhs.y;
		
		return *this;
	};

	inline Vector2Int& operator-=(const Vector2Int& rhs) noexcept {
		x -= rhs.x; 
		y -= rhs.y; 

		return *this;
	};


	inline bool operator==(const Vector2Int& rhs) const noexcept { return (x == rhs.x && y == rhs.y); };
	inline bool operator!=(const Vector2Int& rhs) const noexcept { return !(*this == rhs); };

};