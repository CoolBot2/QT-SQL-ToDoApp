#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

todo* Dialog::CreateTask(){
    QString Name = ui->Name->text();
    QString Task = ui->Task->text();
    return new todo(Name.toStdString(), Task.toStdString());
}
