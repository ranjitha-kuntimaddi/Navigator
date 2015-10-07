/*
 * cfileio.cpp
 *
 *  Created on: 14-Dec-2012
 *      Author: varun
 */


#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <string.h>
#include <sstream>
#include <cstring>
#include "cpoi.h"
#include<fstream>
using namespace std;

#include "cfileio.h"
#include "croute.h"


bool cfileio::openfile(string filename,t_direction dir)
{

	switch (dir)

	{

	case IN :
		m_file.open(filename.c_str(),fstream::in);
		m_file.seekg(0);
        break;

	case OUT:
		m_file.open(filename.c_str(),fstream::out);
	    m_file.seekp(0);
      	break;


	default: break;

	}

	m_dir = dir;

	return true;
}

bool cfileio::closefile()
{

	if (m_file.is_open()==0)
	{
		m_file.close();
	}

	return true;
}


bool cfileio::writedata(croute p)
{

	cpoidatabase* poidatabase;
	poidatabase=p.m_poidatabase;
	vector<cwaypoint> pwaypoint;
	pwaypoint=p.m_poidatabase;

	if (m_file.is_open())
	{

	std::vector<cwaypoint>::iterator it;
	for (it=pwaypoint.begin(); it<pwaypoint.end(); it++)
	{
		m_file<<*it;
		m_file<<"\n";

	}

		return true;
	}

	else
	{
		return false;
	}

}

bool cfileio::readdata(croute& p)
{
	cpoidatabase* poidatabase;
	poidatabase=p.m_poidatabase;
	vector<cwaypoint> pwaypoint;
	pwaypoint=p.m_poidatabase;



	if ((m_file.is_open()) && (m_file.eof()!=0))
	{
		m_file>>p;
/*
 *
 */
		return true;
	}

	else
	{
		return false;
	}
}

