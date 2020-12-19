// _TicTacToe.h
//
#pragma once

#include <iostream>

// Parte do codigo para Windows
#ifdef _WIN32 || WIN32
#include <conio.h>   // Biblioteca para usar _getch
#include <string>

#endif // end if _WIN32 || WIN23


// Parte do codigo para Linux
#ifdef __linux__ || LINUX

#error
#include <string>
#endif // end if __linux__ || LINUX

using namespace std;

#define _player ( player ? 'X' : 'O' )

#define ESC "\033"

class _TicTacToe
{
	// ================================================= Parte privada da classe =================================================
	private:
		// Matriz do tabuleiro
		char game_board[3][3]{{'7','8','9'},
							  {'4','5','6'},
							  {'1','2','3'}};

		// Matriz do tabuleiro do jogo (exibido na tela)
		char print_game_board[3][3]{{' ',' ',' '},
									{' ',' ',' '},
									{' ',' ',' '}};

		// Array com todas as possibilidades de teclas de entrada
		char key[11]{ 'x','1','2','3','4','5','6','7','8','9','p' };

		// --- Variáveis de controle do jogo ---

		bool player = 0;      // Define a vez dos jogadores
		bool winGame = 0;     // Define quando o jogo acaba com vitória
		bool controlErr = 0;  // Quando ocorre algum erro
		bool testkey = 0;     // Verifição para caso tenha sido inserido uma tecla invalida (teclas validas em key[]) 
		bool showMask = 0;    // Define se ativa ou desativa a mascara
		int  char_control;    // Guarda a tecla digitada
		int  num_valid_plays; // Numero de jogadas invalidas, para definir quando acaba o jogo e gera o empate

		// --- Variáveis adicionais do jogo ---

		// --- Definição das funções privadas ---
		string verificControlGame();

	// ================================================= Parte publica da classe =================================================
	public:

		// --- Definição das funções publicas ---
		void setup();
		string draw();
		void input();
		void logic();

		// -- gets --
		bool getPlayer()        { return player;          }
		bool getWinGame()       { return winGame;         }
		bool getControlErr()    { return controlErr;      }
		bool getTestKey()       { return testkey;         }
		bool getShowMask()      { return showMask;        }
		int  getCharControl()   { return char_control;    }
		int  getNumValidPlays() { return num_valid_plays; }

		// -- sets --
		void setControlErr(bool controlErr) 
		{
			this->controlErr = controlErr; 
		}
};
