/********************************************************************************
** Form generated from reading UI file 'Tp3_fenetrePrincipal.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TP3_FENETREPRINCIPAL_H
#define UI_TP3_FENETREPRINCIPAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Tp3_fenetrePrincipal
{
public:
    QAction *actionEpargne;
    QAction *actionCheque;
    QAction *actionSupprimerCompte;
    QAction *actionAjouterCompte;
    QAction *actionQuitter;
    QAction *actionCheque_2;
    QAction *actionEpargne_2;
    QWidget *centralwidget;
    QPlainTextEdit *textEditReleves;
    QMenuBar *menubar;
    QMenu *menuMenu;
    QMenu *menuAjouter_Compte;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Tp3_fenetrePrincipal)
    {
        if (Tp3_fenetrePrincipal->objectName().isEmpty())
            Tp3_fenetrePrincipal->setObjectName(QString::fromUtf8("Tp3_fenetrePrincipal"));
        Tp3_fenetrePrincipal->resize(911, 566);
        actionEpargne = new QAction(Tp3_fenetrePrincipal);
        actionEpargne->setObjectName(QString::fromUtf8("actionEpargne"));
        actionCheque = new QAction(Tp3_fenetrePrincipal);
        actionCheque->setObjectName(QString::fromUtf8("actionCheque"));
        actionSupprimerCompte = new QAction(Tp3_fenetrePrincipal);
        actionSupprimerCompte->setObjectName(QString::fromUtf8("actionSupprimerCompte"));
        actionAjouterCompte = new QAction(Tp3_fenetrePrincipal);
        actionAjouterCompte->setObjectName(QString::fromUtf8("actionAjouterCompte"));
        actionQuitter = new QAction(Tp3_fenetrePrincipal);
        actionQuitter->setObjectName(QString::fromUtf8("actionQuitter"));
        actionCheque_2 = new QAction(Tp3_fenetrePrincipal);
        actionCheque_2->setObjectName(QString::fromUtf8("actionCheque_2"));
        actionEpargne_2 = new QAction(Tp3_fenetrePrincipal);
        actionEpargne_2->setObjectName(QString::fromUtf8("actionEpargne_2"));
        centralwidget = new QWidget(Tp3_fenetrePrincipal);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        textEditReleves = new QPlainTextEdit(centralwidget);
        textEditReleves->setObjectName(QString::fromUtf8("textEditReleves"));
        textEditReleves->setGeometry(QRect(60, 30, 801, 481));
        textEditReleves->setReadOnly(true);
        Tp3_fenetrePrincipal->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Tp3_fenetrePrincipal);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 911, 22));
        menuMenu = new QMenu(menubar);
        menuMenu->setObjectName(QString::fromUtf8("menuMenu"));
        menuAjouter_Compte = new QMenu(menuMenu);
        menuAjouter_Compte->setObjectName(QString::fromUtf8("menuAjouter_Compte"));
        Tp3_fenetrePrincipal->setMenuBar(menubar);
        statusbar = new QStatusBar(Tp3_fenetrePrincipal);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Tp3_fenetrePrincipal->setStatusBar(statusbar);

        menubar->addAction(menuMenu->menuAction());
        menuMenu->addAction(menuAjouter_Compte->menuAction());
        menuMenu->addAction(actionSupprimerCompte);
        menuMenu->addAction(actionQuitter);
        menuAjouter_Compte->addAction(actionCheque_2);
        menuAjouter_Compte->addAction(actionEpargne_2);

        retranslateUi(Tp3_fenetrePrincipal);
        QObject::connect(actionCheque_2, SIGNAL(triggered()), Tp3_fenetrePrincipal, SLOT(slotAjoutCheque()));
        QObject::connect(actionEpargne_2, SIGNAL(triggered()), Tp3_fenetrePrincipal, SLOT(slotAjoutEpargne()));
        QObject::connect(actionSupprimerCompte, SIGNAL(triggered()), Tp3_fenetrePrincipal, SLOT(slotSupprimerCompte()));
        QObject::connect(actionQuitter, SIGNAL(triggered()), Tp3_fenetrePrincipal, SLOT(close()));

        QMetaObject::connectSlotsByName(Tp3_fenetrePrincipal);
    } // setupUi

    void retranslateUi(QMainWindow *Tp3_fenetrePrincipal)
    {
        Tp3_fenetrePrincipal->setWindowTitle(QCoreApplication::translate("Tp3_fenetrePrincipal", "Tp3_fenetrePrincipal", nullptr));
        actionEpargne->setText(QCoreApplication::translate("Tp3_fenetrePrincipal", "Epargne", nullptr));
        actionCheque->setText(QCoreApplication::translate("Tp3_fenetrePrincipal", "Cheque", nullptr));
        actionSupprimerCompte->setText(QCoreApplication::translate("Tp3_fenetrePrincipal", "Supprimer Compte", nullptr));
        actionAjouterCompte->setText(QCoreApplication::translate("Tp3_fenetrePrincipal", "AjouterCompte", nullptr));
        actionQuitter->setText(QCoreApplication::translate("Tp3_fenetrePrincipal", "Quitter", nullptr));
        actionCheque_2->setText(QCoreApplication::translate("Tp3_fenetrePrincipal", "Cheque", nullptr));
        actionEpargne_2->setText(QCoreApplication::translate("Tp3_fenetrePrincipal", "Epargne", nullptr));
        menuMenu->setTitle(QCoreApplication::translate("Tp3_fenetrePrincipal", "Menu", nullptr));
        menuAjouter_Compte->setTitle(QCoreApplication::translate("Tp3_fenetrePrincipal", "Ajouter Compte", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Tp3_fenetrePrincipal: public Ui_Tp3_fenetrePrincipal {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TP3_FENETREPRINCIPAL_H
