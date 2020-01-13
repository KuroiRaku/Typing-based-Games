#include "Combat.h"
Combat::Combat() {}
Combat::~Combat() {}

void Combat::PrintResult() const
{
	std::cout << "End of Turn " << std::endl;
	std::cout << "You have perform " << std::endl;
	std::cout << this->LightAttackCounter << "Light Attack(s) " << std::endl;
	std::cout << this->HeavyAttackCounter << "Heavy Attack(s) " << std::endl;
	std::cout << this->DefenceCounter << "Defence(s)" << std::endl;
	std::cout << this->AvoidCounter << "Avoid(s)" << std::endl;
	std::cout << this->DefenceCounter << "Defence(s)" << std::endl;
	std::cout << this->WindMagicCounter << "Wind Magic(s)" << std::endl;
	std::cout << this->FireMagicCounter << "Fire Magic(s)" << std::endl;
	std::cout << this->WaterMagicCounter << "Water Magic(s)" << std::endl;
	std::cout << this->EarthMagicCounter << "Earth Magic(s)" << std::endl;
	std::cout << this->ThunderMagicCounter << "Thunder Magic(s)" << std::endl;
	std::cout << this->LightMagicCounter << "Light Magic(s)" << std::endl;
	std::cout << this->DarkMagicCounter << "Dark Magic(s)" << std::endl;

}

void Combat::combat(Character Character)
{
	//battle Variables
	int BattleTime = Character.GetTimeForImpact();
	int Damage = 0;

	
	//end conditions
	bool PlayerDefeated = false;
	bool EnemiesDefeated = false;

	while (BattleTime >= 0)
	{
		BattleTime -= 1;
		std::cin >> Input;
		if (Input.compare("Attack Heavy")) {
			HeavyAttackCounter += 1;
		}

		PrintResult();
		LightAttackCounter=0;
		HeavyAttackCounter=0;
		DefenceCounter=0;
		AvoidCounter=0;
		WindMagicCounter=0;
		FireMagicCounter=0;
		WaterMagicCounter=0;
		ThunderMagicCounter=0;
		EarthMagicCounter=0;
		DarkMagicCounter=0;
		LightMagicCounter=0;
		FailCounter=0;
	}
}

