#include "game.h"

game::game()
{
	choice = 0;
	playing = true;
	ActiveCharacter = 0;
	filename = "SaveFile.txt";
}

game::~game()
{

}
//functions

void game::initGame()
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
	cin >> choice;
	bool ok = true;
	while (ok) {
		switch (choice)
		{
		case 1:
			character.Speeder(name);
			ok = false;
			break;
		case 2:
			character.Warrior(name);
			ok = false;
			break;
		case 3:
			character.Mage(name);
			break;
		case 4:
			character.Tank(name);
			ok = false;
			break;
		case 5:
		{
			int j = rand() % 5 + 1;
			switch (j)
			{
			case 1:
				character.Speeder(name);
				break;
			case 2:
				character.Warrior(name);
				break;
			case 3:
				character.Mage(name);
				break;
			case 4:
				character.Tank(name);
				break;
			case 5:
				character.Special(name);
				break;
			}
			ok = false;
			break;
		}
		default:
			std::cout << "Please don't mess with me :(" << std::endl;
			cin.clear();
			cin.ignore();
			cin >> choice;
			break;
		}
	}
}
void game::mainmenu()
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
	cin >> choice;

	switch (choice)
	{
	case 0:
		playing = false;
		break;
	case 5:
		characters[ActiveCharacter].printstats();
		break;
	case 6:
		save();
		break;
	case 7:
		load();
		break;
	default:
		break;
	}
}
void game::createNewCharacters()
{

}
void game::save()
{

}
void game::load()
{

}
