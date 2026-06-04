#pragma once

//#include "MazeCommon.h";
#include "Player.h"
#include "Monster.h"
#include "Orc.h"
#include "Slime.h"
#include "Wyvern.h"

/// <summary>
/// 해당 위치의 타일 정보를 리턴하는 함수
/// </summary>
/// <param name="X">X좌표</param>
/// <param name="Y">Y좌표</param>
/// <returns>해당 위치의 데이터</returns>
EMapEnv GetMazeData(int X, int Y);
EMapEnv GetMazeData(Position* Pos);
/// <summary>
/// 해당 위치의 타일 정보를 세팅하는 함수
/// </summary>
/// <param name="X">X좌표</param>
/// <param name="Y">Y좌표</param>
/// <param name="Data">세팅할 값</param>
void SetMazeData(int X, int Y, EMapEnv Data);

/// <summary>
/// 맵을 출력하는 함수
/// </summary>
void Print2DMap(Player& player);
/// <summary>
/// 주어진 좌표를 기준으로 상하좌우로 갈 수 있는지 판단하는 함수
/// </summary>
/// <param name="DirArr">상하좌우의 가능여부를 담는 배열</param>
/// <param name="PlayerX">플레이어의 X좌표</param>
/// <param name="PlayerPosY">플레이어의 ㅛ좌표</param>
void CheckDirCanGO(bool* DirArr, Player& player);

/// <summary>
/// 이동할 수 있는 방향을 출력하는 함수
/// </summary>
/// <param name="DirArr">상하좌우의 가능여부를 담는 배열</param>
void PrintChoiceScreen(bool* DirArr);

/// <summary>
/// 방향을 입력받는 함수 (wasd로 입력받아 방향값으로 반환)
/// </summary>
/// <returns>입력받은 방향, 비정상적인 값일 경우 EDirLength 반환</returns>
int GetDirInput();

/// <summary>
/// 랜덤 인카운더를 결정하는 함수
/// </summary>
/// <returns> 랜덤인카운터 플래그</returns>
int RandEncounter();

int GetRandMonsterIndex();

/// <summary>
/// 나와 몬스터의 체력을 출력하는 함수
/// </summary>
/// <param name="YoursHp">당신의 체력</param>
/// <param name="MonstersHP">몬스터의 체력</param>
void PrintHP(Player& InPlayer, Monster& monster);

/// <summary>
/// DiceMax면체의 주사위를 굴려서 반환하는 함수
/// </summary>
/// <param name="DiceMax">주사위의 최대값</param>
/// <returns></returns>
int RollDice(int DiceMax);

/// <summary>
/// 공격 데미지를 계산해서 반환하는 함수
/// </summary>
/// <param name="BaseDamage">기본 데미지</param>
/// <param name="DiceMax">주사위의 최대값</param>
/// <returns></returns>
int GetAdditiveDamageByDice(int DiceMax);

/// <summary>
/// 턴제 전투를 진행하는 함수
/// </summary>
/// /// <param name="InitailPlayerHp">플레이어 체력</param>
/// <returns>승리 여부</returns>
bool TurnBasedCombat(Player* player);

/// <summary>
/// MazeAdventure 실행 함수
/// </summary>
void MazePrac1_Run();

/// <summary>
/// 
/// </summary>
void InitMap();
void MazeAdventure();

void FindStart(int& OutX, int& OutY);
