#include "todo.h"
unsigned int todo::currentID = 1;
todo::todo(const string& name, const string& task):taskName(name),ID(currentID++) ,task(task){
    auto now = std::chrono::system_clock::now();

    time_t timec = std::chrono::system_clock::to_time_t(now);
    this->timestamp = ctime(&timec);
    cout<<ID<< " todo task named: "<<taskName<<" created at "<<timestamp<<endl;
}

todo::~todo(){
    cout<<"task "<<ID<<" deleted"<<endl;
}

void todo::deleteFromDB(){

    sqlite3 *db;
    char* errMsg = nullptr;
    int rc = sqlite3_open("ToDo.db",&db);
    if( rc ){
        cerr<<"cant open db"<<endl;
        return;
    }
    cout<<"opened database successfully"<<endl;
    string sql_deleteFromTable = "DELETE FROM TODOLIST WHERE TASKNAME="+taskName+';' ;
    int cmd = sqlite3_exec(db,sql_deleteFromTable.c_str(),0,0,&errMsg);
    if( cmd != SQLITE_OK ){
        cerr<< "SQL error:"<< errMsg<<endl;
        sqlite3_free(errMsg);
    }
    else{
        cout<<taskName<<" deleted"<<endl;
    }


    sqlite3_close(db);
    todo::~todo();
}

void todo::saveToDB(){
    sqlite3 *db;
    char* errMsg = nullptr;
    int rc = sqlite3_open("ToDo.db",&db);
    if( rc ){
        cerr<<"cant open db"<<endl;
        return;
    }
    cout<<"opened database successfully"<<endl;

    const char* sql_createTable =    "CREATE TABLE IF NOT EXISTS TODOLIST ("

                                  "TASKNAME TEXT NOT NULL,"
                                  "TASK TEXT NOT NULL,"
                                  "TIME TEXT NOT NULL"
                                  ");";
    sqlite3_exec(db,sql_createTable,0,0,&errMsg);
    std::string ts = timestamp;
    if (!ts.empty() && ts.back() == '\n') ts.pop_back();
    string sql_insertElement =
        "INSERT INTO TODOLIST(TASKNAME,TASK,TIME) VALUES('" + taskName + "','" + task + "','" + ts+ "');";
    int cmd = sqlite3_exec(db,sql_insertElement.c_str(),0,0,&errMsg);
    if( cmd != SQLITE_OK ){
        cerr<< "SQL error:"<< errMsg<<endl;
        sqlite3_free(errMsg);
    }
    else{
        cout<<taskName<<" gespeichert"<<endl;
    }


    sqlite3_close(db);
}

QString todo::getTaskName(){
    return QString::fromStdString(taskName);
}
QString todo::getTask(){
    return QString::fromStdString(task);
}
QString todo::getTimestamp(){
    return QString::fromStdString(timestamp);
}
