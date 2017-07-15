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


	// 入口程序
	allStudents all;
	all.showMenu();

	return 0;
}