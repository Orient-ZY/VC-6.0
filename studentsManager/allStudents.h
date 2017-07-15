// allStudents.h: interface for the allStudents class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ALLSTUDENTS_H__70A3384C_4D82_436F_8166_FC447BB3CF72__INCLUDED_)
#define AFX_ALLSTUDENTS_H__70A3384C_4D82_436F_8166_FC447BB3CF72__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <iostream>
#include <string>
#include <vector>
#include <conio.h>
#include "juniorStudents.h"
#include "secondaryStudents.h"
#include "collegeStudents.h"

class allStudents
{
public:
	void showSecondaryMenu();
	void showJuniorMenu();
	void showMenu();
	void showCollegeMenu();

	allStudents();
	virtual ~allStudents();

};

#endif // !defined(AFX_ALLSTUDENTS_H__70A3384C_4D82_436F_8166_FC447BB3CF72__INCLUDED_)
