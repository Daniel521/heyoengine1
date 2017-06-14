#include "h_Image.h"
#include "h_Graphics.h"
#include <SDL_image.h>

namespace Heyo {

	Image::Image() : m_surface(NULL), m_texture(NULL), m_width(0), m_height(0), m_imgtype(0) // Done?
	{
	}

	Image::~Image()	// Done?
	{
		clear();
	}

	void Image::clear()	// Done?
	{
		if (m_surface != NULL) {
			SDL_FreeSurface(m_surface);
			m_surface = NULL;
		}
		if (m_texture != NULL) {
			SDL_DestroyTexture(m_texture);
			m_texture = NULL;
		}
		m_width = 0;
		m_height = 0;
	}

	bool Image::loadImage(std::string imgAddress, Graphics & graphics)
	{
		if (m_surface != NULL)
			clear();

		// Load image at specified path
		SDL_Surface * loadedSurface = IMG_Load(imgAddress.c_str());
		if (loadedSurface == NULL) {
			SDL_Log("Unable to load image %s! SDL_image error: %s\n", imgAddress.c_str(), IMG_GetError());
			return false;
		}
		else {
			// Convert surface to screen format
			m_surface = SDL_ConvertSurface(loadedSurface, graphics.m_winSurface->format, NULL);
			// Get rid of old loaded surfaces
			SDL_FreeSurface(loadedSurface);
			SDL_SetColorKey(m_surface, SDL_TRUE, SDL_MapRGB(m_surface->format, 0, 0xFF, 0xFF));

			// Convert surface to texture
			m_texture = SDL_CreateTextureFromSurface(graphics.m_renderer, m_surface);

			// Misc information
			m_width = m_surface->w;
			m_height = m_surface->h;

			return true;
		}
	}

	const int & Image::getWidth()
	{
		return m_width;
	}

	const int & Image::getHeight()
	{
		return m_height;
	}

	void Image::setColorPercent(Uint8 red, Uint8 green, Uint8 blue)
	{
		red = (red/100.0f) * 255;
		green = (green / 100.0f) * 255;
		blue = (blue / 100.0f) * 255;

		SDL_SetTextureColorMod(m_texture, red, green, blue);
	}

}