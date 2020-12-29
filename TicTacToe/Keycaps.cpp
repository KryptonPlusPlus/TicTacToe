#include "Keycaps.h"


// --- sets ---
void Keycaps::createCharRectangle(int _width, int _height)
{
	keycaps = CharRectangle(_width, _height);
}

void Keycaps::setLine(int line)
{
	this->line = line;
}

void Keycaps::setColum(int colum)
{
	this->colum = colum;
}