// Jogo da velha 1.1.0
#include <iostream>

#include "_TicTacToe.h"

using namespace std;

_TicTacToe game;

int main()
{
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

    // Fim...
    cout << "\n\n";

    system("pause");
    system("cls");
    
    return 0;
} // --- end main ---