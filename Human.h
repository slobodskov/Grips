#pragma once
#include <iostream>
#include <string>
using namespace std;

class Human
{
	public:
		Human(string name);
		bool operator==(const Human& otherHuman) const;
		bool operator<(const Human& otherHuman) const;
		string getName() const;
		int getData() const;

	private:
		string _name;
		int data;
		static int currentData;
};

