// Jogo da velha 1.1.0
#include <iostream> // cout -> Para escrever no terminal

#include "GameMenu.h"
#include "_TicTacToe.h"
#include "CharRectangle.h"
#include "Keyboard.h"
#include "Utils.h"

using namespace std;

void initGame();

int main()
{
    system("pause");

    GameMenu menuGame = GameMenu();   
    Keyboard a = Keyboard();

    a.createLine(2);
    a.createLine(2);
    a.createLine(2);
    
    a.createKey(0, 0, 3, 5);
    a.createKey(0, 1, 10, 5);
    a.createKey(1, 1, 4, 6);

    std::string *oi = a.getKeycaps(0, 0);
    std::string *oai = a.getKeycaps(0, 1);
    std::string *oaai = a.getKeycaps(1, 1);

    for (int i = 0; i < 3; i++)
    {
        cout << oi[i] << "\n";
    }
    for (int i = 0; i < 3; i++)
    {
        cout << oai[i] << "\n";
    }
    for (int i = 0; i < 3; i++)
    {
        cout << oaai[i] << "\n";
    }
    
    system("pause");
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