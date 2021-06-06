#pragma once
namespace FST
{
	struct RELATION					//�����:������ -> ������� ����� ��������� ��
	{
		char symbol;				//������ ��������	
		short nnode;				//����� ������� �������
		RELATION(
			char c = 0x00,			//������ ��������
			short ns = 0			//����� ������� �������
		);
	};

	struct NODE						//������� ����� ���������
	{
		short n_relation;			//���������� ����������� �����
		RELATION *relations;		//����������� �����
		NODE();
		NODE
		(short n,				//���������� ����������� �����
			RELATION rel, ...		//������ �����
		);
	};

	struct FST						//������������������� �������� �������
	{
		char* string;				//������� (������,����������� 0�00)
		short position;				//������� ������� � �������
		short nstates;				//���������� ��������� ��������
		NODE* nodes;				//���� ���������: [0] - ��������� ���������, [nstate-1] - ��������
		short* rstates;				//��������� ��������� �������� �� ������ �������
		FST(
			char* s,				//������� (������, ���������� 0�00)
			short ns,				//���������� ��������� ��������
			NODE n, ...				//������ ��������� (���� ���������)
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
