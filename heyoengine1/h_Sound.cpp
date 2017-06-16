#include "h_Sound.h"
#include <SDL.h>

namespace Heyo {

	void playSound(Sound & sound)
	{
		sound.m_channel = Mix_PlayChannel(-1, sound.m_chunk, 0);
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

	void Sound::setVolume(Uint8 volume)
	{
		volume = (volume * 128) / 100;
		m_volume = volume;
		Mix_VolumeChunk(m_chunk, volume);
	}

	Music::Music() : m_music(NULL), m_volume(100)
	{
	}

	Music::~Music()
	{
		if (m_music != NULL)
			Mix_FreeMusic(m_music);
	}

	bool Music::loadMusic(std::string musicAddress)
	{
		m_music = Mix_LoadMUS(musicAddress.c_str());
		if (m_music == NULL)
		{
			SDL_Log("Failed to load %s.\n", musicAddress);
			return false;
		}
	}

	bool Music::playing()
	{
		return Mix_PlayingMusic();
	}

	void Music::end()
	{
		Mix_HaltMusic();
	}

	void Music::setVolume(Uint8 volume)
	{
		volume = (volume * 128) / 100;
		m_volume = volume;
		Mix_VolumeMusic(volume);
	}

	void Music::start()
	{
		Mix_PlayMusic(m_music, 0);
	}

}