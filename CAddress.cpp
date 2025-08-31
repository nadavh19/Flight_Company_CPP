#include "CAddress.h"




bool CAddress::isValidAddress(const int homeNumber, const string& street, const string& city)const
{
    if (city == "" || street == "" || homeNumber <= 0)
    {
        return false;
    }
    return true;
}

CAddress& CAddress::operator=(const CAddress& other)
{
    if (*this != other)
    {
        UpdateAddress(other.city, other.street, other.homeNumber);
    }
    return *this;

}

bool CAddress::operator==(const CAddress& other) const
{
    return ((city == other.city) && (street == other.street) && (homeNumber == other.homeNumber));
}

bool CAddress::operator!=(const CAddress& other) const
{
    return !(*this == other);
}


CAddress::CAddress(const int homeNumber, const string& street, const string& city) : city("Tel Aviv"), street(""), homeNumber(0)

{
    UpdateAddress(city, street, homeNumber);

}

CAddress::CAddress(const int homeNumber, const char* street, const char* city) : city("Tel Aviv"), street(""), homeNumber(0)
{
    UpdateAddress((string&)city, (string&)street, homeNumber);
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

std::ostream& operator<<(std::ostream& os, const CAddress& ad)
{
    os << ad.street << " " << ad.homeNumber << " " << ad.city << endl;
    return os;
}

std::istream& operator>>(std::istream& is, CAddress& ad)
{
    cout << "Please enter house number street name and city name:\n";
    is >> ad.homeNumber >> ad.street >> ad.city;
    return is;  
}

