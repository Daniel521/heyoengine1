#pragma once

#include "h_Image.h"
#include <SDL.h>
#include <SDL_image.h>
#include <string>


namespace Heyo {

	class Sprite;

	typedef Uint32 Uint32;

	class Graphics
	{
	public:
		const int SCREEN_WIDTH;
		const int SCREEN_HEIGHT;
		const std::string m_title;

		friend class Texture;
		friend class Image;

	private:
		SDL_Window * m_window;
		SDL_Renderer * m_renderer;
		SDL_Texture * m_texture;
		SDL_Surface * m_winSurface;

		Uint32 * buffer1;

	public:
		Graphics();
		Graphics(int width, int height, std::string title);
		~Graphics();

		// Heyo
		// How's life?
		void update();
		void update(Texture & p_texture);
		void update(Sprite & p_sprite);
		//void update(Texture & p_texture, Coord clip);

		void render();

		void drawPixel(int x, int y, Uint8 r = 0xFF, Uint8 g = 0xFF, Uint8 b = 0xFF);

	private:
		bool Init();
		void Close();

	};

}