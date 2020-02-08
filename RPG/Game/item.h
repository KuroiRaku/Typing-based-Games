#pragma once
#include <string>
#include <iostream>
#include <iomanip>


class item
{
public:
	item();
	virtual ~item();
	inline std::string DebugPrint()const
	{
		return this->Name;
	}
private:
	std::string Name;
	std::string Description;
	int Sellprice;
	int Buyprice;
	item Item();
	std::string State;
};
