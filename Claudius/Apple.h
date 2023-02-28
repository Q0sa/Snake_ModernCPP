#pragma once

#include "Renderer.h"

class Apple
{
public:

	void Render(const Renderer& renderer) const noexcept;
	void SetRandomPosition(const Vector2Int& window_bounds) noexcept;

	Vector2Int GetPosition() const noexcept;

private:

	Vector2Int pos = _APPLE_START_POS;

};