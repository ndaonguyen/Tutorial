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
	void loadImage(QString pathImg,QLabel* mylabel)
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

	void setMouseOverImg(QString pathImg,QLabel *imgShow)
	{
		/** 
		Mouse over picture --> get picture bigger
		**/
		QPixmap pix;					
		pix.load(pathImg);
		int imgWidth  = pix.width()/2;
		int imgHeight = pix.height()/2;
		if(pix.width()>thresholdImg)
		{
			int scale = pix.width()/standardImgShow;
			imgWidth  = pix.width()/scale;
			imgHeight = pix.height()/scale;
		}
		imgShow->setToolTip("<html><img src='"+pathImg+"' width='"+QString::number(imgWidth)+"' height='"+QString::number(imgHeight)+"' /></html>");
	}


	
private:
	Ui::TutorialClass ui;
	QString strFileName;
	public slots:
		// Register tab
		void fileAction()
		{
			QString fn = QFileDialog::getOpenFileName(this, tr("Open file..."),tr("C:\\Users\\ndnguyen\\Desktop\\"),tr("Image-files (*.jpg *.png *.gif)"));
			strFileName = fn;
			loadImage(fn,ui.myLabel);
			// load big pic by tooltip
			setMouseOverImg(fn,ui.myLabel);
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
		// Log in tab
		void loginAction()
		{
			//check whether 2 required blank are filled
			QString nameLogin = ui.nameEdit_2->text();
			QString pswLogin  = ui.passwordEdit_2->text();
			if(nameLogin.trimmed().isEmpty() || pswLogin.trimmed().isEmpty())
			{
				QMessageBox::StandardButton reply;
				reply = QMessageBox::question(this, "Error filling blank ...", "Please re-enter login information!!!", QMessageBox::Yes | QMessageBox::No);
				if (reply == QMessageBox::Yes)
				{
					ui.nameEdit_2->setFocus();
					return;
				}
				else
				{
					cancelAction();
				}
			}
			// check information from database
			QByteArray tempPwd  = pswLogin.toUtf8();
			QString temPwd2      = QString(QCryptographicHash::hash((tempPwd),QCryptographicHash::Md5).toHex());
			
			QString query = tr("SELECT * FROM `qt_tracking`.`employee` WHERE `name` ='");
			query = query  + nameLogin + "' AND `password` ='" +temPwd2+"'";
			
			std::string query2 = query.toStdString();
			const char* query1 = query2.c_str();
			MYSQL* connection = database::connectByC();	
			MYSQL_RES* result;
			MYSQL_ROW  row;
			
			if(mysql_query(connection,query1)==0)
			{

				result = mysql_store_result(connection);
				row    = mysql_fetch_row(result);
				if(row!=NULL)
				{					
					// list that personal information
						//set hidden
					ui.nameEdit_2->setHidden(true);
					ui.passwordEdit_2->setHidden(true);
					ui.loginButton->setHidden(true);
					ui.refillButton->setHidden(true);
					ui.cancelButon->setHidden(true);
					ui.passwordLabel_2->setText("Birthday");
					//get location
					QRect nameEditGeo   = ui.nameEdit_2->geometry();
					QRect birthEditGeo  = ui.passwordEdit_2->geometry();
					QRect nameLabelGeo  = ui.nameLabel_2->geometry();
					QRect birthLabelGeo = ui.passwordLabel_2->geometry();
					
					QLabel *birthdayAdd = new QLabel(ui.loginWidget);
					QString birth       = QString::fromUtf8(row[3]);
					birthdayAdd->setText(birth);
					birthdayAdd->setGeometry(birthEditGeo);
					birthdayAdd->show();

					QLabel *nameAdd    = new QLabel(ui.loginWidget);
					QString name       = QString::fromUtf8(row[1]);
					ui.userLabel->setText("Name :"+name);
					nameAdd->setText(name);
					nameAdd->setGeometry(nameEditGeo);
					nameAdd->show();

					int distance        = birthLabelGeo.y() - nameLabelGeo.y();
					QLabel * imgShow    = new QLabel(ui.loginWidget);
					imgShow->setSizeIncrement(120,100);
					imgShow->setText("");
					imgShow->setGeometry(QRect(QPoint(birthLabelGeo.x(),birthLabelGeo.y()+10), QSize(120,100)));
					//showPicture
					QString pathImg = QDir::currentPath() +"/Resources/img/"+QString::fromUtf8(row[4]);
					loadImage(pathImg,imgShow);
					setMouseOverImg(pathImg,imgShow);		
					imgShow->show();
					
					// Add more tab : employee list
					QWidget *listTab = new QWidget();
					ui.tabWidget->addTab(listTab, "Employee list");

					




					return;
				}
			}	
		}
};

#endif // TUTORIAL_H
