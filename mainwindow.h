#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QMainWindow>
#include <QListWidgetItem>
#include "todo.h"
#include "dialog.h"
#include "delete_dialog.h"
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void AddTasksOnload();

    void on_pushButton_addTask_clicked();

    void on_TaskList_itemDoubleClicked(QListWidgetItem *item);

    void on_pushButton_DeleteTask_clicked();

    void on_pushButton_DeleteAll_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
