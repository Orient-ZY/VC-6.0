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
	std::cout<<"〓〓〓〓〓〓〓〓〓〓  ☆   中 学 生 成 绩 管 理 系  统  ☆  〓〓〓〓〓〓〓〓〓〓"<<std::endl;  
	std::cout<<"〓〓〓〓〓〓〓★★★★★         ★★★★★★★         ★★★★★〓〓〓〓〓〓〓"<<std::endl;  
	std::cout<<"〓〓〓〓〓〓〓〓〓★  ☆          1.增加学生成绩        ☆  ★〓〓〓〓〓〓〓〓〓"<<std::endl;  
	std::cout<<"〓〓〓〓〓〓〓〓〓★  ☆          2.查找学生成绩        ☆  ★〓〓〓〓〓〓〓〓〓"<<std::endl;  
	std::cout<<"〓〓〓〓〓〓〓〓〓★  ☆          3.显示学生成绩        ☆  ★〓〓〓〓〓〓〓〓〓"<<std::endl;  
	std::cout<<"〓〓〓〓〓〓〓〓〓★  ☆          4.修改学生成绩        ☆  ★〓〓〓〓〓〓〓〓〓"<<std::endl;  
	std::cout<<"〓〓〓〓〓〓〓〓〓★  ☆          5.删除学生成绩        ☆  ★〓〓〓〓〓〓〓〓〓"<<std::endl;  		
	std::cout<<"〓〓〓〓〓〓〓〓〓★  ☆          6.学生成绩排序        ☆  ★〓〓〓〓〓〓〓〓〓"<<std::endl;  
	std::cout<<"〓〓〓〓〓〓〓〓〓★  ☆          0.  返回首页          ☆  ★〓〓〓〓〓〓〓〓〓"<<std::endl;  

	std::cout<<"\n\t\t\n\t\t请选择：";  

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
			std::cout << "输入有误，请重新输入" << std::endl; 
			break;
		}
	}
}

void secondaryStudents::add()
{
	std::cout << "学号：";
	std::cin >> secondaryStudents::id;
	std::cout << "姓名：";
	std::cin >> secondaryStudents::name;
	std::cout << "年龄：";
	std::cin >> secondaryStudents::age;
	std::cout << "性别：";
	std::cin >> secondaryStudents::gender;
	std::cout << "班级：";
	std::cin >> secondaryStudents::grade;
	std::cout << "语文成绩：";
	std::cin >> secondaryStudents::chinese;
	std::cout << "数学成绩：";
	std::cin >> secondaryStudents::math;
	std::cout << "英语成绩：";
	std::cin >> secondaryStudents::english;
	std::cout << "地理成绩：";
	std::cin >> secondaryStudents::geography;
	std::cout << "历史成绩：";
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
	std::cout << "输入需要查找的学生学号或姓名：";
	std::string f;
	std::cin >> f;
	MySQLInterface mysqlInterface;
	mysqlInterface.connectMySQL("localhost", "root", "zyzzz", "student", 3306);

	std::vector<std::vector<std::string> > data;
	std::string sql = "select * from secondary where id = '"+f+"' or name = '"+f+"';";
	mysqlInterface.getDatafromDB(sql, data);
	std::cout << "|学号|\t\t" << "|姓名|\t\t" << "|年龄|\t\t" << "|性别|\t\t" << "|班级|\t\t" << "|语文|\t\t" << "|数学|\t\t" << "|英语|\t\t"<< "|地理|\t\t"<< "|历史|\t\t" << "|总分|" << std::endl;
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
	std::cout << "|学号|\t\t" << "|姓名|\t\t" << "|年龄|\t\t" << "|性别|\t\t" << "|班级|\t\t" << "|语文|\t\t" << "|数学|\t\t" << "|英语|\t\t"<< "|地理|\t\t"<< "|历史|\t\t" << "|总分|" << std::endl;
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
	std::cout << "需要修改的学生学号：";
	std::cin >> secondaryStudents::id;
	std::cout << "姓名：";
	std::cin >> secondaryStudents::name;
	std::cout << "年龄：";
	std::cin >> secondaryStudents::age;
	std::cout << "性别：";
	std::cin >> secondaryStudents::gender;
	std::cout << "班级：";
	std::cin >> secondaryStudents::grade;
	std::cout << "语文成绩：";
	std::cin >> secondaryStudents::chinese;
	std::cout << "数学成绩：";
	std::cin >> secondaryStudents::math;
	std::cout << "英语成绩：";
	std::cin >> secondaryStudents::english;
	std::cout << "地理成绩：";
	std::cin >> secondaryStudents::geography;
	std::cout << "历史成绩：";
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
	std::cout << "需要删除的学生学号：";
	std::cin >> secondaryStudents::id;
	std::cout << "需要删除的学生姓名：";
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
	std::cout << "输入需要排序的项目（请输入对应英文项目）：" << std::endl;
	std::cout << "学号：id\t姓名：name\t年龄：age\t性别：gender\t班级：grade\t语文：chinese\t数学：math\t英语：english\t地理：geography\t历史：history\t总分：sum" << std::endl;
	std::cin >> item;

	MySQLInterface mysqlInterface;
	mysqlInterface.connectMySQL("localhost", "root", "zyzzz", "student", 3306);

	std::vector<std::vector<std::string> > data;

	std::string sql = "select * from secondary order by `"+item+"` desc;";
	mysqlInterface.getDatafromDB(sql, data);
	std::cout << "|学号|\t\t" << "|姓名|\t\t" << "|年龄|\t\t" << "|性别|\t\t" << "|班级|\t\t" << "|语文|\t\t" << "|数学|\t\t" << "|英语|\t\t"<< "|地理|\t\t"<< "|历史|\t\t" << "|总分|" << std::endl;
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
