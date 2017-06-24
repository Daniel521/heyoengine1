#pragma once
#include <SDL_mixer.h>
#include <iostream>

namespace Heyo {

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

		// Plays the sound from the start
		// int millisec : how many seconds to fade in
		void play(int millisecs = 0);

		void pause() { Mix_Pause(m_channel); }
		
		void resume() { Mix_Resume(m_channel); }

		void stop();

		bool playing() { return Mix_Playing(m_channel); }

		Sound & operator=(const Sound & sound);

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

		void stop();

		// Sets music's volume
		// From a value of 0-100,
		// default value is 100
		void setVolume(Uint8 volume = 100);

		void play();

		void pause() { Mix_PauseMusic(); }

		void resume() { Mix_ResumeMusic(); }

		// Returns volume
		Uint8 getVolume() { return m_volume; }
	};

}