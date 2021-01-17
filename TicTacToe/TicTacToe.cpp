// _TicTacToe.cpp
//
#include "TicTacToe.h"

void TicTacToe::setup()
{
    start = clock();    // Come�a o tempo
    printf(ESC"[?25l"); // Desativa o cursor
}

// String dos dados do jogo, para imprimir na tela
std::string TicTacToe::draw()
{
    std::string StringDraw = "";

    StringDraw += "TicTacToe 1.1.0  \n\n";
    
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            StringDraw += " ";
            StringDraw += ((!showMask) ? print_game_board[i][j] : (game_board[i][j]));
            StringDraw += ((j != 2) ? " |" : "");
        }

        StringDraw += "\n";
        StringDraw += ((i != 2) ? "---+---+---" : "");
        StringDraw += "\n";
    }
    StringDraw += "\nVez do jogador " + std::to_string(player + 1) + ".\n" + verificControlGame();
    
    return StringDraw;
}

// Verifica��es de controle do jogo
std::string TicTacToe::verificControlGame()
{
    std::string StringVerific = "";
    if (winGame)
    {
        StringVerific += "\nParabens o jogador " + std::to_string(player + 1) + " venceu." +  "\njogador " + _player + ".\n";
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
void TicTacToe::input()
{
    testkey = 0;

    char_control = _getch();
    // Verifica��o de se o caracter digitado � valido
    for (auto& num_key : key)
    {
        if (char_control == num_key)
        {
            testkey = 1;
            break;
        }
    }
}

// Logica do progama
void TicTacToe::logic()
{
    // Verifica��o para exibir a mascara
    if (char_control == 'p')
    {
        showMask = 1;
        return;
    }
    else
    {
        showMask = 0;
    }

    // Verifica��o de jogada invalida
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

    // Verifica��o de vit�ria
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
    // Se n�o venceu troca a vez da jogada
    else
    {
        player = !player;
    }

    // Incrementa as jogadas
    num_valid_plays++;
}

void TicTacToe::endGame()
{
    end = clock();
    temp_in_game = ((end - start) / (CLOCKS_PER_SEC));
}
