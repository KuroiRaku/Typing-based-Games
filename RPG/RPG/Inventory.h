#ifndef INVENTORY_H
#define INVENTORY_H
#include "item.h"


class Inventory
{
public:
	Inventory();
	virtual ~Inventory();
	void addItem(const item& item);
	void removeItem(int index);
	inline void debugPrint()const
	{

		for (size_t i = 0; i < this->nrofItems; i++)
		{
			std::cout << this->itemArr[i]->debugPrint() << std::endl;
		}
	}

	//function
private:
	void initialize(const int from);
	void expand();
	item** itemArr;
	int caps;
	int nrofItems;

};

#endif // INVENTORY_H


