/**
 * \file Compte.cpp
 * \brief Implémentation des méthodes de la classe Compte
 */

#include "Compte.h"
#include "ContratException.h"
#include <string>
#include <iostream>
#include <sstream>

using namespace util;

namespace bancaire
{

  /**
   * \brief Constructeur de la classe Compte
   */
  Compte::Compte (int p_noCompte, double p_tauxInteret, float p_solde, const std::string& p_description)
    : m_noCompte (p_noCompte), m_tauxInteret (p_tauxInteret), m_solde (p_solde), m_description (p_description), m_dateOuverture()
  {
    PRECONDITION (p_noCompte > 0);
    PRECONDITION (!p_description.empty());

    POSTCONDITION (m_noCompte == p_noCompte);
    POSTCONDITION (m_tauxInteret == p_tauxInteret);
    POSTCONDITION (m_solde == p_solde);
    POSTCONDITION (m_description == p_description);

    INVARIANTS();
  }

  int Compte::reqNoCompte () const { return m_noCompte; }

  double Compte::reqTauxInteret () const { return m_tauxInteret; }

  float Compte::reqSolde () const { return m_solde; }

  const std::string& Compte::reqDescription () const { return m_description; }

  const std::string Compte::reqDateOuverture () const {
    return m_dateOuverture.reqDateFormatee();
  }

  /**
   * \brief Assigne un nouveau taux d'intérêt au compte
   */
  void Compte::asgTauxInteret (double p_tauxInteret)
  {
    m_tauxInteret = p_tauxInteret;
    POSTCONDITION (m_tauxInteret == p_tauxInteret);
    INVARIANTS ();
  }

  /**
   * \brief Assigne un nouveau solde au compte
   */
  void Compte::asgSolde (float p_solde)
  {
    m_solde = p_solde;
    POSTCONDITION (m_solde == p_solde);
    INVARIANTS ();
  }

  /**
   * \brief Assigne une nouvelle description au compte
   */
  void Compte::asgDescription (const std::string& p_description)
  {
    PRECONDITION (!p_description.empty());
    m_description = p_description;
    POSTCONDITION (m_description == p_description);
    INVARIANTS ();
  }

  /**
   * \brief Calcule les intérêts. La version de base retourne 0.
   */
  double Compte::calculerInteret () const
  {
    return 0;
  }

  /**
   * \brief Retourne les informations du compte formatées
   */
  std::string Compte::reqCompteFormate () const
  {
    std::ostringstream os;
    os << "numero : " << m_noCompte << std::endl
       << "Description : " << m_description << std::endl
       << "Date d'ouverture : " << reqDateOuverture() << std::endl
       << "Taux d'interet : " << m_tauxInteret << std::endl
       << "Solde : " << m_solde << " $" << std::endl;
    return os.str ();
  }

  /**
   * \brief Vérifie les invariants de la classe Compte
   */
  void Compte::verifieInvariant () const
  {
    INVARIANT(m_noCompte > 0);
    INVARIANT(!m_description.empty());
  }

} // namespace bancaire