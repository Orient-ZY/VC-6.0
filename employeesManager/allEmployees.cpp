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

	// 主菜单 
	// ------
	std::cout << "**********************************************************************************" << std::endl;  
	std::cout << "〓〓〓〓〓〓〓〓〓〓  ☆    员 工 考 勤 管 理 系  统      ☆  〓〓〓〓〓〓〓〓〓〓" << std::endl;  
	std::cout << "〓〓〓〓〓〓〓★★★★★          ★★★★★★★          ★★★★★〓〓〓〓〓〓〓" << std::endl;  
	std::cout << "〓〓〓〓〓〓〓〓〓★  ☆          1.添加考勤记录          ☆  ★〓〓〓〓〓〓〓〓〓" << std::endl;  
	std::cout << "〓〓〓〓〓〓〓〓〓★  ☆          2.查询考勤记录          ☆  ★〓〓〓〓〓〓〓〓〓" << std::endl;  
	std::cout << "〓〓〓〓〓〓〓〓〓★  ☆          3.显示所有考勤          ☆  ★〓〓〓〓〓〓〓〓〓" << std::endl; 
	std::cout << "〓〓〓〓〓〓〓〓〓★  ☆          4.修改考勤记录          ☆  ★〓〓〓〓〓〓〓〓〓" << std::endl;  
	std::cout << "〓〓〓〓〓〓〓〓〓★  ☆          5.员工信息排序          ☆  ★〓〓〓〓〓〓〓〓〓" << std::endl;  
	std::cout << "〓〓〓〓〓〓〓〓〓★  ☆          0.安全退出系统          ☆  ★〓〓〓〓〓〓〓〓〓" << std::endl;  


	std::cout << "\n\t\t\n\t\t请选择："; 

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
			std::cout << "输入有误，请重新输入" << std::endl;
			allEmployees::showMenu();
			break;
		}

	}
}


void allEmployees::add()
{
	std::cout << "工号：";
	std::cin >> allEmployees::id;
	std::cout << "姓名：";
	std::cin >> allEmployees::name;
	std::cout << "性别：";
	std::cin >> allEmployees::gender;
	std::cout << "部门：";
	std::cin >> allEmployees::department;
	std::cout << "级别：";
	std::cin >> allEmployees::level;
	std::cout << "工资：";
	std::cin >> allEmployees::wage;
	std::cout << "带薪假：";
	std::cin >> allEmployees::payleave;
	std::cout << "病假：";
	std::cin >> allEmployees::sickleave;

	// 数据库类的实例化
	MySQLInterface mysql;
	// 数据库的连接
	mysql.connectMySQL("localhost", "root", "zyzzz", "employee", 3306);
	// 数据库sql语句
	std::string sql = "insert into attendance (id, name, gender, department, level, wage, payleave, sickleave) values ('"+allEmployees::id+"', '"+allEmployees::name+"', '"+allEmployees::gender+"', '"+allEmployees::department+"', '"+allEmployees::level+"', '"+allEmployees::wage+"', '"+allEmployees::payleave+"', '"+allEmployees::sickleave+"');";
	// 执行sql语句
	mysql.writeDataToDB(sql);
	// 关闭数据库连接
	mysql.closeMySQL();
}

void allEmployees::find()
{
	std::cout << "输入需要查询的员工工号或姓名：";
	std::string f;
	std::cin >> f;

	MySQLInterface mysql;

	mysql.connectMySQL("localhost", "root", "zyzzz", "employee", 3306);

	std::vector<std::vector<std::string> > data;
	// sql语句改变
	std::string sql = "select * from attendance where id = '"+f+"' or name = '"+f+"';";

	mysql.getDatafromDB(sql, data);

	std::cout << "|工号|\t\t" << "|姓名|\t\t" << "|性别|\t\t" << "|部门|\t\t" << "|级别|\t\t" << "|工资|\t\t" << "|带薪假|\t" << "|病假|\t\t" << std::endl;

	// 打印所有查询到的数据
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

	std::cout << "|工号|\t\t" << "|姓名|\t\t" << "|性别|\t\t" << "|部门|\t\t" << "|级别|\t\t" << "|工资|\t\t" << "|带薪假|\t" << "|病假|\t\t" << std::endl;
	
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

	std::cout << "需要更改的工号：";
	std::cin >> allEmployees::id;
	std::cout << "姓名：";
	std::cin >> allEmployees::name;
	std::cout << "性别：";
	std::cin >> allEmployees::gender;
	std::cout << "部门：";
	std::cin >> allEmployees::department;
	std::cout << "级别：";
	std::cin >> allEmployees::level;
	std::cout << "工资：";
	std::cin >> allEmployees::wage;
	std::cout << "带薪假：";
	std::cin >> allEmployees::payleave;
	std::cout << "病假：";
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
	std::cout << "输入需要排序的项目（请输入对应英文项目）：" << std::endl;
	std::cout << "工号：id\t姓名：name\t性别：gender\t部门：department\t级别：level\t工资：wage\t带薪假：payleave\t病假：sickleave" << std::endl;
	std::cin >> item;

	MySQLInterface mysql;
	mysql.connectMySQL("localhost", "root", "zyzzz", "employee", 3306);

	std::vector<std::vector<std::string> > data;

	std::string sql = "select * from attendance order by `"+item+"` desc;";

	mysql.getDatafromDB(sql, data);

	std::cout << "|工号|\t\t" << "|姓名|\t\t" << "|性别|\t\t" << "|部门|\t\t" << "|级别|\t\t" << "|工资|\t\t" << "|带薪假|\t" << "|病假|\t\t" << std::endl;
	
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
