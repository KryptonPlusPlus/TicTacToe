// Jogo da velha 1.1.0
#include <iostream> // cout -> Para escrever no terminal

#include "GameMenu.h"
#include "_TicTacToe.h"

using namespace std;

void initGame();

int main()
{
    GameMenu menuGame = GameMenu();   

    while (menuGame.getCharControl() != 'x')
    {
        system("cls");
        menuGame.setup();

        cout << menuGame.draw();
        menuGame.input();
        menuGame.logic();

        if (menuGame.getInitJogar())
        {
            initGame();
            system("pause");

            menuGame = GameMenu();
        }
    }

    // Fim...
    system("cls");
    cout << "Obrigado por Jogar, volte sempre.\n";

    system("pause");

    return 0;
} // --- end main ---

// Função para começar o jogo
void initGame()
{
    _TicTacToe game = _TicTacToe();
    game.setup();

    while (game.getCharControl() != 'x')
    {
        system("cls");

        cout << game.draw();

        if (game.getWinGame())
            break;
        game.input();
        if (game.getTestKey())
            game.logic();
    }
    game.endGame();

    cout << "\nTempo decorrido: " << game.getTempInGame() << " segundos.\n";
}