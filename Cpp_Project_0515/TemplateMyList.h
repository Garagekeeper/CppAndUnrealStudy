#pragma once
#include <iostream>

template<typename T>
struct TemplateListNode
{
	T Data = 0;
	TemplateListNode<T>* Next = nullptr;
	TemplateListNode(T InData) : Data(InData) {}
};

template<typename T>
class TemplateMyLinkedList
{

	TemplateListNode<T>* Head = nullptr;
	TemplateListNode<T>* Tail = nullptr;
	int Size = 0;

public:
	TemplateMyLinkedList() = default;
	~TemplateMyLinkedList();

	void Add(T InData);						// 리스트의 마지막에 데이터를 추가하는 함수
	void InsertAt(T InData, int InPosition);	// 리스트의 중간에 데이터를 추가하는 함수
	void Remove(T InData);					// 특정 데이터를 가지는 노드를 제거하는 함수
	void RemoveAt(int InPosition);				// 특정 번째의 노드를 제거하는 함수
	TemplateListNode<T>* Search(T InData) const;			// 특정 데이터가 있는지 확인하는 함수. 리턴이 null이면 없다. null이 아니면 찾은 노드
	void Clear();								// 모든 노드를 제거하는 함수
	void PrintList() const;
};


template<typename T>
TemplateMyLinkedList<T>::~TemplateMyLinkedList()
{
	Clear();
}

template<typename T>
void TemplateMyLinkedList<T>::Add(T Data)
{
	TemplateListNode<T>* NewNode = new TemplateListNode<T>(Data);
	if (Head == nullptr)
	{
		Head = NewNode;
		Tail = NewNode;
	}
	else
	{
		Tail->Next = NewNode;
		Tail = NewNode;
	}
	Size++;
}

template<typename T>
void TemplateMyLinkedList<T>::InsertAt(T Data, int Index)
{
	if (Index == 0)
	{
		TemplateListNode<T>* NewNode = new TemplateListNode<T>(Data);

		NewNode->Next = Head;
		Head = NewNode;
	}
	else if (Index >= Size - 1)
	{
		Add(Data);
		return;
	}
	else
	{
		TemplateListNode<T>* NewNode = new TemplateListNode<T>(Data);
		TemplateListNode<T>* Prev = Head;
		TemplateListNode<T>* Curr = Head;
		for (int i = 0; i < Index; i++)
		{
			Prev = Curr;
			Curr = Curr->Next;
		}

		Prev->Next = NewNode;
		NewNode->Next = Curr;
	}

	++Size;
}

template<typename T>
void TemplateMyLinkedList<T>::Remove(T InData)
{
	TemplateListNode<T>* TargetNode = Search(InData);
	if (TargetNode)
	{
		TemplateListNode<T>* TargetPrev = Head;
		if (TargetNode == Head)
		{
			Head = TargetNode->Next;
		}
		else
		{
			while (TargetPrev->Next != TargetNode)
				TargetPrev = TargetPrev->Next;

			TargetPrev->Next = TargetNode->Next;

			if (TargetNode == Tail) Tail = TargetPrev;
		}

		delete TargetNode;
		TargetNode = nullptr;
		--Size;
	}
}

template<typename T>
void TemplateMyLinkedList<T>::RemoveAt(int InPosition)
{
	if (Size <= InPosition)
	{
		printf("Err [MyLinkedList RenoveAt()] : invalide index\n");
		return;
	}

	TemplateListNode<T>* Prev = Head;
	TemplateListNode<T>* Target = nullptr;
	int TargetIndex = InPosition - 1;
	for (int i = 0; i < TargetIndex; i++)
	{
		Prev = Prev->Next;
	}

	if (InPosition == 0)
	{
		Target = Head;
		Head = Target->Next;
		if (Head == nullptr)
			Tail = nullptr;
	}
	else if (InPosition == Size - 1)
	{

		Target = Tail;
		Tail = Prev;
		Prev->Next = nullptr;
	}
	else
	{
		Target = Prev->Next;
		Prev->Next = Target->Next;
	}


	delete Target;
	Target = nullptr;

	--Size;
}

template<typename T>
TemplateListNode<T>* TemplateMyLinkedList<T>::Search(T InData) const
{
	TemplateListNode<T>* CurrentNode = Head;
	TemplateListNode<T>* Res = nullptr;
	while (CurrentNode)
	{
		if constexpr (std::is_same_v<T, float>)
		{
			float diff = InData - CurrentNode->Data;
			if (diff < 0) diff *= -1;
			if (diff < 0.001f) 
			{
				Res = CurrentNode;
				break;
			}
		}
		else if constexpr (std::is_same_v<T, double>)
		{
			double diff = InData - CurrentNode->Data;
			if (diff < 0) diff *= -1;
			if (diff < 0.000001)
			{
				Res = CurrentNode;
				break;
			}
		}
		else
		{
			if (CurrentNode->Data == InData)
			{
				Res = CurrentNode;
				break;
			}
		}


		CurrentNode = CurrentNode->Next;
	}

	if (Res)
	{
		if constexpr (std::is_same_v<T, double> || std::is_same_v<T, float>)
			printf("결과: %f 값을 가진 노드를 찾았습니다. (주소: %p, 데이터: %f)\n", InData, (void*)Res, Res->Data);
		else
			printf("결과: %d 값을 가진 노드를 찾았습니다. (주소: %p, 데이터: %d)\n", InData, (void*)Res, Res->Data);
	}
	else
	{
		if constexpr (std::is_same_v<T, double> || std::is_same_v<T, float>)
			printf("결과: %f 값을 가진 노드를 찾지 못했습니다.\n", InData);
		else 
			printf("결과: %d 값을 가진 노드를 찾지 못했습니다.\n", InData);
	}

	return Res;
}

template<typename T>
void TemplateMyLinkedList<T>::Clear()
{
	while (Head)
	{
		RemoveAt(0);
	}
}

template<typename T>
void TemplateMyLinkedList<T>::PrintList() const
{
	TemplateListNode<T>* Curr = Head;
	while (Curr != nullptr)
	{
		std::cout <<"[ " << Curr->Data << " ]";
		Curr = Curr->Next;
	}
	printf("nullptr \n");
}