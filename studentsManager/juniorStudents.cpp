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
	std::cout<<"〓〓〓〓〓〓〓〓〓〓  ☆   小 学 生 成 绩 管 理 系  统  ☆  〓〓〓〓〓〓〓〓〓〓"<<std::endl;  
	std::cout<<"〓〓〓〓〓〓〓★★★★★         ★★★★★★★         ★★★★★〓〓〓〓〓〓〓"<<std::endl;  
	std::cout<<"〓〓〓〓〓〓〓〓〓★  ☆          1.增加学生成绩        ☆  ★〓〓〓〓〓〓〓〓〓"<<std::endl;  
	std::cout<<"〓〓〓〓〓〓〓〓〓★  ☆          2.查找学生成绩        ☆  ★〓〓〓〓〓〓〓〓〓"<<std::endl;  
	std::cout<<"〓〓〓〓〓〓〓〓〓★  ☆          3.显示学生成绩        ☆  ★〓〓〓〓〓〓〓〓〓"<<std::endl;  
	std::cout<<"〓〓〓〓〓〓〓〓〓★  ☆          4.修改学生成绩        ☆  ★〓〓〓〓〓〓〓〓〓"<<std::endl;  
	std::cout<<"〓〓〓〓〓〓〓〓〓★  ☆          5.删除学生成绩        ☆  ★〓〓〓〓〓〓〓〓〓"<<std::endl;  		
	std::cout<<"〓〓〓〓〓〓〓〓〓★  ☆          6.学生成绩排序        ☆  ★〓〓〓〓〓〓〓〓〓"<<std::endl;  
	std::cout<<"〓〓〓〓〓〓〓〓〓★  ☆          0.  返回首页          ☆  ★〓〓〓〓〓〓〓〓〓"<<std::endl;  

	std::cout<<"\n\t\t\n\t\t请选择：";  

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
			std::cout << "输入有误，请重新输入" << std::endl; 
			break;
		}
	}
}

void juniorStudents::add()
{
	std::cout << "学号：";
	std::cin >> juniorStudents::id;
	std::cout << "姓名：";
	std::cin >> juniorStudents::name;
	std::cout << "年龄：";
	std::cin >> juniorStudents::age;
	std::cout << "性别：";
	std::cin >> juniorStudents::gender;
	std::cout << "班级：";
	std::cin >> juniorStudents::grade;
	std::cout << "语文成绩：";
	std::cin >> juniorStudents::chinese;
	std::cout << "数学成绩：";
	std::cin >> juniorStudents::math;
	std::cout << "英语成绩：";
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
	std::cout << "输入需要查找的学生学号或姓名：";
	std::string f;
	std::cin >> f;
	MySQLInterface mysqlInterface;
	mysqlInterface.connectMySQL("localhost", "root", "zyzzz", "student", 3306);

	std::vector<std::vector<std::string> > data;
	std::string sql = "select * from junior where id = '"+f+"' or name = '"+f+"';";
	mysqlInterface.getDatafromDB(sql, data);
	std::cout << "|学号|\t\t" << "|姓名|\t\t" << "|年龄|\t\t" << "|性别|\t\t" << "|班级|\t\t" << "|语文|\t\t" << "|数学|\t\t" << "|英语|\t\t" << "|总分|" << std::endl;
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
	std::cout << "|学号|\t\t" << "|姓名|\t\t" << "|年龄|\t\t" << "|性别|\t\t" << "|班级|\t\t" << "|语文|\t\t" << "|数学|\t\t" << "|英语|\t\t" << "|总分|" << std::endl;
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
	std::cout << "需要修改的学生学号：";
	std::cin >> juniorStudents::id;
	std::cout << "姓名：";
	std::cin >> juniorStudents::name;
	std::cout << "年龄：";
	std::cin >> juniorStudents::age;
	std::cout << "性别：";
	std::cin >> juniorStudents::gender;
	std::cout << "班级：";
	std::cin >> juniorStudents::grade;
	std::cout << "语文成绩：";
	std::cin >> juniorStudents::chinese;
	std::cout << "数学成绩：";
	std::cin >> juniorStudents::math;
	std::cout << "英语成绩：";
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
	std::cout << "需要删除的学生学号：";
	std::cin >> juniorStudents::id;
	std::cout << "需要删除的学生姓名：";
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
	std::cout << "输入需要排序的项目（请输入对应英文项目）：" << std::endl;
	std::cout << "学号：id\t姓名：name\t年龄：age\t性别：gender\t班级：grade\t语文：chinese\t数学：math\t英语：english\t总分：sum" << std::endl;
	std::cin >> item;

	MySQLInterface mysqlInterface;
	mysqlInterface.connectMySQL("localhost", "root", "zyzzz", "student", 3306);

	std::vector<std::vector<std::string> > data;

	std::string sql = "select * from junior order by `"+item+"` desc;";
	mysqlInterface.getDatafromDB(sql, data);
	std::cout << "|学号|\t\t" << "|姓名|\t\t" << "|年龄|\t\t" << "|性别|\t\t" << "|班级|\t\t" << "|语文|\t\t" << "|数学|\t\t" << "|英语|\t\t" << "|总分|" << std::endl;
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
