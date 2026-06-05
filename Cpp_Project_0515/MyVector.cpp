#include "MyVector.h"
#include <iostream>

MyVector::MyVector()
{
	DataArr = new int[InitCapacity];
	Capacity = InitCapacity;
	Size = 0;
}

MyVector::~MyVector()
{
	Clear();
}

void MyVector::Reserve(size_t Amount)
{
	if (DataArr != nullptr)
	{
		delete[] DataArr;
	}

	DataArr = new int[Amount];
}

void MyVector::PushBack(int Data)
{
	if (Size == Capacity)
		Reallocation();

	DataArr[Size] = Data;
	Size++;
}

int MyVector::PopBack()
{
	return DataArr[Size--];
}

void MyVector::Print()
{
	for (int i = 0; i < Size; i++)
	{
		printf("[%d] ", DataArr[i]);
	}

	printf("\n");
}

void MyVector::Clear()
{
	if (DataArr)
	{
		delete[] DataArr;
	}

	Size = 0;
	Capacity = 4;
	Reserve(Capacity);
}

void MyVector::Reallocation()
{
	Capacity = static_cast<int>(Capacity * 1.5);
	int* NewData = new int[Capacity];
	for (int i = 0; i < Size; i++)
	{
		*(NewData+i) = *(DataArr+i);
	}

	delete[] DataArr;
	DataArr = nullptr;

	DataArr = NewData;
}

void MyVector::PrintSizeAndCapacity()
{
	printf("Size : %d, Capacity %d\n\n", static_cast<int>(Size), static_cast<int>(Capacity));
}
