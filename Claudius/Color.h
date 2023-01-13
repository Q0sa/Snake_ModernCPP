#pragma once

struct Color
{
	unsigned char r, g, b, a;

	Color() noexcept ;
	Color(const Color& rhs) noexcept;
	Color(unsigned char r, unsigned char g, unsigned char b, unsigned char a) noexcept;

};