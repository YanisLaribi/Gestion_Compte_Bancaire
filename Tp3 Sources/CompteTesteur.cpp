/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */


/**
 * \file CompteTesteur.cpp
 * \brief Tests unitaires de la classe abstraite Compte via une classe de test
 * \date Avril
 *
 * La classe CompteTesteur permet de vérifier le bon fonctionnement de la classe de base Compte.
 * Les tests portent sur :
 * - la construction valide d'un objet CompteTeste
 * - les accesseurs
 * - les mutateurs (solde, taux, description)
 * - le respect des préconditions lors de la construction ou de l'appel aux mutateurs
 */

#include <gtest/gtest.h>
#include "Compte.h"
#include "ContratException.h"
#include <memory>
#include <sstream>

using namespace bancaire;

// Classe fictive dérivée de Compte pour permettre les tests
class CompteTeste : public Compte
{
public:
  CompteTeste(int p_noCompte, double p_tauxInteret, float p_solde,
              const std::string& p_description)
    : Compte(p_noCompte, p_tauxInteret, p_solde, p_description) {}

  std::unique_ptr<Compte> clone() const override
  {
    return std::make_unique<CompteTeste>(*this);
  }
};

// -------------------- TESTS --------------------

TEST(CompteTest, Constructeur_parametresValides_objetValide)
{
    CompteTeste compte(1001, 0.02, 500.0, "Test");
    ASSERT_EQ(compte.reqNoCompte(), 1001);
    ASSERT_EQ(compte.reqTauxInteret(), 0.02);
    ASSERT_EQ(compte.reqSolde(), 500.0);
    ASSERT_EQ(compte.reqDescription(), "Test");
    ASSERT_FALSE(compte.reqDateOuverture().empty());
}

TEST(CompteTest, AsgTauxInteret_valeurValide_modifieTaux)
{
    CompteTeste compte(1001, 0.02, 500.0, "Test");
    compte.asgTauxInteret(0.03);
    ASSERT_EQ(compte.reqTauxInteret(), 0.03);
}

TEST(CompteTest, AsgDescription_valeurValide_modifieDescription)
{
    CompteTeste compte(1001, 0.02, 500.0, "Test");
    compte.asgDescription("Nouveau");
    ASSERT_EQ(compte.reqDescription(), "Nouveau");
}

TEST(CompteTest, AsgSolde_valeurValide_modifieSolde)
{
    CompteTeste compte(1001, 0.02, 500.0, "Test");
    compte.asgSolde(1000);
    ASSERT_EQ(compte.reqSolde(), 1000);
}

TEST(CompteTest, Constructeur_numeroInvalide_leveException)
{
    ASSERT_THROW(CompteTeste(-1, 0.02, 500, "Test"), PreconditionException);
}

TEST(CompteTest, Constructeur_descriptionVide_leveException)
{
    ASSERT_THROW(CompteTeste(1001, 0.02, 500, ""), PreconditionException);
}

TEST(CompteTest, AsgDescription_valeurVide_leveException)
{
    CompteTeste compte(1001, 0.02, 500, "Test");
    ASSERT_THROW(compte.asgDescription(""), PreconditionException);
}

TEST(CompteTest, Accesseurs_Valides)
{
    CompteTeste compte(1234, 0.025, 1000, "TestCompte");
    ASSERT_EQ(compte.reqNoCompte(), 1234);
    ASSERT_EQ(compte.reqTauxInteret(), 0.025);
    ASSERT_EQ(compte.reqSolde(), 1000);
    ASSERT_EQ(compte.reqDescription(), "TestCompte");
    ASSERT_FALSE(compte.reqDateOuverture().empty());
}