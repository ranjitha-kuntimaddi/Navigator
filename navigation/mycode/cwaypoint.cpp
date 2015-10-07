/*
 * cwaypoint.cpp
 *
 *  Created on: 13-Dec-2012
 *      Author: varun
 */



#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <string.h>
#include <sstream>
#include <cstring>
#include <math.h>
#include "cwaypoint.h"
using namespace std;

cwaypoint::cwaypoint(string name,double latitude,double longitude)
{

	m_name=name;
	m_longitude=longitude;
	m_latitude=latitude;

}

void cwaypoint::set(string name,double longitude,double latitude)
{
	m_name=name;

	if(longitude>=-180 && longitude<=180)
	{
		m_longitude=longitude;
	}
	else
	{
		m_longitude=0;
	}

	if(latitude>=-90 && latitude<=90)
	{
		m_latitude=latitude;
	}
	else
	{
		m_latitude=0;
	}

}

void cwaypoint::transformlongitude2degmmss(int &deg,int &mm,double &ss)
{
	deg=m_longitude/1;
	float a;
	a=m_longitude-deg;
	a=a*3600;
	mm=a/60;
	ss=a-mm;

}
void cwaypoint::transformlatitude2degmmss(int &deg,int &mm,double &ss)
{
	deg=m_latitude/1;
	float a;
	a=m_latitude-deg;
	a=a*3600;
	mm=a/60;
	ss=a-mm;

}


void cwaypoint::print(int format)
{

	if(format==1)
	{

		cout<<m_name;
		cout<<" On Latitude="<<m_latitude;
		cout<<" and Longitude="<<m_longitude;
	}
	else if(format==2)
	{
	int mm=0,deg=0;
	double ss=0;
	cout<<"\n";
	cout<<m_name;
	transformlatitude2degmmss(deg,mm,ss);
	cout<<"  on Latitude="<<deg<<"deg"<<mm<<"min"<<ss<<"sec";
	transformlongitude2degmmss(deg,mm,ss);
	cout<<"  and Longitude="<<deg<<"deg"<<mm<<"min"<<ss<<"sec";

	}
}

string cwaypoint::getname()
{
	return(m_name);
}

double cwaypoint::getlongitude()
{
	return(m_longitude);
}

double cwaypoint::getlatitude()
{
	return(m_latitude);
}


void cwaypoint::getalldatabypointer(string *pname,double *plongitude,double *platitude)
{
	pname=m_name;
	*plongitude=m_longitude;
	*platitude=m_latitude;
}

void cwaypoint::getalldatabyreference(string pname,double &plongitude,double &platitude)
{
	pname=m_name;
	plongitude=m_longitude;
	platitude=m_latitude;
}

double cwaypoint::calculatedistance(const cwaypoint &wp1)
{
	double dist;
	double a=wp1.m_latitude,b=wp1.m_longitude;
	dist=(sin(m_latitude)*sin(a));
	dist=dist+(cos(m_latitude)*cos(a)*cos(b-m_longitude));
	dist=acos(dist);
	dist=6378*dist;
	return(dist);
}

cwaypoint cwaypoint::add(cwaypoint const &wp_right)
{
	string name;
	name=m_name+wp_right.m_name;
	double a,b;
	a=m_longitude+wp_right.m_longitude;
	b=m_latitude+wp_right.m_latitude;
	cwaypoint addedobject(name,a,b);
	return(addedobject);

}

bool cwaypoint::less(cwaypoint const &wp_right)
{
	bool a=0;
	string name="      \0";
	cwaypoint zer(name,0,0);
	double dist1,dist2;
	dist1=zer.calculatedistance(wp_right);
	dist2=calculatedistance(zer);
	if(dist1>dist2)
	{
		a=1;
	}
	return(a);
}


