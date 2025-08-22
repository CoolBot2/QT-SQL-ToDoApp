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

class Ui_MainWindow
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

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(792, 544);
        MainWindow->setStyleSheet(QString::fromUtf8("  background-color: lightblue;"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        TaskList = new QListWidget(centralwidget);
        TaskList->setObjectName("TaskList");
        QFont font;
        font.setFamilies({QString::fromUtf8("Times New Roman")});
        font.setPointSize(18);
        font.setBold(true);
        font.setItalic(true);
        TaskList->setFont(font);
        TaskList->viewport()->setProperty("cursor", QVariant(QCursor(Qt::CursorShape::PointingHandCursor)));
        TaskList->setStyleSheet(QString::fromUtf8("background-image: url(\"/home/daniel/Projects/Qt-Projects/ToDoApp/background.jpeg\");\n"
"color:black;\n"
""));
        TaskList->setLineWidth(2);

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
        pushButton_DeleteAll->setStyleSheet(QString::fromUtf8("  background-color: black;"));

        verticalLayout->addWidget(pushButton_DeleteAll);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 792, 20));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton_addTask->setText(QCoreApplication::translate("MainWindow", "Add", nullptr));
        pushButton_DeleteTask->setText(QCoreApplication::translate("MainWindow", "Delete", nullptr));
        pushButton_DeleteAll->setText(QCoreApplication::translate("MainWindow", "Delete ALL", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
