#pragma once
/*
	템플릿 클래스
		- 템플릿 함수와 같음. 코드 중복을 줄이는 것이 목적
		- 컴파일 타임에 템플릿을 사용하는 코드가 나오면 컴파일러가 생성(템플릿 인스턴스화)
		- 이항 연산자는 구조체 밖에서 연산자 오버로딩 하는게 정석
		- 템플릿 클래스의 맴버 함수는 헤더에 선언
			- 실제 사용될 때 코드를 생성하기 때문에
				- 바이트코드를 생성하려면 구현이 필요함 그런데 다른 파일을 접근이 불가능
				- 물론 헤더파일이 가능하게 해주지만 템플릿은 이게 안된데여

	// 소수 같은지 비교
	// 매우 큰 수도 상대오차로 비교
	template<typename T>
	inline bool TemplateMyLinkedList<T>::IsEqual(T Left, T Right)
	{
		bool Res = false;
		//if constexpr (std::is_same_v<T, float> || std::is_same_v<T, double>)
		if constexpr (std::is_floating_point_v<T>)
		{
			float diff = std::abs(Left - Right);
			Res = diff <= std::numeric_limits<T>::epsilon() * std::max(std::(Left), std::abs(Right));
		}
		else
		{
			Res = Left == Right;
		}

		return Res;
	}

	//소수 같은이 비교 c++ 20 이상
	//c++20이상
	// 클래스 자체가 아래 형식으로 되어야 사용가능
	// 아니면 함수 선언할 때 부터 require를 붙이던가
	//#include <concepts>
	
	template <std::floating_point T>
	bool IsEqula(T Left, T Right)
	{
		float diff = std::abs(Left - Right);
		return = diff <= std::numeric_limits<T>::epsilon() * std::max(std::(Left), std::abs(Right));
	}
	
	template <std::integral T>
	bool IsEqula(T Left, T Right)
	{
		Res = Left == Right;
	}

	typename std::enable_if_t<std::is_enum_v<T>, T> operator|(T Left, T Right)
	T가 Enum일 경우에만 코드를 생성

	std::underlying_type_t<T>
	T의 본질적인 타입을 리턴

	트리
		- 특징 부모-자식 관계를 가지는 계층적 구조를 나타내는 구조
			- 하나의 Root에서 시작하여 가지가 뻗어나가는 형태
			- 순환이 없는 그래프의 한 구조
			- 대표적인 비선형 자료구조
		- 장점 
			- 계층적인 데이터를 표혀하기에 최적화됨
			- 탐색과 정렬에 효율적
			- 배열과 리스트의 장점을 둘 다 가짐
		- 단점
			- 구조가 복잡하고 구현이 어려울 수 있다.
			- 추가/삭제가 복잡할 수 있다.
		- 순회
			- 전 ULR
			- 중 LUR
			- 후 LRU

	set
		- RBTree 기반으로 구현 (찾아보기, O(logN))
		- 자동 정렬
		- 집합이라는 이름답게 중복이 안됨
		- 탐색 속도 빠름
		- 데이터의 유일성, 정렬, 빠른 검색
		- 사용자 정의 구조체/클래스를 넣으려면 operator<를 오버로딩
		- bool operator<(const T& t) const

	map
		- Key valu 쌍으로 보관, Key 중복 안됨, 빠른 탐색 O(logN)
		- []연산자로 접근 가능, 단 []로 접근하면 없었던 경우는 기본값으로 생성해버림
		- 리소스 관리자, 데이터 드리븐, 다국어 지원 등

	unordered_map
		- 해시 테이블 기반 O(1)
		- 쌍 저장, Key 중복 안됨, 빠른 탐색
		- struct hash<T> { }; 생성
		- operator== 오버로딩
		- 청크 단위로 할당
		- 충돌시 같은 버킷에 리스트로 관리
			- 정렬이 필요없는 Key Value 쌍


	set과 map 의 find가 operator==를 오버로딩 하지 않는 이유
	-> A < B == False && A > B == false 이면 같은 경우로 판단.
*/

#include "Coordinate.h"
#include <stdexcept>
class Day0610
{
public:
	void Day0610_Run();
	void TestTemplateClass();
	void BSTTest();

	void TemplateListTest();
	void TemplateStackTest();
	//간단 실습 
	// - 계산기 클래스 만들기
	//		- Add Sub Multiply Divide
	//		- int * int, float * int, int* float, float * float
	// 비트 플래스 연산자 추가하기

	// 여태 만든 자료구조 템플릿화 시키기
};

template <typename T, typename V>
class Calculator
{
public:
	auto Add(T Left, V Right);
	auto Sub(T Left, V Right);
	auto Mul(T Left, V Right);
	auto Div(T Left, V Right);
};

template <typename T, typename V>
auto Calculator<T, V>::Add(T Left, V Right)
{
	if constexpr (std::is_same_v<T, float> && std::is_same_v<V, int>)
	{
		return Left + static_cast<T>(Right);
	}
	else if constexpr (std::is_same_v<T, int> && std::is_same_v<V, float>)
	{
		return static_cast<T>(Left) + Right;
	}
	
	return Left + Right;

}

template<typename T, typename V>
auto Calculator<T, V>::Sub(T Left, V Right)
{
	if constexpr (std::is_same_v<T, float> && std::is_same_v<V, int>)
	{
		return  Left - static_cast<T>(Right);
	}
	else if constexpr (std::is_same_v<T, int> && std::is_same_v<V, float>)
	{
		return  static_cast<T>(Left) - Right;
	}

	return  Left - Right;
}

template<typename T, typename V>
auto Calculator<T, V>::Mul(T Left, V Right)
{
	if constexpr (std::is_same_v<T, float> && std::is_same_v<V, int>)
	{
		return Left * static_cast<T>(Right);
	}
	else if constexpr (std::is_same_v<T, int> && std::is_same_v<V, float>)
	{
		return static_cast<T>(Left) * Right;
	}

	return Left * Right;
}

template<typename T, typename V>
auto Calculator<T, V>::Div(T Left, V Right)
{
	if (Right == 0)
		throw std::runtime_error("0으로 나눌 수 없습니다.");

	if constexpr (std::is_same_v<T, float> && std::is_same_v<V, int>)
	{
		return Left / static_cast<T>(Right);
	}
	else if constexpr (std::is_same_v<T, int> && std::is_same_v<V, float>)
	{
		return  static_cast<T>(Left) / Right;
	}
	else if constexpr (std::is_same_v<T, int> && std::is_same_v<V, int>)
	{
		if (Left % Right != 0)
		{
			return Left / static_cast<float>(Right);
		}
	}


	return Left / Right;

}
