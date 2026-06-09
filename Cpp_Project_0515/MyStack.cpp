#include "MyStack.h"
#include <iostream>


#pragma region DynamicRangeStack
MyStack::~MyStack()
{
	delete[] Data;
	Data = nullptr;
}
void MyStack::Push(int InData)
{
	if (IsFull())
	{
		printf("스택이 가득 차있어 Reallocation을 수행합니다.\n");
		bool ReallocationRes = Reallocation();
		if (!ReallocationRes)
		{
			printf("Reallocation 실패!\n");
			return;
		}


	}

	TopIndex++;
	Size++;
	Data[TopIndex] = InData;
}

int MyStack::Pop()
{
	int Res = StackEmpty;
	if (!IsEmpty())
	{
		Res = Data[TopIndex];
		TopIndex--;
		Size--;
	}
	else
	{
		printf("스택이 비어 있어 Pop을 진행할 수 없습니다.\n");
	}

	return Res;
}

int MyStack::Top() const
{
	int Res = StackEmpty;
	if (!IsEmpty())
	{
		Res = Data[TopIndex];
	}
	else
	{
		printf("스택이 비어 있습니다.\n");
	}

	return Res;
}

bool MyStack::Reallocation()
{
	bool Res = true;
	Capacity = Capacity * 2;
	int* NewData = new int[Capacity];
	if (NewData == nullptr)
	{
		Res = false;
	}
	else
	{
		for (int i = 0; i < Size; i++)
		{
			*(NewData + i) = *(Data + i);
		}

		delete[] Data;
		Data = nullptr;

		Data = NewData;
	}

	return Res;
}


#pragma endregion


#pragma region FixedStack
void FixedStack::Push(int InData)
{
	if (!IsFull())
	{
		TopIndex++;
		Size++;
		Data[TopIndex] = InData;
	}
	else
	{
		printf("스택이 가득 차있어 Push를 진행할 수 없습니다.\n");
	}
}

int FixedStack::Pop()
{
	int Res = StackEmpty;
	if (!IsEmpty())
	{
		Res = Data[TopIndex];
		TopIndex--;
		Size--;
	}
	else
	{
		printf("스택이 비어 있어 Pop을 진행할 수 없습니다.\n");
	}

	return Res;
}


#pragma endregion

