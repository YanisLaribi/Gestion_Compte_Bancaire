/**
 * \file DateTesteur.cpp
 * \brief Fichier de tests unitaires pour la classe Date
 * \author Thierry Eude
 * \version 1.0
 */

#include<gtest/gtest.h>
#include <ctime>
#include "Date.h"
#include "ContratException.h"

using namespace util;

/**
 * \brief Test du constructeur par défaut de Date
 *
 *    cas valide 
 *    	ConstructeurParDefaut: Création d'une date à l'aide du constructeur par défaut
 *        et d'une autre avec la fonction time, elles doivent être égales
 *    cas invalide
 *    	aucun d'identifié.
 */

TEST (DateTest, Constructeur_parDefaut_objetValide)
{
  Date aujourdhui;
  time_t m_temps = time (NULL);
  struct tm* infoTempsP = localtime (&m_temps);

  EXPECT_EQ (infoTempsP->tm_mday, aujourdhui.reqJour ())
          << "reqJour devrait retourner " << infoTempsP->tm_mday;
  EXPECT_EQ (infoTempsP->tm_mon + 1, aujourdhui.reqMois ())
          << "reqMois devrait retourner " << infoTempsP->tm_mon + 1;
  EXPECT_EQ (infoTempsP->tm_year + 1900, aujourdhui.reqAnnee ())
          << "reqAnnee devrait retourner " << infoTempsP->tm_year + 1900;
}

/**
 * \brief Test du constructeur avec paramètres de Date::Date(int, int, int)
 *
 *        cas valide :
 *          Création d'une date valide : ParametresValides
 *
 *        cas invalides :
 *        	jour invalide -> ParametreJourInvalide,
 *        	mois invalide : ParametreMoisInvalide,
 *        	jour+mois+année invalides : ParametreDateInvalide
 */

TEST (DateTest, Constructeur_parametresValides_objetValide)
{
  Date dateTest (10, 4, 1960);

  ASSERT_EQ (dateTest.reqJour (), 10);
  ASSERT_EQ (dateTest.reqMois (), 4);
  ASSERT_EQ (dateTest.reqAnnee (), 1960);
}

// jour invalide

TEST (DateTest, Constructeur_parametreJourInvalide_erreurDePrecondition)
{
  ASSERT_THROW (Date (50, 2, 2011), PreconditionException);
}
// mois invalide

TEST (DateTest, Constructeur_parametreMoisInvalide)
{
  ASSERT_THROW (Date (1, 13, 2011), PreconditionException);
}

TEST (DateTest, Constructeur_parametreDateInvalide_erreurDePrecondition)
{
  int jour_invalide_fevrier_anneeNonBissextile {29};
  int mois_invalide_fevrier_anneeNonBissextile {02};

  ASSERT_THROW (Date (jour_invalide_fevrier_anneeNonBissextile, 02, 2011), PreconditionException);
}

/**
 * \brief  Test de la méthode bool Date::estBissextile(long annee)
 *        cas valide:
 *  		EstBissextile_vrai: 	Année bissextile      2000
 * 		EstBissextile_faux: 	Année non bissextile  1900
 *        cas invalide Aucun d'identifié
 */
TEST (DateTest, EstBissextile_anneeBissextile_vrai)
{
  ASSERT_TRUE (Date::estBissextile (2000));
}

TEST (DateTest, EstBissextile_anneeNonBissextile_faux)
{
  ASSERT_FALSE (Date::estBissextile (1900));
}

/**
 * \brief  Test de la méthode bool Date::validerDate(long jour, long mois, long annee)
 * 	cas valide:
 *   	EstValide: Vérifier une date valide, p.e. 1 mars 2001
 *   	JourInvalide : Vérifier un jour invalide, p.e. 32
 *   	MoisInvalide : Vérifier une année invalide, p.e. 13
 *   	DateInvalide : Vérifier une date invalide (jour+mois+année), p.e. 29 février 1981
 * 	cas invalide Aucun d'identifié
 */

TEST (DateTest, ValiderDate_dateValide_vrai)
{
  ASSERT_TRUE (Date::validerDate (1, 3, 2001));
}

