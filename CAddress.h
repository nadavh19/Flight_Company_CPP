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
	CAddress(const int homeNumber, const char* street, const char* city = "Tel Aviv"); //new for suppurting NULL
	CAddress(const CAddress& other);
	~CAddress();
	string getCity() const;
	string getStreet() const;
	int getHomeNumber() const;
	void Print() const;
	void UpdateAddress(const string& city, const string& street, const int homeNumber);
	bool isValidAddress(const int homeNumber, const string& street, const string& city)const;


	//OPS
	CAddress& operator=(const CAddress& other);
	bool operator==(const CAddress& other) const;
	bool operator!=(const CAddress& other) const;
	friend std::istream& operator>>(std::istream& is, CAddress& ad);
	friend std::ostream& operator<<(std::ostream& os, const CAddress& ad);
	string getCurrentAddress() const;




};

