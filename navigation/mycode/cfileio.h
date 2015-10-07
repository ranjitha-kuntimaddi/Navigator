/*
 * cfileio.h
 *
 *  Created on: 14-Dec-2012
 *      Author: varun
 */

#ifndef CFILEIO_H_
#define CFILEIO_H_

#include "fstream"
#include "croute.h"

enum t_direction {IN,OUT};

class cfileio
{
	t_direction m_dir;

	fstream m_file;

public:

	cfileio();

	bool closefile();

	bool openfile(string filename,t_direction dir);

	bool readdata(croute& s);

	bool writedata(croute p);



};


#endif /* CFILEIO_H_ */
