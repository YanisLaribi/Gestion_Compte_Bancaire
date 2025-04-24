/********************************************************************************
** Form generated from reading UI file 'AjoutEpargne.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AJOUTEPARGNE_H
#define UI_AJOUTEPARGNE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_AjoutEpargne
{
public:
    QPushButton *pushButton;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *lineEditCompte;
    QLineEdit *lineEditTaux;
    QLineEdit *lineEditSolde;
    QLineEdit *lineEditDescription;
    QPushButton *pushButton_2;

    void setupUi(QDialog *AjoutEpargne)
    {
        if (AjoutEpargne->objectName().isEmpty())
            AjoutEpargne->setObjectName(QString::fromUtf8("AjoutEpargne"));
        AjoutEpargne->resize(409, 401);
        pushButton = new QPushButton(AjoutEpargne);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(50, 330, 90, 28));
        label = new QLabel(AjoutEpargne);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(60, 30, 181, 16));
        label_2 = new QLabel(AjoutEpargne);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(60, 90, 171, 16));
        label_3 = new QLabel(AjoutEpargne);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(60, 160, 58, 16));
        label_4 = new QLabel(AjoutEpargne);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(60, 240, 171, 16));
        label_5 = new QLabel(AjoutEpargne);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(70, 230, 58, 16));
        lineEditCompte = new QLineEdit(AjoutEpargne);
        lineEditCompte->setObjectName(QString::fromUtf8("lineEditCompte"));
        lineEditCompte->setGeometry(QRect(260, 30, 113, 28));
        lineEditTaux = new QLineEdit(AjoutEpargne);
        lineEditTaux->setObjectName(QString::fromUtf8("lineEditTaux"));
        lineEditTaux->setGeometry(QRect(260, 90, 113, 28));
        lineEditSolde = new QLineEdit(AjoutEpargne);
        lineEditSolde->setObjectName(QString::fromUtf8("lineEditSolde"));
        lineEditSolde->setGeometry(QRect(260, 160, 113, 28));
        lineEditDescription = new QLineEdit(AjoutEpargne);
        lineEditDescription->setObjectName(QString::fromUtf8("lineEditDescription"));
        lineEditDescription->setGeometry(QRect(260, 240, 113, 28));
        pushButton_2 = new QPushButton(AjoutEpargne);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(270, 330, 91, 31));

        retranslateUi(AjoutEpargne);
        QObject::connect(pushButton, SIGNAL(clicked()), AjoutEpargne, SLOT(slotAjoutEpargne()));
        QObject::connect(pushButton_2, SIGNAL(clicked()), AjoutEpargne, SLOT(close()));

        QMetaObject::connectSlotsByName(AjoutEpargne);
    } // setupUi

    void retranslateUi(QDialog *AjoutEpargne)
    {
        AjoutEpargne->setWindowTitle(QCoreApplication::translate("AjoutEpargne", "AjoutEpargne", nullptr));
        pushButton->setText(QCoreApplication::translate("AjoutEpargne", "Ajouter", nullptr));
        label->setText(QCoreApplication::translate("AjoutEpargne", "Num\303\251ro de votre compte :", nullptr));
        label_2->setText(QCoreApplication::translate("AjoutEpargne", "Taux Interet :", nullptr));
        label_3->setText(QCoreApplication::translate("AjoutEpargne", "Solde :", nullptr));
        label_4->setText(QCoreApplication::translate("AjoutEpargne", "Description :", nullptr));
        label_5->setText(QString());
        pushButton_2->setText(QCoreApplication::translate("AjoutEpargne", "Retour", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AjoutEpargne: public Ui_AjoutEpargne {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AJOUTEPARGNE_H
