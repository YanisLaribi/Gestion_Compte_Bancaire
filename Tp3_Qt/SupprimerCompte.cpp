/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/qtFiles/form.cc to edit this template
 */

/*
 * File:   SupprimerCompte.cpp
 * Author: etudiant
 *
 * Created on 21 avril 2025, 20 h 54
 */

#include "SupprimerCompte.h"
#include <qmessagebox.h>
#include "Client.h"

SupprimerCompte::SupprimerCompte ()
{
  widget.setupUi (this);
}

int
SupprimerCompte::reqCompte () const
{
  return widget.lineEdit->text ().toInt ();
}

void
SupprimerCompte::slotSupprimerCompte ()
{
  if (reqCompte () < 0)
    {
      QString message = "Numéro de Compte Invalide";
      QMessageBox::information (this, "ERREUR", message);
      return;
    }
  accept();
}
SupprimerCompte::~SupprimerCompte (){}
