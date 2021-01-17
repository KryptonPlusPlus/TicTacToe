// CharRectangle.h
//

#pragma once

// ----- Início das Inclusões das Bibliotecas -----

#include <string> // std::string & strlen() & to_string() -> strlen pega o tamanho de uma string, e o to_string() converte um int para string

#include "Utils/Utils.h"

// Parte do codigo para Windows
#ifdef _WIN32 

#endif // end if _WIN32 || WIN23


// Parte do codigo para Linux
#ifdef __linux__ 

#error

#endif // end if __linux__ || LINUX

//  ----- Fim das Inclusões das Bibliotecas -----

class DrawRectangle
{
    // ================================================= Parte privada da classe =================================================
    private:

        const char* char_upper_left_edge       = nullptr;
        const char* char_upper_right_edge      = nullptr;
        const char* char_bottom_left_edge      = nullptr;
        const char* char_bottom_right_edge     = nullptr;
        const char* char_side_edge             = nullptr;
        const char* char_upper_bottom_edge     = nullptr;
        const char* char_bottom_edge_with_dash = nullptr;
        const char* char_top_edge_with_dash    = nullptr;
        const char* char_right_edge_with_dash  = nullptr;
        const char* char_left_edge_with_dash   = nullptr;
        const char* char_cross                 = nullptr;


        // Tamanho do retângulo
        int _width = 0;
        int _height = 0;

        // Enum para os tipos de retângulos     
        enum class TypeRectangle { CompleteSingle, CompleteDouble, OnlyLateralSingle, OnlyLateralDouble } type_rectangle = TypeRectangle::CompleteSingle;

        ColorForeground color_rectangle_foreground = ColorForeground::white;
        ColorBackground color_rectangle_background = ColorBackground::black;

        std::string* draw_rectangle       = nullptr;
        std::string* draw_rectangle_color = nullptr;

    // ================================================= Parte publica da classe =================================================
    public:

        // --- contructor & destructor ---
        DrawRectangle(const int _width, const int _height, int type_line = (int)TypeRectangle::CompleteSingle);

        virtual ~DrawRectangle();

        // --- Definição das funções publicas ---

        // formas de adicionar um texto dentro do retângulo
        void charInCenter(char _char);
        void stringInCenter(const char* _string);
        void stringInCenterAligneToRight(const char* _string);

        std::string* stringDrawRectangleColor();

        // --- gets ---
        int getWidth()  { return _width; }
        int getHeight() { return _height; }

        std::string* getDrawRectangle() { return draw_rectangle; }

        TypeRectangle   getTypeRectangle() { return type_rectangle; }
        ColorForeground getColorForeground() { return color_rectangle_foreground; }
        ColorBackground getColorBackground() { return color_rectangle_background; }

        // --- sets ---
        void setColorForeground(ColorForeground color);
        //void setColorBackground(ColorBackground color);

};
