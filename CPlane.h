#pragma once

#include <iostream>
using std::string;
using std::cout;
using std::cin;
using std::endl;



class CPlane
{
private:
	int serialNum;
	string model;
	int numOfChairs;



public:
	CPlane(const int serialNum, const int numOfChairs, const string& model);
	CPlane(const CPlane& other);
	~CPlane();
	int getSerialNum() const;
	string getModel() const;
	int getNumOfChairs() const;
	void Print() const;
	bool IsEqual(const CPlane& cp) const;
	bool isValidPlane(const int serialNum, const int numOfChairs, const string& model)const;


};

