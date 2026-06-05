#pragma once
#include <type_traits>
/*
	인터페이스
		- 구현 없이 함수 선언만 있는 클래스
			- 사실 추상 클래스를 인터페이스처럼 쓰는 것 (실제 인터페이스는 아님)
				- 추상 클래스에 멤버를 넣어도 컴파일 에러는 아님
				- 근데 그냥 안하는걸 권장
			- 언리얼을 지원함
			- 반드시 public 함수의 선언만 있어야함.
			- 구현이 있으면 안됨
			- 변수도 있으면 안됨
			- 추상 클래스 자체로는 인스턴스화 할 수 없음
			- 소멸자가 반드시 있어야함
		- 해당 인터페이스를 상속받은 클래스는 반드시 인터페이스의 내용을 구현해한다.
		- 인터페이스만 봐도 무슨 역할인지 알 수 있음
		- 일종의 약속
		- 다이아몬드 문제 해결
		- 앞에 접두사I를 붙여서 인터페이스임을 표시
			- I + ~Able 식으로 이름 붙여주기
			
		* C++에서 한 번 가상 함수로 메소드를 선언했다면, 그 메소드는 상속 계층 전체에서 계속 가상 함수로 취급됨.
		사실 자식의 메소드 시그니처가 부모의 virtual 메소드 시그니처와 같기만 하면 자동으로 오버라이드가 일어난다.
		하지만 명시적으로 override를 붙여주는 게 좋다.

	enum class
		- 더 안전한(불편한) enum
		- 타입 안정성이 강화됨
			- 일반 enum의 암시적 변환은 논리적 오류가 있을 수 있음
				- Color MyColor = Red;
				- Fruit MyFruit = Apple
				MyColor == MyFruit <- true(숫자로만 보면 맞는말이지만, 논리적으로 보면 말이 안댐)
			- 정수형이랑 명시적 변환을 해줘야 함
				- Color MyColor = Color::Red;
				- Fruit MyFruit = Fruit::Apple
				MyColor == MyFruit <- 문법 자체가 성립이 안됨
		- 이름 겹침 문제를 줄일 수 있음
		- 사이즈를 지정해줄 수 있음 (정수형)
			- enum class AnimalType : char
			- 타입 하나 표현하는데 char 타입사용
		- 비트연산 오버로딩 해서 비트연산 사용가능
			- 알아보기 편함(뭐랑 뭐가 합쳐진건지 보임)
		- 언리얼에서는 안씀

	* #include<cstint>
		- int8_t, int16_t 이런식으로 구분하기 쉽게 만들어져 있음.
	* #include <type_traits>
		- using RealType = std::underlying_type_t<AnimalType>;
		- RealType이 int8_t, int 이런식으로 나옴


	자료 구조
		- 데이터를 어떻게 보관할 것인지.
		- 배열, 리스트, 스택, 큐, 트리, 그래프

		배열
			- 랜덤 액세스 빠름
			- 고정크기
			- 중간 삽입 삭제 시간 걸림

		리스트 (재생 목록, 턴 순서 관리, 버프 디버프)
			- 중간 삽입삭제 빠름
			- 가변 길이
			- 랜덤 액세스가 느림 (탐색 속도가 느림)
			- 추가적인 메모리 필요(이전 이후 노드 기록)
			- 이중 연결 리스트

		벡터
			- 리저브 해놓는게 좋다.
			- size와 capacity
			
*/

// 추상 클래스 
class IFlyable
{
public:
	// 순수 가상함수
	virtual void FlyHigh() = 0;
	virtual ~IFlyable() = default;
};

class Eagle : public IFlyable
{
public :
	void FlyHigh();
};
// 간단실습 0602에 인터페이 붙이기


enum class Direction : int8_t
{
	Up = 1 << 0,
	Down = 1 << 1,
	Left = 1 << 2,
	Right = 1 << 3,
};

using DirectionType = std::underlying_type_t<Direction>;

inline Direction operator|(Direction Inleft, Direction InRight)
{
	return static_cast<Direction>(static_cast<DirectionType>(Inleft) | static_cast<DirectionType>(InRight));
}

inline Direction operator&(Direction Inleft, Direction InRight)
{
	return static_cast<Direction>(static_cast<DirectionType>(Inleft) & static_cast<DirectionType>(InRight));
}

inline Direction operator~(Direction InVal)
{
	return static_cast<Direction>(~static_cast<DirectionType>(InVal));
}

inline Direction& operator|=(Direction& Inleft, Direction InRight)
{
	Inleft = Inleft | InRight;
	return Inleft;
}

inline Direction& operator&=(Direction& Inleft, Direction InRight)
{
	Inleft = Inleft & InRight;
	return Inleft;
}

void Daya0605EnumTest();
void Daya0605TestList();
void Daya0605TestSTLList();
void Daya0605TestVec();