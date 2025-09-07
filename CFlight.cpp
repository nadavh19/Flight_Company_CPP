#include "CFlight.h"




CFlight::CFlight(const CFlightInfo& info): info(info), plane(nullptr), numOfMembers(0)
{
    for (int i = 0;i < MAX_CREW;++i)
    {
        members[i] = nullptr;
    }
}

CFlight::CFlight(const CFlightInfo& info, const CPlane* plane)
    : info(info), numOfMembers(0),plane(nullptr)
{

    for (int i = 0;i < MAX_CREW;++i)
    {
        members[i] = nullptr;
    }
	SetPlane(plane);
}

CFlight::CFlight(const CFlight& other):
	info(other.info),plane(nullptr),
	numOfMembers(other.numOfMembers)
{
    if (other.plane)
    {
        plane = new CPlane(*other.plane);
    }

    for (int i = 0; i < MAX_CREW; ++i) 
    {
        members[i] = nullptr;
    }
    for (int i = 0; i < numOfMembers; i++)
    {
        members[i] = new CCrewMember(*other.members[i]);
    }
    
}

CFlight::~CFlight()
{
    for (int i = 0;i < numOfMembers;++i)
    {
        delete members[i];
        members[i] = nullptr;
    }

    delete plane;
    plane = nullptr;
      
}

void CFlight::SetPlane(const CPlane* other)
{
    if (other->isValidPlane(other->getNumOfChairs(), other->getModel()))
    {
        if (!plane)
        {
            plane = new CPlane(*other);
        }
        else
        {
            *plane = *other;
        }
    }
    
}
CFlight CFlight::operator+(const CCrewMember& cmr) const
{

    if (!cmr.isValidCrewMember(cmr.getName(), cmr.getAddress(), cmr.getAirTime())) 
    {
        return *this;
    }

    CFlight res(*this);
    if (res.numOfMembers < MAX_CREW && !res.hasMemberByName(cmr.getName()))
    {
        res.members[res.numOfMembers++] = new CCrewMember(cmr);
    }
    return res;
    
    

    

}

bool CFlight::operator==(const CFlight& other) const
{
    return info == other.info;
}

CFlight& CFlight::operator=(const CFlight& other)
{
    if (this == &other) 
    {
        return *this;
    }
    for (int i = 0;i < numOfMembers;++i) 
    {

        delete members[i];
        members[i] = nullptr;
    }
    
    numOfMembers = other.numOfMembers;
    

    for (int i = 0;i < numOfMembers;++i)
    {
        members[i] = new CCrewMember(*other.members[i]);

    }
    for (int i = numOfMembers;i < MAX_CREW;++i)
    {

        members[i] = nullptr;
    }
    info = other.info;
    plane = other.plane;
    return *this;
}

CFlightInfo CFlight::getInfo() const
{
    return info;
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



std::ostream& operator<<(std::ostream& os, const CFlight& flt)
{
    os << "Flight " << flt.info;
    if (!flt.plane)
    {
        os << "No plane assign yet ";
    }
    else
    {
        os << *flt.plane;
    }
    os << "There are " << flt.numOfMembers << " crew memebers in flight:" << endl;
    if (flt.numOfMembers != 0)
    {
        for (int i = 0; i < flt.numOfMembers; i++)
        {
            os << *flt.members[i];
        }
    }

    return os;
}
