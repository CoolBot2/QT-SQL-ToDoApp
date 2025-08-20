#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    AddTasksOnload();
}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::AddTasksOnload(){
    qDebug()<<"we fucked";
    if (QSqlDatabase::contains("qt_sql_default_connection")) {
        QSqlDatabase::removeDatabase("qt_sql_default_connection");
    }
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("ToDo.db");
    if (!db.open()) {
        QMessageBox::warning(this, "DB", "Kann DB nicht öffnen: " + db.lastError().text());
        return;
    }
    QSqlQuery sql(db);
    if (!sql.exec("SELECT TASKNAME, TASK, TIME FROM TODOLIST")) {
        //QMessageBox::warning(this, "DB", "SELECT-Fehler: " + sql.lastError().text());
        return;
    }
    ui->TaskList->clear();
    while (sql.next()) {


        QString TASKNAME = sql.value(0).toString();
        QString TASK = sql.value(1).toString();
        QString TIME = sql.value(2).toString();

        ui->TaskList->addItem(QString("%1: %2 \t \t \t \t     at %3 ").arg(TASKNAME).arg(TASK,TIME));


    }
}

void MainWindow::on_pushButton_addTask_clicked()
{
    Dialog addTask;
    if(addTask.exec()==QDialog::Accepted){
        todo * task = addTask.CreateTask();
        task->saveToDB();
       QString entry = QString("%1: %2 \t \t \t \t     at %3")
                              .arg((task->getTaskName()))
                              .arg((task->getTask()))
                              .arg((task->getTimestamp()));

        ui->TaskList->addItem(entry);

    } else{
        qDebug()<<"benutzer hat cancel geclickt";
    }
}


void MainWindow::on_TaskList_itemDoubleClicked(QListWidgetItem *item)
{
    auto reply = QMessageBox::question(this, "Delete Task",
                                       "Do you really want to delete this task?",
                                       QMessageBox::Yes | QMessageBox::No);
    if (reply != QMessageBox::Yes) return;

}


void MainWindow::on_pushButton_DeleteTask_clicked()
{
    Delete_Dialog deleteTask;
    if(deleteTask.exec()==QDialog::Accepted){
        deleteTask.DeleteItem();
        qDebug()<<"task have been deleted";

        AddTasksOnload();


    } else{
        qDebug()<<"benutzer hat cancel geclickt";
    }
}


void MainWindow::on_pushButton_DeleteAll_clicked()
{
    auto reply = QMessageBox::question(this, "Delete All Task",
                                       "Do you really want to delete all tasks?",
                                       QMessageBox::Yes | QMessageBox::No);
    if (reply != QMessageBox::Yes) return;
    QSqlDatabase db = QSqlDatabase::database();//sehr wichtiggggggggggg

    if (!db.open()) {
        QMessageBox::warning(this, "DB", "Kann DB nicht öffnen: " + db.lastError().text());
        return;
    }
    QSqlQuery sql(db);
    if (!sql.exec("DELETE FROM TODOLIST")) {
        QMessageBox::warning(this, "DB", "SELECT-Fehler: " + sql.lastError().text());
        return;
    }
    qDebug()<<"all tasks have been deleted";
    ui->TaskList->clear();

}

