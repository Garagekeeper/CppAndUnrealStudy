#pragma once
#include <iostream>
template <typename T>
class TemplateMyVector
{
	const int InitCapacity = 4;
	T* DataArr;
	size_t Size;
	size_t Capacity;

public:
	TemplateMyVector() = default;
	~TemplateMyVector();
	void Reserve(size_t Amount);
	void PushBack(T Data);
	T PopBack();
	void Print();
	void Clear();
	bool Reallocation();
	void PrintSizeAndCapacity();

	int& operator[](size_t index)
	{
		return DataArr[index];
	}

	inline size_t GetSize() {return Size;}
	inline bool IsFull() { return Size == Capacity; }
};

template<typename T>
TemplateMyVector<T>::~TemplateMyVector()
{
	delete[] DataArr;
	DataArr = nullptr;
}

template<typename T>
void TemplateMyVector<T>::Reserve(size_t Amount)
{
	if (DataArr != nullptr)
	{
		delete[] DataArr;
	}

	DataArr = new T[Amount];
}

template<typename T>
void TemplateMyVector<T>::PushBack(T Data)
{
	bool bTryReallocation = true;
	if (IsFull())
	{
		bTryReallocation = Reallocation();
		if (bTryReallocation == false)
			printf("Reallocation 실패");
	}

	DataArr[Size] = Data;
	Size++;
}

template<typename T>
T TemplateMyVector<T>::PopBack()
{
	return DataArr[Size--];
}

template<typename T>
void TemplateMyVector<T>::Print()
{

	for (int i = 0; i < Size; i++)
	{
		if constexpr (std::is_same_v<T, int>)
		{
			printf("[%d] ", DataArr[i]);
		}
		else if constexpr (std::is_same_v<T, unsigned int>)
		{
			printf("[%u] ", DataArr[i]);
		}
		else if constexpr (std::is_same_v<T, float>)
		{
			printf("[%f] ", DataArr[i]);
		}
		else if constexpr (std::is_same_v<T, double>)
		{
			printf("[%lf] ", DataArr[i]);
		}
		else
		{
			std::cout << DataArr[i] << " ";
		}
	}

	printf("\n");
}

template<typename T>
void TemplateMyVector<T>::Clear()
{
	if (DataArr)
	{
		delete[] DataArr;
		DataArr = nullptr;
	}

	Size = 0;
	Capacity = InitCapacity;
	Reserve(Capacity);
}

template<typename T>
bool TemplateMyVector<T>::Reallocation()
{
	bool Res = true;
	Capacity = static_cast<int>(Capacity * 1.5);
	T* NewData = new T[Capacity];

	if (NewData == nullptr)
	{
		Res = false;
	}

	for (int i = 0; i < Size; i++)
	{
		*(NewData + i) = *(DataArr + i);
	}

	delete[] DataArr;
	DataArr = nullptr;

	DataArr = NewData;

	return Res;
}

template<typename T>
void TemplateMyVector<T>::PrintSizeAndCapacity()
{
	printf("Size : %d, Capacity %d\n\n", static_cast<int>(Size), static_cast<int>(Capacity));
}