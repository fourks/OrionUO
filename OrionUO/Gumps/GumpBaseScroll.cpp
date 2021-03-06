/***********************************************************************************
**
** GumpBaseScroll.cpp
**
** Copyright (C) August 2016 Hotride
**
************************************************************************************
*/
//----------------------------------------------------------------------------------
#include "GumpBaseScroll.h"
#include "../OrionUO.h"
#include "../Managers/MouseManager.h"

//----------------------------------------------------------------------------------
CGumpBaseScroll::CGumpBaseScroll(GUMP_TYPE type, uint serial, ushort graphic, int height, short x, short y, bool haveMinimizer, int scrollerOffsetY, bool haveBackgroundLines, int scissorOffsetHeight)
: CGump(type, serial, x, y), m_Height(height), m_StartResizeHeight(0),
m_ScrollerOffsetY(scrollerOffsetY), m_HaveBackgroundLines(haveBackgroundLines),
m_ScissorOffsetHeight(scissorOffsetHeight), m_MinHeight(160)
{
	m_Page = 2;
	Add(new CGUIPage(2));

	int offsetY = 0;
	int w = 0;

	CGLTexture *th = g_Orion.ExecuteGump(0x082D);

	if (th != NULL)
	{
		w = th->Width;

		if (haveMinimizer)
			offsetY = th->Height - 3;
	}

	m_Minimizer = (CGUIButton*)Add(new CGUIButton(ID_GBS_BUTTON_MINIMIZE, 0x082D, 0x082D, 0x082D, 0, 0));
	m_Minimizer->Visible = haveMinimizer;

	m_Background = (CGUIScrollBackground*)Add(new CGUIScrollBackground(0, graphic, 0, offsetY, m_Height));
	WISP_GEOMETRY::CRect rect = m_Background->WorkSpace;

	m_Minimizer->X = m_Background->Width / 2;

	int heightDecBonus = m_ScissorOffsetHeight;

	if (m_HaveBackgroundLines)
	{
		m_ScrollerOffsetY += 16;
		heightDecBonus += 16;
	}

	m_HTMLGump = (CGUIHTMLGump*)Add(new CGUIHTMLGump(ID_GBS_HTMLGUMP, 0, rect.Position.X, offsetY + rect.Position.Y + m_ScrollerOffsetY, rect.Size.Width, rect.Size.Height - m_ScrollerOffsetY - heightDecBonus, false, true));

	CGUIHTMLButton *button = m_HTMLGump->m_ButtonUp;

	if (button != NULL)
	{
		button->Graphic = 0x0824;
		button->GraphicSelected = 0x0824;
		button->GraphicPressed = 0x0824;
		button->CheckPolygone = true;
	}

	button = m_HTMLGump->m_ButtonDown;

	if (button != NULL)
	{
		button->Graphic = 0x0825;
		button->GraphicSelected = 0x0825;
		button->GraphicPressed = 0x0825;
		button->CheckPolygone = true;
	}

	CGUIHTMLSlider *slider = m_HTMLGump->m_Slider;

	if (slider != NULL)
	{
		slider->Graphic = 0x001F;
		slider->GraphicSelected = 0x001F;
		slider->GraphicPressed = 0x001F;
		slider->BackgroundGraphic = 0;
	}

	m_Resizer = (CGUIResizeButton*)Add(new CGUIResizeButton(ID_GBS_BUTTON_RESIZE, 0x082E, 0x082F, 0x082F, 0, offsetY + m_Height - 3));
	m_Resizer->X = (m_Background->Width / 2) - (w / 2);
}
//----------------------------------------------------------------------------------
CGumpBaseScroll::~CGumpBaseScroll()
{
}
//----------------------------------------------------------------------------------
void CGumpBaseScroll::UpdateHeight()
{
	m_Height = m_StartResizeHeight + g_MouseManager.LeftDroppedOffset().Y;

	if (m_Height < m_MinHeight)
		m_Height = m_MinHeight;

	int maxHeight = GetSystemMetrics(SM_CYSCREEN) - 50;

	if (m_Height >= maxHeight)
		m_Height = maxHeight;

	int offsetY = 0;

	CGLTexture *th = g_Orion.ExecuteGump(0x082D);

	if (th != NULL && m_Minimizer->Visible)
		offsetY = th->Height - 3;

	m_Background->UpdateHeight(m_Height);

	int heightDecBonus = m_ScissorOffsetHeight;

	if (m_HaveBackgroundLines)
		heightDecBonus += 16;

	m_HTMLGump->UpdateHeight(m_Background->WorkSpace.Size.Height - m_ScrollerOffsetY - heightDecBonus);

	m_Resizer->Y = offsetY + m_Height - 3;
}
//----------------------------------------------------------------------------------
void CGumpBaseScroll::GUMP_RESIZE_START_EVENT_C
{
	m_StartResizeHeight = m_Height;
}
//----------------------------------------------------------------------------------
void CGumpBaseScroll::GUMP_RESIZE_EVENT_C
{
	if (m_StartResizeHeight)
		UpdateHeight();
}
//----------------------------------------------------------------------------------
void CGumpBaseScroll::GUMP_RESIZE_END_EVENT_C
{
	if (m_StartResizeHeight)
		m_StartResizeHeight = 0;
}
//----------------------------------------------------------------------------------
