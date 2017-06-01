#include "h_Image.h"
#include <SDL_image.h>

namespace Heyo {

	bool Texture::loadTexture(std::string imgAddress, Graphics & graphics)
	{
		clear();

		// Load image at specified path
		SDL_Surface * loadedSurface = IMG_Load(imgAddress.c_str());
		if (loadedSurface == NULL) {
			SDL_Log("Unable to load image %s! SDL_image error: %s\n", imgAddress.c_str(), IMG_GetError());
			return false;
		}
		else {
			// Convert surface to screen format
			img_surface = SDL_ConvertSurface(loadedSurface, graphics.m_winSurface->format, NULL);
			SDL_SetColorKey(img_surface, SDL_TRUE, SDL_MapRGB(img_surface->format, 0, 0xFF, 0xFF));
			// Convert surface to texture
			img_texture = SDL_CreateTextureFromSurface(graphics.m_renderer, img_surface);

			// Misc information
			m_width = img_surface->w;
			m_height = img_surface->h;
			img_Rect.h = m_height;
			img_Rect.w = m_width;
			img_Rect.x = 0;
			img_Rect.y = 0;
			frameCount = 0;
			frame = 0;
			frameDivider = 0;

			// Get rid of old loaded surfaces
			SDL_FreeSurface(loadedSurface);

			return true;
		}
	}

	void Texture::clear()
	{
		if (img_surface != NULL) {
			SDL_FreeSurface(img_surface);
			img_surface = NULL;
		}
		if (img_texture != NULL) {
			SDL_DestroyTexture(img_texture);
			img_texture = NULL;
		}
		m_width = 0;
		m_height = 0;
		img_Rect.h = 0;
		img_Rect.w = 0;
		img_Rect.x = 0;
		img_Rect.y = 0;
		frameCount = 0;
		frame = 0;
		frameDivider = 0;
	}

	int Texture::getWidth()
	{
		return m_width;
	}

	int Texture::getHeight()
	{
		return m_height;
	}

	Rect Texture::getRect()
	{
		return img_Rect;
	}

	bool Texture::setRect(Rect clip)
	{
		if (clip.h > m_height || clip.w > m_width) {
			SDL_Log("Texture error: Passed Rect in setRect is out of bound.\n");
			return false;
		}

		img_Rect = clip;
		return true;
		
	}

	Texture::Texture()
	{
		// Initialize PNG loading
		clear();
		int imgFlags = IMG_INIT_PNG;
		if (!(IMG_Init(imgFlags) & imgFlags)) {
			SDL_Log("SDL_image could not initialize! SDL_image error: %s\n", IMG_GetError());
		}
	}


	Texture::~Texture()
	{
		clear();
	}

}