#include "player.h"
#include <iostream>

Player::Player()
{

}

void Player::init(std::string name,int money)
{
	_name=name;
	_money=money;
}

void Player::printInventory()
{
	std::cout << std::endl << _name << "'s money: " << _money << std::endl;
	std::cout << std::endl << _name << "'s inventory" << std::endl << std::endl;

	std::list<Item>::iterator it;

	int i=1;

	for (it = _items.begin(); it!=_items.end(); it++) {
		std::cout << i << "." << (*it).getName() << " x " << (*it).getCount() << " - Price: " << (*it).getValue() << std::endl;
		i++;
	}
}

bool Player::isItemPresent(std::string name)
{
	std::list<Item>::iterator it;

	for (it = _items.begin(); it!=_items.end(); it++) {
		if ((*it).getName() == name)
			return true;
	}
	return false;
}

bool Player::canAffordItem(std::string name,int money)
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

bool Player::removeItem(std::string name,Item &newItem)
{
	std::list<Item>::iterator it;

	for (it=_items.begin(); it!=_items.end(); it++) {

		if ((*it).getName() == name) {

			newItem=(*it);
			(*it).removeOne();

			if ((*it).getCount() == 0)
				_items.erase(it);	

			return true;;
		}
	}

	return false;
}

void Player::addItem(Item newItem)
{
	std::list<Item>::iterator it;

	for (it=_items.begin(); it!=_items.end(); it++) {

		if ((*it).getName() == newItem.getName()) {

			(*it).addOne();
			return;
		}
	}

	_items.push_back(newItem);
}
