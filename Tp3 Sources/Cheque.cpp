/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/**
 * \file Cheque.cpp
 * \brief Implémentation des méthodes de la classe Cheque
 */

#include "Cheque.h"
#include "ContratException.h"
#include <memory>
#include <sstream>
#include <iostream>

namespace bancaire
{

  /**
   * \brief Constructeur du compte chèque
   */
  Cheque::Cheque (int p_noCompte, double p_tauxInteret, float p_solde,
                  int p_nombreTransactions, double p_tauxInteretMinimum,
                  const std::string& p_description)
  : Compte (p_noCompte, p_tauxInteret, p_solde, p_description),
  m_tauxInteretMinimum (p_tauxInteretMinimum),
  m_nombreTransactions (p_nombreTransactions)
  {
    PRECONDITION (p_nombreTransactions >= 0 && p_nombreTransactions <= 40);
    PRECONDITION (p_tauxInteret >= p_tauxInteretMinimum)
    PRECONDITION (p_tauxInteretMinimum >= 0.1);

    POSTCONDITION (reqTauxInteretMinimum () == p_tauxInteretMinimum);
    POSTCONDITION (reqNombreTransactions () == p_nombreTransactions);

    INVARIANTS ();
  }

  double
  Cheque::reqTauxInteretMinimum () const
  {
    return m_tauxInteretMinimum;
  }

  int
  Cheque::reqNombreTransactions () const
  {
    return m_nombreTransactions;
  }

  /**
   * \brief Modifie le nombre de transactions
   */
  void
  Cheque::asgNombreTransactions (int p_nombreTransactions)
  {
    PRECONDITION (p_nombreTransactions >= 0 && p_nombreTransactions <= 40);
    m_nombreTransactions = p_nombreTransactions;
    POSTCONDITION (m_nombreTransactions == p_nombreTransactions);
    INVARIANTS ();
  }

  /**
   * \brief Calcule les intérêts en fonction du solde et des transactions
   */
  double
  Cheque::calculerInteret () const
  {
    if (reqSolde () >= 0)
      {
        return 0.0;
      }

    double taux = m_tauxInteretMinimum;

    if (m_nombreTransactions >= 11 && m_nombreTransactions <= 25)
      {
        taux += m_tauxInteretMinimum * 0.4;
      }
    else if (m_nombreTransactions >= 26 && m_nombreTransactions <= 35)
      {
        taux += m_tauxInteretMinimum * 0.8;
      }
    else if (m_nombreTransactions > 35)
      {
        taux = reqTauxInteret ();
      }

    return reqSolde () * taux;
  }

  /**
   * \brief Clone le compte chèque
   */
  std::unique_ptr<Compte>
  Cheque::clone () const
  {
    return std::make_unique<Cheque>(*this);
  }

  /**
   * \brief Retourne les informations formatées du compte chèque
   */
  std::string
  Cheque::reqCompteFormate () const
  {
    std::ostringstream os;
    os << "Compte Cheque" << std::endl;
    os << Compte::reqCompteFormate ();
    os << "nombre de transactions : " << reqNombreTransactions () << std::endl;
    os << "Taux d'interet minimum : " << reqTauxInteretMinimum () << std::endl;
    os << "Interet: " << calculerInteret () << " $" << std::endl;
    return os.str ();
  }

  /**
   * \brief Redéfinit le solde du compte (aucune restriction spécifique)
   */
  void
  Cheque::asgSolde (float p_solde)
  {
    Compte::asgSolde (p_solde);
  }

  /**
   * \brief Assigne un nouveau taux d'intérêt supérieur au taux minimal
   */
  void
  Cheque::asgTauxInteret (double p_tauxInteret)
  {
    PRECONDITION (p_tauxInteret >= m_tauxInteretMinimum);
    Compte::asgTauxInteret (p_tauxInteret);
    POSTCONDITION (reqTauxInteret () == p_tauxInteret);
    INVARIANTS ();
  }

  /**
   * \brief Vérifie les invariants de la classe Cheque
   */
  void
  Cheque::verifieInvariant () const
  {
    INVARIANT (m_nombreTransactions >= 0 && m_nombreTransactions <= 40);
    INVARIANT (reqTauxInteret () >= m_tauxInteretMinimum);
    INVARIANT (reqTauxInteretMinimum () >= 0.1)
  }

} // namespace bancaire
