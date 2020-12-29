// Keyboard.cpp
//

#include "Keyboard.h"
#include <iostream>
Keyboard::Keyboard()
{
	

}

void Keyboard::createLine(int columns)
{
	lines++;

	delete columns_each_rows;

	columns_each_rows = new int[lines];

	for (int i = 0; i < lines - 1; i++)
	{
		columns_each_rows[i] = last_columns_each_rows[i];
	}

	columns_each_rows[lines - 1] = columns;

	last_columns_each_rows = new int[lines];

	for (int i = 0; i < lines; i++)
	{
		last_columns_each_rows[i] = columns_each_rows[i];
	}

	data = (((lines - 1) * columns) + columns);

	keyboard = new Keycaps[data];
}

void Keyboard::createKey(int line, int colum, const int _width, const int _height)
{
	keyboard[((line * columns_each_rows[line]) + colum)].createCharRectangle(_width, _height);
	keyboard[((line * columns_each_rows[line]) + colum)].setLine(line);
	keyboard[((line * columns_each_rows[line]) + colum)].setColum(colum);
}

//key mapping