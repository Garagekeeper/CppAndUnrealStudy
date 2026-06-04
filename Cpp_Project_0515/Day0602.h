#pragma once
#include <string>

/*
	객체 지향
		- 프로그램 패러다임 중 하나.
		- 객체(object)를 만들고 객체간의 상호작용으로 프로그램이 동작하도록 만드는 방식.
		- 4대 특성
			- 추상화
				- 불필요한 세부사항을 숨기고, 핵심적인 부분만 말하는 것 
				- 중요한 개념과 기능만을 드러내는 것 (상위 개념으로 묶기)
				- 코드의 복잡성을 낮출 수 있음.
			- 캡슐화
				- 접근제한자를 통한 데이터 은닉
					- public
					- private
					- protected
				- 몰라도 되는 것은 안보이게 하는 것
				- 데이터 은닉
				- 코드 안정성 높임
				- 결합도 낮춤
			- 상속
				- 부모 클래스의 데이터와 기능을 물려받는 자식 클래스를 만드는 것.
				- 코드의 재사용성이 높아짐
				- 계층구조 형성
			- 다형성
				- 동일한 인터페이스를 통해 다양한 처리를 하는 것.
				- (함수가) 다양한 형태를 가질 수 있음
				- 가상함수의 오버라이드를 통한 다형성 구현
					* 오버로딩 (이름 같고 매개변수 다름)
					* 오버라이딩 (이름 매개변수 같은데, 구현이 다름)

	class
		- 객체를 만들기 위한 설계도
		- 객체가 가지게 될 상태(데이터, 변수)와 동작(기능, 함수)을 하나로 묶어 놓은 것.
		- 구성요소
			- 생성자
			- 소멸자
				- 객체가 사용하던 자원 반환시에 사용
			- 멤버 변수
				- 객체의 상태나 데이터를 저장하는 변수
				- attribute, field라고도 함.
			- 멤버 함수 
				- 객체의 기능을 정의한 함수
				- method라고도 함
		- 인스턴스
			- 객체라고 하기도 하는데 인스턴스가 더 와닿는 듯.
			- 특정 클래스를 이용해 실제 메모리에 올라간 실체
		- 기본 private

	접근 제한자
		- 특정 객체의 내부를 누구까지 볼 수 있을 것인가
		- public		: 전부
		- protected		: 자식까지
		- private		: 자기 자신만 

	*  강사님은 어지간하면 소멸자 안쓰신다고함.
	
	상속
		- 부모 클래스의 멤버를 물려 받는것.
		- 자식은 부모 클래스를 확장 시킨다.
		- 부모클래스의 포인터로 자식포인터를 저장할 수 있음.

	가상함수
		- virtual 키워드 사용
		- 자식 클래스에서 해당 함수를 오버라이드 할 수있음
		- 가상 테이블을 통해서 적절한 함수에 매핑
			- 가상함수가 하나라도 있는 클래스에만 테이블이 만들어짐
		- 소멸자

	*  C++에서는 다중 상속이 가능함
		- 다이아몬드 상속 문제의 결과는 알 수 없음
		- 언리얼에서는 막아놓음
*/


//	간단 실습
//	- 동물 클래스 만들
//		- 움직이면 에너지를 소비
//		- 소리를 지를 수 있다.
//		- 먹을 수 있다. (먹으면 에너지 증가)
//		- 잠을 잘 수 있다.
//		- 잠을 자면 나이증가, 에너지 만땅
//		- 자신의 정보를 출력할 수 있음
//
class Animal
{

protected:
	std::string			Name = "동물";
	int					Age	= 0;
	float				Energy = 0;
	float				EnergyMax = 0;
	const float			MoveEnergyDelta = 10.0f;
	const float			EatEnergyDelta = 10.0f;

public:
						Animal() = default;
						Animal(std::string _Name, float _Energy, float _EnergyMax, int _Age) 
							: Name(_Name), Energy(_Energy), EnergyMax(_EnergyMax), Age(_Age) {};
	virtual				~Animal() = default;

	void				Eat();
	virtual void		Move();
	void				PrintStatus();
	virtual void		Roar();
	void				Sleep();

	// getter / setter
	// 여기서 const는 함수 내에서 멤버변수를 수정하지 않는다는 의미
	int					GetAge() const;
	void				voidSetAge(int _Age);
	// getter / setter 는 인라인 함수를 쓰기도 함
	inline std::string	GetName()const { return Name; }
	inline float		GetEnergy() const { return Energy; }
	inline float		GetEnergyMax() const { return EnergyMax; }
	inline void			SetEnergy(float InEnergy) { Energy = InEnergy; }
	inline float		GetMoveEnergyDelta() const { return MoveEnergyDelta; }
	inline float		GetEatEnergyDelta() const { return MoveEnergyDelta; }
};


class Dragon : public Animal
{
	const float			FlyEnergyDelta = 15.0f;


public:
						Dragon() :Animal() {}
						Dragon(std::string _Name, float _Energy, float _EnergyMax, int _Age)
							: Animal(_Name, _Energy, _EnergyMax, _Age){};

	void				Fly();
	virtual void		Move() override;
};

class Fish : public Animal
{
	const float			SwimEnergyDelta = 15.0f;


public:
						Fish() :Animal() {}
						Fish(std::string _Name, float _Energy, float _EnergyMax, int _Age)
							: Animal(_Name, _Energy, _EnergyMax, _Age){};

	void				Swim();
	virtual void		Move() override;
};

class FlyingFish : public Fish
{
	const float			JumpOnWateDelta = 20.0f;


public:
						FlyingFish() :Fish() {}
						FlyingFish(std::string _Name, float _Energy, float _EnergyMax, int _Age)
							: Fish(_Name, _Energy, _EnergyMax, _Age){};

	void				JumpOnWater();
	virtual void		Move() override;
};

class EasternDragon : public Dragon
{
	const float			GrantWishEnergyDelta = 50.0f;


public:
						EasternDragon() :Dragon() {}
						EasternDragon(std::string _Name, float _Energy, float _EnergyMax, int _Age)
							: Dragon(_Name, _Energy, _EnergyMax, _Age){};

	void				GrantWish();
	virtual void		Move() override;
};

class WesternDragon : public Dragon
{
	const float			ThrowFlameEnergyDelta = 45.0f;


public:
						WesternDragon() :Dragon() {}
						WesternDragon(std::string _Name, float _Energy, float _EnergyMax, int _Age)
							: Dragon(_Name, _Energy, _EnergyMax, _Age){};

	void				ThrowFlame();
	virtual void		Roar() override;
	virtual void		Move() override;
};


void Day0602_Run();
void Day0602_Class();
void Day0602_virtual();

