/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/qtFiles/form.cc to edit this template
 */

/*
 * File:   AjoutEpargne.cpp
 * Author: etudiant
 *
 * Created on 21 avril 2025, 20 h 48
 */

#include "AjoutEpargne.h"
#include <qmessagebox.h>
#include <string>

AjoutEpargne::AjoutEpargne ()
{
  widget.setupUi (this);
}

int
AjoutEpargne::reqCompte () const
{
  return widget.lineEditCompte->text ().toInt ();
}

double
AjoutEpargne::reqTauxInteret () const
{
  return widget.lineEditTaux->text ().toDouble ();
}

float
AjoutEpargne::reqSolde () const
{
  return widget.lineEditSolde->text ().toFloat ();
}

const std::string
AjoutEpargne::reqDesc () const
{
  return widget.lineEditDescription->text ().toStdString ();
}

void
AjoutEpargne::slotAjoutEpargne ()
{
  if (reqCompte () < 0)
    {
      QString message = "Numéro de Compte Invalide";
      QMessageBox::information (this, "ERREUR", message);
      return;
    }

  if (((reqTauxInteret ())< 0.1) or ((reqTauxInteret ()) > 3.5))
    {
      QString message = "Taux d'interet doit être entre 0.1 et 3.5";
      QMessageBox::information (this, "ERREUR", message);
      return;
    }

  if (reqSolde () < 0)
    {
      QString message = "Solde doit être positive ou nul";
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

AjoutEpargne::~AjoutEpargne () { }
