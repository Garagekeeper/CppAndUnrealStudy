#pragma once
/*
	문자열 std::string
		- string Str1 = "Hello";
		- string Str2("Hello"); (생성자를 이용한 선언, 초기화)
		- +, += 연산자 지원
		- .append() : 이어 붙이기
		- .length(), .size() (unsinged __int64)
		- == 연산자로 비교 가능 물론 !=도 가능 (내부에서 메모리cmp를 하는듯)
		- >, < 같은것도 사전순으로 비교 가능
		- 특정 문자 위치 찾기
			- .find(target, startOffset(생략가능))
		- string::npos (-1로 정의된 상수인데 unsigned라 인트 최댓값, 길이나 위치로 쓰면 맨 매지막을, 혹은 못찾음을 의미)
		- substr(x) x부터 끝까지
		- substr(x, y) x부터 y개
		- stoi
		- stringstream
			- 찾아보려면 찾아보기
		- getline
	
	파싱
		- 문자열이나 데이터 구조를 분석하여 의미 있는 정보로 변환하는 과정
		- csv, json, xml

	파일 입출력
		- string FilePath = "./Data/DataFile.txt"; //  워킹 디렉토리 (파일이 실행되는 곳)
			- ./의 의미는 .vcxproj가 있는 디렉토리를 의미(디버깅에서)

		- 파일 입력
			cosnt string FilePath = "./Data/DataFile.txt"; // 현재 폴더 (원래는 파일이 실행되는 곳)
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

		- 파일 출력 (기존 파일을 덮어쓴다, 옵션을 통해서 append식으로 가능)

			const string OutputFilePath = "./Data/OutTest.txt";
			std::ofstream OutFile(OutputFilePath);
			//std::ofstream OutFile(OutputFilePath std::ios::app);
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
		
	생성자
		- 구조체나 클래스가 인스턴스화 될때 자동으로 호출되는 함수 같은 것.
		- 주로 멤버 변수 초기화에 사용
		- 이름이 구조체와 같고 반환형이 없음
		- 객체 생성시 자동 호출
		- 파라미터별로 오버라이딩 되어 있음 (여러개일 수 있음)
		- 기본 생성자는 자동으로 생김
			- 단 기본형태와 다른 생성자를 만들면 기본 생성자를 반드시 만들어줘야함
		- Enemy() = default	// 기본 생성자를 사용한다는 의미

	구조체
		- 관련된 데이터 집합을 표현하는데 사용
			- 여러 종류의 데이터 타입을 하나로 묶어서 사용
		- 프로그램의 가독성이 높아짐
		- Day0528_Struct() 한번 보기
		- 멤버에 접근할 때는 .사용 (실제 인스턴스)
			- 구조체 포인터의 멤버에 접근할때 *.을 ->로 변환 가능
		- 구조체 초기화 (위에 있는게 제일 먼저 밑에가 나중에 (덮어씀))
			- 맴버 직접 초기화 (구조체 선언시 직접 초기화)
			- 중괄호 초기화 인스턴스 생성할 때 만드는 방식
				- Enemy Orc2 = {"Orc2", 124.0f, 2.0f, 100};
			- 생성자 초기화 리스트
				- Enemy() : Name("쓰랄"), Hp(124.0f), AttackDamage(2.0f), Reward(100) {};
			- 생성자 내부 대입 (쓰지마소 이건 만들어진 다음에 들어감)
			Enemy(float Hp)
				{
					this -> Hp = Hp;
				}

	* cin.getLine -> 공백 포함 한 줄 받기
	* this는 자기 자신의 주소
*/

struct Enemy
{
	std::string Name = "";
	float Health=0.0f;
	float AttackDamage=0.0f;
	int Reward = 0;
};

struct EnemyOrc
{
	std::string Name = "";
	float Health = 0.0f;
	float AttackDamage = 0.0f;
	int Reward = 0;;
	
	// 간단 실습
	EnemyOrc(float Modifier = 1.0f)
	{
		Health			*= 10.0f * Modifier;
		AttackDamage	*= 5.0f * Modifier;
		Reward			*= (int)(3.0f * Modifier);
	}

	EnemyOrc(EnemyOrc& other)
	{
		
		Name = other.Name;
		Health = other.Health;
		AttackDamage = other.AttackDamage;
		Reward = other.Reward;
	}

	EnemyOrc& operator=(const EnemyOrc& other)
	{
		if (this != &other)
		{ //다를때만 복사 수행
			// 기본 제공되는 복대연은 얕은 복사 (포인터 변수의 경우 주소값만 가져옴)
			// 그래서 다른 곳에서 해제되면 문제
			// 사용자 정의로 깊은 복사를 구현해서 가져갈 수 있음
			printf("복대연\n");
		}
		return *this;
	}

	//
	EnemyOrc(std::string _Name, float _Health, float _AttackDamage, int _Reward) 
		: Name(_Name), Health(_Health), AttackDamage(_AttackDamage), Reward(_Reward)
	{};
};

void Day0528_Run();

void Day0528_String();
void Day0528_FileIO();
void Day0528_Struct();

void Day0528_Exam01(const std::string& Str, const  char TargetChar);
void Day0528_Exam02();
//callbyRef
void Day0528_Exam03(Enemy& enemy);
//callbtAdd
void Day0528_Exam04(Enemy* enemy);