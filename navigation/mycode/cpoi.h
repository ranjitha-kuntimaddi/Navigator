/*
 * cpoi.h
 *
 *  Created on: 13-Dec-2012
 *      Author: varun
 */

#ifndef CPOI_H_
#define CPOI_H_

using namespace std;

#include "cxmlstring.h"
#include "cwaypoint.h"

enum t_poi {COLLEGE=1, ENTERTAINMENT, FOOD, NIGHTLIFE, NONE, OFFICE, OUTDOORS, RECREATION, RESIDENCE, SHOP, TRANSPORT};


class cpoi: public cwaypoint
{

	string m_poidiscription;//={"restaurent","gasstation","sightseeing"};

	t_poi m_type;

	string m_discription;

	int m_count;

public:

	cpoi (t_poi type,string name,string discription,double latitude,double longitude);

	void print();

	cxmlstring toxml();

	int getid();


};


#endif /* CPOI_H_ */
