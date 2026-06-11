#include "MyQueue.h"
#include <iostream>

MyQueue::~MyQueue()
{
	delete[] Data;
	Data = nullptr;
}

void MyQueue::Enqueue(int InValue)
{
	if (IsFull())
	{
		printf("큐가 가득 차있어 Reallocation을 수행합니다.\n");
		bool ReallocationRes = Reallocation();
		if (!ReallocationRes)
		{
			printf("Reallocation 실패!\n");
			return;
		}
	}

	if (IsEmpty())
		Front = 0;

	Rear = (Rear + 1) % Capacity;
	Data[Rear] = InValue;

}


int MyQueue::Dequeue()
{
	int Res = Empty;

	if (IsEmpty())
	{
		printf("Queue가 비어있습니다.");
	}
	else if (Front == Rear)
	{
		Front = Rear = Empty;
	}
	else
	{
		Res = Data[Front];
		Front = (Front + 1) % Capacity;

	}


	return Res;
}

int MyQueue::Peek() const
{
	int Res = Empty;
	if (IsEmpty())
	{
		printf("Queue가 비어있습니다.");
	}
	else
	{
		Res = Data[Front];
	}

	return Res;
}

void MyQueue::Print()
{
	if (IsEmpty())
	{
		printf("Queue가 비어있습니다.");
	}
	else
	{
		int Size = GetSize();
		for (int i = 0; i < Size; i++)
		{
			int PeekVal = Peek();
			printf("%d ", PeekVal);
			int FrontVal = Dequeue();
			Enqueue(FrontVal);
		}
		printf("\n");
	}
}

bool MyQueue::Reallocation()
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
		for (int i = 0; i < Capacity; i++)
		{
			*(NewData + i) = *(Data + i);
		}

		delete[] Data;
		Data = nullptr;

		Data = NewData;
	}

	return Res;
}


