#include "tutorial.h"

#include <QtSql/QSqlDatabase> 
#include <QtGui/QApplication>
#include <QtGui/QMessageBox>
#include <QtSql/QSqlError>
using namespace std;



int main(int argc, char *argv[])
{
	MYSQL *conn;
	QApplication a(argc, argv);

	Tutorial w;
	w.show();
	return a.exec();
}
