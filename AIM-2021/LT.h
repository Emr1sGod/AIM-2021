#pragma once
#define LEXEMA_FIXSIZE	1			// фиксированный размер лексемы
#define LT_MAXSIZE		4096		// максимальное количество строк в таблице лексем
#define LT_TI_NULLIDX	0xfffffff	// нет элемента таблицы идентификаторов
#define LEX_BRIEF		't'	// лексема для brief
#define LEX_LINE		't'	// лексема для line
#define LEX_TYPES		't'	// лексема для types
#define LEX_ID			'i'	// лексема для идентификатора
#define LEX_LITERAL		'l'	// лексема для литерала
#define LEX_ACTION	    'a'	// лексема для action
#define LEX_VAR			'v'	// лексема для var
#define LEX_GIVEBACK	'g'	// лексема для giveback
#define LEX_OUTPUT		'o'	// лексема для output
#define LEX_MAJOR	    'm'	// лексема для major
#define LEX_FROM  	    'f'	// лексема для from
#define LEX_END			'e'	// лексема для end
#define LEX_EITHER		'r'	// лексема для either
#define LEX_WHEN		'w'	// лексема для when
#define LEX_WHENEND	    '?'	// лексема для конца when
#define LEX_LIBFUNCTION	'z'	// лексема для библиотечных функций
#define LEX_INCLUDELIB	'w'	// лексема подключения библиотеки
#define LEX_SEMICOLON	';'	// лексема для ;
#define LEX_COMMA		','	// лексема для ,
#define LEX_LEFTBRACE	'{'	// лексема для {
#define LEX_RIGHTBRACE	'}'	// лексема для }
#define LEX_LEFTTHESIS	'('	// лексема для (
#define LEX_RIGHTTHESIS	')'	// лексема для )
#define LEX_PLUS		'^'	// лексема для +
#define LEX_MINUS		'^'	// лексема для -
#define LEX_STAR		'^'	// лексема для *
#define LEX_DIRSLASH	'^'	// лексема для /
#define LEX_OPERCHECK	'y'	
#define LEX_CYCLEEND	'$'	// лексема для $
#define LEX_OPERATOR	'^'	// лексема для операторов
#define LEX_EQUAL		'=' // лексема для =
#define NEWLINE			'\n'// новая строка
#define POLISHFUNCTION  '@'
#define LATTICE 		'#'// #
#define SPACE	 		' '// space

namespace LT		// таблица лексем
{
	struct Entry	// строка таблицы лексем
	{
		unsigned char lexema;	// лексема
		char value;             // значение
		int sn;							// номер строки в исходном тексте
		int idxTI;						// индекс в таблице идентификаторов или LT_TI_NULLIDX
		int index;						// индекс для польской записи
		bool used = false;				// для польской записи
	};

	struct LexTable						// экземпляр таблицы лексем
	{
		int maxsize;					// емкость таблицы лексем < LT_MAXSIZE
		int size;						// текущий размер таблицы лексем < maxsize
		Entry* table;					// массив строк таблицы лексем
	};

	LexTable Create(		// создать таблицу лексем
		int size			// емкость таблицы лексем < LT_MAXSIZE
	);

	void Add(				// добавить строку в таблицу лексем
		LexTable& lextable,	// экземпляр таблицы лексем
		Entry entry			// строка таблицы лексем
	);

	Entry GetEntry(			// получить строку таблицы лексем
		LexTable& lextable,	// экземпляр таблицы лексем
		int n				// номер получаемой строки
	);

	void Delete(LexTable& lextable);	// удалить таблицу лексем (освободить память)

	void showTable(LexTable lextable,std::ofstream &file);	// вывод таблицы лексем
	void showTable_mini(LexTable lextable,std::ofstream &file);	// вывод таблицы лексем легкий вид
};