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
	public:
		Sound();
		~Sound();

		bool loadSound(std::string soundAddress);

		friend void playSound(Sound & sound);
	};

	class Music
	{

	};

}