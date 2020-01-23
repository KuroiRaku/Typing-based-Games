#pragma once
#include <iostream>
#include "Character.h"
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
	void MainMenu();
	void InitGame();
	void CreateNewCharacters();
	void Save();
	void Load();


	//Accessors
	inline bool GetPlaying() const { return this->Playing; }

	//modifiers
private:
	int Choice;
	bool Playing;

	//Character related
	int ActiveCharacter;
	std::string Filename;
	std::vector<Character> Characters;
	Character Character;
};


