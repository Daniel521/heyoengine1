#include "h_Sprite.h"
#include "iostream"
using namespace std;

namespace Heyo {

	Sprite::Sprite() : m_rect(NULL), m_numFrames(0), m_curFrame(0), m_spriteWidth(0), m_spriteHeight(0)
	{
		// Heyo
	}

	Sprite::~Sprite()
	{
		if (m_rect != NULL)
			delete[] m_rect;
		// Bye
	}

	bool Sprite::loadSprite(std::string imgAddress, Graphics & graphics, int indiWidth, int indiHeight, int numX, int numY)
	{
		// Step 1: load image
		if (m_image.loadImage(imgAddress, 2, graphics) == false) {
			SDL_Log("%s image did not load.\n");
			return false;
		}

		// Step 2: initilize all the member variables
		m_spriteWidth = indiWidth;
		m_spriteHeight = indiHeight;
		m_numFrames = numX * numY;
		m_rect = new Rect[m_numFrames];

		// Step 3: Fill every rect
		// 1) Every rect will have the same h and w;
		for (int i = 0; i < m_numFrames; i++) {
			m_rect[i].h = indiHeight;
			m_rect[i].w = indiWidth;
		}
		// 2) Now some math to determine position
		int curFrame = 0;
		int yStartPos = 0;
		for (int y = 0; y < numY; y++) {
			int xStartPos = 0;
			for (int x = 0; x < numX; x++) {
				m_rect[curFrame].x = xStartPos;
				m_rect[curFrame].y = yStartPos;
				xStartPos += indiWidth + 1;
			}
			yStartPos += indiHeight + 1;
		}
		return true;
	}


	Rect * Sprite::getcurRect()
	{
		return &m_rect[m_curFrame];
	}

	Sprite Sprite::operator[](int val)
	{
		if (val < 4)
			m_curFrame = val;
		if (val >= 4)
			cout << "Que" << endl;
		return *this;
	}


}