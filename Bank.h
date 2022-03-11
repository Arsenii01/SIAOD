#pragma once
#include <string>

using namespace std;

struct Bank
{
	string name = "";
	unsigned int code;
	string address = "";
	string formOfOwnership = "";
	bool credits;
	bool cards;
};

