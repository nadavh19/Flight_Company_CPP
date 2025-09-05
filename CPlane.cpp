#include "CPlane.h"


int CPlane::s_nextSerial = 100;



bool CPlane::isValidPlane(const int numOfChairs, const string& model) const
{
	if (numOfChairs <= 0 || model == "")
	{
		return false;
	}
	return true;
}

CPlane& CPlane::operator=(const CPlane& other)
{
	if (this != &other)
	{
		model = other.model;
		numOfChairs = other.numOfChairs;
		serialNum = s_nextSerial; 
		

	}
	return *this;
}

CPlane& CPlane::operator++()
{
	++numOfChairs;
	return *this;
}

CPlane CPlane::operator++(int)
{
	CPlane old = *this;
	++(*this);
	return old;

}

bool CPlane::operator==(const CPlane& other) const
{
	return serialNum == other.serialNum;
}

CPlane::CPlane(const int numOfChairs, const string& model) : serialNum(s_nextSerial++), model(""), numOfChairs(0)
{
	if (isValidPlane(numOfChairs, model))
	{
		this->model = model;
		this->numOfChairs = numOfChairs;
	}
}

CPlane::CPlane(const CPlane& other) : serialNum(other.serialNum), model(other.model), numOfChairs(other.numOfChairs)
{
	
}

int CPlane::getSerialNum() const
{
	return serialNum;
}
string CPlane::getModel() const
{
	return model;
}
int CPlane::getNumOfChairs() const
{
	return numOfChairs;
}


CPlane::~CPlane()
{
}

std::ostream& operator<<(std::ostream& os, const CPlane& p)
{
	os << "Plane " << p.serialNum << " " << p.model << " " << p.numOfChairs << endl;
	return os;
}
