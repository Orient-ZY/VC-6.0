// collegeStudents.cpp: implementation of the collegeStudents class.
//
//////////////////////////////////////////////////////////////////////

#include "collegeStudents.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

collegeStudents::collegeStudents()
{

}

collegeStudents::~collegeStudents()
{

}

void collegeStudents::showMenu()
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

	char c;
	std::cin >> c;
	switch(c)
	{
	case '1':
		{
			collegeStudents::add(); 
			collegeStudents::showMenu(); 
			break;
		}
	case '2':
		{
			collegeStudents::find(); 
			collegeStudents::showMenu(); 
			break;
		}
	case '3':
		{
			collegeStudents::show(); 
			collegeStudents::showMenu(); 
			break;
		}
	case '4':
		{
			collegeStudents::modify(); 
			collegeStudents::showMenu(); 
			break;
		}
	case '5':
		{
			collegeStudents::remove(); 
			collegeStudents::showMenu(); 
			break;
		}
	case '6':
		{
			collegeStudents::sort(); 
			collegeStudents::showMenu(); 
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

void collegeStudents::add()
{
	std::cout << "ѧ�ţ�";
	std::cin >> collegeStudents::id;
	std::cout << "������";
	std::cin >> collegeStudents::name;
	std::cout << "���䣺";
	std::cin >> collegeStudents::age;
	std::cout << "�Ա�";
	std::cin >> collegeStudents::gender;
	std::cout << "�༶��";
	std::cin >> collegeStudents::grade;
	std::cout << "רҵ�ɼ���";
	std::cin >> collegeStudents::major;
	std::cout << "Ӣ��ɼ���";
	std::cin >> collegeStudents::english;
	std::cout << "������Ƴɼ���";
	std::cin >> collegeStudents::program;
	std::cout << "�����ɼ���";
	std::cin >> collegeStudents::math;

	collegeStudents::sum = collegeStudents::major + collegeStudents::english + collegeStudents::program + collegeStudents::math;
	string major = f2s::toString(collegeStudents::major);
	string math = f2s::toString(collegeStudents::math);
	string english = f2s::toString(collegeStudents::english);
	string program = f2s::toString(collegeStudents::program);
	string sum = f2s::toString(collegeStudents::sum);


	MySQLInterface mysqlInterface;
	mysqlInterface.connectMySQL("localhost", "root", "zyzzz", "student", 3306);
	std::string sql = "insert into college (id, name, age, gender, grade, major, english, program, math, sum) values ('"+collegeStudents::id+"', '"+collegeStudents::name+"', '"+collegeStudents::age+"', '"+collegeStudents::gender+"', '"+collegeStudents::grade+"', '"+major+"', '"+english+"', '"+program+"', '"+math+"', '"+sum+"');";

	mysqlInterface.writeDataToDB(sql);

	mysqlInterface.closeMySQL();
}

void collegeStudents::find()
{
	std::cout << "������Ҫ���ҵ�ѧ��ѧ�Ż�������";
	std::string f;
	std::cin >> f;
	MySQLInterface mysqlInterface;
	mysqlInterface.connectMySQL("localhost", "root", "zyzzz", "student", 3306);

	std::vector<std::vector<std::string> > data;
	std::string sql = "select * from college where id = '"+f+"' or name = '"+f+"';";
	mysqlInterface.getDatafromDB(sql, data);
	std::cout << "|ѧ��|\t\t" << "|����|\t\t" << "|����|\t\t" << "|�Ա�|\t\t" << "|�༶|\t\t" << "|רҵ|\t\t" << "|Ӣ��|\t\t" << "|�������|\t\t" << "|����|\t\t" << "|�ܷ�|" << std::endl;
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

void collegeStudents::show()
{
	MySQLInterface mysqlInterface;
	mysqlInterface.connectMySQL("localhost", "root", "zyzzz", "student", 3306);

	std::vector<std::vector<std::string> > data;
	std::string sql = "select * from college;";
	mysqlInterface.getDatafromDB(sql, data);
	std::cout << "|ѧ��|\t\t" << "|����|\t\t" << "|����|\t\t" << "|�Ա�|\t\t" << "|�༶|\t\t" << "|רҵ|\t\t" << "|Ӣ��|\t\t" << "|�������|\t\t" << "|����|\t\t" << "|�ܷ�|" << std::endl;
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

void collegeStudents::modify()
{
	std::cout << "��Ҫ�޸ĵ�ѧ��ѧ�ţ�";
	std::cin >> collegeStudents::id;
	std::cout << "������";
	std::cin >> collegeStudents::name;
	std::cout << "���䣺";
	std::cin >> collegeStudents::age;
	std::cout << "�Ա�";
	std::cin >> collegeStudents::gender;
	std::cout << "�༶��";
	std::cin >> collegeStudents::grade;
	std::cout << "רҵ�ɼ���";
	std::cin >> collegeStudents::major;
	std::cout << "Ӣ��ɼ���";
	std::cin >> collegeStudents::english;
	std::cout << "������Ƴɼ���";
	std::cin >> collegeStudents::program;
	std::cout << "�����ɼ���";
	std::cin >> collegeStudents::math;

	collegeStudents::sum = collegeStudents::major + collegeStudents::english + collegeStudents::program + collegeStudents::math;
	string major = f2s::toString(collegeStudents::major);
	string math = f2s::toString(collegeStudents::math);
	string english = f2s::toString(collegeStudents::english);
	string program = f2s::toString(collegeStudents::program);
	string sum = f2s::toString(collegeStudents::sum);


	MySQLInterface mysqlInterface;
	mysqlInterface.connectMySQL("localhost", "root", "zyzzz", "student", 3306);
	std::string sql = "update college set name = '"+collegeStudents::name+"', age='"+collegeStudents::age+"', gender='"+collegeStudents::gender+"', grade='"+collegeStudents::grade+"', major='"+major+"', english='"+english+"', program='"+program+"', math='"+math+"', sum='"+sum+"' where id='"+collegeStudents::id+"';";

	mysqlInterface.writeDataToDB(sql);

	mysqlInterface.closeMySQL();
}

void collegeStudents::remove()
{
	std::cout << "��Ҫɾ����ѧ��ѧ�ţ�";
	std::cin >> collegeStudents::id;
	std::cout << "��Ҫɾ����ѧ��������";
	std::cin >> collegeStudents::name;

	MySQLInterface mysqlInterface;
	mysqlInterface.connectMySQL("localhost", "root", "zyzzz", "student", 3306);

	std::string sql = "delete from college where id = '"+collegeStudents::id+"' and name = '"+collegeStudents::name+"';";

	mysqlInterface.writeDataToDB(sql);

	mysqlInterface.closeMySQL();
}

void collegeStudents::sort()
{
	std::string item;
	std::cout << "������Ҫ�������Ŀ���������ӦӢ����Ŀ����" << std::endl;
	std::cout << "ѧ�ţ�id\t������name\t���䣺age\t�Ա�gender\t�༶��grade\tרҵ��major\tӢ�english\t������ƣ�program\t��ѧ��math\t�ܷ֣�sum" << std::endl;
	std::cin >> item;

	MySQLInterface mysqlInterface;
	mysqlInterface.connectMySQL("localhost", "root", "zyzzz", "student", 3306);

	std::vector<std::vector<std::string> > data;

	std::string sql = "select * from college order by `"+item+"` desc;";
	mysqlInterface.getDatafromDB(sql, data);
	std::cout << "|ѧ��|\t\t" << "|����|\t\t" << "|����|\t\t" << "|�Ա�|\t\t" << "|�༶|\t\t" << "|רҵ|\t\t" << "|Ӣ��|\t\t" << "|�������|\t\t" << "|����|\t\t" << "|�ܷ�|" << std::endl;
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
