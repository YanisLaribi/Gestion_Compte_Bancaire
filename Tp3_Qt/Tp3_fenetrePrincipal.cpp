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

#include "Tp3_fenetrePrincipal.h"
#include <qmessagebox.h>
#include <QMessageBox>

Tp3_fenetrePrincipal::Tp3_fenetrePrincipal ()
: m_client (1234, "Dupont", "Jean", "4181234567", util::Date (1, 1, 2000))

{
  widget.setupUi (this);
  afficherReleves ();
}

void
Tp3_fenetrePrincipal::afficherReleves ()
{
  widget.textEditReleves->setPlainText (QString::fromStdString (m_client.reqReleves ()));
}

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

        }

      catch (CompteDejaPresentException& e)
        {
          QString message = (e.what ());

          QMessageBox::information (this, "ERREUR", message);
          return;
        }
      catch (PreconditionException& e)
        {
          QString message = ("Erreur Fatale! Assurez-vous d'avoir tout remplis!");

          QMessageBox::information (this, "ERREUR", message);
          return;
        }
    }
}

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
        }

      catch (CompteDejaPresentException& e)
        {
          QString message = (e.what ());

          QMessageBox::information (this, "ERREUR", message);
          return;
        }
      catch (PreconditionException& e)
        {
          QString message = ("Erreur Fatale! Assurez-vous d'avoir tout remplis!");

          QMessageBox::information (this, "ERREUR", message);
          return;
        }
    }
}

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
        }
      catch (const CompteAbsentException& e)
        {
          QMessageBox::critical (this, "Erreur", e.what ());
          return;
        }
    }

}

Tp3_fenetrePrincipal::~Tp3_fenetrePrincipal () { }
