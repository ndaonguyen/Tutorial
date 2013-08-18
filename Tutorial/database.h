#ifndef DATABASE_H
#define DATABASE_H

#include <QtSql/QSqlDatabase> 
#include <QtGui/QMessageBox>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>
#include <QtSql/qsqldriver.h>
#include <QtSql/QSqlDriverPlugin>

#include <windows.h>
#include <stdio.h>
#include <iostream>
#include <C:\wamp32\bin\mysql\mysql5.5.16\include\mysql.h>

using namespace std;




class database
{
public:
	static bool createConnection()
	{
		QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
		db.setHostName("127.0.0.1");
		db.setDatabaseName("qt_tracking");
		db.setUserName("root");
		db.setPassword("");
		if (!db.open()) {
		    QMessageBox::critical(0, QObject::tr("Database Error"),db.lastError().text());
			return false;
		}
		return true;
	}

	static MYSQL* connectByC()
	{
		/*
		MYSQL *connection,mysql;
		mysql_init(&mysql);
		connection = mysql_real_connect(&mysql,"127.0.0.1","root","","qt_tracking",0,NULL,0);
		
		if(connection==NULL)
			return connection;
		else
			return NULL;
		*/

		MYSQL *con = mysql_init(NULL);
		if(mysql_real_connect(con, "127.0.0.1","root","","qt_tracking",0,NULL,0)== NULL)
		{
			mysql_error(con);
			return NULL;
		}
		else
		{
			return con;
		}		
	}

	static void closeConnectionC(MYSQL *connect)
	{
		mysql_close(connect);
	}
};

/*
	QSqlQuery query;

	query.exec("create table artists (id int primary key, "
								  "artist varchar(40), "
								  "albumcount int)");

	query.exec("insert into artists values(0, '<all>', 0)");
	query.exec("insert into artists values(1, 'Ane Brun', 2)");
	query.exec("insert into artists values(2, 'Thomas Dybdahl', 3)");
	query.exec("insert into artists values(3, 'Kaizers Orchestra', 3)");

	query.exec("create table albums (albumid int primary key, "
								  "title varchar(50), "
								  "artistid int, "
								  "year int)");

	query.exec("insert into albums values(1, 'Spending Time With Morgan', 1, "
					"2003)");
	query.exec("insert into albums values(2, 'A Temporary Dive', 1, 2005)");
	query.exec("insert into albums values(3, '...The Great October Sound', 2, "
					"2002)");
	query.exec("insert into albums values(4, 'Stray Dogs', 2, 2003)");
	query.exec("insert into albums values(5, "
	 "'One day you`ll dance for me, New York City', 2, 2004)");
	query.exec("insert into albums values(6, 'Ompa Til Du D\xf8r', 3, 2001)");
	query.exec("insert into albums values(7, 'Evig Pint', 3, 2002)");
	query.exec("insert into albums values(8, 'Maestro', 3, 2005)");
*/

#endif