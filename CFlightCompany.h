#pragma once
#include <iostream>
using std::string;
using std::cout;
using std::cin;
using std::endl;
#include "CCrewMember.h"
#include "CPlane.h"
#include "CFlight.h"




//
//את ה - methods הבאים :
//1.	פונקצית הוספת איש צוות אויר רק במידה ולא קיים בחברה.
//2.	פונקצית הוספת מטוס רק במידה ולא קיים בחברה.
//3.	פונקצית הוספת טיסה רק במידה ולא רשום כבר בחברה.לטיסה המוספת לחברה אין כרגע אנשי צוות אויר מוקצים.
//4.	פונקציה המוסיפה איש צוות לטיסה מסוימת.הפונקציה מקבלת מספר עובד ומספר הטיסה.צור פונקצית עזר המחזירה טיסה על פי מספרה ואיש צוות על פי מספרו.
//5.	קבלת מטוס CPlane * לפי אינדקס.יש לוודא שהאינדקס חוקי.



class CFlightCompany
{
private:
	const static int MAX_CREWS = 10;
	const static int MAX_PLANES = 10;
	const static int MAX_FLIGHT = 10;
	string name;
	CCrewMember* members[MAX_CREWS];
	int numOfMembers;
	CPlane* planes[MAX_PLANES];
	int numOfPlanes;
	CFlight* flights[MAX_FLIGHT];
	int numOfFlights;


public:
	CFlightCompany(const string& name);
	CFlightCompany(const CFlightCompany& other);
	~CFlightCompany();
	void SetName(const string& name);
	string getName() const;
	void Print(std::ostream& os) const;

	bool AddCrewMember(const CCrewMember& cmr);
	bool AddPlane(const CPlane& cp);
	bool AddFlight(const CFlight& flt);
	void AddCrewToFlight(const int flightNum, const int memberId ); 
	CPlane* GetPlane(int index)const;

	CFlightCompany& operator=(const CFlightCompany& other);
	bool operator==(const CFlightCompany& other);
	friend std::ostream& operator<<(std::ostream& os, const CFlightCompany& company);


};

