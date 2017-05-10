#ifndef _BOARD_H
#define _BOARD_H

#include <windows.h>
#include "Block.h"

enum GameStatus{
	PLAYING, END
};

#define BOARD_ROW_SIZE 24
#define BOARD_COL_SIZE 14

typedef struct _tetrisManager{
	char board[BOARD_ROW_SIZE][BOARD_COL_SIZE];
	Block block;
	int isHoldAvailable; // if hold block is empty or hold turn is passed, this variable is true
	Block shadow;
	int deletedLineCount;
	int speedLevel;
	int score;
	HANDLE totalTimeThread;
	long totalTime;
	int isTotalTimeAvailable; // if totalTimeThread is alive, this variable is true
	int itemArray[7];
	int changeNextCount;		//�������� ������ϰ� �ٴ�������� �ٲ� �� �ִ� Ƚ���� ����

	HANDLE mutex;				//�����忡�� �浹�� ���ϱ� ���� lock�� �ɾ��ش�.
	int checkBlindStatus;		/*�������� �����ִ� ���ȿ��� �������� �ٴ����� �ٲٱ� ����� �� �� ������ �����ϱ� ����
								���� ���� ���߾��� �ִ� �������� �ƴ����� üũ�Ѵ�.*/
	int blindNextInterval;		//������ �ö� ������ ��������� ���ߴ� �ֱ⸦ ª�� �����Ѵ�.
}TetrisManager;

void TetrisManager_Init(TetrisManager* tetrisManager, int speedLevel);
void TetrisManager_ProcessDirection(TetrisManager* tetrisManager, int direction);
void TetrisManager_ProcessAuto(TetrisManager* tetrisManager);
void TetrisManager_ProcessDirectDown(TetrisManager* tetrisManager);
void TetrisManager_ProcessDeletingLines(TetrisManager* tetrisManager);
int TetrisManager_IsReachedToBottom(TetrisManager* tetrisManager, int blockType);
int TetrisManager_ProcessReachedCase(TetrisManager* tetrisManager);
void TetrisManager_Print(TetrisManager* tetrisManager);
void TetrisManager_PrintBoard(TetrisManager* tetrisManager);
void TetrisManager_PrintDetailInfomation(TetrisManager* tetrisManager);
DWORD TetrisManager_GetDownMilliSecond(TetrisManager* tetrisManager);
void TetrisManager_MakeHold(TetrisManager* tetrisManager);
void TetrisManager_StartTotalTime(TetrisManager* tetrisManager);
void TetrisManager_PauseTotalTime(TetrisManager* tetrisManager);
void TetrisManager_StopTotalTime(TetrisManager* tetrisManager);

void TetrisManager_AddItem(TetrisManager* tetrisManager); //������ �߰� �Լ�
void TetrisManager_UseItem(TetrisManager* tetrisManager, int index); //������ ��� �Լ�

void TetrisManager_Item_RemoveOneRow(TetrisManager* tetrisManager);	//������1 : �� �� ����
void TetrisManager_Item_RemoveTwoRow(TetrisManager* tetrisManager);	//������2 : �� �� ����
void TetrisManager_Item_RemoveAllRow(TetrisManager* tetrisManager);	//������3 : ��ü �� ����
void TetrisManager_ChangeNextBlock(TetrisManager* tetrisManager);	//�������� �ٴ����� �ٲٱ�
void TetrisManager_BlindNextBlock(TetrisManager* tetrisManager);	//������ �����

void changeShadowColor(int level); // �������� �׸��� ���� �ٸ��� ����ϴ� �Լ�

#endif