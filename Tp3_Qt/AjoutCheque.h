/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/qtFiles/form.h to edit this template
 */

/* 
 * File:   AjoutCheque.h
 * Author: etudiant
 *
 * Created on 21 avril 2025, 20 h 23
 */

#ifndef _AJOUTCHEQUE_H
#define _AJOUTCHEQUE_H

#include "ui_AjoutCheque.h"

class AjoutCheque : public QDialog
{
  Q_OBJECT
public:
  AjoutCheque ();
  virtual ~AjoutCheque ();

  int reqCompte () const;

  double reqTauxInteret () const;

  float reqSolde () const;

  const std::string reqDesc () const;
  
  int reqNombreTransaction() const;
  
  double reqTauxMin() const;

private slots:
  void slotAjoutCheque ();


private:
  Ui::AjoutCheque widget;
};

#endif /* _AJOUTCHEQUE_H */
