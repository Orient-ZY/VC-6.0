#include <iostream>
#include <string>
#include "allStudents.h"
#include "MySQLInterface.h"
#include "f2s.h"

int main()
{
	/* ���ݿ�Ĳ���
	
	MySQLInterface mysqlInterface;
	mysqlInterface.connectMySQL("localhost", "root", "zyzzz", "student", 3306);
	// д������
	// --------
	//std::string sql = "insert into junior (id, name, age, gender, chinese, math, english) values ('150101', '����', '10', '��', '90', '91', '85');";
	//mysqlInterface.writeDataToDB(sql);
	// ��ѯ����
	// --------
	//std::vector<std::vector<std::string> > data;
	//std::string sql = "select * from junior;";
	//mysqlInterface.getDatafromDB(sql, data);
	//std::cout << data[0][0] << std::endl;
	// �ر����ݿ�
	// ----------
	mysqlInterface.closeMySQL();

	*/


	// ��ڳ���
	allStudents all;
	all.showMenu();

	return 0;
}