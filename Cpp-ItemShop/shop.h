#ifndef SHOP_H
#define SHOP_H

#include <string>
#include <list>
#include "item.h"

class Shop
{
	private:
		std::string _name;
		std::list<Item> _items;
		int _money;
	public:
		Shop(std::string name,int money);
		void printShop();
		bool isItemPresent(std::string name);
		bool canAffordItem(std::string name,int money);
		bool purchaseItem(std::string name,Item &newItem);
		void addItem(Item newItem);
		void addMoney(int money) {_money += money;}
		std::string getName() {return _name;}
		int getMoney() {return _money;}
};

#endif // SHOP_H
