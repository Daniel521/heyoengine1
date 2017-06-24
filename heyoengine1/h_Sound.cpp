#include "h_Sound.h"
#include <SDL.h>
#include <iostream>
using namespace std;

namespace Heyo {

	Sound::Sound() : m_chunk(NULL), m_channel(-1)
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
		Mix_Volume(m_channel, volume);
	}

	void Sound::play(int millisecs)
	{
		if (m_channel != -1)
			Mix_HaltChannel(m_channel);
		m_channel = Mix_FadeInChannel(m_channel, m_chunk, 0, millisecs);
	}

	void Sound::stop()
	{
		Mix_HaltChannel(m_channel);
	}

	Sound & Sound::operator=(const Sound & sound)
	{
		m_channel = -1;
		m_chunk = sound.m_chunk;
		m_volume = 128;

		return *this;
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

	void Music::stop()
	{
		Mix_HaltMusic();
	}

	void Music::setVolume(Uint8 volume)
	{
		volume = (volume * 128) / 100;
		m_volume = volume;
		Mix_VolumeMusic(volume);
	}

	void Music::play()
	{
		Mix_PlayMusic(m_music, 0);
	}

}