#include "CPlane.h"



bool CPlane::isValidPlane(const int serialNum, const int numOfChairs, const string& model) const
{
	if (serialNum <= 0 || numOfChairs <= 0 || model == "")
	{
		return false;
	}
	return true;
}

CPlane::CPlane(const int serialNum, const int numOfChairs, const string& model) : serialNum(0), model(""), numOfChairs(0)
{
	if (isValidPlane(serialNum, numOfChairs, model))
	{
		this->serialNum = serialNum;
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

void CPlane::Print() const
{
	cout << "Plane " << serialNum << " " << model << " " << numOfChairs << endl;
}

bool CPlane::IsEqual(const CPlane& cp) const
{
	return serialNum == cp.serialNum;
}

CPlane::~CPlane()
{
}







