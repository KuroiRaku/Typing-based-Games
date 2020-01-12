#include "Character.h"
#include <cstdlib>
#include <sstream>

Character::Character()
{
	this->xPos = 0.0;
	this->yPos = 0.0;
	name = "Executer";
	level = 1;
	exp = 0;
	expNext = static_cast<int>(level * 100) + 200;
	attack = 5;
	magicattack = 5;
	defence = 5;
	speed = 5;
	hp = 10;

	mana = 20;
	stamina = 20;
	damageMin = 1;
	damageMax = 30;
	skillPoints = 0;
}

Character::~Character()
{
	//dtor
}

//functions
void Character::Warrior(std::string name1)
{
	this->xPos = 0.0;
	this->yPos = 0.0;
	name = name1;
	level = 1;
	exp = 0;
	expNext = static_cast<int>(level * 100) + 200;
	attack = 5;
	magicattack = 5;
	defence = 5;
	speed = 5;
	hp = 10;

	mana = 20;
	stamina = 20;
	damageMin = 1;
	damageMax = 30;
	skillPoints = 0;
}

void Character::Tank(std::string name1)
{
	this->xPos = 0.0;
	this->yPos = 0.0;
	name = name1;
	level = 1;
	exp = 0;
	expNext = static_cast<int>(level * 100) + 200;
	attack = 10;
	magicattack = 2;
	defence = 6;
	speed = 3;
	hp = 20;

	mana = 5;
	stamina = 20;
	damageMin = 2;
	damageMax = 40;
	skillPoints = 0;
}
void Character::Mage(std::string name1)
{
	this->xPos = 0.0;
	this->yPos = 0.0;
	name = name1;
	level = 1;
	exp = 0;
	expNext = static_cast<int>(level * 100) + 300;
	attack = 2;
	magicattack = 12;
	defence = 3;
	speed = 6;
	hp = 8;

	mana = 20;
	stamina = 25;
	damageMin = 3;
	damageMax = 100;
	skillPoints = 0;
}

void Character::Speeder(std::string name1)
{
	this->xPos = 0.0;
	this->yPos = 0.0;
	name = name1;
	level = 1;
	exp = 0;
	expNext = static_cast<int>(level * 100) + 200;
	attack = 2;
	magicattack = 7;
	defence = 3;
	speed = 12;
	hp = 5;

	mana = 10;
	stamina = 20;
	damageMin = 1;
	damageMax = 5;
	skillPoints = 0;
}

void Character::Special(std::string name1)
{
	this->xPos = 0.0;
	this->yPos = 0.0;
	name = name1;
	level = 10;
	exp = 0;
	expNext = static_cast<int>(level * 100) + 300;
	attack = 15;
	magicattack = 30;
	defence = 20;
	speed = 20;
	hp = 40;
	mana = 40;
	stamina = 10;
	damageMin = 8;
	damageMax = 100;
	skillPoints = 0;
}
void Character::printstats()const
{
	std::cout << "Character Stats: " << std::endl;
	std::cout << "Name: " << this->name << std::endl;
	std::cout << "Level: " << this->level << std::endl;
	std::cout << "Exp: " << this->exp << std::endl;
	std::cout << "Exp to Next Level: " << this->expNext << std::endl;
	std::cout << std::setw(10) << std::setfill('=') << std::endl;
	std::cout << "HP: " << this->hp << std::endl;
	std::cout << "Attack: " << this->attack << std::endl;
	std::cout << "Magic Attack: " << this->magicattack << std::endl;
	std::cout << "Defence: " << this->defence << std::endl;
	std::cout << std::setw(10) << std::setfill('=') << std::endl;
	std::cout << "Speed: " << this->speed << std::endl;
	std::cout << "Mana: " << this->mana << std::endl;
	std::cout << std::setw(5) << std::setfill('=') << std::endl;
	std::cout << "Stamina: " << this->stamina << std::endl;
	std::cout << "Skillpoint: " << this->skillPoints << std::endl;
	std::cout << std::setw(5) << std::setfill('=') << std::endl;
	std::cout << std::endl;
}
void Character::levelUp()
{
	while (exp >= expNext)
	{
		level++;
		this->exp = exp - expNext;
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
		this->setStamina(this->getStamina() + 2);
		break;
	default:
		break;
	}
}

void Character::AddStat()
{
	int j;
	int Attack;
	int defence;
	int Speed;
	int HP;
	for (int i = 0; i < 6; i++)
	{
		j = (rand() % 6);
		switch (i)
		{
		case 0:
			this->setDefence(this->getDefence() + 1);
			break;
		case 1:
			this->setAttack(this->getAttack() + 1);
			break;
		case 2:
			this->setHP(this->getHp() + 2);
			break;
		case 3:
			this->setMagicAttack(this->getMagicAttack() + 1);
			break;
		case 4:
			this->setSpeed(this->getSpeed() + 1);
			break;
		case 5:
			this->setMana(this->getMana() + 1);
		}
	}
}
	std::string Character:: getAsString() const
	{
		return std::to_string(xPos) + " "
			+ std::to_string(yPos) + " "
			+ name+ " "
			+ std::to_string(level) + " "
			+ std::to_string(exp) + " "
			+ std::to_string(attack) + " "
			+ std::to_string(magicattack) + " "
			+ std::to_string(defence) + " "
			+ std::to_string(speed) + " "
			+ std::to_string(hp) + " "
			+ std::to_string(mana) + " "
			+ std::to_string(stamina);
	}