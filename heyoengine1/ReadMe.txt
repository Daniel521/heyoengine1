Heyo Game Engine

Daniel Verdugo
- 2017

Changes to be done:
1. Want to make Graphics' pixels not cover the whole screen if put up front, i only want the pixels themselves to be shown, not the black background as well
2. Add sound
3. Change up the textures class (Image.h) to be able to show animated sprites.
4. Add more support to different type of images, not only png in the textures class








#include "h_Graphics.h"
#include "h_Event.h"
#include "h_Sprite.h"
#include <SDL.h>
#include <iostream>

//using namespace Heyo;
using namespace std;


int main(int argc, char * argv[]) {
	Heyo::Graphics graphics(900, 650, "Heyo");
	Heyo::Sprite blah;
	Heyo::Sprite sprite;
	Heyo::Sprite title;
	Heyo::Sprite heyo;
	blah.loadSprite("blah.png", graphics, 1018, 642);
	if (sprite.loadSprite("Greg.png", graphics, 32, 32, 7, 1) == false)
		cout << "Damn!" << endl;
	if (title.loadSprite("gregtheflower.png", graphics, 85, 10, 1, 1) == false)
		cout << "Damn!" << endl;
	if (heyo.loadSprite("HeyoEngine.png", graphics, 97, 24, 1, 1) == false)
		cout << "Damn!" << endl;

	Heyo::Rect spriteR = { 350,200,200,200 };
	Heyo::Rect titleR = { 200, 50, 500, 100 };
	Heyo::Rect heyoR = { 250, 500, 400, 100 };
	Heyo::Rect blahR = { 520, 290, 60, 35 };


	Heyo::Event events;




	bool quit = false;

	int divider = 12;
	int count = 0;
	int curFrame = 0;
	bool show = false;
	// LOOP
	while (quit == false) {
		graphics.clear();
		if (count % divider == 0)
			curFrame++;
		curFrame %= 6;
		count++;

		graphics.update(sprite[curFrame], spriteR);
		graphics.update(title[0], titleR);
		graphics.update(heyo[0], heyoR);
		if (show == true)
			graphics.update(blah, blahR);
		
		graphics.render();

		if (Heyo::processEvent(events)) {
			if (events.quit())
				quit = true;

			if (events.type() == Heyo::Event::types::KEYDOWN)
			{
				if (events.keyPressed() == Heyo::Event::keys::K_SPACE)
					show = true;
				if (events.keyPressed() == Heyo::Event::keys::K_w)
					;
				if (events.keyPressed() == Heyo::Event::keys::K_s)
					;
				if (events.keyPressed() == Heyo::Event::keys::K_a)
					;
				if (events.keyPressed() == Heyo::Event::keys::K_d)
					;
			}

			if (events.type() == Heyo::Event::types::KEYUP) {
				if (events.keyPressed() == Heyo::Event::keys::K_SPACE)
					show = false;
			}
		}


	}

	return 0;
}