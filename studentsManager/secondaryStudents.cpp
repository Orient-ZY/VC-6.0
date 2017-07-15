// secondaryStudents.cpp: implementation of the secondaryStudents class.
//
//////////////////////////////////////////////////////////////////////

#include "secondaryStudents.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

secondaryStudents::secondaryStudents()
{

}

secondaryStudents::~secondaryStudents()
{

}

void secondaryStudents::showMenu()
{

	std::cout<<"********************************************************************************"<<std::endl;  
	std::cout<<"��������������������  ��   �� ѧ �� �� �� �� �� ϵ  ͳ  ��  ��������������������"<<std::endl;  
	std::cout<<"��������������������         ��������         �������������������"<<std::endl;  
	std::cout<<"��������������������  ��          1.����ѧ���ɼ�        ��  �������������������"<<std::endl;  
	std::cout<<"��������������������  ��          2.����ѧ���ɼ�        ��  �������������������"<<std::endl;  
	std::cout<<"��������������������  ��          3.��ʾѧ���ɼ�        ��  �������������������"<<std::endl;  
	std::cout<<"��������������������  ��          4.�޸�ѧ���ɼ�        ��  �������������������"<<std::endl;  
	std::cout<<"��������������������  ��          5.ɾ��ѧ���ɼ�        ��  �������������������"<<std::endl;  		
	std::cout<<"��������������������  ��          6.ѧ���ɼ�����        ��  �������������������"<<std::endl;  
	std::cout<<"��������������������  ��          0.  ������ҳ          ��  �������������������"<<std::endl;  

	std::cout<<"\n\t\t\n\t\t��ѡ��";  

	char s;
	std::cin >> s;
	switch(s)
	{
	case '1':
		{
			secondaryStudents::add(); 
			secondaryStudents::showMenu(); 
			break;
		}
	case '2':
		{
			secondaryStudents::find(); 
			secondaryStudents::showMenu(); 
			break;
		}
	case '3':
		{
			secondaryStudents::show(); 
			secondaryStudents::showMenu(); 
			break;
		}
	case '4':
		{
			secondaryStudents::modify(); 
			secondaryStudents::showMenu(); 
			break;
		}
	case '5':
		{
			secondaryStudents::remove(); 
			secondaryStudents::showMenu(); 
			break;
		}
	case '6':
		{
			secondaryStudents::sort(); 
			secondaryStudents::showMenu(); 
			break;
		}
	case '0':
		{
			allStudents all; 
			all.showMenu(); 
			break;
		}
	default: 
		{
			std::cout << "������������������" << std::endl; 
			break;
		}
	}
}

void secondaryStudents::add()
{
	std::cout << "ѧ�ţ�";
	std::cin >> secondaryStudents::id;
	std::cout << "������";
	std::cin >> secondaryStudents::name;
	std::cout << "���䣺";
	std::cin >> secondaryStudents::age;
	std::cout << "�Ա�";
	std::cin >> secondaryStudents::gender;
	std::cout << "�༶��";
	std::cin >> secondaryStudents::grade;
	std::cout << "���ĳɼ���";
	std::cin >> secondaryStudents::chinese;
	std::cout << "��ѧ�ɼ���";
	std::cin >> secondaryStudents::math;
	std::cout << "Ӣ��ɼ���";
	std::cin >> secondaryStudents::english;
	std::cout << "����ɼ���";
	std::cin >> secondaryStudents::geography;
	std::cout << "��ʷ�ɼ���";
	std::cin >> secondaryStudents::history;
	
	secondaryStudents::sum = secondaryStudents::chinese + secondaryStudents::math + secondaryStudents::english + secondaryStudents::geography + secondaryStudents::history;
	string chinese = f2s::toString(secondaryStudents::chinese);
	string math = f2s::toString(secondaryStudents::math);
	string english = f2s::toString(secondaryStudents::english);
	string geography = f2s::toString(secondaryStudents::geography);
	string history = f2s::toString(secondaryStudents::history);
	string sum = f2s::toString(secondaryStudents::sum);


	MySQLInterface mysqlInterface;
	mysqlInterface.connectMySQL("localhost", "root", "zyzzz", "student", 3306);
	std::string sql = "insert into secondary (id, name, age, gender, grade, chinese, math, english, geography, history, sum) values ('"+secondaryStudents::id+"', '"+secondaryStudents::name+"', '"+secondaryStudents::age+"', '"+secondaryStudents::gender+"', '"+secondaryStudents::grade+"', '"+chinese+"', '"+math+"', '"+english+"', '"+geography+"', '"+history+"', '"+sum+"');";

	mysqlInterface.writeDataToDB(sql);

	mysqlInterface.closeMySQL();
}

void secondaryStudents::find()
{
	std::cout << "������Ҫ���ҵ�ѧ��ѧ�Ż�������";
	std::string f;
	std::cin >> f;
	MySQLInterface mysqlInterface;
	mysqlInterface.connectMySQL("localhost", "root", "zyzzz", "student", 3306);

	std::vector<std::vector<std::string> > data;
	std::string sql = "select * from secondary where id = '"+f+"' or name = '"+f+"';";
	mysqlInterface.getDatafromDB(sql, data);
	std::cout << "|ѧ��|\t\t" << "|����|\t\t" << "|����|\t\t" << "|�Ա�|\t\t" << "|�༶|\t\t" << "|����|\t\t" << "|��ѧ|\t\t" << "|Ӣ��|\t\t"<< "|����|\t\t"<< "|��ʷ|\t\t" << "|�ܷ�|" << std::endl;
	for(int n=0; n<data.size(); n++)
	{
		for(int m=0; m<data[0].size(); m++ ) 
		{
			std::cout << data[n][m] << "\t\t";
		}
		std::cout << std::endl;
	}

	mysqlInterface.closeMySQL();
}

