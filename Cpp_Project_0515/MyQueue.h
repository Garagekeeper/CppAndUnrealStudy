#pragma once
class MyQueue
{

private:
	static constexpr int	InitCapacity = 10;
	static constexpr int	Empty = -1;
	int*					Data;
	int						Front = Empty;
	int						Rear  = Empty;
	int						Capacity = InitCapacity;
	int						Size = 0;

public:
							MyQueue() : Data(new int[InitCapacity]) {}
							MyQueue(int Capacity) : Capacity(Capacity), Data(new int[Capacity]) {}
							~MyQueue();
	void					Enqueue(int InValue);
	int						Dequeue();
	int						Peek() const;
	void					Print();
	bool					Reallocation();
	
	inline bool				IsFull() const { return (Rear + 1) % Capacity == Front; }
	inline bool				IsEmpty() const { return Front == -1; }
	inline int				GetSize() const { return (Rear + Capacity - Front) % Capacity + 1; }
	inline int				GetCapacity() const { return Capacity; }
	inline int				GetEmpty() const { return Empty; }


};

