#pragma once
#include "Renderer2D.h"
#include "Vector2.h"
class SmithingSite
{
public:
	SmithingSite(Vector2 v2Position);
	void Update(float fDeltaTime);

	void Draw(aie::Renderer2D* pRenderer);

	Vector2 GetPosition();
	void SetPosition(Vector2 v2Position);
private:
	Vector2 m_v2Position;
};

