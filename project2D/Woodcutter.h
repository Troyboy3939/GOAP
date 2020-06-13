#pragma once
#include "Person.h"
class Woodcutter : public Person
{
public:
	//Put in default miner colour
	Woodcutter(Vector3 v3Colour =  Vector3(1,0.549f,0), Vector2 v2Position = Vector2(0,0));
	void Update(float fDeltaTime);

	void Draw(aie::Renderer2D* pRenderer);

	float GetToolDurability();
	bool HasTool();
private:

};

