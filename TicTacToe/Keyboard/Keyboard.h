// Keyboard.h
//

#pragma once

// ----- Início das Inclusões das Bibliotecas -----

#include "Utils/VetorPlus.h"
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

		VetorPlus<Keycaps> keyboard;

		std::string *__keyboard__ = nullptr;

		int _height = 0;

	// ================================================= Parte publica da classe =================================================
	public:

		enum class TypeKeyboard : short { _NULL_ = 0, ABNT_2 };

		Keyboard(int _height, TypeKeyboard type_keyboard = TypeKeyboard::_NULL_);
		virtual ~Keyboard();

		std::string* stringKeyboard();

		void createLine(int columns);
		void createKeycaps(int line, int colum, int _width);
		// createKeycaps com stringInCenterKeycaps() e setColorKeycaps()
		void createKeycaps(int line, int colum, int _width, const char* _string_, ColorForeground color = ColorForeground::white);
		// createKeycaps com charInCenterKeycaps() e setColorKeycaps()
		void createKeycaps(int line, int colum, int _width, char key, ColorForeground color = ColorForeground::white);

		void charInCenterKeycaps(int line, int colum, char key);
		void stringInCenterKeycaps(int line, int colum, const char* _string_);
		void stringInCenterToRightKeycaps(int line, int colum, const char* _string_);

		// --- gets ---
		std::string* getKeycaps(int line, int colum) { return keyboard.getPosArray(line, colum).keycaps->getDrawRectangle(); };
		int getHeight() { return _height; };
		int getLines() { return keyboard.getLines(); }

		// --- sets ---
		void setColorKeycaps(int line, int colum, ColorForeground color);


};