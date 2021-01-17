#pragma once

#define ESC "\033"

//ANSI COLORS
// "\033[1;31m bold e vermelho \033[0m Reset\n"
//
//         foreground background
//black        30         40
//red          31         41
//green        32         42
//yellow       33         43
//blue         34         44
//magenta      35         45
//cyan         36         46
//white        37         47
//
//reset             0  (everything back to normal)
//bold / bright     1  (often a brighter shade of the same colour)
//underline         4
//inverse           7  (swap foreground and background colours)
//bold / bright of  21
//underline off     24
//inverse off       27

// Teclas do teclado
constexpr int key_arrow_up    = 72;
constexpr int key_arrow_down  = 80;
constexpr int key_arrow_left  = 75;
constexpr int key_arrow_right = 77;
constexpr int key_enter       = 13;

// --- caracteres de bordas ---
// Bordas simples
constexpr char char_single_upper_left_edge       = '\xda'; // ┌
constexpr char char_single_upper_right_edge      = '\xbf'; // ┐
constexpr char char_single_bottom_left_edge      = '\xc0'; // └
constexpr char char_single_bottom_right_edge     = '\xd9'; // ┘
constexpr char char_single_side_edge             = '\xb3'; // │
constexpr char char_single_upper_bottom_edge     = '\xc4'; // ─
constexpr char char_single_bottom_edge_with_dash = '\xc1'; // ┴
constexpr char char_single_top_edge_with_dash    = '\xc2'; // ┬
constexpr char char_single_right_edge_with_dash  = '\xc3'; // ├
constexpr char char_single_left_edge_with_dash   = '\xb4'; // ┤
constexpr char char_single_cross                 = '\xc5'; // ┼

// Bordas duplas
constexpr char char_double_upper_left_edge       = '\xc9'; // ╔	
constexpr char char_double_upper_right_edge      = '\xbb'; // ╗
constexpr char char_double_bottom_left_edge      = '\xc8'; // ╚
constexpr char char_double_bottom_right_edge     = '\xbc'; // ╝
constexpr char char_double_side_edge             = '\xba'; // ║
constexpr char char_double_upper_bottom_edge     = '\xcd'; // ═
constexpr char char_double_bottom_edge_with_dash = '\xca'; // ╩
constexpr char char_double_top_edge_with_dash    = '\xcb'; // ╦
constexpr char char_double_right_edge_with_dash  = '\xcc'; // ╠
constexpr char char_double_left_edge_with_dash   = '\xb9'; // ╣
constexpr char char_double_cross                 = '\xce'; // ╬

// Enum para as cores do terminal Foreground 
const enum class ColorForeground : short { black = 30, red, green, yellow, blue, magenta, cyan, white };
// Enum para as cores do terminal Background 
const enum class ColorBackground : short { black = 40, red, green, yellow, blue, magenta, cyan, white };

