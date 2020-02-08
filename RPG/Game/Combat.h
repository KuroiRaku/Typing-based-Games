#pragma once
#include "game.h"
class Combat
{
public:
	Combat();
	virtual ~ Combat();

	//functions
	void EnemyEncounter();
	void PrintResult()const;
	void combat(Character Character);


private:
	std::string Input;
	int LightAttackCounter;
	int HeavyAttackCounter;
	int DefenceCounter;
	int AvoidCounter;
	int WindMagicCounter;
	int FireMagicCounter;
	int WaterMagicCounter;
	int ThunderMagicCounter;
	int EarthMagicCounter;
	int DarkMagicCounter;
	int LightMagicCounter;
	int FailCounter;
};

