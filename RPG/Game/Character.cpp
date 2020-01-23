#include "Character.h"
#include <cstdlib>
#include <sstream>

Character::Character()
{
	this->XPos = 0.0;
	this->YPos = 0.0;
	Name = "Executer";
	Level = 1;
	TimeForImpact = 8;
	Exp = 0;
	ExpNext = static_cast<int>(Level * 100) + 200;
	Attack = 5;
	MagicAttack = 5;
	Defence = 5;
	Speed = 5;
	Hp = 10;

	Mana = 20;
	Stamina = 20;
	DamageMin = 1;
	DamageMax = 30;
	SkillPoints = 0;
}

Character::~Character()
{
	//dtor
}

//functions
void Character::Warrior(std::string name1)
{
	this->XPos = 0.0;
	this->YPos = 0.0;
	Name = name1;
	Level = 1;
	TimeForImpact = 8;
	Exp = 0;
	ExpNext = static_cast<int>(Level * 100) + 200;
	Attack = 5;
	MagicAttack = 5;
	Defence = 5;
	Speed = 5;
	Hp = 10;

	Mana = 20;
	Stamina = 20;
	DamageMin = 1;
	DamageMax = 30;
	SkillPoints = 0;
}

void Character::Tank(std::string name1)
{
	this->XPos = 0.0;
	this->YPos = 0.0;
	Name = name1;
	TimeForImpact = 3;
	Level = 1;
	Exp = 0;
	ExpNext = static_cast<int>(Level * 100) + 200;
	Attack = 10;
	MagicAttack = 2;
	Defence = 6;
	Speed = 3;
	Hp = 20;

	Mana = 5;
	Stamina = 20;
	DamageMin = 2;
	DamageMax = 40;
	SkillPoints = 0;
}
void Character::Mage(std::string name1)
{
	this->XPos = 0.0;
	this->YPos = 0.0;
	Name = name1;
	Level = 1;
	Exp = 0;
	TimeForImpact = 8;
	ExpNext = static_cast<int>(Level * 100) + 300;
	Attack = 2;
	MagicAttack = 12;
	Defence = 3;
	Speed = 6;
	Hp = 8;

	Mana = 20;
	Stamina = 25;
	DamageMin = 3;
	DamageMax = 100;
	SkillPoints = 0;
}

void Character::Speeder(std::string name1)
{
	this->XPos = 0.0;
	this->YPos = 0.0;
	Name = name1;
	Level = 1;
	TimeForImpact = 12;
	Exp = 0;
	ExpNext = static_cast<int>(Level * 100) + 200;
	Attack = 2;
	MagicAttack = 7;
	Defence = 3;
	Speed = 12;
	Hp = 5;

	Mana = 10;
	Stamina = 20;
	DamageMin = 1;
	DamageMax = 5;
	SkillPoints = 0;
}

void Character::Special(std::string name1)
{
	this->XPos = 0.0;
	this->YPos = 0.0;
	Name = name1;
	Level = 10;
	TimeForImpact = 8;
	Exp = 0;
	ExpNext = static_cast<int>(Level * 100) + 300;
	Attack = 15;
	MagicAttack = 30;
	Defence = 20;
	Speed = 20;
	Hp = 40;
	Mana = 40;
	Stamina = 10;
	DamageMin = 8;
	DamageMax = 100;
	SkillPoints = 0;
}
void Character::PrintStats()const
{
	std::cout << "Character Stats: " << std::endl;
	std::cout << "Name: " << this->Name << std::endl;
	std::cout << "Level: " << this->Level << std::endl;
	std::cout << "TimeForImpact: " << this->TimeForImpact << std::endl;
	std::cout << "Exp: " << this->Exp << std::endl;
	std::cout << "Exp to Next Level: " << this->ExpNext << std::endl;
	std::cout << std::setw(10) << std::setfill('=') << std::endl;
	std::cout << "HP: " << this->Hp << std::endl;
	std::cout << "Attack: " << this->Attack << std::endl;
	std::cout << "Magic Attack: " << this->MagicAttack << std::endl;
	std::cout << "Defence: " << this->Defence << std::endl;
	std::cout << std::setw(10) << std::setfill('=') << std::endl;
	std::cout << "Speed: " << this->Speed << std::endl;
	std::cout << "Mana: " << this->Mana << std::endl;
	std::cout << std::setw(5) << std::setfill('=') << std::endl;
	std::cout << "Stamina: " << this->Stamina << std::endl;
	std::cout << "Skillpoint: " << this->SkillPoints << std::endl;
	std::cout << std::setw(5) << std::setfill('=') << std::endl;
	std::cout << std::endl;
}
void Character::LevelUp()
{
	while (Exp >= ExpNext)
	{
		Level++;
		this->Exp = Exp - ExpNext;
		std::cout << "Your Hero has leveled up!" << std::endl;
	}
}

void Character::SpendSkillPoint()
{
	int choice;
	std::cout << "Select 1 to spend on stats" << std::endl;
	std::cout << "Select 2 to spend increase stamina by 2" << std::endl;
	std::cin >> choice;

	switch (choice)
	{
	case 1:
		this->AddStat();
		break;
	case 2:
		this->SetStamina(this->GetStamina() + 2);
		break;
	default:
		break;
	}
}

void Character::AddStat()
{
	int J;
	int Attack;
	int Defence;
	int Speed;
	int HP;
	for (int i = 0; i < 6; i++)
	{
		J = (rand() % 6);
		switch (i)
		{
		case 0:
			this->SetDefence(this->GetDefence() + 1);
			break;
		case 1:
			this->SetAttack(this->GetAttack() + 1);
			break;
		case 2:
			this->SetHp(this->GetHp() + 2);
			break;
		case 3:
			this->SetMagicAttack(this->GetMagicAttack() + 1);
			break;
		case 4:
			this->SetSpeed(this->GetSpeed() + 1);
			break;
		case 5:
			this->SetMana(this->GetMana() + 1);
		}
	}
}
	std::string Character:: GetAsString() const
	{
		return std::to_string(XPos) + " "
			+ std::to_string(YPos) + " "
			+ Name+ " "
			+ std::to_string(TimeForImpact) + " "
			+ std::to_string(Level) + " "
			+ std::to_string(Exp) + " "
			+ std::to_string(Attack) + " "
			+ std::to_string(MagicAttack) + " "
			+ std::to_string(Defence) + " "
			+ std::to_string(Speed) + " "
			+ std::to_string(Hp) + " "
			+ std::to_string(Mana) + " "
			+ std::to_string(Stamina);
	}