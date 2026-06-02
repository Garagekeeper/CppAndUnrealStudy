#include <iostream>
#include "Day0602.h"

void Animal::Roar()
{
	printf("짱쎈 %s가 울부짖어따\n\n", Name.c_str());
}

void Animal::Move()
{
	printf("%s가 움직였다\n", Name.c_str());
	printf("에너지가 %.1f 감소한다\n\n", MoveEnergyDelta);
	Energy -= MoveEnergyDelta;
}

void Animal::Eat()
{
	printf("%s가 밥을 먹는다\n", Name.c_str());
	printf("에너지가 %.1f 증가한다\n\n", EatEnergyDelta );
	Energy+= EatEnergyDelta;
}

void Animal::Sleep()
{
	printf("%s가 잠을 잔다\n", Name.c_str());
	printf("에너지가 모두 회복되고, 나이가 1 증가한다.\n\n");
	Energy = EnergyMax;
	Age++;
}

int Animal::GetAge() const
{
	return Age;
}

void Animal::voidSetAge(int _Age)
{
	Age = _Age;
}

void Animal::PrintStatus()
{
	printf("---------------------------------\n");
	printf("%s의 상태\n", Name.c_str());
	printf("나이   : %d\n" ,Age);
	printf("에너지 : %.1f\n", Energy);
	printf("---------------------------------\n");
}

void Dragon::Fly()
{
	printf("%s가 잠을 잔다\n", Name.c_str());
	printf("에너지가 모두 회복되고, 나이가 1 증가한다.\n\n");
	Energy = EnergyMax;
	Age++;
}

void Dragon::Move()
{
	Fly();
}


void Fish::Swim()
{
	printf("%s가 헤엄을 잔다\n", Name.c_str());
	printf("에너지가 %.1f 감소한다\n\n", SwimEnergyDelta);
	Energy -= SwimEnergyDelta;
}

void Fish::Move()
{
	Swim();
}


void FlyingFish::JumpOnWater()
{
	printf("%s가 물 위로 점프 한다.\n", Name.c_str());
	printf("에너지가 %.1f 감소한다\n\n", JumpOnWateDelta);
	Energy -= JumpOnWateDelta;
}

void FlyingFish::Move()
{
	JumpOnWater();
}


void EasternDragon::GrantWish()
{
	printf("%s가 소원을 이뤄준다\n", Name.c_str());
	printf("에너지가 %.1f 감소한다\n\n", GrantWishEnergyDelta);
	Energy -= GrantWishEnergyDelta;
}

void EasternDragon::Move()
{
	GrantWish();
}


void WesternDragon::ThrowFlame()
{
	printf("%s가 불을 뿜는다.\n", Name.c_str());
	printf("에너지가 %.1f 감소한다\n\n", ThrowFlameEnergyDelta);
	Energy -= ThrowFlameEnergyDelta;
}

void WesternDragon::Roar()
{
	printf("짱쎈 서양 고룡 %s가 울부짖어따\n\n", Name.c_str());
}

void WesternDragon::Move()
{
	ThrowFlame();
}


void Day0602_Run()
{
	//Day0602_Class();
	Day0602_virtual();
}

void Day0602_Class()
{
	Animal* MyAnimal = new Animal("동물", 100.0f, 100.0f, 100);

	MyAnimal->Eat();
	MyAnimal->Move();
	MyAnimal->Roar();
	MyAnimal->Sleep();
	MyAnimal->PrintStatus();

	delete MyAnimal;
	MyAnimal = nullptr;

	Animal* MyAnimal2 = new Dragon("투명 드래곤", 100.0f, 100.0f, 100);
	//MyAnimal2->Fly(); // Err
	(Dragon*)MyAnimal2; // 이렇게 C스타일의 캐스팅은 위험 (캐스팅 안되는 타입도 억지로 해버림)

	//dynamic_cast 이 캐스팅은 타입 변환 검사를 해서 안전한데 느리다.
	static_cast<Dragon*>(MyAnimal2)->Fly();

	delete MyAnimal2;
	MyAnimal2 = nullptr;

	// delete후에 MyAnimal2에 접근하면 안대여
	// 댕글링 포인터

	Dragon* MyDragon = new Dragon();
	MyDragon->Fly();
	MyDragon->PrintStatus();

	delete MyDragon;
	MyDragon = nullptr;

	//Dragon* MyAnimal3 = new Animal();	//	Err
}

void Day0602_virtual()
{
	Animal* Zoo[3] = { nullptr, };
	Zoo[0] = new WesternDragon("와이번",1000,1000,300);
	Zoo[1] = new EasternDragon("용용이", 2000, 2000, 1300);
	Zoo[2] = new FlyingFish("날치", 10, 10, 1);

	for (Animal* animal : Zoo)
	{
		animal->PrintStatus();
		animal->Roar();
		animal->Move();
	}

	//new는 각자 타입인데
	//delete는 부모타입만 호출 (원래는 자기거 호출하고 부모거 호출)
	//소멸자에 virtual 붙이기 (아예 안만들면 상관없음, 일단 만들었으면 붙이기)
	for (int i = 0; i < 3; i++)
	{
		delete Zoo[i];
		Zoo[i] = nullptr;
	}
}

