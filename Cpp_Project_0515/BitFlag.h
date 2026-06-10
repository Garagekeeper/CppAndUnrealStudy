#pragma once
#include <type_traits>

template <typename T>
typename std::enable_if_t<std::is_enum_v<T>, T> operator|(T Left, T Right)
{
	return static_cast<T>(
		static_cast<std::underlying_type_t<T>>(Left) | static_cast<std::underlying_type_t<T>>(Right));
}

template <typename T>
typename std::enable_if_t<std::is_enum_v<T>, T> operator&(T Left, T Right)
{
	return static_cast<T>(
		static_cast<std::underlying_type_t<T>>(Left) & static_cast<std::underlying_type_t<T>>(Right));
}

template <typename T>
typename std::enable_if_t<std::is_enum_v<T>, T&> operator|=(T& Left, T& Right)
{
	Left =
		static_cast<T>(static_cast<std::underlying_type_t<T>>(Left) | static_cast<std::underlying_type_t<T>>(Right));

	return Left;
}

template <typename T>
typename std::enable_if_t<std::is_enum_v<T>, T&> operator&=(T& Left, T& Right)
{
	Left =
		static_cast<T>(static_cast<std::underlying_type_t<T>>(Left) & static_cast<std::underlying_type_t<T>>(Right));

	return Left;
}

enum class TestEnum
{
	Up = 1 << 0,
	Down = 1 << 1,
	Right = 1 << 2,
	Left = 1 << 3,
};