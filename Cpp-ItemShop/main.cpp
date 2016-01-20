#include <iostream>
#include <string>
#include "player.h"
#include "shop.h"

void initShops(std::list<Shop> &shops);
void initPlayer(Player &player);
void enterShop(Player &player,Shop &shop);

int main()
{
	std::list<Shop> shops;
	Player player;	

	initPlayer(player);
	initShops(shops);

	bool isDone=false;

	while (!isDone) {

		std::cout << "\nShops\n\n";

		int i=1;

		std::list<Shop>::iterator it;

		for (it=shops.begin(); it!=shops.end(); it++) {

			std::cout << i << "." << (*it).getName() << std::endl;
			i++;
		}

		std::string shopName;

		std::cout << "\nWhich shop would you like to enter?\nPress q to exit\n\n";
		std::cin.clear();
		getline(std::cin,shopName);

		bool validShop=false;

		if (shopName=="q") {

			validShop=true;
			isDone=true;
		}

		for (it=shops.begin(); it!=shops.end(); it++) {
			if ((*it).getName() == shopName) {
				
				enterShop(player,(*it));
				validShop=true;
			}
		}

		if (!validShop)
			std::cout << "\nInvalid shop selection\n";
	}

	return 0;
}

void initShops(std::list<Shop> &shops)
{
	shops.push_back(Shop("Bills Leather Shop",1500));
	shops.back().addItem(Item("Leather Boots",50));
	shops.back().addItem(Item("Leather Hat",50));
	shops.back().addItem(Item("Leather Gloves",50));
	shops.back().addItem(Item("Leather Leggings",50));
	shops.back().addItem(Item("Leather Armor",50));

	shops.push_back(Shop("Blacksmith",3000));
	shops.back().addItem(Item("Iron Boots",100));
	shops.back().addItem(Item("Iron Hat",100));
	shops.back().addItem(Item("Iron Gloves",100));
	shops.back().addItem(Item("Iron Leggings",100));
	shops.back().addItem(Item("Iron Armor",100));

	shops.push_back(Shop("Beverly's Fruity Fruit Shop",1000));
	shops.back().addItem(Item("Apples",5));
	shops.back().addItem(Item("Oranges",5));
	shops.back().addItem(Item("Grapes",5));
	shops.back().addItem(Item("Watermelon",5));
	shops.back().addItem(Item("Tomato",5));
}

void initPlayer(Player &player)
{
	std::cout << "\nEnter name of player:\n\n";
	std::string name;
	std::cin.clear();
	getline(std::cin,name);
	player.init(name,100);
	player.addItem(Item("Bronze Sword",5));
}

void enterShop(Player &player,Shop &shop)
{
	bool isDone=false;
	Item newItem("NOITEM",0);
	std::string itemName;

	while (!isDone) {

		shop.printShop();
		player.printInventory();

		std::cout << "\nWould you like to buy or sell? (Q to quit or B/S):\n\n";
		char input;
		std::cin >> input;

		std::cin.ignore(64,'\n');
		std::cin.clear();

		if (input == 'Q' || input =='q')
			return;

		if (input == 'B' || input == 'b') {
						
			std::cout << "\nEnter the item you wish to buy:\n\n";
			getline(std::cin,itemName);

			if (shop.isItemPresent(itemName)) {

				if (shop.canAffordItem(itemName,player.getMoney())) {

					if (shop.purchaseItem(itemName,newItem)) {

						player.addItem(newItem);
						player.addMoney(-newItem.getValue());
						shop.addMoney(newItem.getValue());
						std::cout << "\nPurchase Successful\n";
					}
				} else
					std::cout << "\nYou cannot afford this item\n";	
			} else
				std::cout << "\nNo such item exists in shop\n";

		} else if (input == 'S' || input == 's') {
			
			std::cout << "\nEnter the item you wish to sell:\n\n";
			getline(std::cin,itemName);

			if (player.isItemPresent(itemName)) {
			
				if (player.canAffordItem(itemName,shop.getMoney())) {

					if (player.removeItem(itemName,newItem)) {

						shop.addItem(newItem);
						shop.addMoney(-newItem.getValue());
						player.addMoney(newItem.getValue());
						std::cout << "\nSell successful\n";
					}
				} else
					std::cout << "\nShopkeeper cannot afford this item\n";
			} else
				std::cout << "\nNo such item exists in inventory\n";

		} else {
			std::cout << "\nPlease enter a valid option\n";
		}
	}
}
