/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/qtFiles/form.cc to edit this template
 */

/*
 * File:   AjoutCheque.cpp
 * Author: etudiant
 *
 * Created on 21 avril 2025, 20 h 23
 */

#include "AjoutCheque.h"
#include <qmessagebox.h>
#include <string>

AjoutCheque::AjoutCheque ()
{
  widget.setupUi (this);
}

int
AjoutCheque::reqCompte () const
{
  return widget.lineEditComte->text ().toInt ();
}

double
AjoutCheque::reqTauxInteret () const
{
  return widget.lineEditTaux->text ().toDouble ();
}

float
AjoutCheque::reqSolde () const
{
  return widget.lineEditSolde->text ().toFloat ();
}

const std::string
AjoutCheque::reqDesc () const
{
  return widget.lineEditDesc->text ().toStdString ();
}

int
AjoutCheque::reqNombreTransaction () const
{
  return widget.lineEditTransactions ->text ().toInt ();
}

double
AjoutCheque::reqTauxMin () const
{
  return widget.lineEditTauxMin->text ().toDouble ();
};

void
AjoutCheque::slotAjoutCheque ()
{
  if (reqCompte () < 0)
    {
      QString message = "Numéro de Compte Invalide";
      QMessageBox::information (this, "ERREUR", message);
      return;
    }

  if (reqTauxInteret () < reqTauxMin ())
    {
      QString message = "Taux d'interet doit être supérieur au taux minimum";
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


  if (reqTauxMin () < 0.001)
    {
      QString message = "Taux d'interet minimum doit être supérieur à 0.001";
      QMessageBox::information (this, "ERREUR", message);
      return;
    }
  
   if (reqNombreTransaction () > 40 or reqNombreTransaction () < 0)
    {
      QString message = "Votre nombre de transaction doit être inférieur à 40 ou supérieur à 0";
      QMessageBox::information (this, "ERREUR", message);
      return;
    }


  accept ();
};

AjoutCheque::~AjoutCheque () { }
