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

Tp3_fenetrePrincipal::Tp3_fenetrePrincipal ()
{
  widget.setupUi (this);
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
        }

      catch (CompteDejaPresentException& e)
        {
          QString message = (e.what ());

          QMessageBox::information (this, "ERREUR", message);
        }
    }
}

void Tp3_fenetrePrincipal::slotAjoutCheque()
{
  AjoutCheque ec;
  if (ec.exec ())
    {
      try
        {
          bancaire::Cheque ecTest (ec.reqCompte (), ec.reqTauxInteret (), ec.reqSolde (), ec.reqNombreTransaction (), ec.reqTauxMin(), ec.reqDesc ());
        }

      catch (CompteDejaPresentException& e)
        {
          QString message = (e.what ());

          QMessageBox::information (this, "ERREUR", message);
        }
    }
}

Tp3_fenetrePrincipal::~Tp3_fenetrePrincipal () { }
