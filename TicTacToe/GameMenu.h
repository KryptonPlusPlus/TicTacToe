// GameMenu.h
//
#pragma once

// ----- Início das Inclusões das Bibliotecas -----

#include <string>    // to_string()       -> Converter int para string
#include "keyboard/Utils/Utils.h"

// Parte do codigo para Windows
#ifdef _WIN32 
#include <conio.h>   // _getch()          -> Pegar a tecla digitada 

#endif // end if _WIN32 || WIN23


// Parte do codigo para Linux
#ifdef __linux__ 

#error

#endif // end if __linux__ || LINUX

//  ----- Fim das Inclusões das Bibliotecas -----

using namespace std;

class GameMenu
{
	// ================================================= Parte privada da classe =================================================
	private:

		// Array com todas as possibilidades de teclas de entrada
		char key[4]{ key_arrow_up, key_arrow_down, key_enter, 'x'};

		// --- Variáveis de controle ---
		
		int char_control = 0;
		bool init_jogar = 0;

		enum class SelectionBox{Jogar, Historico, Reset, Instrucoes, Sair};
		SelectionBox selection_box = SelectionBox::Jogar;

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

		// --- gets ---
		int  getCharControl()  { return char_control;       }
		int  getSelectionBox() { return (int)selection_box; }
		bool getInitJogar()    { return init_jogar;         }

		// --- sets ---
		void setInitJogar(bool valuer) {init_jogar = valuer; }
};

