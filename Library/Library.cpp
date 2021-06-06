#pragma warning(disable : 4996)

#include "Library.h"
#include <cstring>
#include <iostream>

extern "C"
{

	char* _stdcall copyline(char* str1, char* str2)
	{
		return strcpy(str1, str2);
	}

	int _stdcall range(char* str) {
		int i = 0;
		while (*(str + i) != NULL)
		{
			i++;
		}
		return i;
	}

	int _stdcall outtxt(char* value)
	{
		std::cout << value << std::endl;
		return 1;
	}

	int _stdcall outlit(int value)
	{
		std::cout << value << std::endl;
		return 1;
	}

}