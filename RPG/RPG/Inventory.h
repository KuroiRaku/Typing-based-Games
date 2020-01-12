#ifndef INVENTORY_H
#define INVENTORY_H
#include "item.h"


class Inventory
{
public:
	Inventory();
	virtual ~Inventory();
	void AddItem(const item& item);
	void RemoveItem(int index);
	inline void DebugPrint()const
	{

		for (size_t i = 0; i < this->NrOfItems; i++)
		{
			std::cout << this->ItemArr[i]->DebugPrint() << std::endl;
		}
	}

	//function
private:
	void Initialize(const int from);
	void Expand();
	item** ItemArr;
	int Caps;
	int NrOfItems;

};

#endif // INVENTORY_H


