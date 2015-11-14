

#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <string.h>
#include <sstream>
#include <cstring>
#include <math.h>
#include "cpoidatabase.h"
#include "cwaypoint.h"
#include "croute.h"
#include "cpoi.h"

using namespace std;

croute::croute(unsigned int maxwp,unsigned int maxpoi)
{
	cwaypoint a("!0",0,0);
	m_pwaypoint.assign(maxwp,a);
    m_poi=maxpoi;

	m_poidatabase = new cpoidatabase;

}

croute::croute(croute const& origin)
{
	m_poidatabase=origin.m_poidatabase;
	m_poi=origin.m_poi;
    m_pwaypoint=origin.m_pwaypoint;
}

croute::~croute()
{
	int i=m_poi;
	while(i>=0)
	{
		delete(m_poidatabase);
	}
}

void croute::connecttopoidatabase(cpoidatabase* ppoidb)
{

	m_poidatabase =ppoidb;

}

void croute::addwaypoint(cwaypoint const &wp)
{

	std::vector<cwaypoint>::iterator it;
	for (it=m_pwaypoint.begin(); it<m_pwaypoint.end(); it++);

	it=m_pwaypoint.insert(it,wp);


}


double getdistancenextpoi(cwaypoint const &wp,cpoi &poi)
{

	double distnextpoi = 0;
	double lon=poi.getlatitude();
	double lan=poi.getlongitude();

	cpoi wppoi;

	wppoi.set(poi.getname(),lon,lan);

	distnextpoi = wppoi.calculatedistance(wp);

	return distnextpoi;


}


void croute::print()
{

	m_poidatabase->print();

	std::vector<cwaypoint>::iterator it;

	for (it=m_pwaypoint.begin(); it<m_pwaypoint.end(); it++)
	{
		cout<<*it;
		cout<<"\n";


	}

}


void croute::printtofile(string name)
{



}


void readfromfile(string filename,bool deleteolddata)
{




}
