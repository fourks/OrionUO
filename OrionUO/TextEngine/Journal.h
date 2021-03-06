/***********************************************************************************
**
** Journal.h
**
** Copyright (C) August 2016 Hotride
**
************************************************************************************
*/
//----------------------------------------------------------------------------------
#ifndef TextDataH
#define TextDataH
//----------------------------------------------------------------------------------
#include "TextData.h"
#include "../Globals.h"
//----------------------------------------------------------------------------------
//����� ��� �������� � ����� ��������� � �������
class CJournal : public CBaseQueue
{
	SETGET(int, MaxSize);
	SETGET(int, Size);

public:
	CJournal(const int &maxSize);
	~CJournal();

	//�������� ��������� � ������
	void Add(CTextData *obj);

	virtual void Clear();
};
//----------------------------------------------------------------------------------
extern CJournal g_Journal;
//----------------------------------------------------------------------------------
#endif
//----------------------------------------------------------------------------------
