#pragma once
#include <iostream>
using std::string;
using std::cout;
using std::cin;
using std::endl;

class CFlightCompany
{
private:
	string name;
public:
	CFlightCompany(const string& name);
	CFlightCompany(const CFlightCompany& other);
	~CFlightCompany();
	void SetName(const string& name);
	string getName() const;
	void Print();

};

