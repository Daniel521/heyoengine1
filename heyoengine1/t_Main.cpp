#include "h_Graphics.h"
#include "h_Event.h"
#include "h_Sprite.h"
#include <SDL.h>
#include <iostream>

//using namespace Heyo;
using namespace std;
// Ideas on the root of the problem?
// the upate function is taking in the wrong rect
// I did the rect array wrong in the sprite class
// the rects... it's most likely the rects.
// try removing the whole operator overload thingy and just add a switch function. if that works just add the switch function in the operator[]
// Get some sleep


int main(int argc, char * argv[]) {
	Heyo::Graphics graphics(900, 650, "Heyo");
	Heyo::Texture texture;
	Heyo::Sprite sprite;
	texture.loadTexture("blah.png", graphics);
	if (sprite.loadSprite("hi.png", graphics, 200, 200, 2, 2) == false)
		cout << "Damn!" << endl;

	Heyo::Event events;


	bool quit = false;

	int choice = 0;
	// LOOP
	while (quit == false) {


		graphics.update(texture);
		graphics.update(sprite);
		
		graphics.render();

		if (Heyo::processEvent(events)) {
			if (events.quit())
				quit = true;

			if (events.type() == Heyo::Event::types::KEYDOWN)
			{
				if (events.keyPressed() == Heyo::Event::keys::K_SPACE)
					sprite[1];
				if (events.keyPressed() == Heyo::Event::keys::K_w)
					choice = 0;
				if (events.keyPressed() == Heyo::Event::keys::K_s)
					choice = 1;
				if (events.keyPressed() == Heyo::Event::keys::K_a)
					choice = 2;
				if (events.keyPressed() == Heyo::Event::keys::K_d)
					choice = 3;
			}

			//if (events.type() == Heyo::Event::types::KEYUP) {
			//	if (events.keyPressed() == Heyo::Event::keys::K_SPACE)
			//		;
			//}
		}


	}

	return 0;
}