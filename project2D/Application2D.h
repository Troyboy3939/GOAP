#pragma once

#include "Application.h"
#include "Renderer2D.h"
#include "GoapManager.h"


class Application2D : public aie::Application {
public:

	Application2D();
	virtual ~Application2D();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

protected:

	aie::Renderer2D*	m_2dRenderer;


	GoapManager* m_pManager;
	Mine* m_pMine;
	LoggingSite* m_pLoggingSite;
	SmithingSite* m_pSmithingSite;


	aie::Font* m_pFont;

	float m_timer;
};