/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Client.cpp
 * Author: etudiant
 * 
 * Created on 3 avril 2025, 19 h 19
 */

/**
 * \file Client.cpp
 * \brief Implémentation des méthodes de la classe Client
 */

#include "Client.h"
#include <sstream>
#include "CompteDejaPresentException.h"
#include "CompteAbsentException.h"
namespace bancaire
{

  /**
   * \brief Constructeur principal de la classe Client
   */
  Client::Client (int p_noFolio, const std::string& p_nom, const std::string& p_prenom,
                  const std::string& p_telephone, const util::Date& p_dateNaissance)
  : m_noFolio (p_noFolio), m_nom (p_nom), m_prenom (p_prenom),
  m_telephone (p_telephone), m_dateNaissance (p_dateNaissance)
  {
    PRECONDITION (p_noFolio >= 1000 && p_noFolio < 10000);
    PRECONDITION (util::validerFormatNom (p_nom));
    PRECONDITION (util::validerFormatNom (p_prenom));
    PRECONDITION (!p_telephone.empty ());

    POSTCONDITION (m_noFolio == p_noFolio);
    POSTCONDITION (m_nom == p_nom);
    POSTCONDITION (m_prenom == p_prenom);
    POSTCONDITION (m_telephone == p_telephone);
    POSTCONDITION (m_dateNaissance == p_dateNaissance);

    INVARIANTS ();
  }

  /**
   * \brief Constructeur par copie
   */
  Client::Client (const Client& p_client)
  : m_noFolio (p_client.m_noFolio), m_nom (p_client.m_nom),
  m_prenom (p_client.m_prenom), m_telephone (p_client.m_telephone),
  m_dateNaissance (p_client.m_dateNaissance)
  {
    for (const auto& compte : p_client.m_comptes)
      {
        m_comptes.push_back (compte->clone ());
      }
    INVARIANTS ();
  }

  /**
   * \brief Opérateur d'assignation
   */
  Client& Client::operator= (const Client& p_client)
  {
    if (this != &p_client)
      {
        m_noFolio = p_client.m_noFolio;
        m_nom = p_client.m_nom;
        m_prenom = p_client.m_prenom;
        m_telephone = p_client.m_telephone;
        m_dateNaissance = p_client.m_dateNaissance;
        m_comptes.clear ();

        for (const auto& compte : p_client.m_comptes)
          {
            m_comptes.push_back (compte->clone ());
          }
      }
    INVARIANTS ();
    return *this;
  }

  int
  Client::reqNoFolio () const
  {
    return m_noFolio;
  }

  const std::string&
  Client::reqNom () const
  {
    return m_nom;
  }

  const std::string&
  Client::reqPrenom () const
  {
    return m_prenom;
  }

  const std::string&
  Client::reqTelephone () const
  {
    return m_telephone;
  }

  const util::Date&
  Client::reqDateNaissance () const
  {
    return m_dateNaissance;
  }

  /**
   * \brief Retourne le nombre de comptes du client
   */
  int
  Client::reqNombreComptes () const
  {
    return m_comptes.size ();
  }

  /**
   * \brief Comparaison par folio
   */
  bool Client::operator< (const Client& p_client) const
  {
    return m_noFolio < p_client.m_noFolio;
  }

  /**
   * \brief Ajoute un compte au client (copie dynamique)seulement si le compte n’est pas déjà présent dans la liste.
   */
  void
  Client::ajouterCompte (const Compte& p_nouveauCompte)
  {
    if (CompteEstDejaPresent (p_nouveauCompte.reqNoCompte ()))
      {
        std::ostringstream os;

        os << "Le compte est déjà présent :"
                << std::endl
                << p_nouveauCompte.reqCompteFormate ();

        CompteDejaPresentException expect (os.str ());
        throw expect;
      }
    m_comptes.push_back (p_nouveauCompte.clone ());
    INVARIANTS ();
  }

  /**
   * \brief Retourne les infos personnelles du client formatées
   */
  std::string
  Client::reqClientFormate () const
  {
    std::ostringstream os;
    os << "Client no de folio : " << m_noFolio << std::endl;
    os << m_prenom << " " << m_nom << std::endl;
    os << "Date de naissance : " << m_dateNaissance.reqDateFormatee () << std::endl;
    os << m_telephone << std::endl;
    return os.str ();
  }

  /**
   * \brief Retourne les relevés de tous les comptes du client
   */
  std::string
  Client::reqReleves () const
  {
    std::ostringstream os;
    os << reqClientFormate ();
    for (const auto& compte : m_comptes)
      {
        os << compte->reqCompteFormate ();
      }
    return os.str ();
  }

  /**
   * \brief Vérifie les invariants de la classe Client
   */
  void
  Client::verifieInvariant () const
  {
    INVARIANT (m_noFolio >= 1000 && m_noFolio < 10000);
    INVARIANT (util::validerFormatNom (m_nom));
    INVARIANT (util::validerFormatNom (m_prenom));
    INVARIANT (!m_telephone.empty ());
  }

  /** 
   * \brief  Vérifie si le client a déjà ce compte. Si oui, elle retourne true et false sinon. 
   */
  bool
  Client::CompteEstDejaPresent (int p_noCompte) const
  {

    bool valide = false;
    for (auto iterateurVecteurCompte = m_comptes.begin (); iterateurVecteurCompte != m_comptes.end (); ++iterateurVecteurCompte)
      {
        if ((*iterateurVecteurCompte)->reqNoCompte () == p_noCompte)
          {
            valide = true;
            break;
          }
      }
    return valide;
  }

  void
  Client::supprimerCompte (int p_noCompte)
  {
    if (!(CompteEstDejaPresent (p_noCompte)))
      {
        std::ostringstream os;

        os << "Le compte : "
                << p_noCompte
                << " est absent.";

        CompteAbsentException expect (os.str ());

        throw expect;
      }

    for (iterateurVecteurCompte = m_comptes.begin (); iterateurVecteurCompte != m_comptes.end (); ++iterateurVecteurCompte)
      {
        if ((*iterateurVecteurCompte) -> reqNoCompte() == p_noCompte)
          {
            m_comptes.erase (iterateurVecteurCompte);
            break;
          }
      }
    INVARIANTS ();
  };
} // namespace bancaire


