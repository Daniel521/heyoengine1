#pragma once

/*
*	h_Sprite.h
*	- This is used to grab images and turn them into sprites. Animated if available.
*
*
*
*
*/

#include <SDL.h>
#include <string>
#include "h_Image.h"
//#include "h_Graphics.h"


namespace Heyo {

	class Graphics;
	class Image;

	typedef SDL_Rect Rect;
	typedef SDL_Point Point;
	typedef SDL_Point Coord;

	class Sprite
	{
	private:
		Image m_image;
		Rect * m_rect;
		int m_numFrames;	// Total number of frames
	public:	// Delete this later
		int m_curFrame;		// Current frame count, 0 is first frame
		int m_spriteWidth;
		int m_spriteHeight;
	private:

	public:
		Sprite();
		~Sprite();

		// Loads the PNG and determines the number of sprites in the sprite sheet
		// imgAddress: the address of the img
		// graphics: graphics where you will use the sprite
		// indiWidth: width of each sprite
		// indiHeight: height of each sprite
		// numX: num of sprites along x-axis
		// numY: num of sprites along y-axis
		bool loadSprite(std::string imgAddress, Graphics & graphics, int indiWidth, int indiHeight, int numX = 1, int numY = 1);
		// returns sprite sheet's total width
		int getTotalWidth();
		// returns sprite sheet's total height
		int getTotalHeight();
		// returns a Rect of the current frame
		Rect *  getcurRect();
		// changes the current frame, 0 is first frame
		Sprite operator[](int val);// $BOOBS: Change the para to Rect & clip, to save space
		// returns the amount of frames in sheet
		int totalFrames();

		friend class Graphics;
	};

}