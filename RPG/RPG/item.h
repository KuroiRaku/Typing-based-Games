#pragma once
#include <string>
#include <iostream>
#include <iomanip>


class item
{
public:
	item();
	virtual ~item();
	inline std::string debugPrint()const
	{
		return this->name;
	}
private:
	std::string name;
	std::string description;
	int sellprice;
	int buyprice;
	item Item();
	std::string state;
};
