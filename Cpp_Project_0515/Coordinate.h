#pragma once
#include <iostream>
#include <type_traits>
template <typename T>
struct Coordinate
{
	T X;
	T Y;

	Coordinate() : X{}, Y{} {}
	Coordinate(T InX, T InY) : X(InX), Y(InY)
	{

	}

	void Print() const
	{
		// 컴파일 타임에 타입 추론 후
		// 컴파일 타임에 조건이 true면 코드 생성
		if constexpr (std::is_same_v<T, int>)
		{
			printf("IntPos : %d, %d\n", X, Y);
		}
		else if constexpr (std::is_same_v<T, float>)
		{
			printf("FloatPos : %f, %f\n", X, Y);
		}
		else
		{
			std::cout << "( " << X << ", " << Y << " )\n";
		}
	}


	//Coordinate& operator+=(Coordinate& InOthers)
	//{
	//	X += InOthers.X;
	//	Y += InOthers.Y;
	//	return *this;
	//}

	//Coordinate& operator-=(Coordinate& InOthers)
	//{
	//	X -= InOthers.X;
	//	Y -= InOthers.Y;
	//	return *this;
	//}
};

template<typename T>
Coordinate<T> operator+(const Coordinate<T>& Left, const Coordinate<T>& Right)
{
	return Coordinate<T>(Left.X + Right.X, Left.X + Right.Y);
}
template<typename T>
Coordinate<T> operator-(const Coordinate<T> Left, const Coordinate<T> Right)
{
	return Coordinate<T>(Left.X - Right.X, Left.X - Right.Y);
}
template<typename T>
bool operator==(const Coordinate<T>& Left, const Coordinate<T>& Right)
{
	bool Res = false;
	if constexpr (std::is_same_v<T, float>)
	{
		float diffX = Left.X - Right.X;
		float diffY = Left.Y - Right.Y;

		if (diffX < 0) diffX *= -1;
		if (diffY < 0) diffY *= -1;

		Res = diffX < 0.001f && diffY < 0.001f;
	}
	else if constexpr (std::is_same_v<T, double>)
	{
		float diffX = Left.X - Right.X;
		float diffY = Left.Y - Right.Y;

		if (diffX < 0) diffX *= -1;
		if (diffY < 0) diffY *= -1;

		Res = diffX < 0.00001 && diffY < 0.00001;
	}
	else
	{
		Res = Left.X == Right.X && Left.Y == Right.Y;
	}

	return Res;
}
template<typename T>
bool operator!=(const Coordinate<T>& Left, const Coordinate<T>& Right)
{
	return !(Left == Right);
}
