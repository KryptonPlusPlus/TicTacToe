#include <conio.h>  // Biblioteca para usar _getch
#include <iostream>

using namespace std;

// --- Definição das funções no escopo ---
void setup();
void draw();
void input();
void logic();
void verificControlGame();


int char_control;     // Guarda a tecla digitada
int num_valid_plays;  // Numero de jogadas invalidas, para definir quando acaba o jogo e gera o empate

// Matriz do tabuleiro
char game_board[3][3]{{'7','8','9'},
                      {'4','5','6'},
                      {'1','2','3'}};

// Matriz do tabuleiro do jogo(exibido na tela)
char print_game_board[3][3]{{' ',' ',' '},
                            {' ',' ',' '},
                            {' ',' ',' '}};

// Array com todas as possibilidades de teclas de entrada
char key[]{'x','1','2','3','4','5','6','7','8','9','p'};

// --- Variáveis de controle ---
bool player = 0;
bool winGame = 0;
bool controlErr = 0;
bool testkey = 0;
bool showMask = 0;

#define _player ( player ? 'X' : 'O' )

int main()
{
    setup();

    while (char_control != 'x')
    {
        draw();
        if (winGame)
            break;
        input();
        if (!testkey)
            logic();
    }

    // Fim...
    cout << "\n\n";
    
    system("pause");
    system("cls");
    
    return 0;
} // --- end main ---

void setup()
{
    // --- ---
}

void draw()
{
    system("cls");

    cout << "TicTacToe 1.0  \n\n";

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << " " << ((!showMask) ? print_game_board[i][j] : game_board[i][j]);
            cout << ((j != 2) ? " |" : "");
        }
        cout << "\n" << ((i != 2) ? "---+---+---" : "") << "\n";
    }
    cout << "\nVez do jogador " << player + 1 << "\n";

    verificControlGame();
}

void input()
{
    testkey = 1;

    char_control = _getch();
    // Verificação de se o caracter digitado é valido
    for (int i = 0; i < sizeof(key) / sizeof(key[0]); i++)
    {
        if (char_control == key[i])
        {
            testkey = 0;
            break;
        }
    }
}

void logic()
{
    // Verificação para exibir a mascara
    if (char_control == 'p')
    {
        showMask = 1;
        return;
    }
    else
    {
        showMask = 0;
    }

    // Verificação de jogada invalida
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (game_board[i][j] == char_control)
            {
                if (print_game_board[i][j] != ' ')
                {
                    controlErr = 1;
                    return;
                }
                print_game_board[i][j] = _player;
                break;
            }
        }
    }

    // Verificação de vitória
    if (print_game_board[0][0] == _player &&
        print_game_board[0][1] == _player &&
        print_game_board[0][2] == _player)
    {
        winGame = 1;
    }
    else if (print_game_board[1][0] == _player &&
             print_game_board[1][1] == _player &&
             print_game_board[1][2] == _player)
    {
        winGame = 1;
    }
    else if (print_game_board[2][0] == _player &&
             print_game_board[2][1] == _player &&
             print_game_board[2][2] == _player)
    {
        winGame = 1;
    }
    else if (print_game_board[0][0] == _player &&
             print_game_board[1][0] == _player &&
             print_game_board[2][0] == _player)
    {
        winGame = 1;
    }
    else if (print_game_board[0][1] == _player &&
             print_game_board[1][1] == _player &&
             print_game_board[2][1] == _player)
    {
        winGame = 1;
    }
    else if (print_game_board[0][2] == _player &&
             print_game_board[1][2] == _player &&
             print_game_board[2][2] == _player)
    {
        winGame = 1;
    }
    else if(print_game_board[0][2] == _player &&
            print_game_board[1][1] == _player &&
            print_game_board[2][0] == _player)
    {
        winGame = 1;
    }
    else if(print_game_board[0][0] == _player &&
            print_game_board[1][1] == _player &&
            print_game_board[2][2] == _player)
    {
        winGame = 1;
    }
    // Se não venceu troca a vez da jogada
    else
    {
        player = !player;
    }

    // Incrementa as jogadas
    num_valid_plays++;
}

void verificControlGame()
{
    if (winGame)
    {
        cout << "\nParabens o jogador " << player + 1 << " venceu" << "\njogador " << _player;
    }

    if (controlErr)
    {
        cout << "Jogada invalida tente novamente";
        controlErr = 0;
    }

    if (testkey)
    {
        cout << "Comando invalido... tente novamente";
    }

    if (num_valid_plays == 9 && winGame != 1)
    {
        winGame = 1;
        cout << "\nEmpate, tente novamente";
    }
}
