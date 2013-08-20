#ifndef TUTORIAL_H
#define TUTORIAL_H
#include <QtSql/QSqlDatabase> 
#include <QtGui/QMainWindow>
#include <QFileDialog>
#include <QByteArray>
#include <QImage>
#include <QPixmap>
#include <QCryptographicHash>
#include "ui_tutorial.h"
#include <cstdlib>
#include <string>
#include "database.h"
using std::string;

class Tutorial : public QMainWindow
{
	Q_OBJECT

public:
	Tutorial(QWidget *parent = 0, Qt::WFlags flags = 0);
	~Tutorial();
	static const int thresholdImg    = 800;
	static const int standardImgShow = 400;

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
	}

	
private:
	Ui::TutorialClass ui;
	QString strFileName;
	public slots:
		void fileAction()
		{
			QString fn = QFileDialog::getOpenFileName(this, tr("Open file..."),tr("C:\\Users\\ndnguyen\\Desktop\\"),tr("Image-files (*.jpg *.png *.gif)"));
			strFileName = fn;

			std::string temp = fn.toStdString();
			char* strPath = (char*)temp.c_str();
			loadImage(strPath,ui.myLabel);
			// load big pic by tooltip
			
			QPixmap pix;
			pix.load(fn);
			int imgWidth  = pix.width()/2;
			int imgHeight = pix.height()/2;
			if(pix.width()>thresholdImg)
			{
				int scale = pix.width()/standardImgShow;
				imgWidth  = pix.width()/scale;
				imgHeight = pix.height()/scale;
			}
			ui.myLabel->setToolTip("<html><img src='"+fn+"' width='"+QString::number(imgWidth)+"' height='"+QString::number(imgHeight)+"' /></html>");
			
		}
		void cancelAction()
		{
			QApplication::quit();
		}

		bool saveAction()
		{
			MYSQL_RES *res_set;
			MYSQL_ROW row;

			QString strName     = ui.nameEdit->text();
			QString strPwdText  = ui.passwordEdit->text();
			QByteArray tempPwd  = strPwdText.toUtf8();
			QString strPwd      = QString(QCryptographicHash::hash((tempPwd),QCryptographicHash::Md5).toHex());

			QString strBirthday = ui.birthdayEdit->date().toString(Qt::ISODate);
			MYSQL* connection = database::connectByC();		
			//get the last id from table
			if(mysql_query(connection,"select MAX(id) from `qt_tracking`.`employee`") ==0)
			{
				res_set = mysql_store_result(connection);
				row = mysql_fetch_row(res_set);
				int idInserted = atoi(row[0])+1;
				char idInsert[5];
				itoa(idInserted,idInsert,10);

				QString path = QDir::currentPath();
				QString name = getRestFromDelimeter(strFileName,'/');
				QString typeFile = getRestFromDelimeter(name,'.');

				QString query = tr("INSERT INTO `qt_tracking`.`employee` (`id` ,`name` , `password`, `birthday` , `img`) VALUES (NULL , '");
				query = query + strName +"','"+strPwd +"','"+ strBirthday+"','" + idInsert+"."+typeFile+"')" ;
				
				std::string query2 = query.toStdString();
				const char* query1 = query2.c_str();
				try
				{
					int result = mysql_query(connection,query1);
					if (result==0)
					{
						QFile::copy(strFileName, QDir::currentPath() +"/Resources/img/"+idInsert+"."+typeFile);
						return true;
					}			
					return false;				
				}
				catch(const ios_base::failure& e)
				{
					return false;
				}
			}
			database::closeConnectionC(connection);
			return true;
		}
};

#endif // TUTORIAL_H
