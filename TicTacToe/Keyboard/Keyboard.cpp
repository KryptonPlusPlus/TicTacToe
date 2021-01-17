// Keyboard.cpp
//

#include "Keyboard.h"

// Teclados
#include "Keyboards/ABNT_2.h"

Keyboard::Keyboard(int _height, TypeKeyboard type_keyboard)
{
	this->_height = _height;

	switch (type_keyboard)
	{
		case TypeKeyboard::_NULL_:
			break;
		case TypeKeyboard::ABNT_2:
			CreateABNT_2(this);
			break;
		default:
			break;
	}
}

Keyboard::~Keyboard()
{
	#ifdef DEBUG
	printf("Keyboard delete\n");
	#endif // DEBUG
	
	delete[]__keyboard__;
}


std::string* Keyboard::stringKeyboard()
{
	delete[]__keyboard__;
	__keyboard__ = new std::string[keyboard.getLines() *_height];

	for (int i = 0; i < keyboard.getLines(); i++)
	{
		for (int j = 0; j < keyboard.getColumnsEachRows(i); j++)
		{
			std::string *tempKeycaps = keyboard.getPosArray(i, j).keycaps->stringDrawRectangleColor();

			for (int _lines = 0; _lines < _height; _lines++)
			{
				__keyboard__[_lines + (_height * i)] += tempKeycaps[_lines];				
			}
		}
	}
	return __keyboard__;
}

void Keyboard::createLine(int columns)
{
	keyboard.createLine(columns);
}

void Keyboard::createKeycaps(int line, int colum, int _width) 
{
	keyboard.getPosArray(line, colum).createKeycaps(_height, _width);
}

void Keyboard::createKeycaps(int line, int colum, int _width, const char* _string_, ColorForeground color)
{
	this->createKeycaps(line, colum, _width);
	this->stringInCenterKeycaps(line, colum, _string_);
	this->setColorKeycaps(line, colum, color);
}

void Keyboard::createKeycaps(int line, int colum, int _width, char key, ColorForeground color)
{
	this->createKeycaps(line, colum, _width);
	this->charInCenterKeycaps(line, colum, key);
	this->setColorKeycaps(line, colum, color);
}

void Keyboard::charInCenterKeycaps(int line, int colum, char key) 
{ 
	keyboard.getPosArray(line, colum).keycaps->charInCenter(key); 
}

void Keyboard::stringInCenterKeycaps(int line, int colum, const char* _string_) 
{
	keyboard.getPosArray(line, colum).keycaps->stringInCenter(_string_); 
}

void Keyboard::stringInCenterToRightKeycaps(int line, int colum, const char* _string_) 
{
	keyboard.getPosArray(line, colum).keycaps->stringInCenterAligneToRight(_string_); 
}

void Keyboard::setColorKeycaps(int line, int colum, ColorForeground color)
{
	keyboard.getPosArray(line, colum).keycaps->setColorForeground(color); 
}
