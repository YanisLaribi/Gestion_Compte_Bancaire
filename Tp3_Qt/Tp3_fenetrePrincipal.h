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

/**
 *\brief Déclaration de la classe Tp3_fenetrePrincipal.
 * 
 * Cette classe représente la fenêtre principale de l'application bancaire.
 * Elle permet l'affichage des relevés de comptes, l'ajout de comptes épargne ou chèque,
 * ainsi que la suppression de comptes. Elle utilise les classes dérivées de QWidget pour 
 * recueillir les informations utilisateur.
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
#include "CompteException.h"
#include "ContratException.h"

/**
 * \class Tp3_fenetrePrincipal
 * \brief Fenêtre principale de l'application bancaire.
 */

class Tp3_fenetrePrincipal : public QMainWindow
{
  Q_OBJECT
public:
  Tp3_fenetrePrincipal ();
  virtual ~Tp3_fenetrePrincipal ();
  void afficherReleves ();

private slots:
  /**
   * \brief Slot appelé lors de l'ajout d'un compte épargne.
   */
  void slotAjoutEpargne ();

  /**
   * \brief Slot appelé lors de l'ajout d'un compte chèque.
   */
  void slotAjoutCheque ();

  /**
   * \brief Slot appelé lors de la suppression d'un compte.
   */
  void slotSupprimerCompte ();
private:
  Ui::Tp3_fenetrePrincipal widget;
  bancaire::Client m_client;
};

#endif /* _TP3_FENETREPRINCIPAL_H */
