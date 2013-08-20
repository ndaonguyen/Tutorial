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
    QWidget *tab;
    QLabel *myLabel;
    QLabel *imgLabel;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *fileEdit;
    QLineEdit *nameEdit;
    QLabel *nameLabel;
    QLabel *birthLabel;
    QDateEdit *birthdayEdit;
    QLabel *passwordLabel;
    QLineEdit *passwordEdit;
    QWidget *tab_3;
    QWidget *tab_2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *TutorialClass)
    {
        if (TutorialClass->objectName().isEmpty())
            TutorialClass->setObjectName(QString::fromUtf8("TutorialClass"));
        TutorialClass->resize(435, 385);
        centralWidget = new QWidget(TutorialClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(30, 10, 371, 321));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        myLabel = new QLabel(tab);
        myLabel->setObjectName(QString::fromUtf8("myLabel"));
        myLabel->setGeometry(QRect(90, 150, 101, 91));
        imgLabel = new QLabel(tab);
        imgLabel->setObjectName(QString::fromUtf8("imgLabel"));
        imgLabel->setGeometry(QRect(80, 110, 46, 13));
        horizontalLayoutWidget = new QWidget(tab);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(50, 260, 241, 31));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(horizontalLayoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(horizontalLayoutWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);

        fileEdit = new QPushButton(tab);
        fileEdit->setObjectName(QString::fromUtf8("fileEdit"));
        fileEdit->setGeometry(QRect(150, 110, 111, 23));
        nameEdit = new QLineEdit(tab);
        nameEdit->setObjectName(QString::fromUtf8("nameEdit"));
        nameEdit->setGeometry(QRect(150, 20, 113, 20));
        nameLabel = new QLabel(tab);
        nameLabel->setObjectName(QString::fromUtf8("nameLabel"));
        nameLabel->setGeometry(QRect(80, 20, 46, 13));
        birthLabel = new QLabel(tab);
        birthLabel->setObjectName(QString::fromUtf8("birthLabel"));
        birthLabel->setGeometry(QRect(80, 80, 46, 13));
        birthdayEdit = new QDateEdit(tab);
        birthdayEdit->setObjectName(QString::fromUtf8("birthdayEdit"));
        birthdayEdit->setGeometry(QRect(150, 80, 110, 22));
        passwordLabel = new QLabel(tab);
        passwordLabel->setObjectName(QString::fromUtf8("passwordLabel"));
        passwordLabel->setGeometry(QRect(80, 50, 46, 13));
        passwordEdit = new QLineEdit(tab);
        passwordEdit->setObjectName(QString::fromUtf8("passwordEdit"));
        passwordEdit->setGeometry(QRect(150, 50, 113, 20));
        tabWidget->addTab(tab, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        tabWidget->addTab(tab_3, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        tabWidget->addTab(tab_2, QString());
        TutorialClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(TutorialClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 435, 21));
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
        QWidget::setTabOrder(fileEdit, pushButton);
        QWidget::setTabOrder(pushButton, pushButton_2);
        QWidget::setTabOrder(pushButton_2, tabWidget);

        retranslateUi(TutorialClass);
        QObject::connect(fileEdit, SIGNAL(clicked()), TutorialClass, SLOT(fileAction()));
        QObject::connect(pushButton_2, SIGNAL(clicked()), TutorialClass, SLOT(cancelAction()));
        QObject::connect(pushButton, SIGNAL(clicked()), TutorialClass, SLOT(saveAction()));

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(TutorialClass);
    } // setupUi

    void retranslateUi(QMainWindow *TutorialClass)
    {
        TutorialClass->setWindowTitle(QApplication::translate("TutorialClass", "Tutorial", 0, QApplication::UnicodeUTF8));
        myLabel->setText(QString());
        imgLabel->setText(QApplication::translate("TutorialClass", "Img", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("TutorialClass", "Save", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("TutorialClass", "Cancel", 0, QApplication::UnicodeUTF8));
        fileEdit->setText(QApplication::translate("TutorialClass", "Browse ..", 0, QApplication::UnicodeUTF8));
        nameLabel->setText(QApplication::translate("TutorialClass", "Name", 0, QApplication::UnicodeUTF8));
        birthLabel->setText(QApplication::translate("TutorialClass", "Birthday", 0, QApplication::UnicodeUTF8));
        passwordLabel->setText(QApplication::translate("TutorialClass", "Password", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("TutorialClass", "Registration", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("TutorialClass", "Page", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("TutorialClass", "Tab 2", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class TutorialClass: public Ui_TutorialClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TUTORIAL_H