TEST (DateTest, ValiderDate_JourInvalide_faux)
{
  ASSERT_FALSE (Date::validerDate (32, 3, 1985));
}

TEST (DateTest, ValiderDate_MoisInvalide_faux)
{
  ASSERT_FALSE (Date::validerDate (1, 32, 1985));
}

TEST (DateTest, ValiderDate_JJValide_MMValide_AAAAValide_DateInvalide_vrai)
{
  ASSERT_FALSE (Date::validerDate (29, 2, 1981));
}

/**
 * \brief Test de la méthode int Date::reqJourDeAnnee()
 *        cas valide
 *   		reqJourAnneePremierJour: Date valide le 1er jour de l'année
 *              reqJourAnneeJour32 : Date valide le 32e jour de l'année
 *  		retJourAnneeBissextile Date valide le dernier jour d'une année bissextile
 *        cas invalide Aucun d'identifié
 */
TEST (DateTest, ReqJourDeAnnee_PremierJour_jourUn)
{
  Date dateTest (1, 1, 2001);

  ASSERT_EQ (dateTest.reqJourDeAnnee (), 1);
}

TEST (DateTest, ReqJourDeAnnee_1Fevrier_Jour32)
{
  Date dateTest (1, 2, 2001);

  ASSERT_EQ (dateTest.reqJourDeAnnee (), 32);
}

TEST (DateTest, ReqJourDeAnnee_dernierJourAnneeBissextile_jour366)
{
  Date dateTest (31, 12, 2000);

  ASSERT_EQ (dateTest.reqJourDeAnnee (), 366);
}

/**
 * \class UneDateValide
 * \brief classe Fixture pour des tests sur une date
 */

class UneDateValide : public ::testing::Test // Une date 10/4/2011
{
public:

  UneDateValide () :
  f_dateTest (10, 4, 2011) { }
  ;

  Date f_dateTest;
};

/**
 * \brief Test de la méthode bool Date::ajouteNbJour(long)
 *   cas valide
 *     	AjouteNbJour_positif:Ajout d'un certain nombre positif de jours.
 *   	AjouteNbJour_negatif:Ajout d'un certain nombre de jours (négatif).
 *    cas invalide Aucun d'identifié.
 */
TEST_F (UneDateValide, AjouteNbJour_positif_objetValide)
{
  f_dateTest.ajouteNbJour (5);

  ASSERT_EQ (f_dateTest.reqJour (), 15);
  ASSERT_EQ (f_dateTest.reqMois (), 4);
  ASSERT_EQ (f_dateTest.reqAnnee (), 2011);
}

TEST_F (UneDateValide, AjouteNbJour_negatif_objetValide)
{
  f_dateTest.ajouteNbJour (-5);

  ASSERT_EQ (f_dateTest.reqJour (), 5);
  ASSERT_EQ (f_dateTest.reqMois (), 4);
  ASSERT_EQ (f_dateTest.reqAnnee (), 2011);
}

/**
 * \brief Test de la méthode Date::asgDate()
 *     	cas valide
 *     		AsgDateValide: Assigner une date avec un jour, un mois et une année valides
 *   	cas invalides
 *        	AsgDateInvalide: Assigner une date invalide
 */
TEST_F (UneDateValide, AsgDate_Valide_objetValide)
{
  f_dateTest.asgDate (12, 12, 2013);

  ASSERT_EQ (f_dateTest.reqJour (), 12);
  ASSERT_EQ (f_dateTest.reqMois (), 12);
  ASSERT_EQ (f_dateTest.reqAnnee (), 2013);
}
//cas invalides

// date invalide

TEST_F (UneDateValide, AsgDate_JJMMAAAAInvalide_erreurDePrecondition)
{
  ASSERT_THROW (f_dateTest.asgDate (29, 02, 2011), PreconditionException);
}

/**
 * \brief Test de la méthode int Date::reqJour()
 *        cas valide reqJour: Création date valide connue et test du jour
 *        cas invalide Aucun d'identifié
 */
TEST_F (UneDateValide, ReqJour_jourValide)
{
  ASSERT_EQ (f_dateTest.reqJour (), 10);
}

