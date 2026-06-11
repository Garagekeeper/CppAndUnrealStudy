#pragma once

template<typename T, int Capacity>
class TemplateFixedStack
{
public:
    void Push(T value);
    T Pop();
    T Top();

    void PrintState();
    inline bool IsFull() const { return TopIndex == (StackCapacity - 1); }
    inline bool IsEmpty() const { return TopIndex == Empty; }
    inline int GetSize() const { return TopIndex + 1; }

private:
    static constexpr int StackCapacity = Capacity;
    static constexpr int Empty = -1;

    T Data[StackCapacity];
    int TopIndex = Empty;
};

template<typename T, int Capacity>
void TemplateFixedStack<T, Capacity>::PrintState()
{
    if constexpr (std::is_same_v<T, double> || std::is_same_v<T, float>)
        if (Top() - Empty < 0.001f)
            printf("Top: %d, Size: %d\n", static_cast<int>(Top()), GetSize());
        else 
            printf("Top: %f, Size: %d\n", Top(), GetSize());
    else
        printf("Top: %d, Size: %d\n", Top(), GetSize());
    
}

template<typename T, int Capacity>
void TemplateFixedStack<T, Capacity>::Push(T InValue)
{
    if (IsFull())
    {
        printf("오류: 스택이 꽉 찼습니다! (Stack Overflow)\n");
        return;
    }
    TopIndex++;
    Data[TopIndex] = InValue;
}

// 스택에서 원소를 제거합니다.
template<typename T, int Capacity>
T TemplateFixedStack<T, Capacity>::Pop()
{
    if (IsEmpty())
    {
        printf("오류: 스택이 비어있습니다! 값을 반환할 수 없습니다.\n");
        return Empty;
    }
    T Result = Data[TopIndex];
    TopIndex--;
    return Result;
}

// 스택의 최상단 원소를 확인합니다.
template<typename T, int Capacity>
T TemplateFixedStack<T, Capacity>::Top()
{
    if (IsEmpty())
    {
        printf("오류: 스택이 비어있습니다! 값을 반환할 수 없습니다.\n");
        return Empty;
    }
    return Data[TopIndex];
}

