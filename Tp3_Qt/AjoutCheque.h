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


/**
 * \brief Déclaration de la classe AjoutCheque.
 * Cette classe représente une boîte de dialogue permettant à l'utilisateur
 * d'ajouter un compte chèque en saisissant les informations nécessaires.
 */

#ifndef _AJOUTCHEQUE_H
#define _AJOUTCHEQUE_H

#include "ui_AjoutCheque.h"

/**
 * \class AjoutCheque
 * \brief Fenêtre de dialogue pour l'ajout d’un compte chèque.
 */

class AjoutCheque : public QDialog
{
  Q_OBJECT

public:
  
  AjoutCheque ();

  virtual ~AjoutCheque ();

  /**
   * \brief Retourne le numéro de compte saisi.
   * \return Numéro de compte (int).
   */
  int reqCompte () const;

  /**
   * \brief Retourne le taux d’intérêt saisi.
   * \return Taux d’intérêt (double).
   */
  double reqTauxInteret () const;

  /**
   * \brief Retourne le solde saisi.
   * \return Solde du compte (float).
   */
  float reqSolde () const;

  /**
   * \brief Retourne la description du compte.
   * \return Description (std::string).
   */
  const std::string reqDesc () const;

  /**
   * \brief Retourne le nombre de transactions mensuelles.
   * \return Nombre de transactions (int).
   */
  int reqNombreTransaction () const;

  /**
   * \brief Retourne le taux minimum autorisé.
   * \return Taux minimum (double).
   */
  double reqTauxMin () const;

private slots:

  /**
   * \brief Slot déclenché à la tentative d’ajout du compte chèque.
   * 
   * Valide les informations et affiche des messages d’erreur si nécessaire.
   */

  void slotAjoutCheque ();


private:
  Ui::AjoutCheque widget;
};

#endif /* _AJOUTCHEQUE_H */
