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
/*
	std::string id = "150105";
	std::string name = "����";
	std::string age = "13";
	std::string gender = "��";
	std::string grade = "һ1��";
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