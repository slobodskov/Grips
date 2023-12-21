#include "Human.h"

Human::Human(string name) : _name(name)
{
	data = currentData++;
}

string Human::getName() const
{
	return _name;
}


int Human::getData() const
{
	return data;
}

bool Human::operator== (const Human& otherHuman) const
{
	return data == otherHuman.getData() && _name == otherHuman.getName();
}

bool Human::operator<(const Human& otherHuman) const
{
	return data < otherHuman.getData();
}

int Human::currentData = 0;