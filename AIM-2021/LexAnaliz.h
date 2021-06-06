#pragma once
#define MAXSIZEIDENTIFICATOR 15

namespace LexA
{
	struct Tables
	{
		LT::LexTable mylextable;
		IT::IdTable myidtable;
	};

	Tables analyze(int currentLine, char *fulltextch);
}