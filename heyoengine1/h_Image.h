#pragma once

#include <SDL.h>
#include <string>
//#include "h_Graphics.h"


namespace Heyo {
	
	class Graphics;

	typedef SDL_Rect Rect;
	typedef SDL_Point Point;
	typedef SDL_Point Coord;

	// Image class, used to load images into Heyo engine, includes a few tools to manipulate the image.
	class Image
	{
	public:
		enum type {
			UNKNOWN = 0,
			BMP = 1,
			PNG = 2
		};

	private:
		SDL_Surface * m_surface;
		SDL_Texture * m_texture;
		int m_imgtype;
		int m_width;
		int m_height;

	private:
		void clear();

	public:
		Image();
		~Image();
		bool loadImage(std::string imgAddress, Graphics & graphics);
		const int & getWidth();
		const int & getHeight();
		// Changes how percentage of a color on an image
		void setColorPercent(Uint8 red = 100, Uint8 green = 100, Uint8 blue = 100);


		friend class Sprite;
		friend class Graphics;
	};

}