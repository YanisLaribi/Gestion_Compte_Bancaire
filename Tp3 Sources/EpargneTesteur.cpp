/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */


/**
 * \file EpargneTesteur.cpp
 * \brief Tests unitaires de la classe Epargne
 * \date Avril
 *
 * Ce fichier regroupe les tests unitaires pour la classe Epargne. Les tests vérifient :
 * - la création valide d'un compte
 * - le comportement des mutateurs (solde et taux)
 * - la gestion des cas invalides (solde négatif, taux hors bornes)
 * - les accesseurs
 */

#include <gtest/gtest.h>
#include "Epargne.h"
#include "ContratException.h"

using namespace bancaire;

// ============== FIXTURE ==============
class EpargneValide : public ::testing::Test
{
protected:
    EpargneValide()
        : f_epargne(3002, 0.2, 500, "vacances") {}

    Epargne f_epargne;
};

// ============== TESTS ===============

TEST_F(EpargneValide, Constructeur_parametresValides_objetValide)
{
    ASSERT_EQ(f_epargne.reqTauxInteret(), 0.2);
    ASSERT_EQ(f_epargne.reqSolde(), 500);
    ASSERT_EQ(f_epargne.reqDescription(), "vacances");
}

TEST_F(EpargneValide, AsgSolde_valeurValide_modifieSolde)
{
    f_epargne.asgSolde(600);
    ASSERT_EQ(f_epargne.reqSolde(), 600);
}

TEST_F(EpargneValide, AsgTauxInteret_valeurValide_modifieTaux)
{
    f_epargne.asgTauxInteret(0.25);
    ASSERT_EQ(f_epargne.reqTauxInteret(), 0.25);
}

TEST(EpargneTest, Constructeur_tauxInteretInvalide_leveException)
{
    ASSERT_THROW(Epargne(3001, 0.0005, 1000, "Test"), PreconditionException);
}

TEST(EpargneTest, Constructeur_soldeNegatif_leveException)
{
    ASSERT_THROW(Epargne(3001, 0.03, -500, "Test"), PreconditionException);
}

TEST_F(EpargneValide, AsgSolde_valeurNegative_leveException)
{
    ASSERT_THROW(f_epargne.asgSolde(-100), PreconditionException);
}

TEST_F(EpargneValide, AsgTauxInteret_valeurInvalide_leveException)
{
    ASSERT_THROW(f_epargne.asgTauxInteret(0.0), PreconditionException);
}

TEST_F(EpargneValide, Accesseurs_retournentValeursAttendues)
{
    ASSERT_EQ(f_epargne.reqNoCompte(), 3002);
    ASSERT_EQ(f_epargne.reqTauxInteret(), 0.2);
    ASSERT_EQ(f_epargne.reqSolde(), 500);
    ASSERT_EQ(f_epargne.reqDescription(), "vacances");
    ASSERT_FALSE(f_epargne.reqDateOuverture().empty());
}