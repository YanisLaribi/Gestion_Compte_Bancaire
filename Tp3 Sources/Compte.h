/**
 * \file Compte.h
 * \brief Déclaration de la classe abstraite Compte, base des comptes bancaires.
 * \author Votre nom
 * \version 1.0
 * \date 2025-04-10
 */

#ifndef COMPTE_H
#define COMPTE_H

#include <memory>
#include <string>
#include "Date.h"

namespace bancaire
{

  /**
   * \class Compte
   * \brief Classe de base abstraite représentant un compte bancaire générique.
   *
   * Cette classe contient les informations communes à tous les types de comptes :
   * numéro, taux d'intérêt, solde, description, date d'ouverture. Elle définit aussi
   * l'interface pour les méthodes polymorphes.
   */
  class Compte
  {
  public:
    /**
     * \brief Constructeur avec paramètres
     * \param[in] p_noCompte un identifiant strictement positif
     * \param[in] p_tauxInteret un taux d'intérêt associé au compte
     * \param[in] p_solde le solde initial du compte
     * \param[in] p_description une courte description du compte
     * \pre p_noCompte > 0 && !p_description.empty()
     * \post tous les attributs sont initialisés correctement
     */
    Compte(int p_noCompte, double p_tauxInteret, float p_solde, const std::string& p_description);

    /** \brief Accesseur : retourne le numéro du compte */
    int reqNoCompte() const;

    /** \brief Accesseur : retourne le taux d'intérêt du compte */
    double reqTauxInteret() const;

    /** \brief Accesseur : retourne le solde du compte */
    float reqSolde() const;

    /** \brief Accesseur : retourne la description du compte */
    const std::string& reqDescription() const;

    /** \brief Accesseur : retourne la date d'ouverture formatée */
    const std::string reqDateOuverture() const;

    /**
     * \brief Mutateur : assigne un nouveau taux d'intérêt
     * \param[in] p_tauxInteret le nouveau taux à appliquer
     */
    void asgTauxInteret(double p_tauxInteret);

    /**
     * \brief Mutateur : assigne un nouveau solde
     * \param[in] p_solde la nouvelle valeur de solde
     */
    void asgSolde(float p_solde);

    /**
     * \brief Mutateur : assigne une nouvelle description
     * \param[in] p_description texte non vide décrivant le compte
     * \pre !p_description.empty()
     */
    void asgDescription(const std::string& p_description);

    /** \brief Destructeur virtuel */
    virtual ~Compte() {}

    /**
     * \brief Méthode virtuelle pure pour la copie dynamique
     * \return un pointeur unique vers une copie de l'objet courant
     */
    virtual std::unique_ptr<Compte> clone() const = 0;

    /**
     * \brief Méthode virtuelle polymorphe de calcul d'intérêt
     * \return le montant des intérêts générés
     */
    virtual double calculerInteret() const;

    /**
     * \brief Retourne les informations formatées du compte
     * \return une chaîne formatée contenant les détails du compte
     */
    virtual std::string reqCompteFormate() const;

  protected:
    util::Date m_dateOuverture; //!< Date d'ouverture du compte

  private:
    int m_noCompte; //!< Numéro d'identification du compte
    double m_tauxInteret; //!< Taux d'intérêt appliqué au compte
    float m_solde; //!< Solde actuel du compte
    std::string m_description; //!< Description textuelle du compte

    /** \brief Méthode pour vérifier l'invariant de la classe */
    void verifieInvariant() const;
  };

} // namespace bancaire

#endif /* COMPTE_H */
