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
	string destination;
	int durationMinutes;
	int distanceKm;



public:

	CFlightInfo(const string& dest, const int num, const int minutes, const int distance);
	CFlightInfo(const CFlightInfo& other);
	~CFlightInfo();
	int GetFNum() const;
	int getDurationMinutes() const;
	int getDistanceKm() const;
	string getDestination() const;
	void setNumber(const int num);
	void setDurationMinutes(const int minutes);
	void setDistanceKm(const int distance);
	void SetDest(const string& dest);
	bool isValidFlightInfo(const int, const string&, const int, const int) const;


	//OPS
	friend std::ostream& operator<<(std::ostream& os, const CFlightInfo& cfi);
	CFlightInfo& operator=(const CFlightInfo& other);
	bool operator==(const CFlightInfo& other)const;
	bool operator!=(const CFlightInfo& other)const;
	operator int() const;



};

