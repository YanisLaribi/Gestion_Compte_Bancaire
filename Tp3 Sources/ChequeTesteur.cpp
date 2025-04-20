/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

/**
 * \file ChequeTesteur.cpp
 * \brief Tests unitaires de la classe Cheque
 * \date Avril
 *
 * Ce fichier contient une suite de tests Google Test pour vérifier le comportement
 * de la classe Cheque, qui est une classe dérivée de Compte. Les tests couvrent :
 * - la validité du constructeur
 * - le calcul des intérêts selon les transactions
 * - les mutateurs (nombre de transactions, taux d'intérêt)
 * - la vérification des préconditions
 * - les accesseurs
 */
#include <gtest/gtest.h>
#include "Cheque.h"
#include "ContratException.h"

using namespace bancaire;

// ================= FIXTURE =================

class ChequeValide : public ::testing::Test
{
protected:

  ChequeValide ()
  : f_cheque (2001, 0.015, -300, 10, 0.001, "Chèque") { }

  Cheque f_cheque;
};

// ================ TESTS ===================

TEST_F (ChequeValide, Constructeur_parametresValides_objetValide)
{
  ASSERT_EQ (f_cheque.reqNombreTransactions (), 10);
  ASSERT_EQ (f_cheque.reqTauxInteretMinimum (), 0.001);
}

TEST (ChequeTest, CalculerInteret_nombreTransactionsFaible_interetMinimal)
{
  Cheque cheque (2002, 0.02, -1000, 5, 0.002);
  ASSERT_EQ (cheque.calculerInteret (), -2.0);
}

TEST_F (ChequeValide, AsgNombreTransactions_valeurValide_modifieValeur)
{
  f_cheque.asgNombreTransactions (25);
  ASSERT_EQ (f_cheque.reqNombreTransactions (), 25);
}

TEST_F (ChequeValide, AsgTauxInteret_valeurValide_modifieTaux)
{
  f_cheque.asgTauxInteret (0.02);
  ASSERT_EQ (f_cheque.reqTauxInteret (), 0.02);
}

TEST (ChequeTest, Constructeur_nombreTransactionsInvalide_leveException)
{
  ASSERT_THROW (Cheque (2001, 0.015, -300, 50), PreconditionException);
}

TEST_F (ChequeValide, AsgNombreTransactions_valeurInvalide_leveException)
{
  ASSERT_THROW (f_cheque.asgNombreTransactions (-1), PreconditionException);
}

TEST_F (ChequeValide, AsgTauxInteret_valeurInvalide_leveException)
{
  ASSERT_THROW (f_cheque.asgTauxInteret (0), PreconditionException);
}

TEST_F (ChequeValide, Accesseurs_retournentValeursAttendues)
{
  ASSERT_EQ (f_cheque.reqNoCompte (), 2001);
  ASSERT_EQ (f_cheque.reqTauxInteret (), 0.015);
  ASSERT_EQ (f_cheque.reqSolde (), -300);
  ASSERT_EQ (f_cheque.reqDescription (), "Chèque");
  ASSERT_FALSE (f_cheque.reqDateOuverture ().empty ());
  ASSERT_EQ (f_cheque.reqNombreTransactions (), 10);
  ASSERT_EQ (f_cheque.reqTauxInteretMinimum (), 0.001);
}