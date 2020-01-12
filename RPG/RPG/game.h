#pragma once
#include <iostream>
#include<iomanip>
#include "../function.h"
#include "Character.h"
#include <ctime>
#include <stdlib.h>
#include <vector>
#include <fstream>


using namespace std;

class game
{
public:
	game();
	virtual ~game();


	//Operators

	//functions
	void mainmenu();
	void initGame();
	void createNewCharacters();
	void save();
	void load();


	//Accessors
	inline bool getPlaying() const { return this->playing; }

	//modifiers
private:
	int choice;
	bool playing;

	//Character related
	int ActiveCharacter;
	std::string filename;
	std::vector<Character> characters;
	Character character;
};


