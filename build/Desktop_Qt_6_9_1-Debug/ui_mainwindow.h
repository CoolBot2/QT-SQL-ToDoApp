/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QT
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QListWidget *TaskList;
    QPushButton *pushButton_addTask;
    QPushButton *pushButton_DeleteTask;
    QPushButton *pushButton_DeleteAll;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *QT)
    {
        if (QT->objectName().isEmpty())
            QT->setObjectName("QT");
        QT->resize(911, 589);
        centralwidget = new QWidget(QT);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        TaskList = new QListWidget(centralwidget);
        TaskList->setObjectName("TaskList");
        QFont font;
        font.setFamilies({QString::fromUtf8("Times New Roman")});
        font.setPointSize(20);
        font.setBold(true);
        font.setItalic(true);
        TaskList->setFont(font);

        verticalLayout->addWidget(TaskList);

        pushButton_addTask = new QPushButton(centralwidget);
        pushButton_addTask->setObjectName("pushButton_addTask");
        pushButton_addTask->setAutoFillBackground(false);
        pushButton_addTask->setStyleSheet(QString::fromUtf8("background-color:green;"));

        verticalLayout->addWidget(pushButton_addTask);

        pushButton_DeleteTask = new QPushButton(centralwidget);
        pushButton_DeleteTask->setObjectName("pushButton_DeleteTask");
        pushButton_DeleteTask->setStyleSheet(QString::fromUtf8("background-color: red;"));

        verticalLayout->addWidget(pushButton_DeleteTask);

        pushButton_DeleteAll = new QPushButton(centralwidget);
        pushButton_DeleteAll->setObjectName("pushButton_DeleteAll");

        verticalLayout->addWidget(pushButton_DeleteAll);

        QT->setCentralWidget(centralwidget);
        menubar = new QMenuBar(QT);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 911, 20));
        QT->setMenuBar(menubar);
        statusbar = new QStatusBar(QT);
        statusbar->setObjectName("statusbar");
        QT->setStatusBar(statusbar);

        retranslateUi(QT);

        QMetaObject::connectSlotsByName(QT);
    } // setupUi

    void retranslateUi(QMainWindow *QT)
    {
        QT->setWindowTitle(QCoreApplication::translate("QT", "MainWindow", nullptr));
        pushButton_addTask->setText(QCoreApplication::translate("QT", "Add", nullptr));
        pushButton_DeleteTask->setText(QCoreApplication::translate("QT", "Delete", nullptr));
        pushButton_DeleteAll->setText(QCoreApplication::translate("QT", "Delete ALL", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QT: public Ui_QT {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
