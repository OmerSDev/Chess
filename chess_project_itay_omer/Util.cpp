#include "Util.h"
#include <iostream>



Util::Util()
{

}
int Util::char_to_int(char x)
{
	char lower = tolower(x);
	lower -= 48;
	return int(lower);
}

int Util::letters_to_int(char letter)
{
	char lower = tolower(letter);
	lower -= 97;
	return int(lower);
}