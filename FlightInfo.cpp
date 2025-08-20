#include "FlightInfo.h"


bool CFlightInfo::isValidFlightInfo(const int number, const string& destanation, const int durationMinutes, const int distanceKm) const
{
    if (number <= 0 || destanation == "" || durationMinutes <= 0 || distanceKm <= 0)
    {
        return false;
    }
    return true;
}


CFlightInfo::CFlightInfo(const string& dest, const int num, const int minutes, const int distance) :
    number(0), destanation(""), durationMinutes(0), distanceKm(0)
{
    if (isValidFlightInfo(num, dest, minutes, distance))
    {
        number = num;
        destanation = dest;
        durationMinutes = minutes;
        distanceKm = distance;
    }
}

CFlightInfo::CFlightInfo(const CFlightInfo& other) :
    number(other.number), destanation(other.destanation), durationMinutes(other.durationMinutes), distanceKm(other.distanceKm)
{
}

int CFlightInfo::getNumber() const
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

string CFlightInfo::getDestanation() const
{
    return destanation;
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

void CFlightInfo::SetDest(const string& dest)
{
    if (dest.length() > 0)
    {
        destanation = dest;
    }

}

bool CFlightInfo::IsEqual(const CFlightInfo& cfi) const
{
    return number == cfi.number;
}

void CFlightInfo::Print() const
{
    cout << "Flight Info dest: " << destanation << " Number " << number
        << " minutes " << durationMinutes << " KM " << distanceKm << endl;
}

CFlightInfo::~CFlightInfo()
{
}

