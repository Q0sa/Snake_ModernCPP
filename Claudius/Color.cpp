#include "Color.h"

Color::Color() noexcept: r(0), g(0), b(0), a(0) 
{
}

Color::Color(const Color& rhs) noexcept : r(rhs.r), g(rhs.g), b(rhs.b), a(rhs.a)
{
}

Color::Color(unsigned char r, unsigned char g, unsigned char b, unsigned char a) noexcept : r(r), g(g), b(b), a(a)
{
}


