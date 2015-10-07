/*
 * cpoi.cpp
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
#include "cpoi.h"
#include "cwaypoint.h"
using namespace std;

ostringstream convert;

char a='<',b='/',c='>';

cpoi::cpoi (t_poi type,string name,string discription,double latitude,double longitude)
{
	m_type=type;
	m_count=0;
    m_discription = discription;
    char ch[20]=name;
    set(ch,latitude,longitude);

}

void cpoi::print()
{
	cout << "Point of Interest" << endl;
	cout << "=================" << endl;

	string printType;


	switch(m_type)
	{
			case COLLEGE: printType = "COLLEGE"; break;

			case ENTERTAINMENT: printType = "ENTERTAINMENT"; break;

			case FOOD: printType = "FOOD"; break;

			case NIGHTLIFE: printType = "NIGHTLIFE"; break;

			case NONE: printType = "NONE"; break;

			case OFFICE: printType = "OFFICE"; break;

			case OUTDOORS: printType = "OUTDOORS"; break;

			case RECREATION: printType = "RECREATION"; break;

			case RESIDENCE: printType = "RESIDENCE"; break;

			case SHOP: printType = "SHOP"; break;

			case TRANSPORT: printType = "TRANSPORT"; break;

	}

		cout << "Type of POI: " << printType << endl;
		cout << "Description: " << m_discription<<endl;
		cwaypoint::print(2);

}


cxmlstring cpoi::toxml()
{

	string printType;


		switch(m_type)
		{
				case COLLEGE: printType = "COLLEGE"; break;

				case ENTERTAINMENT: printType = "ENTERTAINMENT"; break;

				case FOOD: printType = "FOOD"; break;

				case NIGHTLIFE: printType = "NIGHTLIFE"; break;

				case NONE: printType = "NONE"; break;

				case OFFICE: printType = "OFFICE"; break;

				case OUTDOORS: printType = "OUTDOORS"; break;

				case RECREATION: printType = "RECREATION"; break;

				case RESIDENCE: printType = "RESIDENCE"; break;

				case SHOP: printType = "SHOP"; break;

				case TRANSPORT: printType = "TRANSPORT"; break;

		}

        ostringstream con1,con2;

        con1<<getlatitude();

        con2<<getlongitude();


		string str=a+"poi"+c+"\n\t"+a+"name"+c+getname()+a+b+"name"+c+"\n\t"+a+"discription"+c+m_poidiscription+a+b+"discription"+c+"\n\t"+a+"type"+c+m_type+a+b+m_type+c+"\n\t"+a+"typestring"+c+printType+a+b+"typetring"+c+"\n\t"+a+"latitude"+c+con1.str()+a+b+"latitude"+c+"\n\t"+a+"longitude"+c+con2.str()+a+b+"longitude"+c+"\n\t"+a+b+"poi"+c;


		cxmlstring str1(str);

		return(str1);

}

int cpoi::getid()
{
	++m_count;
	return(m_count);
}




