/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Cheque.h
 * Author: etudiant
 *
 * Created on 3 avril 2025, 14 h 39
 */

/**
 * \file Cheque.h
 * \brief Déclaration de la classe Cheque, dérivée de Compte
 */

#ifndef CHEQUE_H
#define CHEQUE_H

#include "Compte.h"
#include <memory>
#include <sstream>

namespace bancaire
{

  /**
   * \class Cheque
   * \brief Représente un compte de type chèque avec un nombre de transactions
   *
   * Le compte peut avoir un solde négatif, et les intérêts sont calculés en fonction
   * du nombre de transactions. Il possède aussi un taux d'intérêt minimum.
   */
  class Cheque : public Compte
  {
  public:

    /**
     * \brief Constructeur avec tous les paramètres
     * \param[in] p_noCompte Numéro de compte (> 0)
     * \param[in] p_tauxInteret Taux d'intérêt du compte (> taux minimum)
     * \param[in] p_solde Solde initial (peut être négatif)
     * \param[in] p_nombreTransactions Nombre de transactions [0, 40]
     * \param[in] p_tauxInteretMinimum Taux d'intérêt de base (> 0, par défaut 0.001)
     * \param[in] p_description Chaîne descriptive (par défaut "Cheque")
     * \pre nombreTransactions dans [0, 40] && tauxInteret > tauxMinimum
     */
    Cheque(int p_noCompte, double p_tauxInteret, float p_solde,
           int p_nombreTransactions, double p_tauxInteretMinimum = 0.1,
           const std::string& p_description = "Cheque");

    /** \brief Accesseur : retourne le taux d'intérêt minimum */
    double reqTauxInteretMinimum() const;

    /** \brief Accesseur : retourne le nombre de transactions */
    int reqNombreTransactions() const;

    /**
     * \brief Mutateur : modifie le nombre de transactions
     * \param[in] p_nombreTransactions un entier dans [0, 40]
     */
    void asgNombreTransactions(int p_nombreTransactions);

    /** \brief Calcule les intérêts du compte selon la logique spécifique au chèque */
    virtual double calculerInteret() const override;

    /** \brief Retourne une copie polymorphe du compte courant */
    virtual std::unique_ptr<Compte> clone() const override;

    /**
     * \brief Mutateur : redéfinit le solde du compte
     * \param[in] p_solde nouveau solde (pas de restriction)
     */
    void asgSolde(float p_solde);

    /**
     * \brief Mutateur : assigne un nouveau taux d'intérêt (> taux minimum)
     * \param[in] p_tauxInteret le nouveau taux
     * \pre p_tauxInteret > m_tauxInteretMinimum
     */
    void asgTauxInteret(double p_tauxInteret);

    /**
     * \brief Formate les informations du compte chèque sous forme textuelle
     * \return Chaîne formatée du compte
     */
    virtual std::string reqCompteFormate() const;

  private:
    int m_nombreTransactions; //!< Nombre de transactions effectuées
    double m_tauxInteretMinimum; //!< Taux d'intérêt minimal

    /** \brief Vérifie les invariants de la classe */
    void verifieInvariant() const;
  };

} // namespace bancaire

#endif /* CHEQUE_H */

