#pragma once
#include <iostream>
using std::string;
using std::cout;
using std::cin;
using std::endl;


//ה members של המחלקה הם :
//1.	שם החברה – מוגדר כ - string
//
//
//יש לממש את ה methods הבאים :
//1.	בנאי(Constructor) המקבל שם החברה.
//2.	פונקציה המחזירה את שם החברה.
//3.	פונקצית הדפסה של פרטי החברה.

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

