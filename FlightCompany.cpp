#include "FlightCompany.h"

CFlightCompany::CFlightCompany(const string& name) : name("")
{
	SetName(name);
}

CFlightCompany::CFlightCompany(const CFlightCompany& other) : name(other.name)
{
}

CFlightCompany::~CFlightCompany()
{
}

void CFlightCompany::SetName(const string& name)
{
	if (name.length() > 0)
	{
		this->name = name;
	}
}

string CFlightCompany::getName() const
{
	return name;
}

void CFlightCompany::Print()
{
	cout << "Flight company: " << name << endl;
}

