// Jogo da velha 1.1.0
#include <iostream> // cout -> Para escrever no terminal

#include "GameMenu.h"
#include "_TicTacToe.h"

using namespace std;

int main()
{
    GameMenu menuGame = GameMenu();
    _TicTacToe game = _TicTacToe();

    cout << menuGame.draw();

    system("pause");

    game.setup();

    while (game.getCharControl() != 'x')
    {
        system("cls");

        cout << game.draw();

        if (game.getWinGame())
            break;
        game.input();
        if (!game.getTestKey())
            game.logic();
    }
    game.endGame();
    
    cout << "\n\nTempo decorrido: " << game.getTempInGame() << " segundos.";

    // Fim...
    cout << "\n\n";

    system("pause");
    system("cls");
    
    return 0;
} // --- end main ---