/**
 * \brief Test de la méthode int Date::reqMois()
 *        cas valide reqMois: Création date valide connue et test du mois
 *        cas invalide Aucun d'identifié
 */
TEST_F (UneDateValide, ReqMois_moisValide)
{
  ASSERT_EQ (f_dateTest.reqMois (), 4);
}

/**
 * \brief  Test de la méthode int Date::reqAnnee()
 *        cas valide reqAnnee: Création date valide connue et test de l'année
 *        cas invalide Aucun d'identifié
 */
TEST_F (UneDateValide, ReqAnnee_anneeValide)
{
  ASSERT_EQ (f_dateTest.reqAnnee (), 2011);
}

/**
 * \brief  Test de la méthode std::string Date::reqDateFormatee()
 *        cas valide DateFormatee: Date connue dont on connaît le format.
 *        cas invalide Aucun d'identifié
 */
TEST_F (UneDateValide, ReqDateFormatee_formatValide)
{
  ASSERT_EQ ("Dimanche le 10 avril 2011", f_dateTest.reqDateFormatee ());
}

/**
 * \class DeuxDates
 * \brief Fixture pour les tests avec Deux dates
 */
class DeuxDates : public ::testing::Test
{
public:

  DeuxDates () :
  f_date1 (15, 4, 2000), f_date2 (16, 4, 2010) { }
  ;

  Date f_date1;
  Date f_date2;
};

/**
 * \brief  Test de la méthode bool Date::operator== (const Date& obj)
 *        cas valide:
 *   		OperatorEgalEgalVrai: 	Date indentique à elle-même.
 *  		OperatorEgalEgalFaux: 	Dates différentes
 *        cas invalide Aucun d'identifié
 */
TEST_F (DeuxDates, OperatorEgalEgal_deuxDatesIdentiques_Vrai)
{
  ASSERT_EQ (f_date1, f_date1);
}

TEST_F (DeuxDates, OperatorEgalEgal__deuxDatesDifferentes_Faux)
{
  ASSERT_FALSE (f_date1 == f_date2); // On ne peut utiliser ASSERT_NE() seulement si l'opérateur != est implémenté

}

/**
 * \brief  Test de la méthode bool Date::operator< (const Date& obj)
 *        cas valide:
 *  		OperatorPlusPetitVrai: d1 < d2
 *   		OperatorPlusPetitFaux: d2 < d1
 *        cas invalide Aucun d'identifié
 */
TEST_F (DeuxDates, OperatorPlusPetit_Vrai)
{
  ASSERT_TRUE (f_date1 < f_date2);
}

TEST_F (DeuxDates, OperatorPlusPetit_Faux)
{
  ASSERT_FALSE (f_date2 < f_date1);
}

/**
 * \brief  Test de la méthode double Date::operator- (const Date& obj)
 *        cas valide:
 *         OperatorMoins: 		résultat positif
 *         OperatorMoins: 		résultat négatif
 *         résultat positif: 	Dates égales résultat nul
 *        cas invalide Aucun d'identifié
 */
TEST_F (DeuxDates, OperatorMoins_resultatPositifValide)
{
  ASSERT_EQ (f_date2 - f_date1, 3653);
}

TEST_F (DeuxDates, OperatorMoins_resultatNegatifValide)
{
  ASSERT_EQ (f_date1 - f_date2, -3653);
}

TEST_F (DeuxDates, OperatorMoins_resultatNul)
{
  ASSERT_EQ (f_date1 - f_date1, 0);
}

/**
 * \brief  Test de la méthode ostream& Date::operator<<(ostream&, const Date&)
 * 	cas valide:
 *  	OperatorPlusPetitPlusPetit: Date valide connue qu'on envoie dans un ostringstream
 *  	et qu'on compare avec la sortie prévue.
 * 	cas invalide Aucun d'identifié
 */
TEST_F (UneDateValide, OperatorFluxPlusPetitPlusPetit_fluxValide)
{
  std::ostringstream os;
  os << f_dateTest;

  ASSERT_EQ (os.str (), "10/04/2011");
}