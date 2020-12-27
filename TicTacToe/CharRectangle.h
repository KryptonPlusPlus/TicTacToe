#pragma once

#include <string>

#define ESC '\003'

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

class CharRectangle
{
    // ================================================= Parte privada da classe =================================================
private:

    // Bordas simples
    const static char key_single_upper_left_edge = '\xda'; // ┌
    const static char key_single_upper_right_edge = '\xbf'; // ┐
    const static char key_single_bottom_left_edge = '\xc0'; // └
    const static char key_single_bottom_right_edge = '\xd9'; // ┘
    const static char key_single_side_edge = '\xb3'; // │
    const static char key_single_upper_bottom_edge = '\xc4'; // ─
    const static char key_single_bottom_edge_with_dash = '\xc1'; // ┴
    const static char key_single_top_edge_with_dash = '\xc2'; // ┬
    const static char key_single_right_edge_with_dash = '\xc3'; // ├
    const static char key_single_left_edge_with_dash = '\xb4'; // ┤
    const static char key_single_cross = '\xc5'; // ┼

    // Bordas duplas
    const static char key_double_upper_left_edge = '\xc9'; // ╔	
    const static char key_double_upper_right_edge = '\xbb'; // ╗
    const static char key_double_bottom_left_edge = '\xc8'; // ╚
    const static char key_double_bottom_right_edge = '\xbc'; // ╝
    const static char key_double_side_edge = '\xba'; // ║
    const static char key_double_upper_bottom_edge = '\xcd'; // ═
    const static char key_double_bottom_edge_with_dash = '\xca'; // ╩
    const static char key_double_top_edge_with_dash = '\xcb'; // ╦
    const static char key_double_right_edge_with_dash = '\xcc'; // ╠
    const static char key_double_left_edge_with_dash = '\xb9'; // ╣
    const static char key_double_cross = '\xce'; // ╬

    // Tamanho do retângulo
    int _width = 0;
    int _height = 0;


    // Enum para as cores dos retângulos
    enum class ColorRectangleForeground { black = 30, red, green, yellow, blue, magenta, cyan, white } color_rectangle_foreground = ColorRectangleForeground::white;
    enum class ColorRectangleBackground { black = 40, red, green, yellow, blue, magenta, cyan, white } color_rectangle_background = ColorRectangleBackground::black;

    // Enum para os tipos de retângulos     
    enum class TypeRectangle { CompleteSingle, CompleteDouble, OnlyLateralSingle, OnlyLateralDouble } type_rectangle = TypeRectangle::CompleteSingle;

    std::string* charRectangle;
    // ================================================= Parte publica da classe =================================================
public:

    // --- contructor & destructor ---
    CharRectangle(const int _width, const int _height = 0, int type_line = (int)TypeRectangle::CompleteSingle);
    virtual ~CharRectangle() {};

    // --- Definição das funções publicas ---

    // formas de adicionar um texto dentro do retângulo
    void charInCenter(char _char);
    void stringInCenter(const char* _string);
    void stringInCenterAligneToRight(const char* _string);

    std::string* stringCharRectangleColor() {}

    // --- gets ---
    int getWidth()  { return _width;  }
    int getHeight() { return _height; }

    std::string*             getCharRectangle()   { return charRectangle;              }
    TypeRectangle            getTypeRectangle()   { return type_rectangle;             }
    ColorRectangleForeground getColorForeground() { return color_rectangle_foreground; }
    ColorRectangleBackground getColorBackground() { return color_rectangle_background; }

};
