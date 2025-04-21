/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Client.h
 * Author: etudiant
 *
 * Created on 3 avril 2025, 19 h 19
 */

/**
 * \file Client.h
 * \brief Déclaration de la classe Client pour la gestion des comptes d'un client bancaire
 */

#ifndef CLIENT_H
#define CLIENT_H

#include <string>
#include <vector>
#include <memory>
#include "Compte.h"
#include "Date.h"
#include "validationFormat.h"
#include "ContratException.h"

namespace bancaire
{

  /**
   * \class Client
   * \brief Représente un client possédant un ou plusieurs comptes bancaires
   *
   * Cette classe contient les informations personnelles du client et gère
   * un vecteur de comptes (par polymorphisme via des pointeurs intelligents).
   */
  class Client
  {
  public:
    /**
     * \brief Constructeur avec tous les attributs
     * \param[in] p_noFolio Numéro de folio [1000, 10000[
     * \param[in] p_nom Nom du client (valide selon validerFormatNom)
     * \param[in] p_prenom Prénom du client (valide selon validerFormatNom)
     * \param[in] p_telephone Numéro de téléphone (non vide)
     * \param[in] p_dateNaissance Date de naissance (valide selon Date)
     * \pre folio entre 1000 et 9999, nom/prenom valides, téléphone non vide
     */
    Client(int p_noFolio, const std::string& p_nom, const std::string& p_prenom,
           const std::string& p_telephone, const util::Date& p_dateNaissance);

    /** \brief Constructeur par copie */
    Client(const Client& p_client);

    /** \brief Opérateur d'assignation */
    Client& operator=(const Client& p_client);

    /** \brief Retourne le numéro de folio */
    int reqNoFolio() const;

    /** \brief Retourne le nom du client */
    const std::string& reqNom() const;

    /** \brief Retourne le prénom du client */
    const std::string& reqPrenom() const;

    /** \brief Retourne le numéro de téléphone */
    const std::string& reqTelephone() const;

    /** \brief Retourne la date de naissance */
    const util::Date& reqDateNaissance() const;

    /** \brief Retourne le nombre de comptes du client */
    int reqNombreComptes() const;

    /** \brief Comparaison par numéro de folio */
    bool operator<(const Client& p_client) const;

    /**
     * \brief Ajoute un compte au client (copie dynamique via clone)
     * \param[in] p_nouveauCompte le compte à ajouter
     */
    void ajouterCompte(const Compte& p_nouveauCompte);

    /** \brief Retourne une chaîne formatée avec les infos personnelles du client */
    std::string reqClientFormate() const;

    /** \brief Retourne une chaîne avec les infos du client et de ses comptes */
    std::string reqReleves() const;

  private:
    int m_noFolio; //!< Numéro du client
    std::string m_nom; //!< Nom du client
    std::string m_prenom; //!< Prénom du client
    std::string m_telephone; //!< Numéro de téléphone
    util::Date m_dateNaissance; //!< Date de naissance
    std::vector<std::unique_ptr<Compte>> m_comptes; //!< Comptes du client
    std::vector<std::unique_ptr<Compte>>::const_iterator iterateurVecteurCompte;

    /** \brief Vérifie les invariants de la classe */
    void verifieInvariant() const;
    
    /** \brief  Vérifie si le client a déjà ce compte. Si oui, elle retourne true et false sinon. */
    bool CompteEstDejaPresent(int p_noCompte) const;
  };

} // namespace bancaire

#endif /* CLIENT_H */


