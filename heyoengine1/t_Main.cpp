#include "h_Graphics.h"
#include "h_Event.h"
#include <SDL.h>
#include <iostream>

//using namespace Heyo;
using namespace std;

int main(int argc, char * argv[]) {
	Heyo::Graphics graphics(900, 650, "Heyo");
	Heyo::Texture texture;
	texture.loadTexture("blah.png", graphics);
	Heyo::Event events;


	bool quit = false;
	float x = 0;
	float y = 0;
	Heyo::Uint32 red = 0x00;
	// LOOP
	while (quit == false) {

		graphics.drawPixel(x, y, red, 150, 150);
		
		red += .42;
		red %= 255;
		graphics.update();
		graphics.update(texture);
		graphics.render();

		if (Heyo::processEvent(events)) {
			if (events.quit())
				quit = true;

			if (events.type() == Heyo::Event::types::KEYDOWN)
			{
				if (events.keyPressed() == Heyo::Event::keys::K_SPACE)
					red = 0xfe;
				if (events.keyPressed() == Heyo::Event::keys::K_w)
					y -= 1;
				if (events.keyPressed() == Heyo::Event::keys::K_s)
					y += 1;
				if (events.keyPressed() == Heyo::Event::keys::K_a)
					x -= 1;
				if (events.keyPressed() == Heyo::Event::keys::K_d)
					x += 1;
			}

			if (events.type() == Heyo::Event::types::KEYUP) {
				if (events.keyPressed() == Heyo::Event::keys::K_SPACE)
					red = 0x00;
			}
		}


	}

	return 0;
}