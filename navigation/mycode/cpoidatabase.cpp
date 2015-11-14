


#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <string.h>
#include <sstream>
#include <cstring>
#include <math.h>
#include "cpoidatabase.h"
#include "cwaypoint.h"
using namespace std;



cpoidatabase::cpoidatabase()
{

}


void cpoidatabase::addpoi(t_poi type,string name,string discription,double latitude,double longitude)
{

	cpoi a(type,name,discription,latitude,longitude);

	int b=a.getid();

	m_poi[b]=a;

}


int cpoidatabase::getpointertopoi(string name)
{
	map<int, cpoi>::iterator it;

	for (it = m_poi.begin(); it != m_poi.end(); ++it)
	{
	  if (it->second.getname() == name)
	  {
	   return it->first;
	  }
	}

	return(-1);
}


cpoi cpoidatabase::getelement(int i)
{


	return(m_poi.find(i)->second);


}

void cpoidatabase::print()
{
	int i;
	map<int,cpoi>::iterator it;
	for(it=m_poi.begin();it!=m_poi.end();++i,++it)
	{
		cpoi a=getelement(i);
		a.print();

	}

}

