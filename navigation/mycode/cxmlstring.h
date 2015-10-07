/*
 * cxmlstring.h
 *
 *  Created on: 13-Dec-2012
 *      Author: varun
 */

#ifndef CXMLSTRING_H_
#define CXMLSTRING_H_

using namespace std;
#include "cwaypoint.h"

enum xmlparseresult_t {xmlfullline=1,xmlopentag=2,xmlclosetag=3,xmlsyntaxerror=4,xmlmax=5,xmlerrorsyntax=6};

class cxmlstring
{
	string str;

	string m_error;//[]={"xmlfullline","xmlopentag","xmlclosetag","xmlerrorsyntax","xmlerrortagmismatch"};

public:

	cxmlstring(string content,string tag);

	cxmlstring(float content,string tag);

	cxmlstring(double content,string tag);

	cxmlstring(int content,string tag);

	cxmlstring(string content);

	string error(xmlparseresult_t err);

	xmlparseresult_t parse(string& tag,string& content);

	bool extracttag(string& tag,string& reminder);

	void trim(string& t);

	bool contains(const string& sub);

	string getstring();


};





#endif /* CXMLSTRING_H_ */
