/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */


/**
 * \file ClientTesteur.cpp
 * \brief Tests unitaires de la classe Client
 * \date Avril
 *
 * Ce fichier contient les tests de la classe Client, qui gère un ensemble de comptes bancaires.
 * Les tests abordent :
 * - la construction valide et les cas d'erreur (préconditions)
 * - l'ajout de comptes et la copie profonde
 * - les accesseurs
 * - les méthodes de formatage de sortie (reqClientFormate et reqReleves)
 * - l'opérateur de comparaison
 */

#include <gtest/gtest.h>
#include "Client.h"
#include "Date.h"
#include"Cheque.h"
#include "Epargne.h"
#include "ContratException.h"
#include "CompteDejaPresentException.h"

using namespace bancaire;
using namespace util;

class ClientValide : public ::testing::Test
{
public:

  ClientValide () :
  f_client (1001, "Laribi", "Yanis", "1234567890", Date (24, 5, 2004)) { }

  Client f_client;
};

TEST_F (ClientValide, Constructeur_paramètresValides_ObjetValide)
{
  ASSERT_EQ (f_client.reqNoFolio (), 1001);
  ASSERT_EQ (f_client.reqNom (), "Laribi");
  ASSERT_EQ (f_client.reqPrenom (), "Yanis");
  ASSERT_EQ (f_client.reqTelephone (), "1234567890");
  ASSERT_EQ (f_client.reqDateNaissance (), Date (24, 5, 2004));
}

TEST (ClientTest, Constructeur_FolioInvalide)
{
  ASSERT_THROW (Client (999, "Laribi", "Yanis", "1234567890", Date (10, 4, 2000)), PreconditionException);
}

TEST (ClientTest, Constructeur_NomInvalide)
{
  ASSERT_THROW (Client (1234, "@Laribi", "Yanis", "1234567890", Date (10, 4, 2000)), PreconditionException);
}

TEST (ClientTest, Constructeur_PrenomInvalide)
{
  ASSERT_THROW (Client (1234, "Laribi", "234Yanis", "1234567890", Date (10, 4, 2000)), PreconditionException);
}

TEST (ClientTest, Constructeur_TelephoneVide)
{
  ASSERT_THROW (Client (1234, "Laribi", "Yanis", "", Date (10, 4, 2000)), PreconditionException);
}

TEST_F (ClientValide, AjouterCompteEtReqNombreComptes_AjouteCorrectementEtCompteCorrectement)
{
  Epargne nouveauCompte (3002, 0.02, 500, "salut");
  int taille = f_client.reqNombreComptes ();
  f_client.ajouterCompte (nouveauCompte);
  ASSERT_EQ (f_client.reqNombreComptes (), taille + 1);
}

TEST_F (ClientValide, AjouterCompte_CompteDéjàExistant_SouleverException)
{
  Epargne nouveauCompte (3002, 0.02, 500, "salut");
  f_client.ajouterCompte (nouveauCompte);
  
  ASSERT_THROW (f_client.ajouterCompte (nouveauCompte), CompteDejaPresentException);
}

TEST (ClientTest, Copie_ConstructeurEtAssignation)
{
  Client original (1234, "Zira", "Nelo", "1234567890", Date (15, 7, 2000));
  Epargne compte (2001, 0.025, 1500.0f, "Vacances");
  original.ajouterCompte (compte);

  Client copie (original);
  ASSERT_EQ (copie.reqNom (), "Zira");
  ASSERT_EQ (copie.reqPrenom (), "Nelo");
  ASSERT_EQ (copie.reqNoFolio (), 1234);
  ASSERT_EQ (copie.reqTelephone (), "1234567890");
  ASSERT_EQ (copie.reqDateNaissance (), Date (15, 7, 2000));
  ASSERT_EQ (copie.reqNombreComptes (), 1);
  ASSERT_NE (copie.reqReleves (), "");

  Client assigné = copie;
  ASSERT_EQ (assigné.reqNom (), "Zira");
  ASSERT_EQ (assigné.reqPrenom (), "Nelo");
  ASSERT_EQ (assigné.reqNoFolio (), 1234);
  ASSERT_EQ (assigné.reqTelephone (), "1234567890");
  ASSERT_EQ (assigné.reqDateNaissance (), Date (15, 7, 2000));
  ASSERT_EQ (assigné.reqNombreComptes (), 1);
  ASSERT_NE (assigné.reqReleves (), "");
}

