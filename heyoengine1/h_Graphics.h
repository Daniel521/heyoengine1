#pragma once
#include <SDL.h>
#include <string>

namespace Heyo {

	class Graphics
	{
	public:
		const int SCREEN_WIDTH;
		const int SCREEN_HEIGHT;
		const std::string m_title;

	private:
		SDL_Window * m_window;
		SDL_Renderer * m_renderer;
		SDL_Texture * m_texture;

		Uint32 * buffer1;

	public:
		Graphics();
		Graphics(int width, int height, std::string title);
		~Graphics();

		void Update();

		void drawPixel(int x, int y, Uint8 r = 0xFF, Uint8 g = 0xFF, Uint8 b = 0xFF);

	private:
		bool Init();
		void Close();

	};

}