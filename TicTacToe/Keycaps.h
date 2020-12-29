#pragma once

#include "CharRectangle.h"

class Keycaps
{
	private:
		CharRectangle keycaps = 0;

		int line    = 0;
		int colum = 0;

	public:
		Keycaps() {};

		//    void charInCenter(char _char);
		//void stringInCenter(const char* _string);
		//void stringInCenterAligneToRight(const char* _string);

		// --- gets ---
		std::string* getKeycaps() { return keycaps.getCharRectangle(); }
		int getLine()  { return line;  }
		int getColum() { return colum; }

		// --- sets ---
		void createCharRectangle(int _width, int _height);
		void setLine(int line);
		void setColum(int colum);


};