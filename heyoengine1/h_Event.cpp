#include "h_Event.h"

namespace Heyo {

	bool processEvent(Event & a_event)		
		/*	Checks to see if there is a new event,
			returns true if there is, false if not*/
	{
		return SDL_PollEvent(&a_event.m_event);
	}

	Event::Event()
	{
		
	}


	Event::~Event()
	{
	}

	int Event::type() {
		return m_event.type;
	}

	int Event::keyPressed() {
		return m_event.key.keysym.sym;
	}

	bool Event::quit() {
		if (m_event.type == QUIT)
			return 1;
		else
			return 0;
	}

}