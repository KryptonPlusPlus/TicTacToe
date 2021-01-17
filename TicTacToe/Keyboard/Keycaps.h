#pragma once

#include "DrawRectangle.h"

// Class criada para utilização da class "DrawRectangle", como um vetor já que o construtor não possui parâmetros, e o do 
// "DrawRectangle" tem parâmetros;
class Keycaps
{
	public:
		Keycaps() {};
		~Keycaps();
		DrawRectangle *keycaps = nullptr;

		// --- sets ---
		void createKeycaps(int _width, int _height);
};

