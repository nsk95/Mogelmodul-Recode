#include "Includes.h"

/* Credits an cragson */

void CColor::changeFGColor(__int8 background, __int8 foreground) {

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), ((16 * background) + foreground));
}

void CColor::cleanColor() {

	changeFGColor(CC_BLACK, CC_WHITE);
}

void CColor::printColorwb(const std::string message, __int8 color1, __int8 color2) {
	
	changeFGColor(color1, color2);

	std::cout << message.c_str();

	cleanColor();
}

void CColor::printColor(const std::string message, __int8 color1, __int8 color2) {

	changeFGColor(color1, color2);

	std::cout << message.c_str();
	std::cout << "\n";

	cleanColor();
}

CColor* g_pColor = new CColor();