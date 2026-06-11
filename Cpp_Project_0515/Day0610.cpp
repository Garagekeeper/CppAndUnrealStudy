#include "Day0610.h"
#include "BitFlag.h"
#include "BST.h"
#include "TemplateMyList.h"
#include "TemplateFixedStack.h"

#include <iostream>

void Day0610::Day0610_Run()
{
	//TestTemplateClass();
	//BSTTest();
	//TemplateListTest();
	TemplateStackTest();
}

void Day0610::TestTemplateClass()
{
	Coordinate<int> IntPos(1,3);
	Coordinate<float> FloatPos(0.5f, 0.7f);

	//printf("IntPos : %d, %d\n", IntPos.X, IntPos.Y);
	//printf("FloatPos : %f, %f\n", FloatPos.X, FloatPos.Y);

	IntPos.Print();
	FloatPos.Print();

	TestEnum t1 = TestEnum::Up;
	TestEnum t2 = TestEnum::Down;
	TestEnum t3 = t1 | t2;
	TestEnum t4 = t1 & t2;
	t4 |= t1;
	t4 &= t1;


	Calculator<int, float> Calc1;
	Calculator<float, int> Calc2;
	Calculator<float, float> Calc3;
	Calculator<int, int> Calc4;

	float temp = 0;
	/*temp = Calc1.Add(10, 2.0f);
	temp = Calc1.Sub(10, 2.0f);
	temp = Calc1.Mul(10, 2.0f);
	temp = Calc1.Div(10, 2.0f);

	temp = Calc2.Add(10, 2.0f);
	temp = Calc2.Sub(10, 2.0f);
	temp = Calc2.Mul(10, 2.0f);
	temp = Calc2.Div(10, 2.0f);

	temp = Calc3.Add(10, 2.0f);
	temp = Calc3.Sub(10, 2.0f);
	temp = Calc3.Mul(10, 2.0f);
	temp = Calc3.Div(10, 2.0f);

	int temp2 = 0;
	temp2 = Calc4.Add(10, 2.0f);
	temp2 = Calc4.Sub(10, 2.0f);
	temp2 = Calc4.Mul(10, 2.0f);
	temp2 = Calc4.Div(10, 3.0f);

	temp = 0;*/


}

void Day0610::BSTTest()
{
	BST bst;
	bst.Insert(40);
	bst.Insert(30);
	bst.Insert(50);

	bst.PrintPostOrder();
}

void Day0610::TemplateListTest()
{
	auto MyList = new TemplateMyLinkedList<float>();
	printf("--- 초기 리스트 생성 ---\n");
	MyList->Add(10.5f);
	MyList->Add(20.5f);
	MyList->Add(30.5f);
	MyList->PrintList();

	printf("\n--- 1. InsertAt 테스트 ---\n");
	printf("1-1. 위치가 Size보다 클 때 (마지막에 추가):\n");
	// 10 20 30 40
	MyList->InsertAt(40.5f, 100);
	MyList->PrintList();
	//5 10 20 30 40
	printf("\n1-2. 정상적인 추가 (위치 0에 5 추가):\n");
	MyList->InsertAt(5.5f, 0);
	MyList->PrintList();

	MyList->InsertAt(15.5f, 2);
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
	float ValueToFind = 30.5f;
	TemplateListNode<float>* FoundNode = MyList->Search(ValueToFind);
	printf("\n4-2. 찾는 노드가 없는 경우 (123 탐색):\n");
	ValueToFind = 123.5f;
	FoundNode = MyList->Search(ValueToFind);

	printf("\n--- 프로그램 종료 (소멸자 호출) ---\n");
	MyList->Clear();
	MyList->PrintList();
	delete MyList;
	MyList = nullptr;
}

void Day0610::TemplateStackTest()
{
	printf("--- FixedStack 테스트 시작 ---\n\n");

	TemplateFixedStack<float, 10> stack;

	// 1. 초기 상태 테스트
	printf("1. 초기 상태 테스트\n");
	printf("스택이 비었나요? %s\n", stack.IsEmpty() ? "예" : "아니요");
	printf("현재 크기: %d\n", stack.GetSize());
	printf("\n");

	// 2. Push 테스트
	printf("2. Push 테스트\n");
	printf("Push: 10\n");
	stack.Push(10.5);
	stack.PrintState();

	printf("Push: 20\n");
	stack.Push(20.5);
	stack.PrintState();

	printf("Push: 30\n");
	stack.Push(30.5);
	stack.PrintState();
	printf("\n");

	// 3. Pop 테스트
	printf("3. Pop 테스트\n");
	printf("Pop 실행\n");
	stack.Pop();
	stack.PrintState();
	printf("\n");

	// 4. 경계 테스트: 스택 오버플로우 (Stack Overflow)
	printf("4. 경계 테스트: 오버플로우\n");
	printf("스택을 가득 채웁니다...\n");
	// 현재 2개의 원소(10, 20)가 있으므로, 8개를 더 추가하면 가득 참 (용량: 10)
	for (int i = 3; i <= 10; ++i)
	{
		int value = i * 10 + .5;
		stack.Push(value);
	}
	printf("스택이 꽉 찼나요? %s\n", stack.IsFull() ? "예" : "아니요");
	stack.PrintState();

	printf("\n오버플로우 시도: Push 110\n");
	stack.Push(110); // "오류: 스택이 꽉 찼습니다!" 메시지 출력 예상
	stack.PrintState(); // 변화 없음
	printf("\n");

	// 5. 경계 테스트: 스택 언더플로우 (Stack Underflow)
	printf("5. 경계 테스트: 언더플로우\n");
	printf("모든 원소를 Pop 합니다...\n");
	while (!stack.IsEmpty())
	{
		stack.Pop();
	}
	printf("스택이 비었나요? %s\n", stack.IsEmpty() ? "예" : "아니요");
	stack.PrintState();

	printf("\n언더플로우 시도 (Pop)\n");
	stack.Pop(); // "오류: 스택이 비어있습니다!" 메시지 출력 예상

	printf("\n언더플로우 시도 (Top)\n");
	float topValue = stack.Top(); // "오류: ..." 메시지 출력 예상
	printf("Top 호출 결과: %d\n", topValue); // Empty(-1) 값 출력 예상
	printf("\n");

	printf("--- FixedStack 테스트 종료 ---\n");
}