void secondaryStudents::show()
{
	MySQLInterface mysqlInterface;
	mysqlInterface.connectMySQL("localhost", "root", "zyzzz", "student", 3306);

	std::vector<std::vector<std::string> > data;
	std::string sql = "select * from secondary;";
	mysqlInterface.getDatafromDB(sql, data);
	std::cout << "|ѧ��|\t\t" << "|����|\t\t" << "|����|\t\t" << "|�Ա�|\t\t" << "|�༶|\t\t" << "|����|\t\t" << "|��ѧ|\t\t" << "|Ӣ��|\t\t"<< "|����|\t\t"<< "|��ʷ|\t\t" << "|�ܷ�|" << std::endl;
	for(int n=0; n<data.size(); n++)
	{
		for(int m=0; m<data[0].size(); m++ ) 
		{
			std::cout << data[n][m] << "\t\t";
		}
		std::cout << std::endl;
	}

	mysqlInterface.closeMySQL();
}

void secondaryStudents::modify()
{
	std::cout << "��Ҫ�޸ĵ�ѧ��ѧ�ţ�";
	std::cin >> secondaryStudents::id;
	std::cout << "������";
	std::cin >> secondaryStudents::name;
	std::cout << "���䣺";
	std::cin >> secondaryStudents::age;
	std::cout << "�Ա�";
	std::cin >> secondaryStudents::gender;
	std::cout << "�༶��";
	std::cin >> secondaryStudents::grade;
	std::cout << "���ĳɼ���";
	std::cin >> secondaryStudents::chinese;
	std::cout << "��ѧ�ɼ���";
	std::cin >> secondaryStudents::math;
	std::cout << "Ӣ��ɼ���";
	std::cin >> secondaryStudents::english;
	std::cout << "����ɼ���";
	std::cin >> secondaryStudents::geography;
	std::cout << "��ʷ�ɼ���";
	std::cin >> secondaryStudents::history;

	secondaryStudents::sum = secondaryStudents::chinese + secondaryStudents::math + secondaryStudents::english + secondaryStudents::geography + secondaryStudents::history;
	string chinese = f2s::toString(secondaryStudents::chinese);
	string math = f2s::toString(secondaryStudents::math);
	string english = f2s::toString(secondaryStudents::english);
	string geography = f2s::toString(secondaryStudents::geography);
	string history = f2s::toString(secondaryStudents::history);
	string sum = f2s::toString(secondaryStudents::sum);


	MySQLInterface mysqlInterface;
	mysqlInterface.connectMySQL("localhost", "root", "zyzzz", "student", 3306);

	std::string sql = "update secondary set name = '"+secondaryStudents::name+"', age='"+secondaryStudents::age+"', gender='"+secondaryStudents::gender+"', grade='"+secondaryStudents::grade+"', chinese='"+chinese+"', math='"+math+"', english='"+english+"', geography='"+geography+"', history='"+history+"', sum='"+sum+"' where id='"+secondaryStudents::id+"';";

	mysqlInterface.writeDataToDB(sql);

	mysqlInterface.closeMySQL();
}

void secondaryStudents::remove()
{
	std::cout << "��Ҫɾ����ѧ��ѧ�ţ�";
	std::cin >> secondaryStudents::id;
	std::cout << "��Ҫɾ����ѧ��������";
	std::cin >> secondaryStudents::name;

	MySQLInterface mysqlInterface;
	mysqlInterface.connectMySQL("localhost", "root", "zyzzz", "student", 3306);

	std::string sql = "delete from secondary where id = '"+secondaryStudents::id+"' and name = '"+secondaryStudents::name+"';";

	mysqlInterface.writeDataToDB(sql);

	mysqlInterface.closeMySQL();
}

void secondaryStudents::sort()
{
	std::string item;
	std::cout << "������Ҫ�������Ŀ���������ӦӢ����Ŀ����" << std::endl;
	std::cout << "ѧ�ţ�id\t������name\t���䣺age\t�Ա�gender\t�༶��grade\t���ģ�chinese\t��ѧ��math\tӢ�english\t����geography\t��ʷ��history\t�ܷ֣�sum" << std::endl;
	std::cin >> item;

	MySQLInterface mysqlInterface;
	mysqlInterface.connectMySQL("localhost", "root", "zyzzz", "student", 3306);

	std::vector<std::vector<std::string> > data;

	std::string sql = "select * from secondary order by `"+item+"` desc;";
	mysqlInterface.getDatafromDB(sql, data);
	std::cout << "|ѧ��|\t\t" << "|����|\t\t" << "|����|\t\t" << "|�Ա�|\t\t" << "|�༶|\t\t" << "|����|\t\t" << "|��ѧ|\t\t" << "|Ӣ��|\t\t"<< "|����|\t\t"<< "|��ʷ|\t\t" << "|�ܷ�|" << std::endl;
	for(int n=0; n<data.size(); n++)
	{
		for(int m=0; m<data[0].size(); m++ ) 
		{
			std::cout << data[n][m] << "\t\t";
		}
		std::cout << std::endl;
	}

	mysqlInterface.closeMySQL();
}
