// Keyboard.h
//

#pragma once

// ----- Início das Inclusões das Bibliotecas -----

#include "Keycaps.h"

// Parte do codigo para Windows
#ifdef _WIN32 

#endif // end if _WIN32 || WIN23


// Parte do codigo para Linux
#ifdef __linux__ 

#error

#endif // end if __linux__ || LINUX

//  ----- Fim das Inclusões das Bibliotecas -----

class Keyboard
{
	// ================================================= Parte privada da classe =================================================
	private:

		int lines                   = 0;

		int *columns_each_rows      = 0;
		int* last_columns_each_rows = 0;

		int data = 0;

		Keycaps* keyboard = 0;
		Keycaps* last_keyboard = 0;

	// ================================================= Parte publica da classe =================================================
	public:

		Keyboard();
		virtual ~Keyboard()  {}

		void createLine(int columns);
		void createKey(int line, int columns, const int _width, const int _height);


	    // --- gets ---
		int getLines()                 { return lines;                    }
		int getColumnsInRow(int lines) { return columns_each_rows[lines]; }
		std::string* getKeycaps(int line, int colum) { return keyboard[((line * columns_each_rows[line]) + colum)].getKeycaps(); }

};