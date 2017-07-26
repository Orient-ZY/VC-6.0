// allEmployees.cpp: implementation of the allEmployees class.
//
//////////////////////////////////////////////////////////////////////

#include "allEmployees.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

allEmployees::allEmployees()
{

}

allEmployees::~allEmployees()
{

}

void allEmployees::showMenu()
{

	char x;

	// ���˵� 
	// ------
	std::cout << "**********************************************************************************" << std::endl;  
	std::cout << "��������������������  ��    Ա �� �� �� �� �� ϵ  ͳ      ��  ��������������������" << std::endl;  
	std::cout << "��������������������          ��������          �������������������" << std::endl;  
	std::cout << "��������������������  ��          1.��ӿ��ڼ�¼          ��  �������������������" << std::endl;  
	std::cout << "��������������������  ��          2.��ѯ���ڼ�¼          ��  �������������������" << std::endl;  
	std::cout << "��������������������  ��          3.��ʾ���п���          ��  �������������������" << std::endl; 
	std::cout << "��������������������  ��          4.�޸Ŀ��ڼ�¼          ��  �������������������" << std::endl;  
	std::cout << "��������������������  ��          5.Ա����Ϣ����          ��  �������������������" << std::endl;  
	std::cout << "��������������������  ��          0.��ȫ�˳�ϵͳ          ��  �������������������" << std::endl;  


	std::cout << "\n\t\t\n\t\t��ѡ��"; 

	std::cin >> x;
	switch(x)
	{
	case '0':
		exit(0);
	break;

	case '1':
		{
			allEmployees::add(); 
			allEmployees::showMenu();
			break;
		}

	case '2':
		{
			allEmployees::find();
			allEmployees::showMenu();
			break;
		}

	case '3':
		{
			allEmployees::show();
			allEmployees::showMenu();
			break;
		}

	case '4':
		{
			allEmployees::modify(); 
			allEmployees::showMenu();
			break;
		}

	case '5':
		{
			allEmployees::sort(); 
			allEmployees::showMenu();
			break;
		}

	default: 
		{
			std::cout << "������������������" << std::endl;
			allEmployees::showMenu();
			break;
		}

	}
}


void allEmployees::add()
{
	std::cout << "���ţ�";
	std::cin >> allEmployees::id;
	std::cout << "������";
	std::cin >> allEmployees::name;
	std::cout << "�Ա�";
	std::cin >> allEmployees::gender;
	std::cout << "���ţ�";
	std::cin >> allEmployees::department;
	std::cout << "����";
	std::cin >> allEmployees::level;
	std::cout << "���ʣ�";
	std::cin >> allEmployees::wage;
	std::cout << "��н�٣�";
	std::cin >> allEmployees::payleave;
	std::cout << "���٣�";
	std::cin >> allEmployees::sickleave;

	// ���ݿ����ʵ����
	MySQLInterface mysql;
	// ���ݿ������
	mysql.connectMySQL("localhost", "root", "zyzzz", "employee", 3306);
	// ���ݿ�sql���
	std::string sql = "insert into attendance (id, name, gender, department, level, wage, payleave, sickleave) values ('"+allEmployees::id+"', '"+allEmployees::name+"', '"+allEmployees::gender+"', '"+allEmployees::department+"', '"+allEmployees::level+"', '"+allEmployees::wage+"', '"+allEmployees::payleave+"', '"+allEmployees::sickleave+"');";
	// ִ��sql���
	mysql.writeDataToDB(sql);
	// �ر����ݿ�����
	mysql.closeMySQL();
}

