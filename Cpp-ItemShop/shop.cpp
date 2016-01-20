#include "shop.h"
#include <iostream>

Shop::Shop(std::string name,int money)
{
	_name=name;
	_money=money;
}

void Shop::printShop()
{
	std::cout << "\nWelcome to " << _name << std::endl;
	std::cout << std::endl << _name << "'s money: " << _money << std::endl << std::endl;

	std::list<Item>::iterator it;

	int i=1;

	for (it = _items.begin(); it!=_items.end(); it++) {
		std::cout << i << "." << (*it).getName() << " x " << (*it).getCount() << " - Price: " << (*it).getValue() << std::endl;
		i++;
	}
}

bool Shop::isItemPresent(std::string name)
{
	std::list<Item>::iterator it;

	for (it = _items.begin(); it!=_items.end(); it++) {
		if ((*it).getName() == name)
			return true;
	}
	return false;
}

bool Shop::canAffordItem(std::string name,int money)
{

	std::list<Item>::iterator it;

	for (it = _items.begin(); it!=_items.end(); it++) {
		if ((*it).getName() == name) {
			if((*it).getValue() <= money)
				return true;
		}
	}

	return false;
}

bool Shop::purchaseItem(std::string name,Item &newItem)
{
	std::list<Item>::iterator it;

	for (it = _items.begin(); it!=_items.end(); it++) {
		if ((*it).getName() == name) {

			newItem = (*it);

			newItem.setCount(1);
			(*it).removeOne();

			if ((*it).getCount()==0)
				_items.erase(it);

			return true;
		}
	}

	return false;
}

void Shop::addItem(Item newItem)
{
	std::list<Item>::iterator it;

	for (it = _items.begin(); it!=_items.end(); it++) {

		if ((*it).getName() == newItem.getName()) {

			(*it).addOne();
			return;
		}
	}
	_items.push_back(newItem);
}
