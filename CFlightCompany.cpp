#include "CFlightCompany.h"
// ----- local helpers (file-scope) -----


namespace {

	inline int flightNumberOf(const CFlight& flt) {
		return flt.getInfo().GetFNum();
	}
	inline int crewIdOf(const CCrewMember& cmr) {
		return cmr.getId();
	}

	inline int findCrewIndexById(CCrewMember* const members[], int count, int id) {
		for (int i = 0; i < count; ++i) 
		{
			if (members[i] && crewIdOf(*members[i]) == id)
			{
				return i;
			}
		}
		return -1;
	}

	inline int findFlightIndexByNumber(CFlight* const flights[], int count, int number) {
		for (int i = 0; i < count; ++i) {
			if (flights[i] && flightNumberOf(*flights[i]) == number) return i;
		}
		return -1;
	}

	inline bool crewExists(const CCrewMember& candidate, CCrewMember* const members[], int count) {
		// Uniqueness by employee id
		const int id = crewIdOf(candidate);
		return findCrewIndexById(members, count, id) != -1;
	}

	inline bool samePlane(const CPlane& a, const CPlane& b) {
		return a == b;
	}

	inline bool planeExists(const CPlane& candidate, CPlane* const planes[], int count) {
		for (int i = 0; i < count; ++i)
		{
			if (planes[i] && samePlane(*planes[i], candidate))
			{
				return true;
			}
		}
		return false;
	}

	inline bool flightExists(const CFlight& candidate, CFlight* const flights[], int count) {
		for (int i = 0; i < count; ++i) 
		{
			if (flights[i] && *flights[i] == candidate)
			{
				return true;

			}
		}
		return false;
	}

} // namespace



CFlightCompany::CFlightCompany(const string& name) : name(""),numOfMembers(0),numOfPlanes(0),numOfFlights(0)
{
	SetName(name);
	for (int i = 0; i < MAX_CREWS; i++)
	{	
		members[i] = nullptr;
	}
	for (int i = 0; i < MAX_PLANES; i++)
	{
		planes[i] = nullptr;
	}
	for (int i = 0; i < MAX_FLIGHT; i++)
	{
		flights[i] = nullptr;
	}
}

CFlightCompany::CFlightCompany(const CFlightCompany& other) : 
	name(other.name), numOfMembers(other.numOfMembers), numOfPlanes(other.numOfPlanes), numOfFlights(other.numOfFlights)
{
	for (int i = 0; i < MAX_CREWS; ++i) 
	{ 
		members[i] = nullptr; 
	}
	for (int i = 0; i < MAX_PLANES; ++i) 
	{ 
		planes[i] = nullptr; 
	}
	for (int i = 0; i < MAX_FLIGHT; ++i) 
	{
		flights[i] = nullptr; 
	}

	for (int i = 0; i < numOfMembers; ++i) 
	{
		members[i] = new CCrewMember(*other.members[i]); 
	}
	for (int i = 0; i < numOfPlanes; ++i) 
	{
		planes[i] = new CPlane(*other.planes[i]); 
	}
	for (int i = 0; i < numOfFlights; ++i) 
	{
		flights[i] = new CFlight(*other.flights[i]); 
	}
}

CFlightCompany::~CFlightCompany() 
{
	for (int i = 0; i < numOfMembers; ++i) {
		delete members[i];
		members[i] = nullptr;
	}
	numOfMembers = 0;
	for (int i = 0; i < numOfPlanes; ++i) {
		delete planes[i];
		planes[i] = nullptr;
	}
	numOfPlanes = 0;
	for (int i = 0; i < numOfFlights; ++i) {
		delete flights[i];
		flights[i] = nullptr;
	}
	numOfFlights;
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

void CFlightCompany::Print(std::ostream& os) const
{
	os << *this;
}



CPlane* CFlightCompany::GetPlane(int index) const
{
	if (numOfPlanes == 0)
	{
		return nullptr;
	}
	CPlane* plane = new CPlane(*planes[index]);
	return plane;
}
bool  CFlightCompany::AddCrewMember(const CCrewMember& cmr) {
	if (numOfMembers >= MAX_CREWS) 
		return false;
	if (crewExists(cmr, members, numOfMembers)) 
		return false;
	members[numOfMembers++] = new CCrewMember(cmr);
	return true;
}
bool CFlightCompany::AddPlane(const CPlane& cp) {
	if (numOfPlanes >= MAX_PLANES) 
		return false;
	if (!cp.isValidPlane(cp.getNumOfChairs(), cp.getModel())) 
		return false;
	if (planeExists(cp, planes, numOfPlanes)) 
		return false;
	planes[numOfPlanes++] = new CPlane(cp);
	return true;
}
bool CFlightCompany::AddFlight(const CFlight& flt) {
	if (numOfFlights >= MAX_FLIGHT) 
		return false;
	if (flightExists(flt, flights, numOfFlights)) 
		return false;
	flights[numOfFlights++] = new CFlight(flt);
	return true;
}
void CFlightCompany::AddCrewToFlight(const int flightNum, const int memberId) {
	int fi = findFlightIndexByNumber(flights, numOfFlights, flightNum);
	if (fi == -1)
	{
		return;

	}
	int mi = findCrewIndexById(members, numOfMembers, memberId);
	if (mi == -1) 
	{
		return;

	}

	// CFlight::operator+ returns a NEW flight; assign back into the existing one.
	*flights[fi] = (*flights[fi] + *members[mi]);
}

CFlightCompany& CFlightCompany::operator=(const CFlightCompany& other) {
	if (this == &other) return *this;

	// Clean current
	for (int i = 0; i < numOfMembers; ++i) 
	{
		delete members[i]; members[i] = nullptr; 
	}
	for (int i = 0; i < numOfPlanes; ++i) 
	{
		delete planes[i];  planes[i] = nullptr; 
	}
	for (int i = 0; i < numOfFlights; ++i)
	{ 
		delete flights[i]; flights[i] = nullptr; 
	}

	// Copy metadata
	name = other.name;
	numOfMembers = other.numOfMembers;
	numOfPlanes = other.numOfPlanes;
	numOfFlights = other.numOfFlights;

	// Deep copy arrays
	for (int i = 0; i < numOfMembers; ++i)
	{
		members[i] = new CCrewMember(*other.members[i]);
	}
	for (int i = 0; i < numOfPlanes; ++i) 
	{
		planes[i] = new CPlane(*other.planes[i]);
	}
	for (int i = 0; i < numOfFlights; ++i)
	{
		flights[i] = new CFlight(*other.flights[i]);

	}

	return *this;
}

bool CFlightCompany::operator==(const CFlightCompany& other)
{
	return name == other.name;
}

std::ostream& operator<<(std::ostream& os, const CFlightCompany& company)
{
	os << "There are " << company.numOfMembers << " Crew members:" << endl;
	if(company.numOfMembers > 0)
	{
		for (int i = 0; i < company.numOfMembers; i++)
		{
			os << *company.members[i];
		}
	}
	

	os << "There are " << company.numOfPlanes << " Planes:" << endl;
	if (company.numOfPlanes > 0)
	{
		for (int i = 0; i < company.numOfPlanes; i++)
		{
			os << *company.planes[i];
		}

	}
	os << "There are " << company.numOfFlights<< " Flights:" << endl;
	if (company.numOfFlights> 0)
	{
		for (int i = 0; i < company.numOfFlights; i++)
		{
			os << *company.flights[i];
		}

	}
	

		return os;
}
