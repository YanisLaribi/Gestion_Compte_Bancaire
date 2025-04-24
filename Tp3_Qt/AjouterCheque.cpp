/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/qtFiles/form.cc to edit this template
 */

/*
 * File:   AjoutCheque.cpp
 * Author: Laribi et Haroun
 *
 * Created on 21 avril 2025, 20 h 23
 */

 /** 
 * \brief Implémentation de la classe AjoutCheque pour la gestion de comptes chèques.
 * 
 * Cette classe fait partie d'une interface utilisateur permettant l'ajout d'un compte chèque,
 * en vérifiant que les données saisies sont valides selon certaines règles métier.
 */

#include "AjoutCheque.h"
#include <qmessagebox.h>
#include <string>

/**
 * \brief Constructeur de la classe AjoutCheque.
 * 
 * Initialise l'interface utilisateur à partir de la définition de l'UI Qt.
 */
AjoutCheque::AjoutCheque ()
{
  widget.setupUi (this);
}

/**
 * \brief Retourne le numéro de compte saisi.
 * 
 * \return Numéro de compte (int).
 */
int AjoutCheque::reqCompte () const
{
  return widget.lineEditComte->text ().toInt ();
}

/**
 * \brief Retourne le taux d'intérêt saisi.
 * 
 * \return Taux d'intérêt (double).
 */
double AjoutCheque::reqTauxInteret () const
{
  return widget.lineEditTaux->text ().toDouble ();
}

/**
 * \brief Retourne le solde saisi.
 * 
 * \return Solde du compte (float).
 */
float AjoutCheque::reqSolde () const
{
  return widget.lineEditSolde->text ().toFloat ();
}

/**
 * \brief Retourne la description saisie.
 * 
 * \return Description du compte (std::string).
 */
const std::string AjoutCheque::reqDesc () const
{
  return widget.lineEditDesc->text ().toStdString ();
}

/**
 * \brief Retourne le nombre de transactions mensuelles.
 * 
 * \return Nombre de transactions (int).
 */
int AjoutCheque::reqNombreTransaction () const
{
  return widget.lineEditTransactions->text ().toInt ();
}

/**
 * \brief Retourne le taux d'intérêt minimum.
 * 
 * \return Taux minimum (double).
 */
double AjoutCheque::reqTauxMin () const
{
  return widget.lineEditTauxMin->text ().toDouble ();
}

/**
 * \brief Slot de validation et d'ajout du compte chèque.
 * 
 * Vérifie les informations saisies par l'utilisateur :
 * - Le numéro de compte ne doit pas être négatif.
 * - Le taux d'intérêt doit être supérieur ou égal au taux minimum.
 * - Le solde doit être positif ou nul.
 * - La description ne doit pas être vide.
 * - Le taux minimum doit être supérieur à 0.1%.
 * - Le nombre de transactions doit être compris entre 0 et 40.
 * 
 * Si toutes les validations sont réussies, le dialogue est accepté avec \c accept().
 */
void AjoutCheque::slotAjoutCheque ()
{
  if (reqCompte () < 0)
  {
    QString message = "Numéro de Compte Invalide";
    QMessageBox::information (this, "ERREUR", message);
    return;
  }

  if ((reqTauxInteret ()/100) < (reqTauxMin()/100))
  {
    QString message = "Taux d'intérêt doit être supérieur ou égal au taux minimum";
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

  if ((reqTauxMin ()/100) < 0.001)
  {
    QString message = "Taux d'intérêt minimum doit être supérieur ou égal à 0.1";
    QMessageBox::information (this, "ERREUR", message);
    return;
  }

  if (reqNombreTransaction () > 40 || reqNombreTransaction () < 0)
  {
    QString message = "Le nombre de transactions doit être entre 0 et 40 inclusivement.";
    QMessageBox::information (this, "ERREUR", message);
    return;
  }

  accept ();
}

/**
 * \brief Destructeur de la classe AjoutCheque.
 */
AjoutCheque::~AjoutCheque () { }
