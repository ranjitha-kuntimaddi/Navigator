/*
 * cwaypoint.h
 *
 *  Created on: 13-Dec-2012
 *      Author: varun
 */

#ifndef CWAYPOINT_H_
#define CWAYPOINT_H_

using namespace std;
#include "cxmlstring.h"

class cwaypoint
{
string m_name;
double m_longitude,m_latitude;

public:
cwaypoint(string name,double latitude,double longitude);
void set(string name,double longitude,double latitude);
void print(int format);
string getname();
double getlongitude();
double getlatitude();
void getalldatabypointer(string *pname,double *plongitude,double *platitude);
void getalldatabyreference(string pname,double &plongitude,double &platitude);
double calculatedistance(const cwaypoint &wp1);
cwaypoint add(cwaypoint const &wp_right);
bool less(cwaypoint const &wp_right);
void transformlongitude2degmmss(int &deg,int &mm,double &ss);
void transformlatitude2degmmss(int &deg,int &mm,double &ss);

//cxmlstring toxml();

};





#endif /* CWAYPOINT_H_ */
