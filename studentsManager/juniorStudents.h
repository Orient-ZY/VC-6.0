// juniorStudents.h: interface for the juniorStudents class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_JUNIORSTUDENTS_H__54467FBF_0A64_4E4E_9F81_F163F828CC9B__INCLUDED_)
#define AFX_JUNIORSTUDENTS_H__54467FBF_0A64_4E4E_9F81_F163F828CC9B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#pragma warning (disable: 4514 4786)
#endif // _MSC_VER > 1000

#include <iostream>
#include <string>
#include "allStudents.h"
#include "MySQLInterface.h"
#include "f2s.h"
#include <vector>

class juniorStudents  
{
public:
	void sort();
	void remove();
	void modify();
	void show();
	void find();
	void add();
	void showMenu();
	std::string id;
	std::string name;
	std::string gender;
	std::string age;
	std::string grade;
	float chinese;
	float math;
	float english;
	float sum;

	juniorStudents();
	virtual ~juniorStudents();

};

#endif // !defined(AFX_JUNIORSTUDENTS_H__54467FBF_0A64_4E4E_9F81_F163F828CC9B__INCLUDED_)
