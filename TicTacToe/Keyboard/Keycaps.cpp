#include "Keycaps.h"

Keycaps::~Keycaps()
{
	#ifdef DEBUG
	printf("Keycaps delete \n");
	#endif // DEBUG
	
	delete keycaps;
}

void Keycaps::createKeycaps(int _width, int _height)
{
	keycaps = new DrawRectangle(_width, _height);
}