void allEmployees::find()
{
	std::cout << "������Ҫ��ѯ��Ա�����Ż�������";
	std::string f;
	std::cin >> f;

	MySQLInterface mysql;

	mysql.connectMySQL("localhost", "root", "zyzzz", "employee", 3306);

	std::vector<std::vector<std::string> > data;
	// sql���ı�
	std::string sql = "select * from attendance where id = '"+f+"' or name = '"+f+"';";

	mysql.getDatafromDB(sql, data);

	std::cout << "|����|\t\t" << "|����|\t\t" << "|�Ա�|\t\t" << "|����|\t\t" << "|����|\t\t" << "|����|\t\t" << "|��н��|\t" << "|����|\t\t" << std::endl;

	// ��ӡ���в�ѯ��������
	for(int n=0; n<data.size(); n++)
	{
		for(int m=0; m<data[0].size(); m++ ) 
		{
			std::cout << data[n][m] << "\t\t";
		}
		std::cout << std::endl;
	}

	mysql.closeMySQL();


}

void allEmployees::show()
{
	MySQLInterface mysql;

	mysql.connectMySQL("localhost", "root", "zyzzz", "employee", 3306);
	
	std::vector<std::vector<std::string> > data;

	std::string sql = "select * from attendance";

	mysql.getDatafromDB(sql, data);

	std::cout << "|����|\t\t" << "|����|\t\t" << "|�Ա�|\t\t" << "|����|\t\t" << "|����|\t\t" << "|����|\t\t" << "|��н��|\t" << "|����|\t\t" << std::endl;
	
	for(int n=0; n<data.size(); n++)
	{
		for(int m=0; m<data[0].size(); m++ ) 
		{
			std::cout << data[n][m] << "\t\t";
		}
		std::cout << std::endl;
	}

	mysql.closeMySQL();

}

void allEmployees::modify()
{

	std::cout << "��Ҫ���ĵĹ��ţ�";
	std::cin >> allEmployees::id;
	std::cout << "������";
	std::cin >> allEmployees::name;
	std::cout << "�Ա�";
	std::cin >> allEmployees::gender;
	std::cout << "���ţ�";
	std::cin >> allEmployees::department;
	std::cout << "����";
	std::cin >> allEmployees::level;
	std::cout << "���ʣ�";
	std::cin >> allEmployees::wage;
	std::cout << "��н�٣�";
	std::cin >> allEmployees::payleave;
	std::cout << "���٣�";
	std::cin >> allEmployees::sickleave;

	MySQLInterface mysql;
	mysql.connectMySQL("localhost", "root", "zyzzz", "employee", 3306);

	std::string sql = "update attendance set name = '"+allEmployees::name+"', gender='"+allEmployees::gender+"', department='"+allEmployees::department+"', level='"+allEmployees::level+"', wage='"+allEmployees::wage+"', payleave='"+allEmployees::payleave+"', sickleave='"+allEmployees::sickleave+"' where id='"+allEmployees::id+"';";

	mysql.writeDataToDB(sql);
	mysql.closeMySQL();
}


void allEmployees::sort()
{
	std::string item;
	std::cout << "������Ҫ�������Ŀ���������ӦӢ����Ŀ����" << std::endl;
	std::cout << "���ţ�id\t������name\t�Ա�gender\t���ţ�department\t����level\t���ʣ�wage\t��н�٣�payleave\t���٣�sickleave" << std::endl;
	std::cin >> item;

	MySQLInterface mysql;
	mysql.connectMySQL("localhost", "root", "zyzzz", "employee", 3306);

	std::vector<std::vector<std::string> > data;

	std::string sql = "select * from attendance order by `"+item+"` desc;";

	mysql.getDatafromDB(sql, data);

	std::cout << "|����|\t\t" << "|����|\t\t" << "|�Ա�|\t\t" << "|����|\t\t" << "|����|\t\t" << "|����|\t\t" << "|��н��|\t" << "|����|\t\t" << std::endl;
	
	for(int n=0; n<data.size(); n++)
	{
		for(int m=0; m<data[0].size(); m++ ) 
		{
			std::cout << data[n][m] << "\t\t";
		}
		std::cout << std::endl;
	}

	mysql.closeMySQL();


}