TEST (ClientTest, OperateurInferieur_VraiEtFaux)
{
  Client c1 (1234, "Durand", "Michel", "514-123-4567", Date (1, 1, 2000));
  Client c2 (5678, "Lemoine", "Alice", "514-987-6543", Date (1, 1, 2000));
  std::cout << "c1 folio: " << c1.reqNoFolio () << std::endl;
  std::cout << "c2 folio: " << c2.reqNoFolio () << std::endl;
  ASSERT_TRUE (c1 < c2);
  ASSERT_FALSE (c2 < c1);
}

TEST_F (ClientValide, reqNoFolio_NoFolio_1001)
{
  ASSERT_EQ (f_client.reqNoFolio (), 1001);
}

TEST_F (ClientValide, reqNom_Nom_Laribi)
{
  ASSERT_EQ (f_client.reqNom (), "Laribi");
}

TEST_F (ClientValide, reqPrenom_Prenom_Yanis)
{
  ASSERT_EQ (f_client.reqPrenom (), "Yanis");
}

TEST_F (ClientValide, reqTelephone_Telephone_1234567890)
{
  ASSERT_EQ (f_client.reqTelephone (), "1234567890");
}

TEST_F (ClientValide, reqDateNaissance_DateNaissance_24Mai2004)
{
  ASSERT_EQ (f_client.reqDateNaissance (), Date (24, 5, 2004));
}

TEST_F (ClientValide, RequeteClientFormate_AfficheCorrectement)
{
  std::string attendu = "Client no de folio : 1001\nYanis Laribi\nDate de naissance : Lundi le 24 mai 2004\n1234567890\n";
  ASSERT_EQ (f_client.reqClientFormate (), attendu);
}

TEST (ClientTest, ReqReleves_AfficheLeRelevéCorrectement)
{
  Client client (5000, "BLO", "Joe", "418 656-2131", Date (12, 5, 1979));

  Cheque cheque (1002, 1.2, -500, 4, 0.3, "courant");
  Epargne epargne (1001, 0.034, 500, "voyage");

  client.ajouterCompte (cheque);
  client.ajouterCompte (epargne);

  std::ostringstream os;
  os << "Client no de folio : 5000\n"
          << "Joe BLO\n"
          << "Date de naissance : Samedi le 12 mai 1979\n"
          << "418 656-2131\n"
          << "Compte Cheque\n"
          << "numero : 1002\n"
          << "Description : courant\n"
          << "Date d'ouverture : " << cheque.reqDateOuverture () << "\n"
          << "Taux d'interet : 1.2\n"
          << "Solde : -500 $\n"
          << "nombre de transactions : 4\n"
          << "Taux d'interet minimum : 0.3\n"
          << "Interet: " << cheque.calculerInteret () << " $\n"
          << "Compte Epargne\n"
          << "numero : 1001\n"
          << "Description : voyage\n"
          << "Date d'ouverture : " << epargne.reqDateOuverture () << "\n"
          << "Taux d'interet : 0.034\n"
          << "Solde : 500 $\n"
          << "Interet : "<< epargne.calculerInteret () << "$" << std::endl;

  std::string attendu = os.str ();

  ASSERT_EQ (client.reqReleves (), attendu);
}
  
 // TEST (ClientTest, CompteEstDejaPresent_DeuxCompteValideAjouté_RetourneFaux)
  //{ 
  //}

