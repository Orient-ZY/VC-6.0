// f2s.h: interface for the f2s class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_F2S_H__C9F0B41D_62F5_4329_9BA2_FD638993A122__INCLUDED_)
#define AFX_F2S_H__C9F0B41D_62F5_4329_9BA2_FD638993A122__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <iostream>
#include <string>

class f2s  
{
public:
	f2s();
	virtual ~f2s();


	// float转为string类型函数
	// -----------------------
	static std::string toString(float val)
	{
		char buf[200];
		sprintf(buf, "%3.1f", val);
		return std::string(buf);
	}

};

#endif // !defined(AFX_F2S_H__C9F0B41D_62F5_4329_9BA2_FD638993A122__INCLUDED_)
