#include "CCrewMember.h"


int CCrewMember::nextId = 1000;

bool CCrewMember::isValidCrewMember(const string& name, const CAddress& address, const int airTime)const
{

    bool isValidAddress = address.isValidAddress(address.getHomeNumber(), address.getStreet(), address.getCity());
    if (!isValidAddress || airTime < 0 || name.length() <= 0)
    {
        return false;
    }
    return true;
}

CCrewMember& CCrewMember::operator=(const CCrewMember& other)
{
    if (this != &other)
    {
        name = other.name;
        address = other.address;
        airTime = other.airTime;
        id = other.id;
    }
    return *this;
}

bool CCrewMember::operator==(const CCrewMember& other) const
{
    return id == other.id;
}

CCrewMember& CCrewMember::operator+=(const int minutes)
{
    if (minutes > 0)
    {
        airTime += minutes;
    }
    return *this;
}

CCrewMember::CCrewMember(const string& n, const CAddress& ad, const int at) :
    name(""), airTime(0), address(ad),id(nextId++)
{
    if (isValidCrewMember(n, ad, at))
    {
        setName(n);
        airTime = at;
    }

}

CCrewMember::CCrewMember(const string& n, const CAddress& ad) : name(n), address(ad), airTime(0),id(nextId++)
{
    if (n.length() > 0 || ad.isValidAddress(ad.getHomeNumber(), ad.getStreet(), ad.getCity()))
    {
        name = n;
        address = ad;
    }
}

CCrewMember::CCrewMember(const CCrewMember& other) :
    name(other.name), airTime(other.airTime), address(other.address), id(other.id)
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





CCrewMember::~CCrewMember()
{

}

std::ostream& operator<<(std::ostream& os, const CCrewMember& cmr)
{
    os << "Crewmember " << cmr.name << " minutes " << cmr.airTime << endl;
    return os;
}
