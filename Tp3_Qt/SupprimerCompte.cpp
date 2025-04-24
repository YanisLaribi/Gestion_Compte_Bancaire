/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/qtFiles/form.cc to edit this template
 */

/*
 * File:   SupprimerCompte.cpp
 * Author: Laribi et Haroun
 *
 * Created on 21 avril 2025, 20 h 54
 */

/** 
 * \brief Implémentation de la classe SupprimerCompte pour la suppression d'un compte bancaire.
 * 
 * Cette classe fournit une interface utilisateur permettant à un client de saisir un numéro
 * de compte à supprimer. Une vérification minimale est effectuée pour s'assurer que le numéro
 * est valide avant de procéder.
 */

#include "SupprimerCompte.h"
#include <qmessagebox.h>
#include "Client.h"

/**
 * \brief Constructeur de la classe SupprimerCompte.
 * 
 * Initialise l'interface utilisateur Qt pour la suppression d’un compte.
 */
SupprimerCompte::SupprimerCompte ()
{
  widget.setupUi (this);
}

/**
 * \brief Récupère le numéro de compte saisi par l'utilisateur.
 * 
 * \return Numéro de compte (int).
 */
int SupprimerCompte::reqCompte () const
{
  return widget.lineEdit->text ().toInt ();
}

/**
 * \brief Slot appelé pour tenter de supprimer un compte.
 * 
 * Vérifie que le numéro de compte est valide (non négatif). Si la validation est réussie,
 * le dialogue est accepté via \c accept(). Sinon, un message d'erreur est affiché.
 */
void SupprimerCompte::slotSupprimerCompte ()
{
  if (reqCompte () < 0)
  {
    QString message = "Numéro de Compte Invalide";
    QMessageBox::information (this, "ERREUR", message);
    return;
  }
  accept();
}

/**
 * \brief Destructeur de la classe SupprimerCompte.
 */
SupprimerCompte::~SupprimerCompte () {}
