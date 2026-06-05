#pragma once
class MyVector
{
	const int InitCapacity = 4;
	int* DataArr;
	size_t Size;
	size_t Capacity;

public:
	MyVector();
	~MyVector();
	void Reserve(size_t Amount);
	void PushBack(int Data);
	int PopBack();
	void Print();
	void Clear();
	void Reallocation();
	void PrintSizeAndCapacity();

	int& operator[](size_t index)
	{
		return DataArr[index];
	}

	inline size_t GetSize() {return Size;}
};

