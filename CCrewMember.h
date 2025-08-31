#pragma once
#include <iostream>
#include <string>
#include "CAddress.h"
using std::string;
using std::cout;
using std::cin;
using std::endl;



class CCrewMember
{
private:
	string name;
	int airTime;
	CAddress address;



public:
	CCrewMember(const string& n, const CAddress& ad, const int at);
	CCrewMember(const string& n, const CAddress& ad);
	CCrewMember(const CCrewMember& other);
	~CCrewMember();

	string getName() const;
	int getAirTime() const;
	CAddress getAddress() const;

	void setName(const string& diffname);
	void setAddress(const CAddress& ad);
	bool UpdateMinutes(const int airTime);
	void Print() const;
	bool IsEqual(const CCrewMember& cm) const;
	bool isValidCrewMember(const string& n, const CAddress& ad, const int at)const;
};

