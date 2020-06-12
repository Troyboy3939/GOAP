#pragma once
#include "Person.h"
class Miner : public Person
{
public: 
	Miner(Vector2 v2Position = Vector2(0,0), Vector3 v3Colour = Vector3(1, 0.843f, 0));
	void Update(float fDeltaTime);

	void Draw(aie::Renderer2D* pRenderer);
private:
};

