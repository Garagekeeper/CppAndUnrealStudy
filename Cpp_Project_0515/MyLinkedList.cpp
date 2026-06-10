#include <iostream>
#include "MyLinkedList.h"

MyLinkedList::~MyLinkedList()
{
	Clear();
}

void MyLinkedList::Add(int Data)
{
	ListNode* NewNode = new ListNode(Data);
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


void MyLinkedList::InsertAt(int Data, int Index)
{
	if (Index == 0)
	{
		ListNode* NewNode = new ListNode(Data);

		NewNode->Next = Head;
		Head = NewNode;
	}
	else if (Index >=Size - 1)
	{
		Add(Data);
		return;
	}
	else
	{
		ListNode* NewNode = new ListNode(Data);
		ListNode* Prev = Head;
		ListNode* Curr = Head;
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

void MyLinkedList::Remove(int InData)
{
	ListNode* TargetNode = Search(InData);
	if (TargetNode)
	{
		ListNode* TargetPrev = Head;
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

void MyLinkedList::RemoveAt(int InPosition)
{
	if (Size <= InPosition)
	{
		printf("\n\nErr [MyLinkedList RenoveAt()] : invalide index\n\n");
		return;
	}

	ListNode* Prev = Head;
	ListNode* Target = nullptr;
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

ListNode* MyLinkedList::Search(int InData) const
{
	ListNode* CurrentNode = Head;
	ListNode* Res = nullptr;
	while (CurrentNode)
	{
		if (CurrentNode->Data == InData)
		{
			Res = CurrentNode;
			break;
		}

		CurrentNode = CurrentNode->Next;
	}

	return Res;
}

void MyLinkedList::Clear()
{
	while (Head)
	{
		RemoveAt(0);
	}
}

void MyLinkedList::PrintList() const
{
	ListNode* Curr = Head;
	while (Curr != nullptr)
	{
		printf("[%d] -> ", Curr->Data);
		Curr = Curr->Next;
	}
	printf("nullptr \n");
}
