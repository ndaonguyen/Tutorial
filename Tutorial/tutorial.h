#ifndef TUTORIAL_H
#define TUTORIAL_H
#include <QtSql/QSqlDatabase> 
#include <QtGui/QMainWindow>
#include <QFileDialog>
#include <QByteArray>
#include <QImage>
#include <QPixmap>
#include "ui_tutorial.h"
#include <string>
#include "database.h"
using std::string;

class Tutorial : public QMainWindow
{
	Q_OBJECT

public:
	Tutorial(QWidget *parent = 0, Qt::WFlags flags = 0);
	~Tutorial();
	QString getRestFromDelimeter(QString pathName,char delimeter)
	{
		pathName = pathName.trimmed();
		int lastSplash = pathName.lastIndexOf(delimeter);
		QString name = pathName.mid(lastSplash+1,-1);
		return name;
	}
	int getScale(QPixmap realImg, QLabel* labelImg)
	{
		int imgHeight = realImg.height();
		int imgWidth  = realImg.width();

		int cellHeight = labelImg->height();
		int cellWidth  = labelImg->width();

		int scaleWidth  = (int)imgWidth/cellWidth;
		int scaleHeight = (int)imgHeight/cellHeight;
		
		return (scaleHeight<scaleWidth)?scaleWidth:scaleHeight;
	}
	void loadImage(char* pathImg,QLabel* mylabel)
	{
		QPixmap pix;
		bool loaded = pix.load(pathImg);
		QSize pixSize = pix.size();
		int scale = getScale(pix, ui.myLabel);
		int widthScale   = pix.width()/scale;
		int heightScalse = pix.height()/scale;
		pix = pix.scaled(widthScale,heightScalse,Qt::IgnoreAspectRatio, Qt::FastTransformation);	
		mylabel->setPixmap(pix);
	//	loadImage("dog.jpg",ui.myLabel);
	}

	
private:
	Ui::TutorialClass ui;
	QString strFileName;
	public slots:
		void fileAction()
		{
			QString fn = QFileDialog::getOpenFileName(this, tr("Open file..."),tr("C:\\"),tr("Image-files (*.jpg *.png *.gif)"));
		//	ui.nameLabel->setText(fn);
			strFileName = fn;

			std::string temp = fn.toStdString();
			char* strPath = (char*)temp.c_str();
			loadImage(strPath,ui.myLabel);
		}
		void cancelAction()
		{
			QApplication::quit();
		}

		bool saveAction()
		{
			MYSQL_RES *res_set;
			MYSQL_ROW row;

			QString strName    = ui.nameEdit->text();
			QString strBirthday = ui.birthdayEdit->date().toString(Qt::ISODate);
			MYSQL* connection = database::connectByC();		
			QString query = tr("INSERT INTO `qt_tracking`.`employee` (`id` ,`name` ,`birthday` ,`img`) VALUES (NULL , '");
			query = query + strName +"','" + strBirthday+"','" + strFileName+"')" ;
			
			std::string query2 = query.toStdString();
			const char* query1 = query2.c_str();
			try
			{
			//	QByteArray qTem = query.toUtf8();
			//	char* query1    = qTem.data();
				
				int result = mysql_query(connection,query1);
				if (result==0)
				{
					//get the last id from table
					if(mysql_query(connection,"select MAX(id) from `qt_tracking`.`employee`") ==0)
					{
						res_set = mysql_store_result(connection);
						row = mysql_fetch_row(res_set);
						QString path = QDir::currentPath();
						QString name = getRestFromDelimeter(strFileName,'/');
						QString typeFile = getRestFromDelimeter(name,'.');
						QFile::copy(strFileName, QDir::currentPath() +"/Resources/img/"+row[0]+"."+typeFile);
						return true;
					}
				}			
				return false;				
			}
			catch(const ios_base::failure& e)
			{
				return false;
			}
			
			database::closeConnectionC(connection);
			return true;
		}
};

#endif // TUTORIAL_H
