#include <iostream>
#include <string>
#include "allStudents.h"
#include "MySQLInterface.h"
#include "f2s.h"

int main()
{
	/* 数据库的操作
	
	MySQLInterface mysqlInterface;
	mysqlInterface.connectMySQL("localhost", "root", "zyzzz", "student", 3306);
	// 写入数据
	// --------
	//std::string sql = "insert into junior (id, name, age, gender, chinese, math, english) values ('150101', '测试', '10', '男', '90', '91', '85');";
	//mysqlInterface.writeDataToDB(sql);
	// 查询数据
	// --------
	//std::vector<std::vector<std::string> > data;
	//std::string sql = "select * from junior;";
	//mysqlInterface.getDatafromDB(sql, data);
	//std::cout << data[0][0] << std::endl;
	// 关闭数据库
	// ----------
	mysqlInterface.closeMySQL();

	*/
/*
	std::string id = "150105";
	std::string name = "王启";
	std::string age = "13";
	std::string gender = "男";
	std::string grade = "一1班";
	float tchinese = 82;
	float tmath = 71;
	float tenglish = 90;
	float tsum = tchinese + tmath + tenglish;
	std::string chinese = f2s::toString(tchinese);
	std::string math = f2s::toString(tmath);
	std::string english = f2s::toString(tenglish);
	std::string sum = f2s::toString(tsum);


	MySQLInterface mysqlInterface;
	mysqlInterface.connectMySQL("localhost", "root", "zyzzz", "student", 3306);
	std::string sql = "insert into junior (id, name, age, gender, grade, chinese, math, english) values ('"+id+"', '"+name+"', '"+age+"', '"+gender+"', '"+grade+"', '"+chinese+"', '"+math+"', '"+english+"');";

	mysqlInterface.writeDataToDB(sql);

	mysqlInterface.closeMySQL();

	exit(0);
*/

	allStudents all;
	all.showMenu();

	return 0;
}