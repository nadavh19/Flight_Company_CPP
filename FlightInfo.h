#pragma once
#include <iostream>
using std::string;
using std::cout;
using std::cin;
using std::endl;



class CFlightInfo
{
private:
	int number;
	string destanation;
	int durationMinutes;
	int distanceKm;



public:

	CFlightInfo(const string& dest, const int num, const int minutes, const int distance);
	CFlightInfo(const CFlightInfo& other);
	~CFlightInfo();
	int getNumber() const;
	int getDurationMinutes() const;
	int getDistanceKm() const;
	string getDestanation() const;
	void setNumber(const int num);
	void setDurationMinutes(const int minutes);
	void setDistanceKm(const int distance);
	void SetDest(const string& dest);
	bool IsEqual(const CFlightInfo& cfi) const;
	void Print() const;
	bool isValidFlightInfo(const int, const string&, const int, const int) const;



};

