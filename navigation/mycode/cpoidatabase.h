/*
 * cpoidatabase.h
 *
 *  Created on: 13-Dec-2012
 *      Author: varun
 */

#ifndef CPOIDATABASE_H_
#define CPOIDATABASE_H_
using namespace std;
#include "cpoi.h"
#include <map>

//enum t_poi {COLLEGE, ENTERTAINMENT, FOOD, NIGHTLIFE, NONE, OFFICE, OUTDOORS, RECREATION, RESIDENCE, SHOP, TRANSPORT};


class cpoidatabase
{
	map<int,cpoi> m_poi;

public:

	cpoidatabase();

	void addpoi(t_poi type,string name,string discription,double latitude,double longitude);

	int getpointertopoi(string name);

	cpoi getelement(int i);

	void print();


};


#endif /* CPOIDATABASE_H_ */
