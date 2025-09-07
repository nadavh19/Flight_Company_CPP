#include "CFlightInfo.h"


bool CFlightInfo::isValidFlightInfo(const int number, const string& destanation, const int durationMinutes, const int distanceKm) const
{
    if (number <= 0 || destanation == "" || durationMinutes <= 0 || distanceKm <= 0)
    {
        return false;
    }
    return true;
}

CFlightInfo& CFlightInfo::operator=(const CFlightInfo& other)
{
    if (*this != other)
    {
        number = other.number;
        destination = other.destination;
        durationMinutes = other.durationMinutes;
        distanceKm = other.distanceKm;
    }
    return *this;
}

bool CFlightInfo::operator==(const CFlightInfo& other) const
{
    return number == other.number;
}

bool CFlightInfo::operator!=(const CFlightInfo& other) const
{
    return !(*this == other);
}

CFlightInfo::operator int() const
{
    return durationMinutes;
}


CFlightInfo::CFlightInfo(const string& dest, const int num, const int minutes, const int distance) :
    number(0), destination(""), durationMinutes(0), distanceKm(0)
{
    setNumber(num);
    SetDest(dest);
    setDurationMinutes(minutes);
    setDistanceKm(distance);
    
}

CFlightInfo::CFlightInfo(const CFlightInfo& other) :
    number(other.number), destination(other.destination), durationMinutes(other.durationMinutes), distanceKm(other.distanceKm)
{
}

int CFlightInfo::GetFNum() const
{
    return number;
}

int CFlightInfo::getDurationMinutes() const
{
    return durationMinutes;
}

int CFlightInfo::getDistanceKm() const
{
    return distanceKm;
}

string CFlightInfo::getDestination() const
{
    return destination;
}

void CFlightInfo::setNumber(const int num)
{
    if (num > 0)
    {
        number = num;
    }
}

void CFlightInfo::setDurationMinutes(const int minutes)
{
    if (minutes > 0)
    {
        durationMinutes = minutes;
    }
}

void CFlightInfo::setDistanceKm(const int distance)
{
    if (distance > 0)
    {
        distanceKm = distance;
    }
}

void CFlightInfo::SetDest(const string& val)
{
    if (val.empty()) {
        destination = "Unknown";
    }
    else {
        destination = val;
    }
}



CFlightInfo::~CFlightInfo()
{
}

std::ostream& operator<<(std::ostream& os, const CFlightInfo& cfi)
{
    os << "Flight Info dest: " << cfi.destination << " Number " << cfi.number
        << " minutes " << cfi.durationMinutes << " KM " << cfi.distanceKm << endl;
    return os;
}
