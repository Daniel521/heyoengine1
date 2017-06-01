#include "h_Graphics.h"
#include "h_Event.h"
#include <SDL.h>
#include <iostream>

//using namespace Heyo;
using namespace std;

int main(int argc, char * argv[]) {
	Heyo::Graphics graphics(900, 650, "Heyo");
	Heyo::Event events;


	bool quit = false;
	float go = 0;
	Heyo::Uint32 red = 0x00;
	// LOOP
	while (quit == false) {

		graphics.drawPixel(go, 30, red, 50, 50);
		go += .5;
		graphics.update();

		if (Heyo::processEvent(events)) {
			if (events.quit())
				quit = true;

			if (events.type() == Heyo::Event::types::KEYDOWN)
			{
				if (events.keyPressed() == Heyo::Event::keys::K_SPACE)
					red = 0xff;
			}

			if (events.type() == Heyo::Event::types::KEYUP) {
				if (events.keyPressed() == Heyo::Event::keys::K_SPACE)
					red = 0x00;
			}
		}


	}

	return 0;
}