// GameMenu.cpp
//

#include "GameMenu.h"

// Layout

// Jogo da Velha [Vers�o 1.1.0]
//
// Vit�rias do Jogador 1 -
// Vit�rias do Jogador 2 -
//
// Tempo Total Jogado -
//
// [X] Jogar
// [ ] Hist�rico das Ultimas Partidas
// [ ] Reset
// [ ] Instru��es
// [ ] Sair
//
// Aperte Enter para escolher uma das op��es

void GameMenu::setup()
{
	printf(ESC"[?25l"); // Desativa o cursor
}

string GameMenu::draw()
{
	string StringDraw = "";

	StringDraw += "Jogo da Velha [Versao 1.1.0]\n\n";

	StringDraw += "Vitorias do Jogador 1 - " + "\n"s;
	StringDraw += "Vitorias do Jogador 2 - " + "\n"s;

	StringDraw += "\nTempo Total Jogado - " + "\n\n"s;

	StringDraw += "["s + ((selection_box == SelectionBox::Jogar)      ? 'X' : ' ') + "]"s + " Jogar\n";
	StringDraw += "["s + ((selection_box == SelectionBox::Historico)  ? 'X' : ' ') + "]"s + " Historico das Ultimas Partidas\n";
	StringDraw += "["s + ((selection_box == SelectionBox::Reset)      ? 'X' : ' ') + "]"s + " Reset\n"; 
	StringDraw += "["s + ((selection_box == SelectionBox::Instrucoes) ? 'X' : ' ') + "]"s + " Instrucoes\n";
	StringDraw += "["s + ((selection_box == SelectionBox::Sair)       ? 'X' : ' ') + "]"s + " Sair\n";

	StringDraw += "\nAperte Enter para escolher uma das opcoes";

	return StringDraw;
}

void GameMenu::input()
{
	char_control = _getch();

	//   Verifica se foi digitado uma seta, pois ela gera duas entradas, caso tenha sido a seta
	// comum retorna 224 mais o valor da seta e se for a seta do teclado numero retorna 0 mais 
	// o valor da seta
	if (char_control == 224 || char_control == 0)
	{
		char_control = _getch();
	}

	
	//                ---< N�o necess�rio >---
	// Verifica��o de se o caracter digitado � valido
	//	for (int i = 0; i < sizeof(key) / sizeof(key[0]); i++)
	//	{
	//		if (char_control == key[i])
	//      {
	//			break;
	//		}
	//  }
	
}

void GameMenu::logic()
{
	switch (char_control)
	{
		case key_arrow_up:

			selection_box = (SelectionBox)((int)selection_box - 1);

			if (selection_box < SelectionBox::Jogar)
			{
				selection_box = SelectionBox::Sair;
			}
			break;
		case key_arrow_down:

			selection_box = (SelectionBox)((int)selection_box + 1);

			if (selection_box > SelectionBox::Sair)
			{
				selection_box = SelectionBox::Jogar;
			}
			break;
		case key_enter:

			switch (selection_box)
			{
				case SelectionBox::Jogar:

					init_jogar = 1;
					break;
				case SelectionBox::Historico:

					break;
				case SelectionBox::Reset:

					break;

				case SelectionBox::Instrucoes:

					break;
				case SelectionBox::Sair:

					exit(0);
					break;

				default:
					init_jogar = 0;
					break;
			}
			break;
		default:
			// Caso n�o tenha digitado um caracter valido
			break;
	}
}
