#pragma once
#include <iostream>
#include <string>
#include "CFlightInfo.h"
#include "CPlane.h"
#include "CCrewMember.h"
using std::string;
using std::cout;
using std::cin;
using std::endl;


class CFlight
{
private:
	static const int MAX_CREW ;
	CFlightInfo info;
	CPlane* plane;
	CCrewMember** members;
	int numOfMembers;
	bool hasPlane;

	bool hasMemberByName(const std::string& name) const;


public:
	CFlight(const CFlightInfo& info); // only info
	CFlight(const CFlightInfo& info, const CPlane& plane); //info and plane
	CFlight(const CFlight& other);
	~CFlight();

	void SetPlane(const CPlane& other);
	CFlight operator+(const CCrewMember& cmr) const ;
	bool operator==(const CFlight& other) const;
	CFlight& operator=(const CFlight& other);
	friend std::ostream& operator<<(std::ostream& os, const CFlight& flt);


};

