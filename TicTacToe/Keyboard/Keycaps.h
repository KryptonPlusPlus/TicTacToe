#pragma once

#include "DrawRectangle.h"

// Class criada para utiliza��o da class "DrawRectangle", como um vetor j� que o construtor n�o possui par�metros, e o do 
// "DrawRectangle" tem par�metros;
class Keycaps
{
	public:
		Keycaps() {};
		~Keycaps();
		DrawRectangle *keycaps = nullptr;

		// --- sets ---
		void createKeycaps(int _width, int _height);
};

