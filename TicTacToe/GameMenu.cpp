// GameMenu.cpp
//

#include "GameMenu.h"

// 				Jogo da Velha 1.1.0
//
// Vitórias do Jogador 1 -
// Vitórias do Jogador 2 -
//
// Tempo Total Jogado -
//
// [ ] Jogar
// [ ] Histórico das Ultimas Partidas
// [ ] Reset

void GameMenu::setup()
{
	printf(ESC"[?25l"); // Desativa o cursor
}

string GameMenu::draw()
{
	string StringDraw = "";

	StringDraw += "Jogo da Velha 1.1.0\n\n";
	StringDraw += "Vitorias do Jogador 1 - " + "\n"s;
	StringDraw += "Vitorias do Jogador 2 - " + "\n"s;

	StringDraw += "\nTempo Total Jogado - " + "\n\n"s;

	StringDraw += "[ ]"s + " Jogar\n";
	StringDraw += "[ ]"s + " Historico das Ultimas Partidas\n";
	StringDraw += "[ ]"s + " Reset\n";

	return StringDraw;
}

void GameMenu::input()
{

}

void GameMenu::logic()
{

}
