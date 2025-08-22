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
    if (!sql.exec("SELECT TASKNAME, TASK, TIME, ISSTRIKEDOUT FROM TODOLIST")) {
        //QMessageBox::warning(this, "DB", "SELECT-Fehler: " + sql.lastError().text());
        return;
    }
    ui->TaskList->clear();
    int id=1;
    while (sql.next()) {


        QString TASKNAME = sql.value(0).toString();
        QString TASK = sql.value(1).toString();
        QString TIME = sql.value(2).toString();
        bool isStriked = sql.value(3).toBool();
        auto *entry = new QListWidgetItem(QString("%3-  %1: %2").arg(TASKNAME).arg(TASK).arg(id));
        entry->setFlags(entry->flags() | Qt::ItemIsUserCheckable);
        entry->setCheckState(Qt::Unchecked);
        // qDebug()<<isStriked;
        if(isStriked){
            QFont f = entry->font();
            f.setStrikeOut(isStriked);
            entry->setFont(f);        }
        ui->TaskList->addItem(entry);

        entry->setData(Qt::UserRole, TASKNAME);
        id++;
    }
}

void MainWindow::on_pushButton_addTask_clicked()
{
    Dialog addTask;


    if(addTask.exec()==QDialog::Accepted){
        todo * task = addTask.CreateTask();
        task->saveToDB();
       AddTasksOnload();
    } else{
        qDebug()<<"benutzer hat cancel geclickt";
    }
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
        QMessageBox::warning(this, "DB", "DELETE-Fehler: " + sql.lastError().text());
        return;
    }
    qDebug()<<"all tasks have been deleted";
    ui->TaskList->clear();
}





void MainWindow::on_TaskList_itemClicked(QListWidgetItem *item)
{
    // QFont f = item->font();
    // const bool strike = !f.strikeOut();
    // f.setStrikeOut(strike);
    // item->setFont(f);
    // QString taskName = item->data(Qt::UserRole).toString();
    // QSqlDatabase db = QSqlDatabase::database();//sehr wichtiggggggggggg

    // if (!db.open()) {
    //     QMessageBox::warning(this, "DB", "Kann DB nicht öffnen: " + db.lastError().text());
    //     return;
    // }
    // QSqlQuery sql(db);
    // sql.prepare("UPDATE TODOLIST SET ISSTRIKEDOUT = :flag WHERE TASKNAME = :name");
    // sql.bindValue(":flag", strike);
    // sql.bindValue(":name", taskName);
    // if (!sql.exec()) {
    //     QMessageBox::warning(this, "DB", "UPDATE-Fehler: " + sql.lastError().text());
    //     return;
    // }

}

void MainWindow::on_TaskList_itemDoubleClicked(QListWidgetItem *item)
{
    QString taskName = item->data(Qt::UserRole).toString();

    QSqlDatabase db = QSqlDatabase::database();//sehr wichtiggggggggggg
    if (!db.open()) {
        QMessageBox::warning(this, "DB", "Kann DB nicht öffnen: " + db.lastError().text());
        return;
    }
    QLineEdit *edit = new QLineEdit(ui->TaskList);
    QString itemText =item->text();
    QString editText = itemText.mid(itemText.indexOf(':')+1);
    edit->setText(editText);
    ui->TaskList->setItemWidget(item, edit);
    edit->selectAll();
    connect(edit, &QLineEdit::editingFinished, this, [=] (/* opt. Varis*/) {
        QSqlQuery sql(db);

        QString newtext = edit->text();
        item->setText(taskName+": "+newtext);
        sql.prepare("UPDATE TODOLIST SET TASK = :text WHERE TASKNAME = :name");
        sql.bindValue(":text", newtext);
        sql.bindValue(":name", taskName);
        if (!sql.exec()) {
            QMessageBox::warning(this, "DB", "UPDATE-Fehler: " + sql.lastError().text());
            return;
        }
        ui->TaskList->removeItemWidget(item);
        edit->deleteLater();
    });
}
