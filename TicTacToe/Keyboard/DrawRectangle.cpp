// DrawRectangle.cpp
//

#include "DrawRectangle.h"

DrawRectangle::DrawRectangle(const int _height, const int _width, int type_line)
{
	draw_rectangle       = new std::string[_height];
	draw_rectangle_color = new std::string[_height];

	this->_height = _height;
	this->_width = _width;
	type_rectangle = (TypeRectangle)type_line;

	// Verifica o tipo de retângulo
	switch (type_rectangle)
	{
	case TypeRectangle::CompleteDouble:
	case TypeRectangle::OnlyLateralDouble:

		char_upper_left_edge = &char_double_upper_left_edge;       // ╔
		char_upper_right_edge = &char_double_upper_right_edge;      // ╗
		char_bottom_left_edge = &char_double_bottom_left_edge;      // ╚
		char_bottom_right_edge = &char_double_bottom_right_edge;     // ╝
		char_side_edge = &char_double_side_edge;             // ║
		char_upper_bottom_edge = &char_double_upper_bottom_edge;     // ═
		char_bottom_edge_with_dash = &char_double_bottom_edge_with_dash; // ╩
		char_top_edge_with_dash = &char_double_top_edge_with_dash;    // ╦
		char_right_edge_with_dash = &char_double_right_edge_with_dash;  // ╠
		char_left_edge_with_dash = &char_double_left_edge_with_dash;   // ╣
		char_cross = &char_double_cross;                 // ╬

		break;

	case TypeRectangle::CompleteSingle:
	case TypeRectangle::OnlyLateralSingle:
	default:

		char_upper_left_edge = &char_single_upper_left_edge;       // ┌
		char_upper_right_edge = &char_single_upper_right_edge;      // ┐
		char_bottom_left_edge = &char_single_bottom_left_edge;      // └
		char_bottom_right_edge = &char_single_bottom_right_edge;     // ┘
		char_side_edge = &char_single_side_edge;             // │
		char_upper_bottom_edge = &char_single_upper_bottom_edge;     // ─
		char_bottom_edge_with_dash = &char_single_bottom_edge_with_dash; // ┴
		char_top_edge_with_dash = &char_single_top_edge_with_dash;    // ┬
		char_right_edge_with_dash = &char_single_right_edge_with_dash;  // ├
		char_left_edge_with_dash = &char_single_left_edge_with_dash;   // ┤
		char_cross = &char_single_cross;                 // ┼

		break;
	}

	// Cria o retângulo
	for (int i = 0; i < _height; i++)
	{
		if (i == 0)
			draw_rectangle[i] += *char_upper_left_edge;
		else if (i == _height - 1)
			draw_rectangle[i] += *char_bottom_left_edge;
		else
			draw_rectangle[i] += *char_side_edge;

		for (int j = 1; j < _width - 1; j++)
		{
			if (type_rectangle == TypeRectangle::CompleteSingle)
				draw_rectangle[i] += ((i == 0) || (i == _height - 1)) ? *char_upper_bottom_edge : ' ';
			else
				draw_rectangle[i] += ' ';
		}

		if (i == 0)
			draw_rectangle[i] += *char_upper_right_edge;
		else if (i == _height - 1)
			draw_rectangle[i] += *char_bottom_right_edge;
		else
			draw_rectangle[i] += *char_side_edge;
	}
}

DrawRectangle::~DrawRectangle()
{
	#ifdef DEBUG
	printf("DrawRectangle delete \n");
	#endif // DEBUG

	delete []draw_rectangle;
	delete []draw_rectangle_color;
}

void DrawRectangle::charInCenter(char _char)
{
	draw_rectangle[_height / 2][_width / 2] = _char;
}

void DrawRectangle::stringInCenter(const char* _string)
{
	if ((int)strlen(_string) >= (int)(_width - 1))
		return;

	int j = ((_width - (int)strlen(_string)) / 2);

	for (int i = 0; i < strlen(_string); i++)
	{
		draw_rectangle[_height / 2][j] = +_string[i];

		j++;
	}
}

void DrawRectangle::stringInCenterAligneToRight(const char* _string)
{
	if ((int)strlen(_string) >= (int)(_width - 1))
		return;

	int j = 0;
	int tam = strlen(_string);
	for (int i = 0; i < tam; i++)
	{
		j++;

		draw_rectangle[_height / 2][j] = +_string[i];

	}
}

std::string* DrawRectangle::stringDrawRectangleColor()
{
	std::string color = std::to_string((int)color_rectangle_foreground);

	for (int i = 0; i < _height; i++)
	{
		draw_rectangle_color[i] = ESC"[;" + color + 'm';
		draw_rectangle_color[i] += draw_rectangle[i] + ESC"[0m";
	}

	return draw_rectangle_color;
}

// --- sets ---
void DrawRectangle::setColorForeground(ColorForeground color)
{
	color_rectangle_foreground = color;
}