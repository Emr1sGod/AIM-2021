#pragma once
namespace FST
{
	struct RELATION					//ребро:символ -> вершина графа переходов КА
	{
		char symbol;				//симпол перехода	
		short nnode;				//номер смежной вершины
		RELATION(
			char c = 0x00,			//символ перехода
			short ns = 0			//номер смежной вершины
		);
	};

	struct NODE						//вершина графа переходов
	{
		short n_relation;			//количество инцидентных ребер
		RELATION *relations;		//инцидентные ребра
		NODE();
		NODE
		(short n,				//количество инцидентных ребер
			RELATION rel, ...		//список ребер
		);
	};

	struct FST						//недетерминированный конечный автомат
	{
		char* string;				//цепочка (строка,завершается 0х00)
		short position;				//текущая позиция в цепочке
		short nstates;				//количество состояний автомата
		NODE* nodes;				//граф переходов: [0] - начальное состояние, [nstate-1] - конечное
		short* rstates;				//возможные состояния автомата на данной позиции
		FST(
			char* s,				//цепочка (строка, завершаеся 0х00)
			short ns,				//количество состояний автомата
			NODE n, ...				//список состояний (граф переходов)
		);
	};

	int getPosition(FST& fst);
	bool execute(FST& fst);
	int brief(char* str);
	int line(char* str);
	int action(char* str);
	int var(char* str);
	int giveback(char* str);
	int output(char* str);
	int major(char* str);
	int from(char* str);
	int end(char* str);
	int when(char* str);
	int either(char* str);
	int id(char* str);
	bool literalInt(char* str);
}
