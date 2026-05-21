#pragma once
#include <iostream>

using namespace std;

void PrintPlayerState(int State);
inline char PrintPlayerStateCheck(int PlayerState, int TargetState)
{
	return (PlayerState & (1 << TargetState)) ? 'O' : 'X';
}
void AddState(int State);
void RemoveState(int State);
void ToggleState(int State);
void RunPracticeOne();