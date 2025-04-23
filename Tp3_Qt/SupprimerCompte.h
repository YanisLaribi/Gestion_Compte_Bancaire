/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/qtFiles/form.h to edit this template
 */

/* 
 * File:   SupprimerCompte.h
 * Author: etudiant
 *
 * Created on 21 avril 2025, 20 h 54
 */

#ifndef _SUPPRIMERCOMPTE_H
#define _SUPPRIMERCOMPTE_H

#include "ui_SupprimerCompte.h"
#include "Client.h"

class SupprimerCompte : public QDialog
{
  Q_OBJECT
public:
  SupprimerCompte ();
  virtual ~SupprimerCompte ();
  
  int reqCompte () const;
  
  private slots:
  void slotSupprimerCompte ();

private:
  Ui::SupprimerCompte widget;

};

#endif /* _SUPPRIMERCOMPTE_H */
