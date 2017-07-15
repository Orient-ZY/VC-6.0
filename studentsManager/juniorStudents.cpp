// juniorStudents.cpp: implementation of the juniorStudents class.
//
//////////////////////////////////////////////////////////////////////

#include "juniorStudents.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

juniorStudents::juniorStudents()
{

}

juniorStudents::~juniorStudents()
{

}

void juniorStudents::showMenu()
{
//	system("cls");
	std::cout<<"********************************************************************************"<<std::endl;  
	std::cout<<"��������������������  ��   С ѧ �� �� �� �� �� ϵ  ͳ  ��  ��������������������"<<std::endl;  
	std::cout<<"��������������������         ��������         �������������������"<<std::endl;  
	std::cout<<"��������������������  ��          1.����ѧ���ɼ�        ��  �������������������"<<std::endl;  
	std::cout<<"��������������������  ��          2.����ѧ���ɼ�        ��  �������������������"<<std::endl;  
	std::cout<<"��������������������  ��          3.��ʾѧ���ɼ�        ��  �������������������"<<std::endl;  
	std::cout<<"��������������������  ��          4.�޸�ѧ���ɼ�        ��  �������������������"<<std::endl;  
	std::cout<<"��������������������  ��          5.ɾ��ѧ���ɼ�        ��  �������������������"<<std::endl;  		
	std::cout<<"��������������������  ��          6.ѧ���ɼ�����        ��  �������������������"<<std::endl;  
	std::cout<<"��������������������  ��          0.  ������ҳ          ��  �������������������"<<std::endl;  

	std::cout<<"\n\t\t\n\t\t��ѡ��";  

	char j;
	std::cin >> j;
	switch(j)
	{
	case '1':
		{
			juniorStudents::add(); 
			juniorStudents::showMenu(); 
			break;
		}
	case '2':
		{
			juniorStudents::find(); 
			juniorStudents::showMenu(); 
			break;
		}
	case '3':
		{
			juniorStudents::show(); 
			juniorStudents::showMenu(); 
			break;
		}
	case '4':
		{
			juniorStudents::modify(); 
			juniorStudents::showMenu(); 
			break;
		}
	case '5':
		{
			juniorStudents::remove(); 
			juniorStudents::showMenu(); 
			break;
		}
	case '6':
		{
			juniorStudents::sort(); 
			juniorStudents::showMenu(); 
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

void juniorStudents::add()
{
	std::cout << "ѧ�ţ�";
	std::cin >> juniorStudents::id;
	std::cout << "������";
	std::cin >> juniorStudents::name;
	std::cout << "���䣺";
	std::cin >> juniorStudents::age;
	std::cout << "�Ա�";
	std::cin >> juniorStudents::gender;
	std::cout << "�༶��";
	std::cin >> juniorStudents::grade;
	std::cout << "���ĳɼ���";
	std::cin >> juniorStudents::chinese;
	std::cout << "��ѧ�ɼ���";
	std::cin >> juniorStudents::math;
	std::cout << "Ӣ��ɼ���";
	std::cin >> juniorStudents::english;

	juniorStudents::sum = juniorStudents::chinese + juniorStudents::math + juniorStudents::english;
	string chinese = f2s::toString(juniorStudents::chinese);
	string math = f2s::toString(juniorStudents::math);
	string english = f2s::toString(juniorStudents::english);
	string sum = f2s::toString(juniorStudents::sum);


	MySQLInterface mysqlInterface;
	mysqlInterface.connectMySQL("localhost", "root", "zyzzz", "student", 3306);
	std::string sql = "insert into junior (id, name, age, gender, grade, chinese, math, english, sum) values ('"+juniorStudents::id+"', '"+juniorStudents::name+"', '"+juniorStudents::age+"', '"+juniorStudents::gender+"', '"+juniorStudents::grade+"', '"+chinese+"', '"+math+"', '"+english+"', '"+sum+"');";

	mysqlInterface.writeDataToDB(sql);

	mysqlInterface.closeMySQL();

}

void juniorStudents::find()
{
	std::cout << "������Ҫ���ҵ�ѧ��ѧ�Ż�������";
	std::string f;
	std::cin >> f;
	MySQLInterface mysqlInterface;
	mysqlInterface.connectMySQL("localhost", "root", "zyzzz", "student", 3306);

	std::vector<std::vector<std::string> > data;
	std::string sql = "select * from junior where id = '"+f+"' or name = '"+f+"';";
	mysqlInterface.getDatafromDB(sql, data);
	std::cout << "|ѧ��|\t\t" << "|����|\t\t" << "|����|\t\t" << "|�Ա�|\t\t" << "|�༶|\t\t" << "|����|\t\t" << "|��ѧ|\t\t" << "|Ӣ��|\t\t" << "|�ܷ�|" << std::endl;
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

void juniorStudents::show()
{
	MySQLInterface mysqlInterface;
	mysqlInterface.connectMySQL("localhost", "root", "zyzzz", "student", 3306);

	std::vector<std::vector<std::string> > data;
	std::string sql = "select * from junior;";
	mysqlInterface.getDatafromDB(sql, data);
	std::cout << "|ѧ��|\t\t" << "|����|\t\t" << "|����|\t\t" << "|�Ա�|\t\t" << "|�༶|\t\t" << "|����|\t\t" << "|��ѧ|\t\t" << "|Ӣ��|\t\t" << "|�ܷ�|" << std::endl;
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

void juniorStudents::modify()
{
	std::cout << "��Ҫ�޸ĵ�ѧ��ѧ�ţ�";
	std::cin >> juniorStudents::id;
	std::cout << "������";
	std::cin >> juniorStudents::name;
	std::cout << "���䣺";
	std::cin >> juniorStudents::age;
	std::cout << "�Ա�";
	std::cin >> juniorStudents::gender;
	std::cout << "�༶��";
	std::cin >> juniorStudents::grade;
	std::cout << "���ĳɼ���";
	std::cin >> juniorStudents::chinese;
	std::cout << "��ѧ�ɼ���";
	std::cin >> juniorStudents::math;
	std::cout << "Ӣ��ɼ���";
	std::cin >> juniorStudents::english;

	juniorStudents::sum = juniorStudents::chinese+juniorStudents::math+juniorStudents::english;
	string chinese = f2s::toString(juniorStudents::chinese);
	string math = f2s::toString(juniorStudents::math);
	string english = f2s::toString(juniorStudents::english);
	string sum = f2s::toString(juniorStudents::sum);


	MySQLInterface mysqlInterface;
	mysqlInterface.connectMySQL("localhost", "root", "zyzzz", "student", 3306);

	std::string sql = "update junior set name = '"+juniorStudents::name+"', age='"+juniorStudents::age+"', gender='"+juniorStudents::gender+"', grade='"+juniorStudents::grade+"', chinese='"+chinese+"', math='"+math+"', english='"+english+"', sum='"+sum+"' where id='"+juniorStudents::id+"';";

	mysqlInterface.writeDataToDB(sql);

	mysqlInterface.closeMySQL();

}

void juniorStudents::remove()
{
	std::cout << "��Ҫɾ����ѧ��ѧ�ţ�";
	std::cin >> juniorStudents::id;
	std::cout << "��Ҫɾ����ѧ��������";
	std::cin >> juniorStudents::name;

	MySQLInterface mysqlInterface;
	mysqlInterface.connectMySQL("localhost", "root", "zyzzz", "student", 3306);

	std::string sql = "delete from junior where id = '"+juniorStudents::id+"' and name = '"+juniorStudents::name+"';";

	mysqlInterface.writeDataToDB(sql);

	mysqlInterface.closeMySQL();
}

void juniorStudents::sort()
{
	std::string item;
	std::cout << "������Ҫ�������Ŀ���������ӦӢ����Ŀ����" << std::endl;
	std::cout << "ѧ�ţ�id\t������name\t���䣺age\t�Ա�gender\t�༶��grade\t���ģ�chinese\t��ѧ��math\tӢ�english\t�ܷ֣�sum" << std::endl;
	std::cin >> item;

	MySQLInterface mysqlInterface;
	mysqlInterface.connectMySQL("localhost", "root", "zyzzz", "student", 3306);

	std::vector<std::vector<std::string> > data;

	std::string sql = "select * from junior order by `"+item+"` desc;";
	mysqlInterface.getDatafromDB(sql, data);
	std::cout << "|ѧ��|\t\t" << "|����|\t\t" << "|����|\t\t" << "|�Ա�|\t\t" << "|�༶|\t\t" << "|����|\t\t" << "|��ѧ|\t\t" << "|Ӣ��|\t\t" << "|�ܷ�|" << std::endl;
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
