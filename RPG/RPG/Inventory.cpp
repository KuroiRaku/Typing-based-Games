#include "Inventory.h"
Inventory::Inventory()
{
	caps = 10;
	nrofItems = 0;
	itemArr = new item * [caps];
}

Inventory::~Inventory()
{
	for (size_t i = 0; i < this->nrofItems; i++)
	{
		delete this->itemArr[i];
	}
	delete[]itemArr;
}

void Inventory::initialize(const int from)
{
	for (size_t i = from; i < this->caps; i++)
	{
		this->itemArr[i] = 0;
	}
}
void Inventory::expand()
{
	this->caps *= 2;
	item** tempArr = new item * [this->caps];
	for (size_t i = 0; i < nrofItems; i++)
	{
		tempArr[i] = new item(*this->itemArr[i]);
	}
	for (size_t i = 0; i < this->nrofItems; i++)
	{
		delete this->itemArr[i];
	}
	delete[]this->itemArr;

	this->itemArr = tempArr;
	this->initialize(this->nrofItems);
}

void Inventory::addItem(const item& Item)
{
	if (this->nrofItems >= this->caps)
	{
		expand();
	}
	this->itemArr[this->nrofItems++] = new item(Item);
}
void Inventory::removeItem(int index)
{

}
