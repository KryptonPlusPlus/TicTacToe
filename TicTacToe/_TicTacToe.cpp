// _TicTacToe.cpp
//
#include "_TicTacToe.h"

void _TicTacToe::setup()
{
    start = clock();    // Começa o tempo
    printf(ESC"[?25l"); // Desativa o cursor
}

// String dos dados do jogo, para imprimir na tela
string _TicTacToe::draw()
{
   string StringDraw = "";

    StringDraw += "TicTacToe 1.1.0  \n\n";
    
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            StringDraw += " "s + ((!showMask) ? print_game_board[i][j] : (game_board[i][j])) + ((j != 2) ? " |" : "");  
        }

        StringDraw += "\n"s + ((i != 2) ? "---+---+---" : "") + "\n"s;
    }
    StringDraw += "\nVez do jogador " + to_string(player + 1) + ".\n"s + verificControlGame();
    
    return StringDraw;
}

// Verificações de controle do jogo
string _TicTacToe::verificControlGame()
{
    string StringVerific = "";
    if (winGame)
    {
        StringVerific += "\nParabens o jogador " + to_string(player + 1) + " venceu." +  "\njogador " + _player + ".\n"s;
    }
    
    if (controlErr)
    {
        StringVerific += "Jogada invalida tente novamente.\n";
    }

    if (!testkey)
    {
        StringVerific += "Comando invalido... tente novamente.\n \a";
    }

    if (num_valid_plays == 9 && winGame != 1)
    {
        winGame = 1;
        StringVerific += "\nEmpate, jogue novamente.";
    }
    return StringVerific;
}

// Entrada de dados
void _TicTacToe::input()
{
    testkey = 0;

    char_control = _getch();
    // Verificação de se o caracter digitado é valido
    for (int i = 0; i < sizeof(key) / sizeof(key[0]); i++)
    {
        if (char_control == key[i])
        {
            testkey = 1;
            break;
        }
    }
}

// Logica do progama
void _TicTacToe::logic()
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
                else
                {
                    controlErr = 0;
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
    else if (print_game_board[0][2] == _player &&
        print_game_board[1][1] == _player &&
        print_game_board[2][0] == _player)
    {
        winGame = 1;
    }
    else if (print_game_board[0][0] == _player &&
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

void _TicTacToe::endGame()
{
    end = clock();
    temp_in_game = ((end - start) / (CLOCKS_PER_SEC));
}
