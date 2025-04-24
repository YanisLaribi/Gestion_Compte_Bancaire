/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/qtFiles/form.cc to edit this template
 */

/*
 * File:   Tp3_fenetrePrincipal.cpp
 * Author: etudiant
 *
 * Created on 21 avril 2025, 19 h 17
 */

/**
 * \brief Implémentation de la classe Tp3_fenetrePrincipal, la fenêtre principale de l'application bancaire.
 * 
 * Cette classe gère l'affichage des relevés de comptes, l'ajout de comptes épargne ou chèques,
 * ainsi que la suppression de comptes existants. Elle interagit avec l'objet Client pour effectuer
 * les opérations bancaires.
 */

#include "Tp3_fenetrePrincipal.h"
#include <qmessagebox.h>
#include <QMessageBox>

using namespace bancaire;

/**
 * \brief Constructeur de la classe Tp3_fenetrePrincipal.
 * 
 * Initialise l'interface graphique, crée un client par défaut et affiche ses relevés.
 */
Tp3_fenetrePrincipal::Tp3_fenetrePrincipal ()
: m_client (1234, "Dupont", "Jean", "4181234567", util::Date (1, 1, 2000))
{
  widget.setupUi (this);
  afficherReleves ();
}

/**
 * \brief Affiche les relevés des comptes du client dans le champ texte.
 */
void
Tp3_fenetrePrincipal::afficherReleves ()
{
  widget.textEditReleves->setPlainText (QString::fromStdString (m_client.reqReleves ()));
}

/**
 * \brief Slot déclenché lors de l'ajout d'un compte épargne.
 * 
 * Affiche une fenêtre modale pour saisir les informations du nouveau compte épargne.
 * Si les informations sont valides, crée un objet \c Epargne et l'ajoute au client.
 * Gère les exceptions suivantes :
 * -CompteDejaPresentException si le compte existe déjà.
 * -PreconditionException si les données saisies sont invalides.
 */
void
Tp3_fenetrePrincipal::slotAjoutEpargne ()
{
  AjoutEpargne ep;
  if (ep.exec ())
    {
      try
        {
          bancaire::Epargne epTest (ep.reqCompte (), ep.reqTauxInteret (), ep.reqSolde (), ep.reqDesc ());
          m_client.ajouterCompte (epTest);
          widget.textEditReleves->setPlainText (QString::fromStdString (m_client.reqReleves ()));
          return;
        }
      catch (CompteDejaPresentException& e)
        {
          QString message = (e.what ());
          QMessageBox::information (this, "ERREUR", message);
          return;
        }
      catch (PreconditionException& e)
        {
          QString message = ("Erreur Fatale! Vous ne remplissez-pas les préconditions pour la création d'un compte!");
          QMessageBox::information (this, "ERREUR", message);
          return;
        }
      catch (PostconditionException& e)
        {
          QString message = (e.what ());
          QMessageBox::information (this, "ERREUR", message);
          return;
        }
    }
}

/**
 * \brief Slot déclenché lors de l'ajout d'un compte chèque.
 * 
 * Affiche une fenêtre modale pour saisir les informations du compte chèque.
 * Si les données sont valides, crée un objet \c Cheque et l'ajoute au client.
 * Gère les exceptions suivantes :
 * -CompteDejaPresentException si le compte existe déjà.
 * -PreconditionException si des préconditions sont violées.
 */
void
Tp3_fenetrePrincipal::slotAjoutCheque ()
{
  AjoutCheque ec;
  if (ec.exec ())
    {
      try
        {
          bancaire::Cheque ecTest (ec.reqCompte (), ec.reqTauxInteret (), ec.reqSolde (), ec.reqNombreTransaction (), ec.reqTauxMin (), ec.reqDesc ());
          m_client.ajouterCompte (ecTest);
          widget.textEditReleves->setPlainText (QString::fromStdString (m_client.reqReleves ()));
          return;
        }
      catch (CompteDejaPresentException& e)
        {
          QString message = (e.what ());
          QMessageBox::information (this, "ERREUR", message);
          return;
        }
      catch (PreconditionException& e)
        {
          QString message = (e.what ());
          QMessageBox::information (this, "ERREUR", message);
          return;
        }
      catch (PostconditionException& e)
        {
          QString message = (e.what ());
          QMessageBox::information (this, "ERREUR", message);
          return;
        }
    }
}

/**
 * \brief Slot déclenché lors de la suppression d’un compte.
 * 
 * Ouvre une boîte de dialogue pour saisir le numéro de compte à supprimer.
 * Supprime le compte du client si celui-ci existe.
 * Gère l'exception suivante :
 * -CompteAbsentException si le compte à supprimer n'existe pas.
 */
void
Tp3_fenetrePrincipal::slotSupprimerCompte ()
{
  SupprimerCompte sc;
  if (sc.exec ())
    {
      try
        {
          m_client.supprimerCompte (sc.reqCompte ());
          widget.textEditReleves->setPlainText (QString::fromStdString (m_client.reqReleves ()));
          return;
        }
      catch (const CompteAbsentException& e)
        {
          QMessageBox::critical (this, "Erreur", e.what ());
          return;
        }
    }
}

/**
 * \brief Destructeur de la classe Tp3_fenetrePrincipal.
 */
Tp3_fenetrePrincipal::~Tp3_fenetrePrincipal () { }
