/*
 * croute.h
 *
 *  Created on: 13-Dec-2012
 *      Author: varun
 */

#ifndef CROUTE_H_
#define CROUTE_H_
#include <iostream>
#include <vector>
#include "cwaypoint.h"
#include "cpoidatabase.h"
#include "cpoi.h"

using namespace std;

class cwaypoint;

class croute
{
	std::vector<cwaypoint> m_pwaypoint;

	int m_poi;

	cpoidatabase* m_poidatabase;

public:

	croute(unsigned int maxwp,unsigned int maxpoi);

	croute(croute const& origin);

	~croute();

	void connecttopoidatabase(cpoidatabase* ppoidb);

	void addwaypoint(cwaypoint const &wp);

	void addpoi(string namepoi);

	double getdistancenextpoi(cwaypoint const &wp,cpoi &poi);

	void print();

	void printtofile(string name);

	void readfromfile(string filename,bool deleteolddata);


};



#endif /* CROUTE_H_ */
