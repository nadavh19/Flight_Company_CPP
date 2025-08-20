#include "CrewMember.h"



bool CCrewMember::isValidCrewMember(const string& name, const CAddress& address, const int airTime)const
{

    bool isValidAddress = address.isValidAddress(address.getHomeNumber(), address.getStreet(), address.getCity());
    if (!isValidAddress || airTime < 0 || name.length() <= 0)
    {
        return false;
    }
    return true;
}

CCrewMember::CCrewMember(const string& n, const CAddress& ad, const int at) :
    name(""), airTime(0), address(ad)
{
    if (isValidCrewMember(n, ad, at))
    {
        name = n;
        airTime = at;
    }

}

CCrewMember::CCrewMember(const string& n, const CAddress& ad) : name(n), address(ad), airTime(0)
{// continue this func and new unit tests to check it
    if (n.length() > 0 || ad.isValidAddress(ad.getHomeNumber(), ad.getStreet(), ad.getCity()))
    {
        name = n;
        address = ad;
    }
}

CCrewMember::CCrewMember(const CCrewMember& other) :
    name(other.name), airTime(other.airTime), address(other.address)
{
}

string CCrewMember::getName() const
{
    return name;
}

int CCrewMember::getAirTime() const
{
    return airTime;
}

CAddress CCrewMember::getAddress() const
{
    return address;
}

void CCrewMember::setName(const string& diffname)
{
    if (name.length() > 0)
    {
        name = diffname;
    }

}

void CCrewMember::setAddress(const CAddress& ad)
{
    bool isValid = ad.isValidAddress(ad.getHomeNumber(), ad.getStreet(), ad.getCity());
    if (isValid)
    {
        address = ad;
    }
}

bool CCrewMember::UpdateMinutes(const int airTime)
{
    if (airTime < 0)
    {
        return false;
    }
    this->airTime = airTime;
    return true;

}

void CCrewMember::Print() const
{
    //Crewmember Momo minutes 125
    cout << "Crewmember " << name << " minutes " << airTime << endl;
}

bool CCrewMember::IsEqual(const CCrewMember& cm) const
{

    return name == cm.getName();
}

CCrewMember::~CCrewMember()
{

}
