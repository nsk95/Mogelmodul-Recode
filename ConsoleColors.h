#pragma once

#ifndef CC_HEADER

#define CC_HEADER

#define CC_BLACK 0

#define CC_BLUE 9

#define CC_GREEN 10

#define CC_CYAN 11

#define CC_RED 12

#define CC_PINK 13

#define CC_YELLOW 14

#define CC_WHITE 15

#endif // !CC_HEADER

class CColor {

public:


	void changeFGColor(__int8 background, __int8 foreground);

	void printColor(const std::string message, __int8 color1, __int8 color2);

	void cleanColor();

	void printColorwb(const std::string message, __int8 color1, __int8 color2);
};

extern CColor* g_pColor;