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

bool CFlightInfo::IsEqual(const CFlightInfo& cfi) const
{
    return number == cfi.number;
}

void CFlightInfo::Print() const
{
    cout << "Flight Info dest: " << destination << " Number " << number
        << " minutes " << durationMinutes << " KM " << distanceKm << endl;
}

CFlightInfo::~CFlightInfo()
{
}

