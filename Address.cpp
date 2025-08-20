#include "Address.h"




bool CAddress::isValidAddress(const int homeNumber, const string& street, const string& city)const
{
    if (city == "" || street == "" || homeNumber <= 0)
    {
        return false;
    }
    return true;
}


CAddress::CAddress(const int homeNumber, const string& street, const string& city) : city("Tel Aviv"), street(""), homeNumber(0)

{
    UpdateAddress(city, street, homeNumber);

}

CAddress::CAddress(const CAddress& other) : city(other.city), street(other.street), homeNumber(other.homeNumber)
{
}

CAddress::~CAddress()
{
}

string CAddress::getCity() const
{
    return city;
}

string CAddress::getStreet() const
{
    return street;
}

int CAddress::getHomeNumber() const
{
    return homeNumber;
}

void CAddress::Print() const
{
    cout << street << " " << homeNumber << ", " << city << endl;
}

void CAddress::UpdateAddress(const string& city, const string& street, const int homeNumber)
{
    if (isValidAddress(homeNumber, street, city))
    {
        this->city = city;
        this->street = street;
        this->homeNumber = homeNumber;
    }

}







