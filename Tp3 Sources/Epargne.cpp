/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

/**
 * \file Epargne.cpp
 * \brief Implémentation des méthodes de la classe Epargne
 */

#include "Epargne.h"
#include "ContratException.h"

namespace bancaire
{
  /**
   * \brief Constructeur : initialise un compte Epargne avec les valeurs reçues
   */
  Epargne::Epargne(int p_noCompte, double p_tauxInteret, float p_solde, const std::string& p_description)
    : Compte(p_noCompte, p_tauxInteret, p_solde, p_description)
  {
    PRECONDITION(p_tauxInteret >= 0.001 && p_tauxInteret <= 0.035);
    PRECONDITION(p_solde >= 0);

    POSTCONDITION(reqTauxInteret() == p_tauxInteret);
    POSTCONDITION(reqSolde() == p_solde);

    INVARIANTS();
  }

  /**
   * \brief Calcule les intérêts pour un compte Epargne : solde * taux
   */
  double Epargne::calculerInteret() const
  {
    return reqSolde() * reqTauxInteret();
  }

  /**
   * \brief Retourne une copie polymorphe du compte Epargne
   */
  std::unique_ptr<Compte> Epargne::clone() const
  {
    return std::make_unique<Epargne>(*this);
  }

  /**
   * \brief Retourne les informations formatées du compte Epargne
   */
  std::string Epargne::reqCompteFormate() const
  {
    std::ostringstream os;
    os << "Compte Epargne" << std::endl;
    os << Compte::reqCompteFormate();
    os << "Interet : " << calculerInteret() << "$" << std::endl;
    return os.str();
  }

  /**
   * \brief Modifie le solde du compte Epargne (doit être >= 0)
   */
  void Epargne::asgSolde(float p_solde)
  {
    PRECONDITION(p_solde >= 0);
    Compte::asgSolde(p_solde);
    POSTCONDITION(reqSolde() == p_solde);
    INVARIANTS();
  }

  /**
   * \brief Modifie le taux d'intérêt du compte Epargne (dans [0.001, 0.035])
   */
  void Epargne::asgTauxInteret(double p_tauxInteret)
  {
    PRECONDITION(p_tauxInteret >= 0.001 && p_tauxInteret <= 0.035);
    Compte::asgTauxInteret(p_tauxInteret);
    POSTCONDITION(reqTauxInteret() == p_tauxInteret);
    INVARIANTS();
  }

  /**
   * \brief Vérifie les invariants de la classe Epargne
   */
  void Epargne::verifieInvariant() const
  {
    INVARIANT(reqTauxInteret() >= 0.001 && reqTauxInteret() <= 0.035);
    INVARIANT(reqSolde() >= 0);
  }

} // namespace bancaire


