#pragma once

#include <SDL.h>
#include <string>
//#include "h_Graphics.h"


namespace Heyo {
	
	class Graphics;

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
		SDL_Rect img_Rect;
		int frameCount;
		int frame;
		int frameDivider;
	public:
		bool loadTexture(std::string imgAddress, Graphics & graphics);
		void clear();
		int getWidth();
		int getHeight();
		SDL_Rect getRect();
		bool setRect(Rect clip); // $BOOBS: Change the para to Rect & clip, to save space

		Texture();
		~Texture();

		friend class Graphics;
	private:

	};

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
		bool loadImage(std::string imgAddress, int imgType, Graphics & graphics);

		friend class Sprite;
		friend class Graphics;
	};

}