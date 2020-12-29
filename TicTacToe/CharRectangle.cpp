// CharRectangle.cpp
//

#include "CharRectangle.h"

CharRectangle::CharRectangle(const int _height, const int _width, int type_line)
{
	charRectangle       = new std::string[_height];
	charRectangleColor  = new std::string[_height];

	this->_height = _height;
	this->_width = _width;
	type_rectangle = (TypeRectangle)type_line;

	switch (type_rectangle)
	{
		case TypeRectangle::CompleteSingle:
		case TypeRectangle::OnlyLateralSingle:

			for (int i = 0; i < _height; i++)
			{
				if (i == 0)
					charRectangle[i] += char_single_upper_left_edge;
				else if (i == _height - 1)
					charRectangle[i] += char_single_bottom_left_edge;
				else
					charRectangle[i] += char_single_side_edge;

				//charRectangle[i] += (i == 0) ? key_single_upper_left_edge : ((i == _height - 1) ? key_single_bottom_left_edge  : key_single_side_edge);

				for (int j = 1; j < _width - 1; j++)
				{
					if (type_rectangle == TypeRectangle::CompleteSingle)
						charRectangle[i] += ((i == 0) || (i == _height - 1)) ? char_single_upper_bottom_edge : ' ';
					else
						charRectangle[i] += ' ';
				}

				if (i == 0)
					charRectangle[i] += char_single_upper_right_edge;
				else if (i == _height - 1)
					charRectangle[i] += char_single_bottom_right_edge;
				else
					charRectangle[i] += char_single_side_edge;

				//charRectangle[i] += (i == 0) ? key_single_upper_right_edge : ((i == _height - 1) ? key_single_bottom_right_edge : key_single_side_edge);
			}

			break;
		case TypeRectangle::CompleteDouble:
		case TypeRectangle::OnlyLateralDouble:

			for (int i = 0; i < _height; i++)
			{
				if (i == 0)
					charRectangle[i] += char_double_upper_left_edge;
				else if (i == _height - 1)
					charRectangle[i] += char_double_bottom_left_edge;
				else
					charRectangle[i] += char_double_side_edge;

				for (int j = 1; j < _width - 1; j++)
				{
					if (type_rectangle == TypeRectangle::CompleteDouble)
						charRectangle[i] += ((i == 0) || (i == _height - 1)) ? char_double_upper_bottom_edge : ' ';
					else
						charRectangle[i] += ' ';
				}

				if (i == 0)
					charRectangle[i] += char_double_upper_right_edge;
				else if (i == _height - 1)
					charRectangle[i] += char_double_bottom_right_edge;
				else
					charRectangle[i] += char_double_side_edge;
			}

			break;

		default:

			break;
	}
}

void CharRectangle::charInCenter(char _char)
{
	charRectangle[_height / 2][_width / 2] = _char;
}

void CharRectangle::stringInCenter(const char* _string)
{
	if ((int)strlen(_string) >= (int)(_width - 1))
		return;
	
	int j = ((_width - (int)strlen(_string)) / 2);

	for (int i = 0; i < strlen(_string); i++)
	{
		charRectangle[_height / 2][j] =+ _string[i];

		j++;
	}
}

void CharRectangle::stringInCenterAligneToRight(const char* _string)
{
	if ((int)strlen(_string) >= (int)(_width - 1))
		return;

	int j = 0;

	for (int i = 0; i < strlen(_string); i++)
	{
		j++;

		charRectangle[_height / 2][j] =+ _string[i];

	}
}

std::string* CharRectangle::stringCharRectangleColor()
{
	std::string color = std::to_string((int)color_rectangle_foreground);
	
	for (int i = 0; i < _height; i++)
	{
		charRectangleColor[i] = ESC"[;" + color + 'm';
		charRectangleColor[i] += charRectangle[i] + ESC"[0m";
	}

	return charRectangleColor;
}

// --- sets ---
void CharRectangle::setColorForeground(ColorForeground color)
{
	color_rectangle_foreground = color;
}