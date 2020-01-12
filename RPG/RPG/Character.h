#pragma once
#include "Inventory.h"

class Character
{
public:
	Character();
	virtual ~Character();

	//functions
	void initialize(int level);
	void Mage(std::string name1);
	void Warrior(std::string name1);
	void Special(std::string name1);
	void Tank(std::string name1);
	void Speeder(std::string name1);
	void printstats()const;
	void levelUp();
	void SpendSkillPoint();
	void AddStat();
	std::string getAsString()const;

	//Accessors
	inline const double& getY()const { return this->yPos; }
	inline const double& getX()const { return this->xPos; }
	inline const std::string& getName()const { return this->name; }
	inline const int& getLevel()const { return this->level; }
	inline const int& getExp()const { return this->exp; }
	inline const int& getExpNext()const { return this->expNext; }
	inline const int& getAttack()const { return this->attack; }
	inline const int& getMagicAttack()const { return this->magicattack; }
	inline const int& getDefence()const { return this->defence; }
	inline const int& getSpeed()const { return this->speed; }
	inline const int& getMana()const { return this->mana; }
	inline const int& getHp()const { return this->hp; }
	inline const int& getStamina()const { return this->stamina; }
	inline const int& getDamageMin()const { return this->damageMin; }
	inline const int& getDamageMax()const { return this->damageMax; }
	inline const int& getSkillPoint()const { return this->skillPoints; }
	//Modifier
	inline void setLevel(int s) { level = s; }
	inline void setAttack(int s) { attack = s; }
	inline void setMagicAttack(int s) { magicattack = s; }
	inline void setDefence(int s) { defence = s; }
	inline void setSpeed(int s) { speed = s; }
	inline void setHP(int s) {  hp = s; }
	inline void setSkillPoint(int s) {  skillPoints = s; }
	inline void setStamina(int s) { stamina = s; }
	inline void setMana(int s) {  mana = s; }



private:
	std::string name;
	int level;
	int levelMax = 30;
	int exp;
	int expNext;
	int attack;
	int magicattack;
	int defence;
	int speed;
	int hp;
	int mana;
	int stamina;
	int damageMin;
	int damageMax;

	int skillPoints;

	double xPos;
	double yPos;
	Character character();

};


