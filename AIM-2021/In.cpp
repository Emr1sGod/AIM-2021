#include "pch.h"
#include "In.h"
#include "Error.h"
#include "FST.h"
#include "LT.h"
#include "IT.h"
#include "LexAnaliz.h"
#include <fstream>
#include <string>
#include <iostream>


namespace In
{
	static helpInfo help;

	helpInfo getInfo() { return help; }

	IN getin(wchar_t infile[], wchar_t outfile[])
	{
		std::string onestr;
		int currentCol = 0;
		IN Info{ 0, 0, 0, nullptr, IN_CODE_TABLE };// инициализация
		std::ifstream in(infile);// чтения
		std::ofstream out(outfile);// записи
		if (!out.is_open())
			throw ERROR_THROW(101);
		if (!in.is_open())
			throw ERROR_THROW(101);
		std::string temp;
		while (!in.eof())//пока открыт файл
		{
			Info.lines++;//кол-во линий
			std::getline(in, temp);//запись tеmp
			temp += "\n";//знак окончания строки
			help.fulltext += temp;
		}
		help.fulltext += ' ';
		Info.text = new unsigned char[help.fulltext.size() + 1];//выделяем память
		unsigned char * Ptemp = Info.text;//указатель на начало
		for (int i = 0; i < help.fulltext.size(); ++i)
		{
			if (Info.code[(unsigned char)help.fulltext[i]] == IN::F)
			{
				throw ERROR_THROW_IN(102, help.currentLine, currentCol)                    //проверка символов на допустимость
			}                              
			else if (Info.code[(unsigned char)help.fulltext[i]] == IN::I)
				++Info.ignor;
			else if (Info.code[(unsigned char)help.fulltext[i]] != IN::T)
			{
				*Ptemp = help.fulltext[i];
				++Ptemp;
			}
			else
			{
				*Ptemp = Info.code[(unsigned char)help.fulltext[i]];                 
				++Ptemp;
			}
			if (help.fulltext[i] == '\n')
			{
				help.currentLine++;                                  //подсчет строк
				currentCol = 0;
			}
			else
				currentCol++;
		}
		*Ptemp = IN_CODE_ENDL;
		Info.size = help.fulltext.size()-Info.lines;
		
		out << Info.text;
		return Info;
	}
}