// allEmployees.h: interface for the allEmployees class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ALLEMPLOYEES_H__8B41911E_36D8_4E3C_B563_968EC44DB8D9__INCLUDED_)
#define AFX_ALLEMPLOYEES_H__8B41911E_36D8_4E3C_B563_968EC44DB8D9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
// 一些类调用后导致名字过长，超过了255个字符解决办法：#pragma warning (disable: 4514 4786)
#pragma warning (disable: 4514 4786)
#endif // _MSC_VER > 1000

#include <iostream>
#include <string>
#include <vector>
#include <conio.h>
#include "MySQLInterface.h"

class allEmployees  
{
public:
	void sort();
	void modify();
	void show();
	void find();
	void showMenu();
	void add();
	allEmployees();
	virtual ~allEmployees();

private:
	std::string id;
	std::string name;
	std::string gender;
	std::string department;
	std::string level;
	std::string wage;
	std::string payleave;
	std::string sickleave;

};

#endif // !defined(AFX_ALLEMPLOYEES_H__8B41911E_36D8_4E3C_B563_968EC44DB8D9__INCLUDED_)
