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
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TutorialClass
{
public:
    QWidget *centralWidget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLineEdit *nameEdit;
    QLabel *nameLabel;
    QLabel *birthLabel;
    QLabel *imgLabel;
    QPushButton *fileEdit;
    QDateEdit *birthdayEdit;
    QLabel *myLabel;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *TutorialClass)
    {
        if (TutorialClass->objectName().isEmpty())
            TutorialClass->setObjectName(QString::fromUtf8("TutorialClass"));
        TutorialClass->resize(343, 310);
        centralWidget = new QWidget(TutorialClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayoutWidget = new QWidget(centralWidget);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(50, 220, 241, 31));
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

        nameEdit = new QLineEdit(centralWidget);
        nameEdit->setObjectName(QString::fromUtf8("nameEdit"));
        nameEdit->setGeometry(QRect(150, 20, 113, 20));
        nameLabel = new QLabel(centralWidget);
        nameLabel->setObjectName(QString::fromUtf8("nameLabel"));
        nameLabel->setGeometry(QRect(80, 20, 46, 13));
        birthLabel = new QLabel(centralWidget);
        birthLabel->setObjectName(QString::fromUtf8("birthLabel"));
        birthLabel->setGeometry(QRect(80, 60, 46, 13));
        imgLabel = new QLabel(centralWidget);
        imgLabel->setObjectName(QString::fromUtf8("imgLabel"));
        imgLabel->setGeometry(QRect(80, 100, 46, 13));
        fileEdit = new QPushButton(centralWidget);
        fileEdit->setObjectName(QString::fromUtf8("fileEdit"));
        fileEdit->setGeometry(QRect(150, 100, 111, 23));
        birthdayEdit = new QDateEdit(centralWidget);
        birthdayEdit->setObjectName(QString::fromUtf8("birthdayEdit"));
        birthdayEdit->setGeometry(QRect(150, 60, 110, 22));
        myLabel = new QLabel(centralWidget);
        myLabel->setObjectName(QString::fromUtf8("myLabel"));
        myLabel->setGeometry(QRect(100, 140, 81, 71));
        TutorialClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(TutorialClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 343, 21));
        TutorialClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(TutorialClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        TutorialClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(TutorialClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        TutorialClass->setStatusBar(statusBar);
        QWidget::setTabOrder(nameEdit, fileEdit);
        QWidget::setTabOrder(fileEdit, pushButton);
        QWidget::setTabOrder(pushButton, pushButton_2);

        retranslateUi(TutorialClass);
        QObject::connect(fileEdit, SIGNAL(clicked()), TutorialClass, SLOT(fileAction()));
        QObject::connect(pushButton_2, SIGNAL(clicked()), TutorialClass, SLOT(cancelAction()));
        QObject::connect(pushButton, SIGNAL(clicked()), TutorialClass, SLOT(saveAction()));

        QMetaObject::connectSlotsByName(TutorialClass);
    } // setupUi

    void retranslateUi(QMainWindow *TutorialClass)
    {
        TutorialClass->setWindowTitle(QApplication::translate("TutorialClass", "Tutorial", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("TutorialClass", "Save", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("TutorialClass", "Cancel", 0, QApplication::UnicodeUTF8));
        nameLabel->setText(QApplication::translate("TutorialClass", "Name", 0, QApplication::UnicodeUTF8));
        birthLabel->setText(QApplication::translate("TutorialClass", "Birthday", 0, QApplication::UnicodeUTF8));
        imgLabel->setText(QApplication::translate("TutorialClass", "Img", 0, QApplication::UnicodeUTF8));
        fileEdit->setText(QApplication::translate("TutorialClass", "Browse ..", 0, QApplication::UnicodeUTF8));
        myLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class TutorialClass: public Ui_TutorialClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TUTORIAL_H
