#include "delete_dialog.h"
#include "ui_delete_dialog.h"

Delete_Dialog::Delete_Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Delete_Dialog)
{
    ui->setupUi(this);
}

Delete_Dialog::~Delete_Dialog()
{
    delete ui;
}

void Delete_Dialog::DeleteItem(){

    QString qname = ui->Name->text();
    string name = qname.toStdString();
        sqlite3 *db;
        char* errMsg = nullptr;
        int rc = sqlite3_open("ToDo.db",&db);
        if( rc ){
            cerr<<"cant open db"<<endl;
            return;
        }
        cout<<"opened database successfully"<<endl;
        string sql_deleteFromTable = "DELETE FROM TODOLIST WHERE TASKNAME='" + name + "';";
        int cmd = sqlite3_exec(db,sql_deleteFromTable.c_str(),0,0,&errMsg);
        if( cmd != SQLITE_OK ){
            cerr<< "SQL error:"<< errMsg<<endl;
            sqlite3_free(errMsg);
        }
        else{
            cout<<name<<" deleted"<<endl;
        }


        sqlite3_close(db);


}
