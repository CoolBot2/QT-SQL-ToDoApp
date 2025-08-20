#ifndef DELETE_DIALOG_H
#define DELETE_DIALOG_H
#include "todo.h"
#include <QDialog>
#include <QString>
namespace Ui {
class Delete_Dialog;
}

class Delete_Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Delete_Dialog(QWidget *parent = nullptr);
    ~Delete_Dialog();
    void DeleteItem();

private:
    Ui::Delete_Dialog *ui;
};

#endif // DELETE_DIALOG_H
