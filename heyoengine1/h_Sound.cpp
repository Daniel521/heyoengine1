#include "h_Sound.h"
#include <SDL.h>

namespace Heyo {

	void playSound(Sound & sound)
	{
		Mix_PlayChannel(-1, sound.m_chunk, 0);
	}

	Sound::Sound() : m_chunk(NULL)
	{
	}

	Sound::~Sound()
	{
		if (m_chunk != NULL)
			Mix_FreeChunk(m_chunk);
	}

	bool Sound::loadSound(std::string soundAddress)
	{
		m_chunk = Mix_LoadWAV(soundAddress.c_str());
		if (m_chunk == NULL)
		{
			SDL_Log("Failed to load %s.\n", soundAddress);
			return false;
		}
	}

}