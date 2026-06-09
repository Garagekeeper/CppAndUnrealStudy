#pragma once
#include <vector>

class MyStack
{
	static constexpr int	InitialCapacity = 10;
	static constexpr int	StackEmpty = -1;

	int						TopIndex = StackEmpty;
	int						Capacity = 10;
	int						Size = 0;
	int*					Data;
	//std::vector<int>		Data;

public:
							MyStack() : Data(new int[InitialCapacity]) {}
							~MyStack();
							//MyStack() : Data(td::vector<int>(InitialCapacity)) {}

	void					Push(int InData);
	int						Pop();
	int						Top() const;
	inline int				GetSize() const { return TopIndex + 1; }
	inline bool				IsEmpty() const { return TopIndex == StackEmpty; };
	inline bool				IsFull() const {  return TopIndex == Capacity - 1; }
	bool					Reallocation();
};

class FixedStack
{
private:
	static constexpr int	Capacity = 10;
	static constexpr int	StackEmpty = -1;

	int						TopIndex = StackEmpty;
	int						Size = 0;
	int						Data[Capacity];

public:

	void					Push(int InData);
	int						Pop();
	int						Top() const;
	inline int				GetSize() const { return TopIndex + 1; }
	inline bool				IsEmpty() const { return TopIndex == StackEmpty; };
	inline bool				IsFull() const { return TopIndex == Capacity - 1; };
};

