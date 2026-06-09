#pragma once

/*
	스택
		- LIFO
		- Push
		- Pop
		- Seek
		- Top
		- 단순한 구조, 구현이 쉬움
		- Data저장 및 읽기 속도가 빠름
		- Popup, Undo, call stack
		- 제한적인 활용도

	큐
		- FIFO
		- Enqueue
		- Dequeue
		- Front
		- Rear
		- 제한적인 활용도

	
	템플릿
		- 

	* 함수 파라미터로 클래스 넘기면 복사 생성자 실행됨

*/

class Day0609
{
public:
	void Day0609_Main();
	void Day0609_Stack();

private:
	void TestStack();
	void TestQueue();
};