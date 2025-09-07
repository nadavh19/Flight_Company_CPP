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
	int id;
	static int nextId;
	


public:

	const static int START_ID = 1000;

	CCrewMember(const string& n, const CAddress& ad, const int at);
	CCrewMember(const string& n, const CAddress& ad);
	CCrewMember(const string& n, const int at);
	CCrewMember(const string& n);
	CCrewMember(const CCrewMember& other);
	~CCrewMember();

	string getName() const;
	int getAirTime() const;
	CAddress getAddress() const;
	int getId() const;

	void setName(const string& diffname);
	void setAddress(const CAddress& ad);
	bool UpdateMinutes(const int airTime);
	bool isValidCrewMember(const string& n, const CAddress& ad, const int at)const;

	CCrewMember& operator=(const CCrewMember& other);
	bool operator==(const CCrewMember& other) const;
	friend std::ostream& operator<<(std::ostream& os, const CCrewMember& cmr);
	//CCrewMember& operator+=(const int minutes);
	bool operator+=(const int minutes);




};

