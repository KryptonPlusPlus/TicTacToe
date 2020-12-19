// GameMenu.h
//
#pragma once

#include <string>    // to_string()       -> Converter int para string

// Parte do codigo para Windows
#ifdef _WIN32 || WIN32
#include <conio.h>   // _getch()          -> Pegar a tecla digitada 

#endif // end if _WIN32 || WIN23


// Parte do codigo para Linux
#ifdef __linux__ || LINUX

#error

#endif // end if __linux__ || LINUX

#define ESC "\033"

// Layout do jogo

using namespace std;

class GameMenu
{
	// ================================================= Parte privada da classe =================================================
	private:
	
		
	// ================================================= Parte publica da classe =================================================
	public:
		// --- contructor & destructor ---
		GameMenu() {};
		virtual ~GameMenu() {};

		// --- Definição das funções publicas ---
		void setup();
		string draw();
		void input();
		void logic();
};

