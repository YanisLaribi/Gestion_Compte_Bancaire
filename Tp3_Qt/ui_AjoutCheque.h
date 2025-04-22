/********************************************************************************
** Form generated from reading UI file 'AjoutCheque.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AJOUTCHEQUE_H
#define UI_AJOUTCHEQUE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_AjoutCheque
{
public:
    QPushButton *pushButton;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_5;
    QLineEdit *lineEdit_6;

    void setupUi(QDialog *AjoutCheque)
    {
        if (AjoutCheque->objectName().isEmpty())
            AjoutCheque->setObjectName(QString::fromUtf8("AjoutCheque"));
        AjoutCheque->resize(350, 407);
        pushButton = new QPushButton(AjoutCheque);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(130, 350, 90, 28));
        label = new QLabel(AjoutCheque);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 30, 141, 16));
        label_2 = new QLabel(AjoutCheque);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(30, 70, 141, 21));
        label_3 = new QLabel(AjoutCheque);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(30, 120, 141, 16));
        label_4 = new QLabel(AjoutCheque);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(30, 170, 141, 16));
        label_5 = new QLabel(AjoutCheque);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(30, 220, 151, 16));
        label_6 = new QLabel(AjoutCheque);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(30, 280, 141, 16));
        lineEdit = new QLineEdit(AjoutCheque);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(200, 20, 113, 28));
        lineEdit_2 = new QLineEdit(AjoutCheque);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(200, 120, 113, 28));
        lineEdit_3 = new QLineEdit(AjoutCheque);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(200, 170, 113, 28));
        lineEdit_4 = new QLineEdit(AjoutCheque);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(200, 220, 113, 28));
        lineEdit_5 = new QLineEdit(AjoutCheque);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));
        lineEdit_5->setGeometry(QRect(200, 70, 113, 28));
        lineEdit_6 = new QLineEdit(AjoutCheque);
        lineEdit_6->setObjectName(QString::fromUtf8("lineEdit_6"));
        lineEdit_6->setGeometry(QRect(200, 280, 113, 28));

        retranslateUi(AjoutCheque);

        QMetaObject::connectSlotsByName(AjoutCheque);
    } // setupUi

    void retranslateUi(QDialog *AjoutCheque)
    {
        AjoutCheque->setWindowTitle(QCoreApplication::translate("AjoutCheque", "AjoutCheque", nullptr));
        pushButton->setText(QCoreApplication::translate("AjoutCheque", "Ajouter", nullptr));
        label->setText(QCoreApplication::translate("AjoutCheque", "Num\303\251ro du compte :", nullptr));
        label_2->setText(QCoreApplication::translate("AjoutCheque", "Taux int\303\252ret :", nullptr));
        label_3->setText(QCoreApplication::translate("AjoutCheque", "Solde :", nullptr));
        label_4->setText(QCoreApplication::translate("AjoutCheque", "Description :", nullptr));
        label_5->setText(QCoreApplication::translate("AjoutCheque", "Nombre de Transactions :", nullptr));
        label_6->setText(QCoreApplication::translate("AjoutCheque", "Taux Interet Minimum :", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AjoutCheque: public Ui_AjoutCheque {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AJOUTCHEQUE_H
