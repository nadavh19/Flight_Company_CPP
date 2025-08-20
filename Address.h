#pragma once
#include<iostream>
using std::string;
using std::cout;
using std::cin;
using std::endl;

class CAddress
{
private:
	string city;
	string street;
	int homeNumber;

public:
	CAddress(const int homeNumber, const string& street, const string& city = "Tel Aviv");
	CAddress(const CAddress& other);
	~CAddress();
	string getCity() const;
	string getStreet() const;
	int getHomeNumber() const;
	void Print() const;
	void UpdateAddress(const string& city, const string& street, const int homeNumber);
	bool isValidAddress(const int homeNumber, const string& street, const string& city)const;






};

