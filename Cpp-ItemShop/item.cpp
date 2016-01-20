#include "item.h"

Item::Item(std::string name, int value)
{
	_name=name;
	_value=value;
	_count=1;
}

void Item::addOne()
{
	_count++;
}

void Item::removeOne()
{
	if (_count > 0)
		_count--;
}
