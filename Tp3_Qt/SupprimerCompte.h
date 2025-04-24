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

 /**
  * \brief Déclaration de la classe SupprimerCompte.
  * Cette classe fournit une interface utilisateur permettant de saisir un numéro
  * de compte bancaire à supprimer. Elle effectue également la validation de base
  * sur le champ saisi.
  */
 
#ifndef _SUPPRIMERCOMPTE_H
#define _SUPPRIMERCOMPTE_H

#include "ui_SupprimerCompte.h"
#include "Client.h"

/**
 * \class SupprimerCompte
 * \brief Boîte de dialogue Qt pour supprimer un compte bancaire.
 */

class SupprimerCompte : public QDialog
{
  Q_OBJECT
public:
  SupprimerCompte ();
  virtual ~SupprimerCompte ();
  
/**
   * \brief Retourne le numéro de compte saisi par l’utilisateur.
   * \return Numéro de compte (int).
   */
  int reqCompte () const;
  
  private slots:
  /**
   * \brief Slot appelé lors de la tentative de suppression du compte.
   * 
   * Vérifie que le numéro de compte est valide (positif).
   */
  void slotSupprimerCompte ();

private:
  Ui::SupprimerCompte widget;

};

#endif /* _SUPPRIMERCOMPTE_H */
