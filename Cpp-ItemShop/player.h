#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <list>
#include "item.h"

class Player
{
	private:
		std::string _name;
		int _money;
		std::list<Item> _items;
	public:
		Player();
		void init(std::string name,int money);
		void printInventory();
		bool isItemPresent(std::string name);
		bool canAffordItem(std::string name,int money);
		bool removeItem(std::string name,Item &newItem);
		void addItem(Item newItem);
		void addMoney(int money) {_money += money;}
		int getMoney() {return _money;}
		void subtractMoney(int amount) {_money -= amount;}
};

#endif // PLAYER_H
