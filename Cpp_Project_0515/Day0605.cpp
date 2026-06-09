#include "Day0605.h"
#include "MyLinkedList.h"
#include "MyVector.h"
#include <iostream>
#include <list>

void Eagle::FlyHigh()
{

}

void Daya0605EnumTest()
{
	Direction Dir = Direction::Up | Direction::Down;
	Dir |= Direction::Left;
	Dir &= Direction::Up;
	Dir = ~Dir;

	int temp = 0;
}

void Daya0605TestList()
{
	MyLinkedList* MyList = new MyLinkedList();
	printf("--- 초기 리스트 생성 ---\n");
	MyList->Add(10);
	MyList->Add(20);
	MyList->Add(30);
	MyList->PrintList();

	// 10 20 30
	printf("\n--- 1. InsertAt 테스트 ---\n");
	printf("1-1. 위치가 Size보다 클 때 (마지막에 추가):\n");
	// 10 20 30 40
	MyList->InsertAt(40, 100);
	MyList->PrintList();
	//5 10 20 30 40
	printf("\n1-2. 정상적인 추가 (위치 0에 5 추가):\n");
	MyList->InsertAt(5, 0);
	MyList->PrintList();

	MyList->InsertAt(15, 2);
	MyList->PrintList();

	printf("\n--- 2. Remove 테스트 ---\n");
	//5 10 30 40
	printf("2-1. 삭제할 노드가 있는 경우 (20 삭제):\n");
	MyList->Remove(20);
	MyList->PrintList();
	//5 10 30 40
	printf("\n2-2. 삭제할 노드가 없는 경우 (99 삭제 시도):\n");
	MyList->Remove(99);
	MyList->PrintList();

	printf("\n--- 3. RemoveAt 테스트 ---\n");
	printf("3-1. 위치가 Size와 같거나 클 때:\n");
	//5 10 30 40
	MyList->RemoveAt(5); // 현재 크기는 4이므로, 인덱스 4는 범위를 벗어남
	MyList->RemoveAt(99);
	MyList->PrintList();
	printf("\n3-2. 정상적인 삭제 (위치 1의 10 삭제):\n");
	//5 10 40
	MyList->RemoveAt(1);
	MyList->PrintList();

	printf("\n--- 4. Search 테스트 ---\n");
	printf("4-1. 찾는 노드가 있는 경우 (30 탐색):\n");
	//5 10 40
	int ValueToFind = 30;
	ListNode* FoundNode = MyList->Search(ValueToFind);
	if (FoundNode != nullptr)
	{
		printf("결과: %d 값을 가진 노드를 찾았습니다. (주소: %p, 데이터: %d)\n", ValueToFind, (void*)FoundNode, FoundNode->Data);
	}
	else
	{
		printf("결과: %d 값을 가진 노드를 찾지 못했습니다.\n", ValueToFind);
	}
	printf("\n4-2. 찾는 노드가 없는 경우 (123 탐색):\n");
	ValueToFind = 123;
	//5 10 40
	FoundNode = MyList->Search(ValueToFind);
	if (FoundNode != nullptr)
	{
		printf("결과: %d 값을 가진 노드를 찾았습니다.\n", ValueToFind);
	}
	else
	{
		printf("결과: %d 값을 가진 노드를 찾지 못했습니다.\n", ValueToFind);
	}

	printf("\n--- 프로그램 종료 (소멸자 호출) ---\n");
	MyList->Clear();
	MyList->PrintList();
	delete MyList;
	MyList = nullptr;
}

void Daya0605TestSTLList()
{
	std::list<int> MyList;

	MyList.push_back(10);
	MyList.push_front(10);

	auto itr = MyList.begin();

	MyList.insert(itr, 10);
	int Data = *itr;

	for (auto itr = MyList.begin(); itr != MyList.end(); itr++)
	{
		int date = *itr;
	}

	for (auto e : MyList)
	{
		int data = e;
		int temp = 3;
	}
	



}

void Daya0605TestVec()
{
	MyVector* MyVec = new MyVector();
	printf("초기 상태\n");
	MyVec->Print();
	MyVec->PrintSizeAndCapacity();

	printf("push_back(10)\n");
	MyVec->PushBack(10);
	printf("%d", (*MyVec)[0]);
	MyVec->Print();
	MyVec->PrintSizeAndCapacity();

	printf("push_back() 3회\n");
	MyVec->PushBack(20);
	MyVec->PushBack(30);
	MyVec->PushBack(40);
	MyVec->Print();
	MyVec->PrintSizeAndCapacity();


	printf("Reallocation 발생하는 경우\n");
	MyVec->PushBack(50);
	MyVec->Print();
	MyVec->PrintSizeAndCapacity();
	MyVec->PushBack(60);
	MyVec->Print();
	MyVec->PrintSizeAndCapacity();
	printf("Reallocation 발생하는 경우\n");
	MyVec->PushBack(70);
	MyVec->Print();
	MyVec->PrintSizeAndCapacity();
	MyVec->PushBack(80);
	MyVec->PushBack(90);
	MyVec->PushBack(100);

	printf("Reallocation 발생하는 경우\n");
	MyVec->Print();
	MyVec->PrintSizeAndCapacity();

	printf("push_back()\n");
	MyVec->PopBack();
	MyVec->Print();
	MyVec->PrintSizeAndCapacity();

	int currSize = static_cast<int>(MyVec->GetSize());

	printf("Size 가 0이 될때까지 pop_back()\n");
	while(currSize!=0)
	{
		MyVec->PopBack();
		currSize--;
	}
	MyVec->Print();
	MyVec->PrintSizeAndCapacity();

}
