#pragma once
#include "Inventory.h"

class Character
{
public:
	Character();
	virtual ~Character();

	//functions
	void Initialize(int level);
	void Mage(std::string name1);
	void Warrior(std::string name1);
	void Special(std::string name1);
	void Tank(std::string name1);
	void Speeder(std::string name1);
	void PrintStats()const;
	void LevelUp();
	void SpendSkillPoint();
	void AddStat();
	std::string GetAsString()const;

	//Accessors
	inline const double& GetY()const { return this->YPos; }
	inline const double& GetX()const { return this->XPos; }
	inline const std::string& GetName()const { return this->Name; }
	inline const int& GetLevel()const { return this->Level; }
	inline const int& GetExp()const { return this->Exp; }
	inline const int& GetExpNext()const { return this->ExpNext; }
	inline const int& GetAttack()const { return this->Attack; }
	inline const int& GetMagicAttack()const { return this->MagicAttack; }
	inline const int& GetDefence()const { return this->Defence; }
	inline const int& GetSpeed()const { return this->Speed; }
	inline const int& GetMana()const { return this->Mana; }
	inline const int& GetHp()const { return this->Hp; }
	inline const int& GetStamina()const { return this->Stamina; }
	inline const int& GetDamageMin()const { return this->DamageMin; }
	inline const int& GetDamageMax()const { return this->DamageMax; }
	inline const int& GetSkillPoint()const { return this->SkillPoints; }
	//Modifier
	inline void SetLevel(int s) { Level = s; }
	inline void SetAttack(int s) { Attack = s; }
	inline void SetMagicAttack(int s) { MagicAttack = s; }
	inline void SetDefence(int s) { Defence = s; }
	inline void SetSpeed(int s) { Speed = s; }
	inline void SetHp(int s) {  Hp = s; }
	inline void SetSkillPoint(int s) {  SkillPoints = s; }
	inline void SetStamina(int s) { Stamina = s; }
	inline void SetMana(int s) {  Mana = s; }



private:
	std::string Name;
	int Level;
	int LevelMax = 30;
	int Exp;
	int ExpNext;
	int Attack;
	int MagicAttack;
	int Defence;
	int Speed;
	int Hp;
	int Mana;
	int Stamina;
	int DamageMin;
	int DamageMax;

	int SkillPoints;

	double XPos;
	double YPos;
	Character Characters();

};


