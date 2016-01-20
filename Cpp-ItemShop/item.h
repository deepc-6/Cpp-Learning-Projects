#ifndef ITEM_H
#define ITEM_H

#include <string>

class Item
{
	private:
		std::string _name;
		int _value;
		int _count;
	public:
		Item(std::string name,int value);
		void addOne();
		void removeOne();
		std::string getName() {return _name;}
		int getValue() {return _value;}
		int getCount() {return _count;}
		void setCount(int count) {_count=count;}
};

#endif // ITEM_H
