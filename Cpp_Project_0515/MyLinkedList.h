#pragma once
struct ListNode
{
	int Data = 0;
	ListNode* Next = nullptr;

	ListNode(int InData) : Data(InData) {}
};

class MyLinkedList
{

	ListNode* Head = nullptr;
	ListNode* Tail = nullptr;
	int Size = 0;

public:
	MyLinkedList() = default;
	~MyLinkedList();

	void Add(int InData);						// 리스트의 마지막에 데이터를 추가하는 함수
	void InsertAt(int InData, int InPosition);	// 리스트의 중간에 데이터를 추가하는 함수
	void Remove(int InData);					// 특정 데이터를 가지는 노드를 제거하는 함수
	void RemoveAt(int InPosition);				// 특정 번째의 노드를 제거하는 함수
	ListNode* Search(int InData) const;			// 특정 데이터가 있는지 확인하는 함수. 리턴이 null이면 없다. null이 아니면 찾은 노드
	void Clear();								// 모든 노드를 제거하는 함수
	void PrintList() const;
};

