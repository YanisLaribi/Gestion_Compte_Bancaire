/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/qtFiles/form.h to edit this template
 */

/* 
 * File:   AjoutEpargne.h
 * Author: etudiant
 *
 * Created on 21 avril 2025, 20 h 48
 */

#ifndef _AJOUTEPARGNE_H
#define _AJOUTEPARGNE_H

#include "ui_AjoutEpargne.h"

class AjoutEpargne : public QDialog
{
  Q_OBJECT
public:
  AjoutEpargne ();
  virtual ~AjoutEpargne ();
private:
  Ui::AjoutEpargne widget;
};

#endif /* _AJOUTEPARGNE_H */
