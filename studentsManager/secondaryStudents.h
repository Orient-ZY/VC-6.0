// secondaryStudents.h: interface for the secondaryStudents class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SECONDARYSTUDENTS_H__1B868E26_AF69_4DCC_BF7E_E8137EA14832__INCLUDED_)
#define AFX_SECONDARYSTUDENTS_H__1B868E26_AF69_4DCC_BF7E_E8137EA14832__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#pragma warning (disable: 4514 4786)
#endif // _MSC_VER > 1000

#include <iostream>
#include <string>
#include "allStudents.h"
#include "MySQLInterface.h"
#include <vector>

class secondaryStudents  
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
	float geography;
	float history;
	float sum;

	secondaryStudents();
	virtual ~secondaryStudents();

};

#endif // !defined(AFX_SECONDARYSTUDENTS_H__1B868E26_AF69_4DCC_BF7E_E8137EA14832__INCLUDED_)
