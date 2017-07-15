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
	std::cout<<"〓〓〓〓〓〓〓〓〓〓  ☆   大 学 生 成 绩 管 理 系  统  ☆  〓〓〓〓〓〓〓〓〓〓"<<std::endl;  
	std::cout<<"〓〓〓〓〓〓〓★★★★★         ★★★★★★★         ★★★★★〓〓〓〓〓〓〓"<<std::endl;  
	std::cout<<"〓〓〓〓〓〓〓〓〓★  ☆          1.增加学生成绩        ☆  ★〓〓〓〓〓〓〓〓〓"<<std::endl;  
	std::cout<<"〓〓〓〓〓〓〓〓〓★  ☆          2.查找学生成绩        ☆  ★〓〓〓〓〓〓〓〓〓"<<std::endl;  
	std::cout<<"〓〓〓〓〓〓〓〓〓★  ☆          3.显示学生成绩        ☆  ★〓〓〓〓〓〓〓〓〓"<<std::endl;  
	std::cout<<"〓〓〓〓〓〓〓〓〓★  ☆          4.修改学生成绩        ☆  ★〓〓〓〓〓〓〓〓〓"<<std::endl;  
	std::cout<<"〓〓〓〓〓〓〓〓〓★  ☆          5.删除学生成绩        ☆  ★〓〓〓〓〓〓〓〓〓"<<std::endl;  		
	std::cout<<"〓〓〓〓〓〓〓〓〓★  ☆          6.学生成绩排序        ☆  ★〓〓〓〓〓〓〓〓〓"<<std::endl;  
	std::cout<<"〓〓〓〓〓〓〓〓〓★  ☆          0.  返回首页          ☆  ★〓〓〓〓〓〓〓〓〓"<<std::endl;  

	std::cout<<"\n\t\t\n\t\t请选择：";  

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
			std::cout << "输入有误，请重新输入" << std::endl; 
			break;
		}
	}
}

void collegeStudents::add()
{
	std::cout << "学号：";
	std::cin >> collegeStudents::id;
	std::cout << "姓名：";
	std::cin >> collegeStudents::name;
	std::cout << "年龄：";
	std::cin >> collegeStudents::age;
	std::cout << "性别：";
	std::cin >> collegeStudents::gender;
	std::cout << "班级：";
	std::cin >> collegeStudents::grade;
	std::cout << "专业成绩：";
	std::cin >> collegeStudents::major;
	std::cout << "英语成绩：";
	std::cin >> collegeStudents::english;
	std::cout << "程序设计成绩：";
	std::cin >> collegeStudents::program;
	std::cout << "高数成绩：";
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
	std::cout << "输入需要查找的学生学号或姓名：";
	std::string f;
	std::cin >> f;
	MySQLInterface mysqlInterface;
	mysqlInterface.connectMySQL("localhost", "root", "zyzzz", "student", 3306);

	std::vector<std::vector<std::string> > data;
	std::string sql = "select * from college where id = '"+f+"' or name = '"+f+"';";
	mysqlInterface.getDatafromDB(sql, data);
	std::cout << "|学号|\t\t" << "|姓名|\t\t" << "|年龄|\t\t" << "|性别|\t\t" << "|班级|\t\t" << "|专业|\t\t" << "|英语|\t\t" << "|程序设计|\t\t" << "|高数|\t\t" << "|总分|" << std::endl;
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
	std::cout << "|学号|\t\t" << "|姓名|\t\t" << "|年龄|\t\t" << "|性别|\t\t" << "|班级|\t\t" << "|专业|\t\t" << "|英语|\t\t" << "|程序设计|\t\t" << "|高数|\t\t" << "|总分|" << std::endl;
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
	std::cout << "需要修改的学生学号：";
	std::cin >> collegeStudents::id;
	std::cout << "姓名：";
	std::cin >> collegeStudents::name;
	std::cout << "年龄：";
	std::cin >> collegeStudents::age;
	std::cout << "性别：";
	std::cin >> collegeStudents::gender;
	std::cout << "班级：";
	std::cin >> collegeStudents::grade;
	std::cout << "专业成绩：";
	std::cin >> collegeStudents::major;
	std::cout << "英语成绩：";
	std::cin >> collegeStudents::english;
	std::cout << "程序设计成绩：";
	std::cin >> collegeStudents::program;
	std::cout << "高数成绩：";
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
	std::cout << "需要删除的学生学号：";
	std::cin >> collegeStudents::id;
	std::cout << "需要删除的学生姓名：";
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
	std::cout << "输入需要排序的项目（请输入对应英文项目）：" << std::endl;
	std::cout << "学号：id\t姓名：name\t年龄：age\t性别：gender\t班级：grade\t专业：major\t英语：english\t程序设计：program\t数学：math\t总分：sum" << std::endl;
	std::cin >> item;

	MySQLInterface mysqlInterface;
	mysqlInterface.connectMySQL("localhost", "root", "zyzzz", "student", 3306);

	std::vector<std::vector<std::string> > data;

	std::string sql = "select * from college order by `"+item+"` desc;";
	mysqlInterface.getDatafromDB(sql, data);
	std::cout << "|学号|\t\t" << "|姓名|\t\t" << "|年龄|\t\t" << "|性别|\t\t" << "|班级|\t\t" << "|专业|\t\t" << "|英语|\t\t" << "|程序设计|\t\t" << "|高数|\t\t" << "|总分|" << std::endl;
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
