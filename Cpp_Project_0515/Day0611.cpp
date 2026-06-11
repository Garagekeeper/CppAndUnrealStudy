#include "Day0611.h"
#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>
#include <sstream>
#include <set>
#include <map>

bool Comp2(const int& a, const int& b)
{
	return a > b;
}

void Day0611::Day0611_Run()
{
	//TemplateQueueTest();
	//TemplateVectorTest();
	//STLAlgoTest();

	Practice1();
	Practice2();
	Practice3();
	Practice4();
}

void Day0611::TemplateQueueTest()
{

}

void Day0611::TemplateVectorTest()
{

}

void Day0611::STLAlgoTest()
{
	std::vector<int> Data = { 10, 35, 55, 22, 47 };
	PrintVector(Data);

	auto itr = std::find(Data.begin(), Data.end(), 55);

	if (itr != Data.end())
	{
		printf("%d 가 벡터 %d번Index에 있었습니다!\n", *itr, static_cast<int>(itr - Data.begin()));
	}
	else
	{
		printf("%d 가 벡터에 없었습니다!\n", *itr);
	}

	std::sort(Data.begin(), Data.end());
	PrintVector(Data);

	// 정렬 되었다는 전제하에
	int TargetVal = 55;
	bool Res = std::binary_search(Data.begin(), Data.end(), TargetVal);

	if (Res)
	{
		printf("%d 가 벡터 에 있었습니다!\n", TargetVal);
	}
	else
	{
		printf("%d 가 벡터에 없었습니다!\n", TargetVal);
	}

	// 람다로 넘기기
	std::sort(Data.begin(), Data.end(), [](int a, int b){ return a > b; });
	PrintVector(Data);
	// 펑터로 넘기기
	std::sort(Data.begin(), Data.end(), Comp());
	PrintVector(Data);
	// 함수로 넘기기
	std::sort(Data.begin(), Data.end(), Comp2);
	PrintVector(Data);

	// 멤버함수 사용
	std::sort(Data.begin(), Data.end(), std::bind(&Day0611::Comp3, this, std::placeholders::_1, std::placeholders::_2));
	PrintVector(Data);

	// 람다를 통한 멤버함수 사용
	std::sort(Data.begin(), Data.end(), [this](int a, int b) {return this->Comp3(a, b); });
	PrintVector(Data);

	int line = 50;
	itr = std::find_if(Data.begin(), Data.end(),
		[line](int n) {
			return n > line;
		});

	if (itr != Data.end())
	{
		printf("%d 를 처음으로 넘는 값이 벡터 %d번Index에 있었습니다!\n", line, static_cast<int>(itr - Data.begin()));
	}
	else
	{
		printf("%d 를 처음으로 넘는 값이 벡터에 없었습니다!\n", line);
	}

}

void Day0611::PrintVector(const std::vector<int>& InData)
{
	for (auto Element : InData)
	{
		printf("[%d] ", Element);
	}

	printf("\n");
}

void Day0611::Practice1()
{
	//STL을 활용해서 다음을 수행
	//	정수를 여러개 입력받고 최대 최소 구하기
	printf("\n정수 여러개를 입력받고 최대 최소 구하기\n");
	std::vector<int> InputData;
	printf("정수들을 입력해 주세요 (입력을 끝내려면 -1을 입력합니다.)\n");
	while (true)
	{
		int Input;
		std::cin >> Input;

		if (Input == -1) break;

		InputData.push_back(Input);
	}

	std::sort(InputData.begin(), InputData.end());
	int Min = *InputData.begin();
	int Max = *(InputData.end() - 1);

	printf("입력받은 정수 중에서 최댓값은 %d, 최솟값은 %d 입니다.)\n", Max, Min);
	
}

void Day0611::Practice2()
{
	//  중복 없는 결과를 출력하기
	printf("\n정수 여러개를 입력받고 중복 없는 결과 출력하기\n");
	std::vector<int> InputData;
	printf("정수들을 입력해 주세요 (입력을 끝내려면 -1을 입력합니다.)\n");
	while (true)
	{
		int Input;
		std::cin >> Input;

		if (Input == -1) break;

		InputData.push_back(Input);
	}

	//std::sort(InputData.begin(), InputData.end());
	//InputData.erase(std::unique(InputData.begin(), InputData.end()), InputData.end());
	std::map<int, int> IntMap;
	std::vector<int> NewIntVec;
	for (int e : InputData)
	{
		if (IntMap[e] == 0)
			IntMap[e]++;
	}

	for (int e : InputData)
	{
		if (IntMap[e] == 1)
		{
			IntMap[e]--;
			NewIntVec.push_back(e);
		}
	}


	printf("중복 없는 결과: ");
	for (int e : NewIntVec)
	{
		printf("%d ", e);
	}

	printf("\n");
}

void Day0611::Practice3()
{
	//  문자열에서 중복되는 글자 제거하고 출력하기
	printf("\n문자열에서 중복되는 글자 제거하고 출력하기\n");
	std::string InputStr;
	printf("문자열을 입력해주세요:");
	std::cin >> InputStr;

	std::map<char, int> StrMap;

	for (char e : InputStr)
	{
		if (StrMap[e] == 0)
			StrMap[e]++;
	}
	

	std::vector<char> CharVec;
	for (char e : InputStr)
	{
		if (StrMap[e] == 1)
		{
			CharVec.push_back(e);
			StrMap[e]--;
		}
	}

	std::string UniqueStr(CharVec.begin(), CharVec.end());

	printf("중복 제거된 문자열 : %s\n", UniqueStr.c_str());
}

void Day0611::Practice4()
{
	//  문장을 입력 받아 각 단어가 등장하는 횟수 측정하기
	printf("\n문장을 입력 받아 각 단어가 등장하는 횟수 측정하기\n");
	std::map<std::string, int> WordMap;

	std::string InputStr;
	std::string InnerString;
	printf("문자열을 입력해주세요:");
	std::cin.clear();
	std::cin.ignore(10000, '\n');
	std::getline(std::cin , InputStr);
	std::stringstream StrStream(InputStr);
	while (StrStream >> InnerString)
	{
		WordMap[InnerString]++;
	}

	printf("문자열 %s 에서\n", InputStr.c_str());
	for (std::pair<std::string, int> e : WordMap)
	{
		printf("%s 는 %d번 \n", e.first.c_str(), e.second);
	}

	printf("등장하였습니다.");
}

