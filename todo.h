#ifndef TODO_H
#define TODO_H
#include <iostream>
#include <ctime>
#include <chrono>
#include <sqlite3.h>
#include<QString>
using namespace std;
class todo
{
private:
    string taskName;
    static unsigned int currentID;

    /*!
     * @brief Eindeutige ID des Mediums
     */
    string timestamp;
    unsigned int ID;
    string task;
    bool strikedout;


public:
    todo(const string& name, const string& task);
    ~todo();
    void saveToDB();
    void deleteFromDB();
    QString getTaskName();
    QString getTask();
    QString getTimestamp();
    int getId();
    void setStrikedout();
    bool getStrikedout();

};
#endif // TODO_H
