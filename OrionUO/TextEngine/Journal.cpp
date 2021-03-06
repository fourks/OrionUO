/***********************************************************************************
**
** Journal.cpp
**
** Copyright (C) August 2016 Hotride
**
************************************************************************************
*/
//----------------------------------------------------------------------------------
#include "Journal.h"
#include "../Gumps/GumpJournal.h"
#include "../Managers/GumpManager.h"
//----------------------------------------------------------------------------------
CJournal g_Journal(50);
//----------------------------------------------------------------------------------
CJournal::CJournal(const int &maxSize)
: CBaseQueue(), m_MaxSize(maxSize), m_Size(0)
{
}
//----------------------------------------------------------------------------------
CJournal::~CJournal()
{
}
//----------------------------------------------------------------------------------
void CJournal::Clear()
{
	CBaseQueue::Clear();

	m_Size = 0;
}
//----------------------------------------------------------------------------------
void CJournal::Add(CTextData *obj)
{
	CBaseQueue::Add(obj);

	CGumpJournal *gump = (CGumpJournal*)g_GumpManager.UpdateGump(g_PlayerSerial, 0, GT_JOURNAL);

	if (gump != NULL)
		gump->AddText(obj);

	if (m_Size >= m_MaxSize)
	{
		CTextData *item = (CTextData*)m_Items;

		if (gump != NULL)
			gump->DeleteText(item);

		Delete(item);
	}
	else
		m_Size++;
}
//----------------------------------------------------------------------------------
