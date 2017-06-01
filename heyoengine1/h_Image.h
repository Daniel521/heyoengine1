#pragma once

#include "h_Graphics.h"
#include <SDL.h>
#include <string>

namespace Heyo {

	typedef SDL_Rect Rect;
	typedef SDL_Point Point;
	typedef SDL_Point Coord;

	class Texture
	{
	private:
		SDL_Surface * img_surface;
		SDL_Texture * img_texture;
		int m_width;
		int m_height;
		Heyo::Rect img_Rect;
		int frameCount;
		int frame;
		int frameDivider;
	public:
		bool loadTexture(std::string imgAddress, Graphics & graphics);
		void clear();
		int getWidth();
		int getHeight();
		Rect getRect();
		bool setRect(Rect clip); // $BOOBS: Change the para to Rect & clip, to save space

		Texture();
		~Texture();

		friend class Graphics;
	private:

	};

}