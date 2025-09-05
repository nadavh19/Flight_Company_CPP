#include "CFlight.h"
#include <new>

const int CFlight::MAX_CREW = 10;

CFlight::CFlight(const CFlightInfo& info): info(info), hasPlane(false), plane(nullptr), members(nullptr), numOfMembers(0)
{
}

CFlight::CFlight(const CFlightInfo& info, const CPlane& plane): info(info), hasPlane(false),plane(nullptr), members(nullptr), numOfMembers(0)
{
	SetPlane(plane);
}

CFlight::CFlight(const CFlight& other):
	info(other.info),plane(other.plane),hasPlane(other.hasPlane),
	members(other.members),numOfMembers(other.numOfMembers)
{
}

CFlight::~CFlight()
{
    
    for (int i = 0; i < numOfMembers; i++) {
        delete members[i];
        members[i] = nullptr;
    }

    delete[] members;
    members = nullptr;

    
    delete plane;
    plane = nullptr;
}

void CFlight::SetPlane(const CPlane& other)
{
    if (other.isValidPlane(other.getNumOfChairs(), other.getModel()))
    {
        delete this->plane;              
        this->plane = nullptr;
        this->plane = new CPlane(other); 
        hasPlane = true;
    }
    
}
CFlight CFlight::operator+(const CCrewMember& cmr) const
{

    if (numOfMembers >= MAX_CREW || hasMemberByName(cmr.getName())|| 
        !(cmr.isValidCrewMember(cmr.getName(),cmr.getAddress(),cmr.getAirTime())))
    {
        return *this;
    }
    CFlight newFlight(*this);

    
    CCrewMember** newArr = new CCrewMember * [newFlight.numOfMembers + 1];

    
    for (int i = 0; i < newFlight.numOfMembers; ++i)
    {
        newArr[i] = new CCrewMember(*newFlight.members[i]);
    }

    
    newArr[newFlight.numOfMembers] = new CCrewMember(cmr);

    
    for (int i = 0; i < newFlight.numOfMembers; ++i)
    {
        delete newFlight.members[i];
    }
    delete[] newFlight.members;

    
    newFlight.members = newArr;
    ++newFlight.numOfMembers;

    return newFlight;

}

bool CFlight::operator==(const CFlight& other) const
{
    return info == other.info;
}

bool CFlight::hasMemberByName(const string& name) const
{
    for (int i = 0; i < numOfMembers; i++)
    {
        if (members[i]->getName() == name)
        {
            return true;
        }
    }
    return false;
}




