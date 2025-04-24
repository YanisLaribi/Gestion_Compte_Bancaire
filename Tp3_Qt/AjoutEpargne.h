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

/** 
 * \brief Déclaration de la classe AjoutEpargne.
 * 
 * Cette classe fournit une interface utilisateur pour l'ajout d’un compte épargne.
 * Elle permet à l’utilisateur de saisir les informations nécessaires à la création
 * d’un compte épargne, comme le numéro de compte, le taux d’intérêt, le solde et la description.
 */

#ifndef _AJOUTEPARGNE_H
#define _AJOUTEPARGNE_H

#include "ui_AjoutEpargne.h"

/**
 * \class AjoutEpargne
 * \brief Boîte de dialogue Qt pour la création d’un compte épargne.
 */ 

class AjoutEpargne : public QDialog
{
  Q_OBJECT
public:
  AjoutEpargne ();
  virtual ~AjoutEpargne ();

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
   * \brief Retourne la description du compte épargne.
   * \return Description (std::string).
   */
  const std::string reqDesc () const;

private slots:
  
 /**
   * \brief Slot appelé lorsqu'on tente d'ajouter un compte épargne.
   * 
   * Effectue des validations sur les champs saisis par l'utilisateur.
   * Affiche des messages d’erreur si nécessaire.
   */
  
  void slotAjoutEpargne ();

private:
  Ui::AjoutEpargne widget;
};

#endif /* _AJOUTEPARGNE_H */
