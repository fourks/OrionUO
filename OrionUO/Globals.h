/***********************************************************************************
**
** Globals.h
**
** Copyright (C) August 2016 Hotride
**
************************************************************************************
*/
//----------------------------------------------------------------------------------
#ifndef GLOBALS_H
#define GLOBALS_H
//----------------------------------------------------------------------------------
//������� ������������������ ��������� ���� �:
//GameCharacter.cpp     PluginManager
//ClientUO.cpp
//Packets.cpp
//PacketManager.cpp
//GameObject.cpp		PluginManager
//GameScreen.cpp
//----------------------------------------------------------------------------------
//!���������� ��������� ������� �������������� �������
extern bool g_AltPressed;
extern bool g_CtrlPressed;
extern bool g_ShiftPressed;
//----------------------------------------------------------------------------------
//!������������� ����� ��� ����������� ���������
extern bool g_MovingFromMouse;

//!������������� ��������������� ����������� ��������� �� �������� �����, ����� ������ ��������� � ������� ����
extern bool g_AutoMoving;

extern bool g_AbyssPacket03First;
//----------------------------------------------------------------------------------
#include "Wisp/WispGlobal.h"
#include "Wisp/WispGeometry.h"
#include "Wisp/WispLogger.h"
#include "OrionApplication.h"
#include "GLEngine/glew.h"
#include "GLEngine/wglew.h"
#include "GLEngine/GLFrameBuffer.h"
#include "GLEngine/GLTexture.h"
#include <gl/gl.h>
#include <gl/glu.h>
#include "EnumList.h"
#include "DefinitionMacro.h"
#include "Constants.h"
//----------------------------------------------------------------------------------
#pragma warning(disable: 4800) //forcing value to bool 'true' or 'false' (performance warning)
//----------------------------------------------------------------------------------
void TileOffsetOnMonitorToXY(int &ofsX, int &ofsY, int &x, int &y);
//----------------------------------------------------------------------------------
//������� ��� ���������� ���������
class CGameObject;
int GetDistance(CGameObject *current, CGameObject *target);
int GetDistance(CGameObject *current, WISP_GEOMETRY::CPoint2Di target);
int GetMultiDistance(WISP_GEOMETRY::CPoint2Di current, CGameObject *target);
int GetDistance(WISP_GEOMETRY::CPoint2Di current, CGameObject *target);
int GetDistance(WISP_GEOMETRY::CPoint2Di current, WISP_GEOMETRY::CPoint2Di target);
int GetTopObjDistance(CGameObject *current, CGameObject *target);
//----------------------------------------------------------------------------------
const char *GetReagentName(const ushort &id);
//----------------------------------------------------------------------------------
//!�������� �������� (������ ��� �������)
extern int g_LandObjectsCount;
extern int g_StaticsObjectsCount;
extern int g_GameObjectsCount;
extern int g_MultiObjectsCount;
extern int g_RenderedObjectsCountInGameWindow;
//----------------------------------------------------------------------------------
extern GLdouble g_GlobalScale;

extern CGLTexture g_MapTexture[6];

//!�������� �������� � �������
extern int g_FrameDelay[2];

//!������� ����� �����
extern uchar g_PingCount;
extern uchar g_PingSequence;

//!����� ��������� �������� ������ �������
extern uint g_LastSendTime;

//!����� ���������� ������ �� �������
extern uint g_LastPacketTime;

//!����� ������ ������������ �������
extern uint g_TotalSendSize;

//!����� ������ �������� �������
extern uint g_TotalRecvSize;

extern uint g_Ticks;

extern GLuint ShaderColorTable;
extern GLuint g_ShaderDrawMode;

extern string g_Language;

extern GAME_STATE g_GameState;

extern CGLTexture g_TextureGumpState[2];

extern WISP_GEOMETRY::CSize g_MapSize[6];
extern WISP_GEOMETRY::CSize g_MapBlockSize[6];

extern int g_MultiIndexCount;

extern class CGLFrameBuffer g_LightBuffer;

extern bool g_GumpPressed;
extern class CRenderObject *g_GumpSelectedElement;
extern class CRenderObject *g_GumpPressedElement;
extern WISP_GEOMETRY::CPoint2Di g_GumpMovingOffset;
extern WISP_GEOMETRY::CPoint2Df g_GumpTranslate;
extern bool g_ShowGumpLocker;

extern bool g_GrayedPixels;

extern bool g_ConfigLoaded;

extern uchar g_LightLevel;
extern uchar g_PersonalLightLevel;

//!��� ���������� ���������
extern char g_SelectedCharName[30];

//!������ ������� �����
extern uchar g_CurrentMap;

//!����� �������
extern uchar g_ServerTimeHour;
extern uchar g_ServerTimeMinute;
extern uchar g_ServerTimeSecond;

extern bool g_PacketLoginComplete;

extern uint g_ClientFlag;

extern bool g_SendLogoutNotification;
extern bool g_NPCPopupEnabled;
extern bool g_ChatEnabled;

//!��������� ������������� ���������� �������
extern uchar g_GameSeed[4];

//!���� ��� ��������, �������� �� ������� g_UpdateRange (���� ��� ������������� �������)
extern ushort g_OutOfRangeColor;

