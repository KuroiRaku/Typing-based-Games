#include "Combat.h"
Combat::Combat() {}
Combat::~Combat() {}

void Combat::PrintResult() const
{
	std::cout << "End of Turn " << std::endl;
	std::cout << "You have perform " << std::endl;
	std::cout << this->AttackCounter << "Attack(s) " << std::endl;
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

