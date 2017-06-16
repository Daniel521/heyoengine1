#include "h_Graphics.h"
#include "h_Sprite.h"

namespace Heyo {

	Graphics::Graphics() : SCREEN_WIDTH(600), SCREEN_HEIGHT(400)
	{
		if (!Init())
		{
			SDL_Log("Failed to Initiate Heyo Engine.");
			Close();
		}
	}

	Graphics::Graphics(int width, int height, std::string title) : SCREEN_WIDTH(width), SCREEN_HEIGHT(height), m_title(title)
	{
		if (!Init())
		{
			SDL_Log("Failed to Initiate Heyo Engine.");
			Close();
		}
	}


	Graphics::~Graphics()
	{
		Close();
		
	}

	void Graphics::clear()
	{
		SDL_RenderClear(m_renderer);
	}

	// Heyo
	void Graphics::update()
	{
		SDL_UpdateTexture(m_texture, NULL, buffer1, SCREEN_WIDTH * sizeof(Uint32));
		SDL_RenderClear(m_renderer);
		SDL_RenderCopy(m_renderer, m_texture, NULL, NULL);
		//SDL_RenderPresent(m_renderer);
	}

	void Graphics::update(Sprite & p_sprite, Rect & destin)
	{
		SDL_RenderCopy(m_renderer, p_sprite.m_image.m_texture, &p_sprite.getcurRect(), &destin);  
	}
	

	void Graphics::render()
	{
		SDL_RenderPresent(m_renderer);
	}

	void Graphics::drawPixel(int x, int y, Uint8 r, Uint8 g, Uint8 b)
	{
		if (x < 0 || x >= SCREEN_WIDTH || y < 0 || y >= SCREEN_HEIGHT)
			return;

		Uint32 color = 0;

		color += r;
		color <<= 8;
		color += g;
		color <<= 8;
		color += b;
		color <<= 8;
		color += 0xFF;

		buffer1[(y * SCREEN_WIDTH) + x] = color;

	}

	bool Graphics::Init()
	{

		std::string blah = m_title;
		// Make Window
		m_window = SDL_CreateWindow(
			(char*)m_title.c_str(),
			SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED,
			SCREEN_WIDTH,
			SCREEN_HEIGHT,
			SDL_WindowFlags::SDL_WINDOW_SHOWN
		);

		if (!m_window)
		{
			SDL_Log("Window failed to create: %s", SDL_GetError());
			return false;
		}
		else
		{
			// Get window surface
			m_winSurface = SDL_GetWindowSurface(m_window);
		}

		// Make Renderer
		m_renderer = SDL_CreateRenderer(
			m_window,
			-1,
			SDL_RendererFlags::SDL_RENDERER_PRESENTVSYNC
		);

		if (!m_renderer)
		{
			SDL_Log("Renderer failed to create: %s", SDL_GetError());
			return false;
		}

		// Make Texture
		m_texture = SDL_CreateTexture(
			m_renderer,
			SDL_PIXELFORMAT_RGBA8888,
			SDL_TextureAccess::SDL_TEXTUREACCESS_STREAMING,
			SCREEN_WIDTH,
			SCREEN_HEIGHT
		);

		if (!m_texture)
		{
			SDL_Log("Renderer failed to create: %s", SDL_GetError());
			return false;
		}

		// buffer1
		buffer1 = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];
		memset(buffer1, 0, sizeof(Uint32) * SCREEN_WIDTH * SCREEN_HEIGHT);

		return true;

	}

	void Graphics::Close()
	{
		if (m_window)
			SDL_DestroyWindow(m_window);

		if (m_renderer)
			SDL_DestroyRenderer(m_renderer);

		if (m_texture)
			SDL_DestroyTexture(m_texture);

		if (m_winSurface)
			SDL_FreeSurface(m_winSurface);

		if (buffer1)
			delete[] buffer1;
	}

}