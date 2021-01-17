#pragma once
#include "Keyboard.h"


void CreateABNT_2(Keyboard* _keyboard_)
{
	_keyboard_->createLine(20); // 0
	_keyboard_->createLine(23); // 1
	_keyboard_->createLine(23); // 2
	_keyboard_->createLine(21); // 3
	_keyboard_->createLine(21); // 4
	_keyboard_->createLine(16); // 5

	// Line 1 - 20
	_keyboard_->createKeycaps(0, 0, 5, "ESC");
	_keyboard_->createKeycaps(0, 1, 5, ' ', ColorForeground::black);
	_keyboard_->createKeycaps(0, 2, 5, "F1");
	_keyboard_->createKeycaps(0, 3, 5, "F2");
	_keyboard_->createKeycaps(0, 4, 5, "F3");
	_keyboard_->createKeycaps(0, 5, 5, "F4");
	_keyboard_->createKeycaps(0, 6, 3, ' ', ColorForeground::black);
	_keyboard_->createKeycaps(0, 7, 5, "F5");
	_keyboard_->createKeycaps(0, 8, 5, "F6");
	_keyboard_->createKeycaps(0, 9, 5, "F7");
	_keyboard_->createKeycaps(0, 10, 5, "F8");
	_keyboard_->createKeycaps(0, 11, 2, ' ', ColorForeground::black);
	_keyboard_->createKeycaps(0, 12, 5, "F9");
	_keyboard_->createKeycaps(0, 13, 5, "F10");
	_keyboard_->createKeycaps(0, 14, 5, "F11");
	_keyboard_->createKeycaps(0, 15, 5, "F12");
	_keyboard_->createKeycaps(0, 16, 2, ' ', ColorForeground::black);
	_keyboard_->createKeycaps(0, 17, 5, "PTR");
	_keyboard_->createKeycaps(0, 18, 5, "SCR");
	_keyboard_->createKeycaps(0, 19, 5, "PSE");

	// Line 2 - 23
	_keyboard_->createKeycaps(1, 0, 5, "\' \"");
	_keyboard_->createKeycaps(1, 1, 5, '1');
	_keyboard_->createKeycaps(1, 2, 5, '2');
	_keyboard_->createKeycaps(1, 3, 5, '3');
	_keyboard_->createKeycaps(1, 4, 5, '4');
	_keyboard_->createKeycaps(1, 5, 5, '5');
	_keyboard_->createKeycaps(1, 6, 5, '6');
	_keyboard_->createKeycaps(1, 7, 5, '7');
	_keyboard_->createKeycaps(1, 8, 5, '8');
	_keyboard_->createKeycaps(1, 9, 5, '9');
	_keyboard_->createKeycaps(1, 10, 5, '0');
	_keyboard_->createKeycaps(1, 11, 5, "- \xC4");
	_keyboard_->createKeycaps(1, 12, 5, "= +");
	_keyboard_->createKeycaps(1, 13, 10, "\x11\xC4\xC4\xC4");
	_keyboard_->createKeycaps(1, 14, 2, ' ', ColorForeground::black);
	_keyboard_->createKeycaps(1, 15, 5, "INS");
	_keyboard_->createKeycaps(1, 16, 5, "HOM");
	_keyboard_->createKeycaps(1, 17, 5, "PGU");
	_keyboard_->createKeycaps(1, 18, 2, ' ', ColorForeground::black);
	_keyboard_->createKeycaps(1, 19, 5, "NUM");
	_keyboard_->createKeycaps(1, 20, 5, ':');
	_keyboard_->createKeycaps(1, 21, 5, '*');
	_keyboard_->createKeycaps(1, 22, 5, '-');

	// Line 3 - 23
	_keyboard_->createKeycaps(2, 0, 7, "TAB");
	_keyboard_->createKeycaps(2, 1, 5, 'Q');
	_keyboard_->createKeycaps(2, 2, 5, 'W');
	_keyboard_->createKeycaps(2, 3, 5, 'E');
	_keyboard_->createKeycaps(2, 4, 5, 'R');
	_keyboard_->createKeycaps(2, 5, 5, 'T');
	_keyboard_->createKeycaps(2, 6, 5, 'Y');
	_keyboard_->createKeycaps(2, 7, 5, 'U');
	_keyboard_->createKeycaps(2, 8, 5, 'I');
	_keyboard_->createKeycaps(2, 9, 5, 'O');
	_keyboard_->createKeycaps(2, 10, 5, 'P');
	_keyboard_->createKeycaps(2, 11, 5, "\' `");
	_keyboard_->createKeycaps(2, 12, 5, "[ {");
	_keyboard_->createKeycaps(2, 13, 8, "\x11\xC4\xBF");
	// Começo Enter 1 - Up
	std::string* Enter = _keyboard_->getKeycaps(2, 13);
	Enter[2] = "\xC0\xBF  \xB3  \xB3";
	// Fim Enter 1 - Up
	_keyboard_->createKeycaps(2, 14, 2, ' ', ColorForeground::black);
	_keyboard_->createKeycaps(2, 15, 5, "DEL");
	_keyboard_->createKeycaps(2, 16, 5, "END");
	_keyboard_->createKeycaps(2, 17, 5, "PGD");
	_keyboard_->createKeycaps(2, 18, 2, ' ', ColorForeground::black);
	_keyboard_->createKeycaps(2, 19, 5, '7');
	_keyboard_->createKeycaps(2, 20, 5, '8');
	_keyboard_->createKeycaps(2, 21, 5, '9');
	_keyboard_->createKeycaps(2, 22, 5, '+');

	// Line 4 - 21
	_keyboard_->createKeycaps(3, 0, 8, "CAPS");
	_keyboard_->createKeycaps(3, 1, 5, 'A');
	_keyboard_->createKeycaps(3, 2, 5, 'S');
	_keyboard_->createKeycaps(3, 3, 5, 'D');
	_keyboard_->createKeycaps(3, 4, 5, 'F');
	_keyboard_->createKeycaps(3, 5, 5, 'G');
	_keyboard_->createKeycaps(3, 6, 5, 'H');
	_keyboard_->createKeycaps(3, 7, 5, 'J');
	_keyboard_->createKeycaps(3, 8, 5, 'K');
	_keyboard_->createKeycaps(3, 9, 5, 'L');
	_keyboard_->createKeycaps(3, 10, 5, 128);
	_keyboard_->createKeycaps(3, 11, 5, "~ ^");
	_keyboard_->createKeycaps(3, 12, 5, "] }");
	// Começo Enter 1 - down
	_keyboard_->createKeycaps(3, 13, 7);
	Enter = _keyboard_->getKeycaps(3, 13);
	Enter[0] = "\xB3  \xB3  \xB3";
	// Fim Enter 1 - down
	_keyboard_->createKeycaps(3, 14, 2, ' ', ColorForeground::black);
	_keyboard_->createKeycaps(3, 15, 15, "Krypton++");
	_keyboard_->createKeycaps(3, 16, 2, ' ', ColorForeground::black);
	_keyboard_->createKeycaps(3, 17, 5, '4');
	_keyboard_->createKeycaps(3, 18, 5, '5');
	_keyboard_->createKeycaps(3, 19, 5, '6');
	_keyboard_->createKeycaps(3, 20, 5, '.');

	// Line 5 - 21
	_keyboard_->createKeycaps(4, 0, 6, "SHFT");
	_keyboard_->createKeycaps(4, 1, 5, "\\ |");
	_keyboard_->createKeycaps(4, 2, 5, 'Z');
	_keyboard_->createKeycaps(4, 3, 5, 'X');
	_keyboard_->createKeycaps(4, 4, 5, 'C');
	_keyboard_->createKeycaps(4, 5, 5, 'V');
	_keyboard_->createKeycaps(4, 6, 5, 'B');
	_keyboard_->createKeycaps(4, 7, 5, 'N');
	_keyboard_->createKeycaps(4, 8, 5, 'M');
	_keyboard_->createKeycaps(4, 9, 5, ", <");
	_keyboard_->createKeycaps(4, 10, 5, ". >");
	_keyboard_->createKeycaps(4, 11, 5, "; :");
	_keyboard_->createKeycaps(4, 12, 5, "/ ?");
	_keyboard_->createKeycaps(4, 13, 9, "SHIFT");
	_keyboard_->createKeycaps(4, 14, 7, ' ', ColorForeground::black);
	_keyboard_->createKeycaps(4, 15, 5, 30);
	_keyboard_->createKeycaps(4, 16, 7, ' ', ColorForeground::black);
	_keyboard_->createKeycaps(4, 17, 5, '1');
	_keyboard_->createKeycaps(4, 18, 5, '2');
	_keyboard_->createKeycaps(4, 19, 5, '3');
	// Começo Enter 2 - Up
	_keyboard_->createKeycaps(4, 20, 5, 'E');
	Enter = _keyboard_->getKeycaps(4, 20);
	Enter[2] = "\xB3 N \xB3";
	// Fim Enter 2 - Up

	// Line 6 - 16
	_keyboard_->createKeycaps(5, 0, 6, "CTRL");
	// Começo Windows 1
	_keyboard_->createKeycaps(5, 1, 6);
	std::string* Windows = _keyboard_->getKeycaps(5, 1);
	Windows[0] = "\xDA\xC4\xC4\xC2\xC4\xBF";
	Windows[1] = "\xC3\xC4\xC4\xC5\xC4\xB4";
	Windows[2] = "\xC0\xC4\xC4\xC1\xC4\xD9";
	// Fim Windows 1
	_keyboard_->createKeycaps(5, 2, 6, "ALT");
	_keyboard_->createKeycaps(5, 3, 33);
	_keyboard_->createKeycaps(5, 4, 6, "ALT");
	// Começo Windows 2
	_keyboard_->createKeycaps(5, 5, 6);
	Windows = _keyboard_->getKeycaps(5, 5);
	Windows[0] = "\xDA\xC4\xC4\xC2\xC4\xBF";
	Windows[1] = "\xC3\xC4\xC4\xC5\xC4\xB4";
	Windows[2] = "\xC0\xC4\xC4\xC1\xC4\xD9";
	// Fim Windows 2
	_keyboard_->createKeycaps(5, 6, 6, "MENU");
	_keyboard_->createKeycaps(5, 7, 6, "CTRL");
	_keyboard_->createKeycaps(5, 8, 2, ' ', ColorForeground::black);
	_keyboard_->createKeycaps(5, 9, 5, 17);
	_keyboard_->createKeycaps(5, 10, 5, 31);
	_keyboard_->createKeycaps(5, 11, 5, 16);
	_keyboard_->createKeycaps(5, 12, 2, ' ', ColorForeground::black);
	_keyboard_->createKeycaps(5, 13, 10, "0    ");
	_keyboard_->createKeycaps(5, 14, 5, ',');
	_keyboard_->createKeycaps(5, 15, 5, 'E');
	// Começo Enter 2 - Down
	Enter = _keyboard_->getKeycaps(5, 15);
	Enter[0] = "\xB3 T \xB3";
	// Fim Enter 2 - Down
}