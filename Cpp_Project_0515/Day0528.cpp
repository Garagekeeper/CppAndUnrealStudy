#include <fstream>
#include <iostream>
#include "Day0528.h"

using namespace std;

void Day0528_Run()
{
	
	//Day0528_String();
	//Day0528_FileIO();
	//Day0528_Struct();
}

void Day0528_String()
{
	string Str1 = "Hello";
	string Str2("Hello World! Hello World! Hello World!");

	Str1 + Str2;

	Day0528_Exam01(Str2, 'W');
	Day0528_Exam01(Str2, 'A');
}

void Day0528_FileIO()
{
	const string FilePath = "./Data/DataFile.txt"; // 현재 폴더 (원래는 파일이 실행되는 곳)
	std::ifstream InputFile(FilePath); // 입력용 파일 스트림 생성
	if (InputFile.is_open()) // 항상 열려있는지 확인하고 사용
	{
		string FileContents(
			(std::istreambuf_iterator<char>(InputFile)),
			std::istreambuf_iterator<char>()
		);

		printf("파일 내용 \n%s\n", FileContents.c_str());
		InputFile.close();
	}
	else
	{
		//파일이 없거나 다른 이유로 열리지 않았다.
		printf("파일을 열 수 없습니다.");
	}

	// 파일 출력
	const string OutputFilePath = "./Data/OutTest.txt";
	std::ofstream OutFile(OutputFilePath);
	if (OutFile.is_open()) // 항상 열려있는지 확인하고 사용
	{
		OutFile << "Hello World! \n";
		OutFile << "안녕하세요 \n";
		OutFile << "Hello World! \n";
		OutFile << "Hello World! \n";

		OutFile.close();
	}
	else
	{
		//파일 생성에 실패
		printf("파일 생성에 실패 했습니다.");
	}

	//Day0528_Exam02();
}

void Day0528_Struct()
{
	Enemy Orc;
	Enemy Orc2 = {"Orc2", 124.0f, 2.0f, 100};
	Enemy Orcs[5];
	Enemy* Elf2 = new Enemy();
	EnemyOrc Orc3 = {"Orc2", 124.0f, 2.0f, 100};

	// 복사 생성자
	EnemyOrc Orc4(Orc3);
	// 복사 생성자
	EnemyOrc Orc5 = Orc4;
	EnemyOrc Orc6;

	// 복사 대입 연산자
	Orc6 = Orc5;

	Orc.Name = "Orc1";
	Orc.Health = 10.0f;
	Orc.AttackDamage = 5.0f;
	Orc.Reward = 10;

	Enemy* Elf = new Enemy(Orc);

	Orc.AttackDamage;
	(*Elf).AttackDamage;
	Elf->AttackDamage;

	Day0528_Exam03(Orc2);
	Day0528_Exam04(Elf);
}

void Day0528_Exam01(const std::string& Str, const char TargetChar)
{
	//std::string과 char를 파라미터로 받아서 string의 char가 어디에 있었는지 출력하는 함수 만들기
	printf("문자 %c는 문자열", TargetChar);
	size_t Pos = Str.find(TargetChar);

	if (Pos == string::npos)
	{
		printf("에 존재하지 않습니다.\n");
		return;
	}
	else
		printf("의 ");

	while (Pos != string::npos)
	{
		printf("%d, ", (int)Pos + 1);
		Pos = Str.find(TargetChar, Pos + 1);
	}

	printf("번째에 있습니다.\n");
}

void Day0528_Exam02()
{
	// 이름과 돈을 입력받고 파일로 저장하기
	const string FilePath = "./Data/StockData.txt";
	std::ofstream OutFile(FilePath);
	printf("품목과 가격을 순차적으로 입력하세요 종료하고 싶으면 둘 다 0을 입력하세요\n");
	string Name ="";
	string Price = "";
	if (OutFile.is_open())
	{
		while (true)
		{
			cin >> Name >> Price;
			if (Name == "0" && Price == "0")
				break;
			OutFile << Name<< " "<< Price << "\n";
		}
		OutFile.close();
	}
	else
	{
		//파일 생성에 실패
		printf("파일 생성에 실패 했습니다.");
	}
	// 파일을 불러와서 저장된 이름과 돈을 출력하기

	std::ifstream InputFile(FilePath);
	if (InputFile.is_open())
	{
		string FileContents(
			(std::istreambuf_iterator<char>(InputFile)),
			std::istreambuf_iterator<char>()
		);

		printf("파일 내용 \n%s\n", FileContents.c_str());
		InputFile.close();
	}
	else
	{
		//파일이 없거나 다른 이유로 열리지 않았다.
		printf("파일을 열 수 없습니다.");
	}
}

void Day0528_Exam03(Enemy& enemy)
{
	// Enemy의 데이터를 출력 (참조를 받기)
	printf("Name            : %s\n", enemy.Name.c_str());
	printf("Health          : %f\n", enemy.Health);
	printf("AttackDamage    : %f\n", enemy.AttackDamage);
	printf("Reward          : %d\n\n", enemy.Reward);

}

void Day0528_Exam04(Enemy* enemy)
{
	// Enemy의 데이터를 출력 (주소를)
	// Enemy의 데이터를 출력 (참조를 받기)
	printf("Name            : %s\n", enemy->Name.c_str());
	printf("Health          : %f\n", enemy->Health);
	printf("AttackDamage    : %f\n", enemy->AttackDamage);
	printf("Reward          : %d\n\n", enemy->Reward);
}

