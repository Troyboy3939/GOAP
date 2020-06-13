#pragma once
#include "Person.h"
 

class Blacksmith : public Person
{
public:
	Blacksmith( Vector2 v2Position = Vector2(0, 0), Vector3 v3Colour = Vector3(0.2f, 0.2f, 0.2f));
	void Update(float fDeltaTime);

	void Draw(aie::Renderer2D* pRenderer);

	bool HasResources();
	bool HasTool();
private:
};

