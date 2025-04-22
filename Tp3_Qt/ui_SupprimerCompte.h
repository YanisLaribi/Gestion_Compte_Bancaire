/********************************************************************************
** Form generated from reading UI file 'SupprimerCompte.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUPPRIMERCOMPTE_H
#define UI_SUPPRIMERCOMPTE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_SupprimerCompte
{
public:
    QLabel *label;
    QPushButton *pushButton;
    QLineEdit *lineEdit;

    void setupUi(QDialog *SupprimerCompte)
    {
        if (SupprimerCompte->objectName().isEmpty())
            SupprimerCompte->setObjectName(QString::fromUtf8("SupprimerCompte"));
        SupprimerCompte->resize(400, 188);
        label = new QLabel(SupprimerCompte);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 50, 201, 16));
        pushButton = new QPushButton(SupprimerCompte);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(150, 120, 90, 28));
        lineEdit = new QLineEdit(SupprimerCompte);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(230, 40, 121, 41));

        retranslateUi(SupprimerCompte);

        QMetaObject::connectSlotsByName(SupprimerCompte);
    } // setupUi

    void retranslateUi(QDialog *SupprimerCompte)
    {
        SupprimerCompte->setWindowTitle(QCoreApplication::translate("SupprimerCompte", "SupprimerCompte", nullptr));
        label->setText(QCoreApplication::translate("SupprimerCompte", "Num\303\251ro du compte \303\240 supprimer :", nullptr));
        pushButton->setText(QCoreApplication::translate("SupprimerCompte", "Supprimer", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SupprimerCompte: public Ui_SupprimerCompte {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUPPRIMERCOMPTE_H
