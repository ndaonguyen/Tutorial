/********************************************************************************
** Form generated from reading UI file 'tutorial.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TUTORIAL_H
#define UI_TUTORIAL_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDateEdit>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TutorialClass
{
public:
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *regisTab;
    QWidget *regisWidget;
    QLabel *imgLabel;
    QLabel *birthLabel;
    QLabel *passwordLabel;
    QDateEdit *birthdayEdit;
    QPushButton *fileEdit;
    QLineEdit *passwordEdit;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *saveButton;
    QPushButton *cancelRegisButton;
    QLabel *myLabel;
    QLineEdit *nameEdit;
    QLabel *nameLabel;
    QWidget *loginTab;
    QWidget *loginWidget;
    QLineEdit *passwordEdit_2;
    QPushButton *loginButton;
    QPushButton *cancelButon;
    QLineEdit *nameEdit_2;
    QLabel *myLabel_2;
    QLabel *passwordLabel_2;
    QLabel *nameLabel_2;
    QPushButton *refillButton;
    QLabel *userLabel;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *TutorialClass)
    {
        if (TutorialClass->objectName().isEmpty())
            TutorialClass->setObjectName(QString::fromUtf8("TutorialClass"));
        TutorialClass->resize(425, 339);
        centralWidget = new QWidget(TutorialClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(30, 30, 381, 251));
        regisTab = new QWidget();
        regisTab->setObjectName(QString::fromUtf8("regisTab"));
        regisWidget = new QWidget(regisTab);
        regisWidget->setObjectName(QString::fromUtf8("regisWidget"));
        regisWidget->setGeometry(QRect(0, 10, 371, 201));
        imgLabel = new QLabel(regisWidget);
        imgLabel->setObjectName(QString::fromUtf8("imgLabel"));
        imgLabel->setGeometry(QRect(40, 120, 46, 13));
        birthLabel = new QLabel(regisWidget);
        birthLabel->setObjectName(QString::fromUtf8("birthLabel"));
        birthLabel->setGeometry(QRect(40, 90, 46, 13));
        passwordLabel = new QLabel(regisWidget);
        passwordLabel->setObjectName(QString::fromUtf8("passwordLabel"));
        passwordLabel->setGeometry(QRect(40, 60, 46, 13));
        birthdayEdit = new QDateEdit(regisWidget);
        birthdayEdit->setObjectName(QString::fromUtf8("birthdayEdit"));
        birthdayEdit->setGeometry(QRect(110, 90, 110, 22));
        fileEdit = new QPushButton(regisWidget);
        fileEdit->setObjectName(QString::fromUtf8("fileEdit"));
        fileEdit->setGeometry(QRect(110, 120, 111, 23));
        passwordEdit = new QLineEdit(regisWidget);
        passwordEdit->setObjectName(QString::fromUtf8("passwordEdit"));
        passwordEdit->setGeometry(QRect(110, 60, 113, 20));
        horizontalLayoutWidget = new QWidget(regisWidget);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(30, 160, 201, 31));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        saveButton = new QPushButton(horizontalLayoutWidget);
        saveButton->setObjectName(QString::fromUtf8("saveButton"));

        horizontalLayout->addWidget(saveButton);

        cancelRegisButton = new QPushButton(horizontalLayoutWidget);
        cancelRegisButton->setObjectName(QString::fromUtf8("cancelRegisButton"));

        horizontalLayout->addWidget(cancelRegisButton);

        myLabel = new QLabel(regisWidget);
        myLabel->setObjectName(QString::fromUtf8("myLabel"));
        myLabel->setGeometry(QRect(250, 40, 121, 101));
        nameEdit = new QLineEdit(regisWidget);
        nameEdit->setObjectName(QString::fromUtf8("nameEdit"));
        nameEdit->setGeometry(QRect(110, 30, 113, 20));
        nameLabel = new QLabel(regisWidget);
        nameLabel->setObjectName(QString::fromUtf8("nameLabel"));
        nameLabel->setGeometry(QRect(40, 30, 46, 13));
        tabWidget->addTab(regisTab, QString());
        loginTab = new QWidget();
        loginTab->setObjectName(QString::fromUtf8("loginTab"));
        loginWidget = new QWidget(loginTab);
        loginWidget->setObjectName(QString::fromUtf8("loginWidget"));
        loginWidget->setGeometry(QRect(0, 10, 371, 201));
        passwordEdit_2 = new QLineEdit(loginWidget);
        passwordEdit_2->setObjectName(QString::fromUtf8("passwordEdit_2"));
        passwordEdit_2->setGeometry(QRect(90, 40, 113, 20));
        loginButton = new QPushButton(loginWidget);
        loginButton->setObjectName(QString::fromUtf8("loginButton"));
        loginButton->setGeometry(QRect(20, 100, 61, 23));
        cancelButon = new QPushButton(loginWidget);
        cancelButon->setObjectName(QString::fromUtf8("cancelButon"));
        cancelButon->setGeometry(QRect(174, 100, 61, 23));
        nameEdit_2 = new QLineEdit(loginWidget);
        nameEdit_2->setObjectName(QString::fromUtf8("nameEdit_2"));
        nameEdit_2->setGeometry(QRect(90, 10, 113, 20));
        myLabel_2 = new QLabel(loginWidget);
        myLabel_2->setObjectName(QString::fromUtf8("myLabel_2"));
        myLabel_2->setGeometry(QRect(260, 10, 101, 91));
        passwordLabel_2 = new QLabel(loginWidget);
        passwordLabel_2->setObjectName(QString::fromUtf8("passwordLabel_2"));
        passwordLabel_2->setGeometry(QRect(20, 40, 46, 13));
        nameLabel_2 = new QLabel(loginWidget);
        nameLabel_2->setObjectName(QString::fromUtf8("nameLabel_2"));
        nameLabel_2->setGeometry(QRect(20, 10, 46, 13));
        refillButton = new QPushButton(loginWidget);
        refillButton->setObjectName(QString::fromUtf8("refillButton"));
        refillButton->setGeometry(QRect(94, 100, 61, 23));
        tabWidget->addTab(loginTab, QString());
        userLabel = new QLabel(centralWidget);
        userLabel->setObjectName(QString::fromUtf8("userLabel"));
        userLabel->setGeometry(QRect(20, 10, 201, 16));
        TutorialClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(TutorialClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 425, 21));
        TutorialClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(TutorialClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        TutorialClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(TutorialClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        TutorialClass->setStatusBar(statusBar);
        QWidget::setTabOrder(nameEdit, passwordEdit);
        QWidget::setTabOrder(passwordEdit, birthdayEdit);
        QWidget::setTabOrder(birthdayEdit, fileEdit);
        QWidget::setTabOrder(fileEdit, saveButton);
        QWidget::setTabOrder(saveButton, cancelRegisButton);
        QWidget::setTabOrder(cancelRegisButton, nameEdit_2);
        QWidget::setTabOrder(nameEdit_2, passwordEdit_2);
        QWidget::setTabOrder(passwordEdit_2, loginButton);
        QWidget::setTabOrder(loginButton, refillButton);
        QWidget::setTabOrder(refillButton, cancelButon);
        QWidget::setTabOrder(cancelButon, tabWidget);

        retranslateUi(TutorialClass);
        QObject::connect(fileEdit, SIGNAL(clicked()), TutorialClass, SLOT(fileAction()));
        QObject::connect(cancelRegisButton, SIGNAL(clicked()), TutorialClass, SLOT(cancelAction()));
        QObject::connect(saveButton, SIGNAL(clicked()), TutorialClass, SLOT(saveAction()));
        QObject::connect(loginButton, SIGNAL(clicked()), TutorialClass, SLOT(loginAction()));
        QObject::connect(refillButton, SIGNAL(clicked()), TutorialClass, SLOT(refillLoginAction()));
        QObject::connect(cancelButon, SIGNAL(clicked()), TutorialClass, SLOT(cancelAction()));

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(TutorialClass);
    } // setupUi

    void retranslateUi(QMainWindow *TutorialClass)
    {
        TutorialClass->setWindowTitle(QApplication::translate("TutorialClass", "Tutorial", 0, QApplication::UnicodeUTF8));
        imgLabel->setText(QApplication::translate("TutorialClass", "Img", 0, QApplication::UnicodeUTF8));
        birthLabel->setText(QApplication::translate("TutorialClass", "Birthday", 0, QApplication::UnicodeUTF8));
        passwordLabel->setText(QApplication::translate("TutorialClass", "Password", 0, QApplication::UnicodeUTF8));
        fileEdit->setText(QApplication::translate("TutorialClass", "Browse ..", 0, QApplication::UnicodeUTF8));
        saveButton->setText(QApplication::translate("TutorialClass", "Save", 0, QApplication::UnicodeUTF8));
        cancelRegisButton->setText(QApplication::translate("TutorialClass", "Cancel", 0, QApplication::UnicodeUTF8));
        myLabel->setText(QString());
        nameLabel->setText(QApplication::translate("TutorialClass", "Name", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(regisTab), QApplication::translate("TutorialClass", "Registration", 0, QApplication::UnicodeUTF8));
        loginButton->setText(QApplication::translate("TutorialClass", "Log in", 0, QApplication::UnicodeUTF8));
        cancelButon->setText(QApplication::translate("TutorialClass", "cancel", 0, QApplication::UnicodeUTF8));
        myLabel_2->setText(QString());
        passwordLabel_2->setText(QApplication::translate("TutorialClass", "Password", 0, QApplication::UnicodeUTF8));
        nameLabel_2->setText(QApplication::translate("TutorialClass", "Name", 0, QApplication::UnicodeUTF8));
        refillButton->setText(QApplication::translate("TutorialClass", "refill", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(loginTab), QApplication::translate("TutorialClass", "Log in ", 0, QApplication::UnicodeUTF8));
        userLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class TutorialClass: public Ui_TutorialClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TUTORIAL_H
