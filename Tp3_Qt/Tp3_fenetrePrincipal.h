/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/qtFiles/form.h to edit this template
 */

/* 
 * File:   Tp3_fenetrePrincipal.h
 * Author: etudiant
 *
 * Created on 21 avril 2025, 19 h 17
 */

#ifndef _TP3_FENETREPRINCIPAL_H
#define _TP3_FENETREPRINCIPAL_H

#include "ui_Tp3_fenetrePrincipal.h"
#include "AjoutCheque.h"
#include "AjoutEpargne.h"
#include "SupprimerCompte.h"
#include "Client.h"
#include "Cheque.h"
#include "Epargne.h"
#include "CompteAbsentException.h"
#include "CompteDejaPresentException.h"

class Tp3_fenetrePrincipal : public QMainWindow
{
  Q_OBJECT
public:
  Tp3_fenetrePrincipal ();
  virtual ~Tp3_fenetrePrincipal ();


private slots:
  void slotAjoutEpargne ();
  void slotAjoutCheque ();
private:
  Ui::Tp3_fenetrePrincipal widget;
};

#endif /* _TP3_FENETREPRINCIPAL_H */
