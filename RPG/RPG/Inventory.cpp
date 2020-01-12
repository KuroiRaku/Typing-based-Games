#include "Inventory.h"
Inventory::Inventory()
{
	Caps = 10;
	NrOfItems = 0;
	ItemArr = new item * [Caps];
}

Inventory::~Inventory()
{
	for (size_t i = 0; i < this->NrOfItems; i++)
	{
		delete this->ItemArr[i];
	}
	delete[]ItemArr;
}

void Inventory::Initialize(const int from)
{
	for (size_t i = from; i < this->Caps; i++)
	{
		this->ItemArr[i] = 0;
	}
}
void Inventory::Expand()
{
	this->Caps *= 2;
	item** TempArr = new item * [this->Caps];
	for (size_t i = 0; i < NrOfItems; i++)
	{
		TempArr[i] = new item(*this->ItemArr[i]);
	}
	for (size_t i = 0; i < this->NrOfItems; i++)
	{
		delete this->ItemArr[i];
	}
	delete[]this->ItemArr;

	this->ItemArr = TempArr;
	this->Initialize(this->NrOfItems);
}

void Inventory::AddItem(const item& Item)
{
	if (this->NrOfItems >= this->Caps)
	{
		Expand();
	}
	this->ItemArr[this->NrOfItems++] = new item(Item);
}
void Inventory::RemoveItem(int index)
{

}
