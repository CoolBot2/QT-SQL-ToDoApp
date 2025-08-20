/********************************************************************************
** Form generated from reading UI file 'delete_dialog.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DELETE_DIALOG_H
#define UI_DELETE_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_Delete_Dialog
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QLineEdit *Name;

    void setupUi(QDialog *Delete_Dialog)
    {
        if (Delete_Dialog->objectName().isEmpty())
            Delete_Dialog->setObjectName("Delete_Dialog");
        Delete_Dialog->resize(400, 300);
        buttonBox = new QDialogButtonBox(Delete_Dialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);
        label = new QLabel(Delete_Dialog);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 70, 58, 15));
        Name = new QLineEdit(Delete_Dialog);
        Name->setObjectName("Name");
        Name->setGeometry(QRect(90, 70, 161, 21));

        retranslateUi(Delete_Dialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, Delete_Dialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, Delete_Dialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(Delete_Dialog);
    } // setupUi

    void retranslateUi(QDialog *Delete_Dialog)
    {
        Delete_Dialog->setWindowTitle(QCoreApplication::translate("Delete_Dialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("Delete_Dialog", "Name:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Delete_Dialog: public Ui_Delete_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DELETE_DIALOG_H
