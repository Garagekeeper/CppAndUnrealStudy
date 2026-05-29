#pragma once

bool IsFloatEqual(float A, float B);

/// <summary>
/// Min 부터 Max사이의 랜덤 값(int)을 반환하는 함수
/// </summary>
/// <param name="Min">랜덤값의 최소</param>
/// <param name="Max">랜덤값의 최대</param>
/// <returns>Min 부터 Max사이의 랜덤 값</returns>
int RandomRange(int Min, int Max);

/// <summary>
/// 0 부터 Max사이의 랜덤 값(int)을 반환하는 함수
/// </summary>
/// <param name="Max">랜덤값의 최대</param>
/// <returns>0 부터 Max사이의 랜덤 값</returns>
int RandomRange(int Max);

/// <summary>
/// 0~1사이의 랜덤 값
/// </summary>
float GetRandom();