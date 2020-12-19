// Jogo da velha 1.1.0
#include <iostream> // cout              -> Para escrever no terminal
#include <time.h>   // clock_t e clock() -> Para calcular o tempo de jogo

#include "_TicTacToe.h"
_TicTacToe game;

using namespace std;

int main()
{
    clock_t start, end;
    start = clock();

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

    end = clock();

    cout << "\n\nTempo decorrido: " << ((double)((double)end - (double)start) / ((double)(CLOCKS_PER_SEC))) << " segundos.";

    // Fim...
    cout << "\n\n";

    system("pause");
    system("cls");
    
    return 0;
} // --- end main ---