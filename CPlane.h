#pragma once

#include <iostream>
using std::string;
using std::cout;
using std::cin;
using std::endl;

//•	המספר הסידורי של המטוס יהיה מספר סידורי המנוהל פנימית ע"י המערכת. מספר סידורי ראשוני הינו 100. שנה את הבנאים בהתאם
//•	אופרטור >> הדפסה באמצעות ה - cout
//•	אופרטור ++ המוסיף כיסא למטוס.עם אפשרות שימוש ב - prefix ו - postfix.


//need to change serialNum to a const


class CPlane
{
private:
	int serialNum;
	static int s_nextSerial;

	string model;
	int numOfChairs;



public:
	CPlane() = delete;
	CPlane(const int numOfChairs, const string& model);
	CPlane(const CPlane& other);
	~CPlane();
	int getSerialNum() const;
	string getModel() const;
	int getNumOfChairs() const;
	
	bool isValidPlane(const int numOfChairs, const string& model)const;
	CPlane& operator=(const CPlane& other);
	CPlane& operator++();//prefix
	CPlane operator++(int);//postfix
	bool operator==(const CPlane& other) const;
	friend std::ostream& operator<<(std::ostream& os, const CPlane& p);



};

