/*
 * cxmlstring.cpp
 *
 *  Created on: 13-Dec-2012
 *      Author: varun
 */

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <string>
#include <iomanip>
#include <locale>
#include <sstream>
#include "cxmlstring.h"
using namespace std;

ostringstream convert;

char a='<',b='>',c='/';
int con_err,ta_err;

cxmlstring::cxmlstring(string content,string tag)
{

	str=a+tag+b+content+a+c+tag+b;
	cout<<endl<<str;

}

cxmlstring::cxmlstring(float content,string tag)
{
    convert<<content;
	str=a+tag+b+convert.str()+a+c+tag+b;
	cout<<endl<<str;

}

cxmlstring::cxmlstring(double content,string tag)
{
	convert<<content;
	str=a+tag+b+convert.str()+a+c+tag+b;
	cout<<endl<<str;
}


cxmlstring::cxmlstring(int content,string tag)
{
	convert<<content;
	str=a+tag+b+convert.str()+a+c+tag+b;
	cout<<endl<<str;
}

cxmlstring::cxmlstring(string content)
{

	str=content;
	cout<<endl<<str;
}

 string cxmlstring::error(xmlparseresult_t err)
 {
	string error;
    if(err==1)
	{
    	error="xmlfullline";
	}
    if(err==2)
    {
       	error="xmlopentag";
   	}

    if(err==3)
    {
       	error="xmlclosetag";
   	}
    if(err==4)
    {
       	error="xmlsyntaxerror";
   	}
    if(err==5)
    {
       	error="xmlmax";
   	}
    if(err==6)
    {
       	error="xmlerrortagmismatch";
   	}
    return(error);
 }

xmlparseresult_t cxmlstring::parse(string& tag,string& content)
{

	string co,ta;
	xmlparseresult_t err;


	int i,j,error=0,len=str.length(),x=0;

	char ch[30];

	for(i=0,j=len-1;i<len;++i,--j)
	{
		ch[i]=str[j];

	}

	for(i=0;i<len;++i)
	{
		if(ch[i]=='>'&&i==0)
		{
			++i;


			while(ch[i]!='/'&&ch[i]!='<')
			{

				ta=ta+ch[i];
				++i;
				x=i;
			}

			if(ch[i]=='<'&&i==len-1)
			{
				error=3;

			}

			if(ch[i]=='/'&&ch[i+1]!='<')
			{
				error=2;
			}

			if(ch[i]=='/' && ch[i+1]=='<'&& i==len-2)
			{
				error=4;
			}

			if(ch[i]=='/'&&ch[i+1]=='<'&&i!=len-2)
			{
				error=1;
			}
		}
	}

			for(i=x+2;ch[i]!='>'&&error==1;++i)
			{
		      co=co+ch[i];
			}
			co=co+'\0';
            //cout<<"\n content test="<<co;


	/*len=ta.length();

		for(i=0,j=len-1;i<len;++i,--j)
		{
			ch[i]=ta[j];

		}
		if(error!=2)
		{
		 tag=ch;
		}

		else
		{
			tag="PARSEERROR";
		}


		len=co.length();

		for(i=0,j=len-1;i<len;++i,--j)
		{
			ch[i]=co[j];

		}*/

		if(error==1)
		{
			err=xmlfullline;
			m_error="xmlfullline";
			content=ch;
			len=ta.length();
			for(j=len-1;j>=0;--j)
			{
				tag=tag+ta[j];

			}
			len=co.length();
			content='\0';
			for(j=len-1;j>=0;--j)
			{
				content=content+co[j];
			}
		}


	if(error==2)
	{
		err=xmlerrorsyntax;
		m_error="xmlerrorsyntax";
		tag="parseerror\0";
		content=tag;
	}

	if(error==3)
	{
		err=xmlopentag;
		m_error="test\0";
		content="nocontent\0";
		len=ta.length();
		for(j=len-1;j>=0;--j)
		{
			tag=tag+ta[j];

		}

	}
	if(error==4)
	{
	  err=xmlclosetag;
	  m_error="test\0";
	  content="nocontent\0";
	  len=ta.length();
	  for(j=len-1;j>=0;--j)
	  {
		  tag=tag+ta[j];

    	}
	}

	return(err);

}



bool cxmlstring::extracttag(string& tag,string& reminder)
{
	char ch[30],ch1[30];
    string co,t;

	int len=str.length();

	int i,j;
    for(i=0;i<len;++i)
    {
    	ch[i]=str[i];
    }

	for(i=len-1;i>=0;--i)
	{
		if(ch[i]=='>')
		{

			--i;
			while(ch[i]!='<'&&ch[i]!='/')
			{
				t=t+ch[i];
			    --i;
			}

			if(ch[i]!='<')
			{
			 //++ta_err;
			 --i;
			}

		}
		while(ch[i]!='>'&& i>=0)
		{
		  co=co+ch[i];
		  --i;
		  //++con_err;
		}

	}

	len=t.length();

	for(i=0,j=len-1;i<len;++i,--j)
	{
		ch1[i]=t[j];

	}
	tag=ch1;

	len=co.length();

	for(i=0,j=len-1;i<len;++i,--j)
	{
		ch1[i]=co[j];

	}
	reminder=ch1+'<'+'/'+tag+'>';


  return(1);
}


void cxmlstring::trim(string& t)
{
	int i,len=t.length();
	string changed;

	for(i=0;i<len;++i)
	{
	   if(t[i]=='/')
	   {
		   ++i;
		   while(t[i]!=' ')
		   {
			   changed=changed+t[i];
			   ++i;
		   }
	   }


	  }
    t=changed;
	/*len=changed.length();
	for(i=0;i<len;++i)
	{
	   t[i]=&changed[i];
    }*/


}

bool cxmlstring::contains(const string& sub)
{
	bool a=0;
	int i,j,len,flag=0;
	len=str.length();
	for(i=0,j=0;i<len;++i)
	{
		while(sub[j]==str[i] && i<len && flag==0)
		{
			++i;
			++j;

		}
		++flag;

	  }
	len=sub.length();
	if(j==len)
	{
		a=1;
	}

	return(a);
}

string cxmlstring::getstring()
{
	return(str);
}



