#pragma once
#include <iostream>
#include <string>
#include "Address.h"
using std::string;
using std::cout;
using std::cin;
using std::endl;



//ה - members של המחלקה הם :
//1.	שם העובד - מוגדר כ - string
//2.	דקות האוויר(air time) המצטברות שלו - INT
//3.	כתובת העובד - CAddress
//
//יש לממש את ה - methods הבאים :
//1.	בנאי(Constructor) המקבל את שם איש צוות האוויר, את הכתובת שלו ואת מספר דקות האוויר שלו.יש לאפשר אתחול שם איש צוות אויר וכתובת ללא מתן מספר הדקות.במקרה זה מספר הדקות יהיה 0.
//2.	פונקציה אשר מעדכנת את דקות האוויר המצטברות שלו – מוסיפה דקות לכמות הנוכחית.יש לוודא חוקיות נתונים.
//3.	פונקציות  get ו set למשתנה שם העובד.
//4.	פונקציות  get ו set למשתנה כתובת העובד.
//5.	פונקציה get  לזמן האוויר.
//6.	פונקציה Print המדפיסה את פרטי האובייקט.
//7.	פונקצית השוואה(IsEqual) לאיש צוות אוויר אחר, השוואה לפי שם.הפונקציה תחזיר true / false.


class CCrewMember
{
private:
	string name;
	int airTime;
	CAddress address;



public:
	//CCrewMember("Momo", b2, 125);
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

