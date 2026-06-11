#pragma once
#include <iostream>

template <typename T>
class TemplateMyQueue
{

private:
	static constexpr int	InitCapacity = 10;
	static constexpr int	Empty = -1;
	T*						Data;
	int						Front = Empty;
	int						Rear  = Empty;
	int						Capacity = InitCapacity;
	int						Size = 0;

public:
							TemplateMyQueue() : Data(new T[InitCapacity]) {}
							TemplateMyQueue(int Capacity) : Capacity(Capacity), Data(new T[Capacity]) {}
							~TemplateMyQueue();
	void					Enqueue(T InValue);
	T						Dequeue();
	T						Peek() const;
	void					Print();
	bool					Reallocation();
	
	inline bool				IsFull() const { return (Rear + 1) % Capacity == Front; }
	inline bool				IsEmpty() const { return Front == -1; }
	inline int				GetSize() const { return (Rear + Capacity - Front) % Capacity + 1; }
	inline int				GetCapacity() const { return Capacity; }
	inline int				GetEmpty() const { return Empty; }


};

template<typename T>
TemplateMyQueue<T>::~TemplateMyQueue()
{
	delete[] Data;
	Data = nullptr;
}

template<typename T>
inline void TemplateMyQueue<T>::Enqueue(T InValue)
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

template<typename T>
inline T TemplateMyQueue<T>::Dequeue()
{

	T Res = Empty;

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

template<typename T>
inline T TemplateMyQueue<T>::Peek() const
{
	T Res = Empty;
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

template<typename T>
inline void TemplateMyQueue<T>::Print()
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
			T PeekVal = Peek();
			if constexpr (std::is_same_v<T, int>)
			{
				printf("%d ", PeekVal);
			}
			else if constexpr (std::is_same_v<T, unsigned int>)
			{
				printf("%u ", PeekVal);
			}
			else if constexpr (std::is_same_v<T, float>)
			{
				printf("%f ", PeekVal);
			}
			else if constexpr (std::is_same_v<T, double>)
			{
				printf("%lf ", PeekVal);
			}
			else
			{
				std::cout << PeekVal << " ";
			}

			T FrontVal = Dequeue();
			Enqueue(FrontVal);
		}
		printf("\n");
	}
}

template<typename T>
inline bool TemplateMyQueue<T>::Reallocation()
{
	bool Res = true;
	Capacity = Capacity * 2;
	T* NewData = new T[Capacity];
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




