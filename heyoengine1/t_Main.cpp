#include "h_Graphics.h"
#include <SDL.h>
#include <iostream>

//using namespace Heyo;
using namespace std;

int main(int argc, char * argv[]) {
	Heyo::Graphics graphics(900, 650, "Heyo");

	graphics.drawPixel(10, 10);
	graphics.Update();
	getchar();
	return 0;
}