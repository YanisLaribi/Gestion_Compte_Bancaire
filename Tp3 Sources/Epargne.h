/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   Epargne.h
 * Author: etudiant
 *
 * Created on 3 avril 2025, 13 h 10
 */

/**
 * \file Epargne.h
 * \brief Déclaration de la classe Epargne dérivée de Compte
 */

#ifndef EPARGNE_H
#define EPARGNE_H

#include "Compte.h"
#include <memory>
#include <sstream>

namespace bancaire
{

  /**
   * \class Epargne
   * \brief Représente un compte d'épargne avec un taux d'intérêt entre 0.1% et 3.5%.
   *
   * Un compte épargne ne peut jamais avoir un solde négatif.
   * Il hérite des attributs et méthodes de la classe de base Compte.
   */
  class Epargne : public Compte
  {
  public:

    /**
     * \brief Constructeur du compte épargne
     * \param[in] p_noCompte Numéro du compte (> 0)
     * \param[in] p_tauxInteret Taux d'intérêt entre 0.001 et 0.035 inclus
     * \param[in] p_solde Solde initial (>= 0)
     * \param[in] p_description Description du compte (par défaut "Epargne")
     * \pre p_tauxInteret entre 0.001 et 0.035, p_solde >= 0
     * \post Le compte est construit avec les valeurs données
     */
    Epargne(int p_noCompte, double p_tauxInteret, float p_solde,
            const std::string& p_description = "Epargne");

    /**
     * \brief Calcule les intérêts selon la formule : solde * taux
     * \return Le montant des intérêts
     */
    virtual double calculerInteret() const override;

    /**
     * \brief Retourne une copie allouée dynamiquement du compte courant
     * \return Un pointeur unique vers une copie
     */
    virtual std::unique_ptr<Compte> clone() const override;

    /**
     * \brief Retourne une chaîne formatée avec les détails du compte
     * \return Chaîne contenant les informations du compte épargne
     */
    virtual std::string reqCompteFormate() const;

    /**
     * \brief Mutateur : assigne un nouveau solde (doit être >= 0)
     * \param[in] p_solde le nouveau solde à assigner
     * \pre p_solde >= 0
     */
    void asgSolde(float p_solde);

    /**
     * \brief Mutateur : assigne un nouveau taux d'intérêt (doit être dans [0.001, 0.035])
     * \param[in] p_tauxInteret le nouveau taux à assigner
     * \pre taux entre 0.001 et 0.035 inclus
     */
    void asgTauxInteret(double p_tauxInteret);

  private:
    /**
     * \brief Vérifie les invariants de la classe
     * \invariant taux d'intérêt dans [0.001, 0.035], solde >= 0
     */
    void verifieInvariant() const;
  };

} // namespace bancaire

#endif

