// collegeStudents.h: interface for the collegeStudents class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_COLLEGESTUDENTS_H__30DB299E_B8D1_4F55_90A0_D0F9302B76F6__INCLUDED_)
#define AFX_COLLEGESTUDENTS_H__30DB299E_B8D1_4F55_90A0_D0F9302B76F6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#pragma warning (disable: 4514 4786)
#endif // _MSC_VER > 1000

#include <iostream>
#include <string>
#include "allStudents.h"
#include "MySQLInterface.h"
#include <vector>

class collegeStudents  
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
	float major;
	float english;
	float program;
	float math;
	float sum;


	collegeStudents();
	virtual ~collegeStudents();

};

#endif // !defined(AFX_COLLEGESTUDENTS_H__30DB299E_B8D1_4F55_90A0_D0F9302B76F6__INCLUDED_)