//!�� �������� �����
extern bool g_NoDrawRoof;

//!������������ �������� Z ���������� ��������� ��� �������
extern char g_MaxGroundZ;

//!������ ������������ ���� ��������
extern char g_FoliageIndex;

//!����������� ������������� ����� ������������
extern bool g_UseCircleTrans;

//!���������� � ������� ��������� ���������
extern bool g_JournalShowSystem;

//!���������� � ������� ��������� �� ��������
extern bool g_JournalShowObjects;

//!���������� � ������� ���������� ��������� �������
extern bool g_JournalShowClient;

extern uint g_PlayerSerial;
extern uint g_StatusbarUnderMouse;

//!������ ���������� ���������� ����������
extern int g_LastSpellIndex;

//!������ ���������� ���������� ������
extern int g_LastSkillIndex;

//!��������� �������������� ������
extern uint g_LastUseObject;

//!��������� ������, �� ������� ������ ��������
extern uint g_LastTargetObject;

//!��������� ����������� ������
extern uint g_LastAttackObject;

extern CHARACTER_SPEED_TYPE g_SpeedMode;

//!������ ������� ������ �� ������
extern uint g_DeathScreenTimer;

//!���������� �������� �����������
extern uchar g_WalkRequestCount;

//!����� ���������� ����
extern uint g_PendingDelayTime;

//!����������� ������� �������� ���������
extern float g_AnimCharactersDelayValue;

typedef vector<pair<uint, uint>> CORPSE_LIST_MAP;
extern CORPSE_LIST_MAP g_CorpseSerialList;

//!����������, � ������� ������� �������� ������ �������� ��������
extern WISP_GEOMETRY::CPoint2Di g_RemoveRangeXY;

//!���������� ����������� ����
extern int g_GrayMenuCount;

//!��� �������
extern PROMPT_TYPE g_ConsolePrompt;

//!������ ���������� ASCII �������
extern uchar g_LastASCIIPrompt[11];

//!������ ���������� Unicode �������
extern uchar g_LastUnicodePrompt[11];

//!�������� ��� ������� �� ������ ����-�����
extern uint g_PartyHelperTarget;

//!����� ����� ��� ������� �� ������ ����-�����
extern uint g_PartyHelperTimer;

extern float g_DrawColor;

extern float g_SkillsTotal;
extern SEASON_TYPE g_Season;

extern uint g_LockedClientFeatures;

extern bool g_GeneratedMouseDown;

const int g_ObjectHandlesWidth = 142;
const int g_ObjectHandlesHeight = 20;
extern ushort g_ObjectHandlesBackgroundPixels[g_ObjectHandlesWidth * g_ObjectHandlesHeight];
//----------------------------------------------------------------------------------
inline bool IsBackground(uint flags) { return (flags & 0x00000001); }
inline bool IsWeapon(uint flags) { return (flags & 0x00000002); }
inline bool IsTransparent(uint flags) { return (flags & 0x00000004); }
inline bool IsTranslucent(uint flags) { return (flags & 0x00000008); }
inline bool IsWall(uint flags) { return (flags & 0x00000010); }
inline bool IsDamaging(uint flags) { return (flags & 0x00000020); }
inline bool IsImpassable(uint flags) { return (flags & 0x00000040); }
inline bool IsWet(uint flags) { return (flags & 0x00000080); }
inline bool IsUnknown(uint flags) { return (flags & 0x00000100); }
inline bool IsSurface(uint flags) { return (flags & 0x00000200); }
inline bool IsBridge(uint flags) { return (flags & 0x00000400); }
inline bool IsStackable(uint flags) { return (flags & 0x00000800); }
inline bool IsWindow(uint flags) { return (flags & 0x00001000); }
inline bool IsNoShoot(uint flags) { return (flags & 0x00002000); }
inline bool IsPrefixA(uint flags) { return (flags & 0x00004000); }
inline bool IsPrefixAn(uint flags) { return (flags & 0x00008000); }
inline bool IsInternal(uint flags) { return (flags & 0x00010000); }
inline bool IsFoliage(uint flags) { return (flags & 0x00020000); }
inline bool IsPartialHue(uint flags) { return (flags & 0x00040000); }
inline bool IsUnknown1(uint flags) { return (flags & 0x00080000); }
inline bool IsMap(uint flags) { return (flags & 0x00100000); }
inline bool IsContainer(uint flags) { return (flags & 0x00200000); }
inline bool IsWearable(uint flags) { return (flags & 0x00400000); }
inline bool IsLightSource(uint flags) { return (flags & 0x00800000); }
inline bool IsAnimated(uint flags) { return (flags & 0x01000000); }
inline bool IsNoDiagonal(uint flags) { return (flags & 0x02000000); }
inline bool IsUnknown2(uint flags) { return (flags & 0x04000000); }
inline bool IsArmor(uint flags) { return (flags & 0x08000000); }
inline bool IsRoof(uint flags) { return (flags & 0x10000000); }
inline bool IsDoor(uint flags) { return (flags & 0x20000000); }
inline bool IsStairBack(uint flags) { return (flags & 0x40000000); }
inline bool IsStairRight(uint flags) { return (flags & 0x80000000); }
//----------------------------------------------------------------------------------
#endif
//----------------------------------------------------------------------------------
