#pragma once
#include "GoapAgent.h"
#include "Vector2.h"
#include "Renderer2D.h"
#include "Vector3.h"
#include <vector>
//Base class for each type of person, inherits from goap Agent
class Person : public GoapAgent
{
public:
    enum class TYPE
    {
        MINER,
        WOODCUTTER,
        BLACKSMITH
    };


    Person(TYPE eType, Vector3 v3Colour = Vector3(0.5f,0.5f,0.5f));
    virtual void Update(float fDeltaTime);
    virtual void Draw(aie::Renderer2D* pRenderer) = 0;

    //Get functions
    Vector2 GetPosition();
    Vector2 GetVelocity();
    bool GetWorking();

    //Set functions
    void SetPosition(Vector2 v2Position);
    void SetVelocity(Vector2 v2Velocity);

    TYPE GetType();

    virtual bool AtStation() = 0;
    virtual bool StationExists() = 0;

    float GetMoney();
    void SetMoney(float fMoney);
protected:

    Vector2 m_v2Position;
    Vector2 m_v2Velocity;
    Vector3 m_v3Colour;
    TYPE m_eType;
    bool m_bWorking;
    float m_fMoney;
};

