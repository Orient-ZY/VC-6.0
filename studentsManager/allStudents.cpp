// allStudents.cpp: implementation of the allStudents class.
//
//////////////////////////////////////////////////////////////////////

#include "allStudents.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

allStudents::allStudents()
{

}

allStudents::~allStudents()
{

}

void allStudents::showMenu()
{
	int i = 0;
	char x;

	// 首页
	// ----
	system("cls");
	std::cout << "\t\t§§§§§§§§§§§§§§§§§§§§§§§§§§" << std::endl;  
	for(i=0;i<3;i++)  
		std::cout << "\t\t◎\t\t\t\t\t\t  ◎"<<std::endl;  
	std::cout << "\t\t◎★★★★【  欢迎进入学生成绩管理系统  】★★★★◎" << std::endl;  
	for(i=0;i<3;i++)  
		std::cout << "\t\t◎\t\t\t\t\t\t  ◎" << std::endl;  
	std::cout << "\t\t§§§§§§§§§§§§§§§§§§§§§§§§§§\n" << std::endl;
	std::cout<<"按任意键开始……";  	
	getch();

	// 主菜单 
	// ------
	system("cls");
	std::cout << "********************************************************************************" << std::endl;  
	std::cout << "〓〓〓〓〓〓〓〓〓〓  ☆   学 生 成 绩 管 理 系  统     ☆  〓〓〓〓〓〓〓〓〓〓" << std::endl;  
	std::cout << "〓〓〓〓〓〓〓★★★★★         ★★★★★★★         ★★★★★〓〓〓〓〓〓〓" << std::endl;  
	std::cout << "〓〓〓〓〓〓〓〓〓★  ☆          1.小学生成绩          ☆  ★〓〓〓〓〓〓〓〓〓" << std::endl;  
	std::cout << "〓〓〓〓〓〓〓〓〓★  ☆          2.中学生成绩          ☆  ★〓〓〓〓〓〓〓〓〓" << std::endl;  
	std::cout << "〓〓〓〓〓〓〓〓〓★  ☆          3.大学生成绩          ☆  ★〓〓〓〓〓〓〓〓〓" << std::endl;  
	std::cout << "〓〓〓〓〓〓〓〓〓★  ☆          0.安全退出系统        ☆  ★〓〓〓〓〓〓〓〓〓" << std::endl;  

	std::cout << "\n\t\t\n\t\t请选择："; 
	
	std::cin >> x;
	switch(x)
	{
	case '0':
		exit(0);
	break;

	case '1':
		allStudents::showJuniorMenu(); 
	break;

	case '2':
		allStudents::showSecondaryMenu(); 
	break;

	case '3':
		allStudents::showCollegeMenu(); 
	break;

	default: 
		std::cout << "输入有误，请重新输入" << std::endl;
	break;
	
	}
}

// 显示小学管理系统
// ----------------
void allStudents::showJuniorMenu()
{
	juniorStudents junior;
	junior.showMenu();
}

// 显示中学管理系统
// ----------------
void allStudents::showSecondaryMenu()
{
	secondaryStudents secondary;
	secondary.showMenu();
}

// 显示大学管理系统
// ----------------
void allStudents::showCollegeMenu()
{
	collegeStudents college;
	college.showMenu();
}
