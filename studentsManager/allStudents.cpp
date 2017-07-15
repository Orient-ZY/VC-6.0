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

	// ��ҳ
	// ----
	system("cls");
	std::cout << "\t\t���������������������������" << std::endl;  
	for(i=0;i<3;i++)  
		std::cout << "\t\t��\t\t\t\t\t\t  ��"<<std::endl;  
	std::cout << "\t\t�����  ��ӭ����ѧ���ɼ�����ϵͳ  ��������" << std::endl;  
	for(i=0;i<3;i++)  
		std::cout << "\t\t��\t\t\t\t\t\t  ��" << std::endl;  
	std::cout << "\t\t���������������������������\n" << std::endl;
	std::cout<<"���������ʼ����";  	
	getch();

	// ���˵� 
	// ------
	system("cls");
	std::cout << "********************************************************************************" << std::endl;  
	std::cout << "��������������������  ��   ѧ �� �� �� �� �� ϵ  ͳ     ��  ��������������������" << std::endl;  
	std::cout << "��������������������         ��������         �������������������" << std::endl;  
	std::cout << "��������������������  ��          1.Сѧ���ɼ�          ��  �������������������" << std::endl;  
	std::cout << "��������������������  ��          2.��ѧ���ɼ�          ��  �������������������" << std::endl;  
	std::cout << "��������������������  ��          3.��ѧ���ɼ�          ��  �������������������" << std::endl;  
	std::cout << "��������������������  ��          0.��ȫ�˳�ϵͳ        ��  �������������������" << std::endl;  

	std::cout << "\n\t\t\n\t\t��ѡ��"; 
	
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
		std::cout << "������������������" << std::endl;
	break;
	
	}
}

// ��ʾСѧ����ϵͳ
// ----------------
void allStudents::showJuniorMenu()
{
	juniorStudents junior;
	junior.showMenu();
}

// ��ʾ��ѧ����ϵͳ
// ----------------
void allStudents::showSecondaryMenu()
{
	secondaryStudents secondary;
	secondary.showMenu();
}

// ��ʾ��ѧ����ϵͳ
// ----------------
void allStudents::showCollegeMenu()
{
	collegeStudents college;
	college.showMenu();
}
