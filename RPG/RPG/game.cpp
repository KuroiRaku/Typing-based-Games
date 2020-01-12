#include "game.h"

game::game()
{
	Choice = 0;
	Playing = true;
	ActiveCharacter = 0;
	Filename = "SaveFile.txt";
}

game::~game()
{

}
//functions

void game::InitGame()
{
	std::string name;
	std::cout << "Enter name your name: ";
	std::getline(cin, name);
	std::cout << "Select an animal that befits you" << std::endl;
	std::cout << "1. Cheetah" << std::endl;
	std::cout << "2. Eagle" << std::endl;
	std::cout << "3. Fox" << std::endl;
	std::cout << "4. Elephant" << std::endl;
	std::cout << "5. I don't know" << std::endl;
	cin >> Choice;
	bool Ok = true;
	while (Ok) {
		switch (Choice)
		{
		case 1:
			Character.Speeder(name);
			Ok = false;
			break;
		case 2:
			Character.Warrior(name);
			Ok = false;
			break;
		case 3:
			Character.Mage(name);
			break;
		case 4:
			Character.Tank(name);
			Ok = false;
			break;
		case 5:
		{
			int J = rand() % 5 + 1;
			switch (J)
			{
			case 1:
				Character.Speeder(name);
				break;
			case 2:
				Character.Warrior(name);
				break;
			case 3:
				Character.Mage(name);
				break;
			case 4:
				Character.Tank(name);
				break;
			case 5:
				Character.Special(name);
				break;
			}
			Ok = false;
			break;
		}
		default:
			std::cout << "Please don't mess with me :(" << std::endl;
			cin.clear();
			cin.ignore();
			cin >> Choice;
			break;
		}
	}
}
void game::MainMenu()
{
	std::cout << "* MAIN MENU *" << std::endl << std::endl;
	std::cout << "0: Quit" << std::endl;
	std::cout << "1: Travel" << std::endl;
	std::cout << "2: Shop" << std::endl;
	std::cout << "3: Level Up" << std::endl;
	std::cout << "4: Rest" << std::endl;
	std::cout << "5: Character Stats" << std::endl;
	std::cout << "6: Save" << std::endl;
	std::cout << "7: Loud" << std::endl;
	std::cout << std::endl;
	std::cout << std::endl << "Player's Choice: ";
	cin >> Choice;

	switch (Choice)
	{
	case 0:
		Playing = false;
		break;
	case 5:
		Character.PrintStats();
		break;
	case 6:
		Save();
		break;
	case 7:
		Load();
		break;
	default:
		break;
	}
}
void game::CreateNewCharacters()
{

}
void game::Save()
{

}
void game::Load()
{

}
