#pragma once
#include <SDL_mixer.h>
#include <iostream>

namespace Heyo {

	class Sound;
	class Music;

	void playSound(Sound & sound);

	class Sound
	{
	private:
		Mix_Chunk * m_chunk;
		int m_channel;
		Uint8 m_volume;
	public:
		Sound();
		~Sound();

		bool loadSound(std::string soundAddress);

		void setVolume(Uint8 volume = 100);

		friend void playSound(Sound & sound);
	};

	class Music
	{
	private:
		Mix_Music * m_music;
		Uint8 m_volume;

	public:
		Music();
		~Music();

		bool loadMusic(std::string musicAddress);

		bool playing();

		void end();

		// Sets music's volume
		// From a value of 0-100,
		// default value is 100
		void setVolume(Uint8 volume = 100);

		void start();

		void pause() { Mix_PauseMusic(); }

		void resume() { Mix_ResumeMusic(); }

		// Returns volume
		Uint8 getVolume() { return m_volume; }
	};

}