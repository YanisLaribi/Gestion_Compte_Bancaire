/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/qtFiles/form.cc to edit this template
 */

/** 
 * File:   CompteAbsentException.h
 * Author: etudiant
 * Created on 20 avril 2025, 22 h 21
 */

 /**
  * \brief Implémentation de la classe AjoutEpargne qui permet d'ajouter un compte d'épargne en validant les informations saisies par l'utilisateur.
  * Cette classe fait partie de l'interface graphique d'une application de gestion bancaire utilisant Qt.
  */

#include "AjoutEpargne.h"
#include <qmessagebox.h>
#include <string>

/**
 * \brief Constructeur de la classe AjoutEpargne.
 * 
 * Initialise l'interface graphique à partir du fichier de conception (UI).
 */
AjoutEpargne::AjoutEpargne ()
{
    widget.setupUi (this);
}

/**
 * \brief Récupère le numéro de compte saisi par l'utilisateur.
 * 
 * \return Le numéro de compte sous forme d'entier.
 */
int AjoutEpargne::reqCompte () const
{
    return widget.lineEditCompte->text ().toInt ();
}

/**
 * \brief Récupère le taux d'intérêt saisi par l'utilisateur.
 * 
 * \return Le taux d'intérêt sous forme de nombre à virgule flottante (double).
 */
double AjoutEpargne::reqTauxInteret () const
{
    return widget.lineEditTaux->text ().toDouble ();
}

/**
 * \brief Récupère le solde saisi par l'utilisateur.
 * 
 * \return Le solde sous forme de nombre à virgule flottante (float).
 */
float AjoutEpargne::reqSolde () const
{
    return widget.lineEditSolde->text ().toFloat ();
}

/**
 * \brief Récupère la description du compte saisie par l'utilisateur.
 * 
 * \return La description sous forme de chaîne de caractères (std::string).
 */
const std::string AjoutEpargne::reqDesc () const
{
    return widget.lineEditDescription->text ().toStdString ();
}

/**
 * \brief Slot permettant de valider l'ajout d'un compte d'épargne.
 * 
 * Vérifie les données saisies par l'utilisateur et affiche des messages d'erreur
 * en cas de saisie invalide.
 * 
 * - Le numéro de compte ne doit pas être négatif.
 * - Le taux d'intérêt doit être compris entre 0.1 et 3.5.
 * - Le solde doit être positif ou nul.
 * - La description du compte ne doit pas être vide.
 * 
 * Si toutes les données sont valides, la fonction `accept()` est appelée pour valider l'ajout.
 */
void AjoutEpargne::slotAjoutEpargne ()
{
    if (reqCompte () < 0)
    {
        QString message = "Numéro de Compte Invalide";
        QMessageBox::information (this, "ERREUR", message);
        return;
    }

    if (((reqTauxInteret ()) < 0.1) || ((reqTauxInteret ()) > 3.5))
    {
        QString message = "Taux d'intérêt doit être entre 0.1 et 3.5";
        QMessageBox::information (this, "ERREUR", message);
        return;
    }

    if (reqSolde () < 0)
    {
        QString message = "Solde doit être positif ou nul";
        QMessageBox::information (this, "ERREUR", message);
        return;
    }

    if (reqDesc ().empty ())
    {
        QString message = "Remplissez le champ de description";
        QMessageBox::information (this, "ERREUR", message);
        return;
    }

    accept ();
}

/**
 * \brief Destructeur de la classe AjoutEpargne.
 * 
 * Libère les ressources allouées par l'interface graphique.
 */
AjoutEpargne::~AjoutEpargne () { }
