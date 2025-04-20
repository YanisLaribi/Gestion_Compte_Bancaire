
#include "validationFormat.h"
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;
namespace util{
bool
validerFormatNom (const std::string& p_nom)
{
  // Vérifier si le nom est vide
  if (p_nom.empty ())
    {
      return false;
    }

  // Vérifier si le premier ou dernier caractère est un espace ou un tiret
  if (p_nom[0] == ' ' || p_nom[0] == '-' || p_nom[p_nom.length () - 1] == ' ' || p_nom[p_nom.length () - 1] == '-')
    {
      return false;
    }

  // Boucle pour parcourir chaque caractère du nom
  for (int i = 0; i < p_nom.length (); i++)
    {
      char c1 = p_nom[i];

      // Vérification si le caractère c1 fait partie des caractères valides (liste1)
      bool caractereValide = false;
      for (int j = 0; j < strlen (liste1); j++) // Correction : strlen() au lieu de sizeof()
        {
          if (c1 == liste1[j])
            {
              caractereValide = true;
              break;
            }
        }

      // Si le caractère c1 n'est pas valide, retourner false
      if (!caractereValide)
        {
          return false;
        }

      // Vérification des caractères consécutifs (espaces ou tirets consécutifs ou caractères spéciaux LISTE 2)
      if (i + 1 < p_nom.length ()) // Assurer que i+1 est dans les limites
        {
          char c2 = p_nom[i + 1]; // Calculer c2 uniquement quand nécessaire

          // Vérifie si c1 et c2 sont tous deux des caractères spéciaux dans liste2
          if (strchr (liste2, c1) && strchr (liste2, c2))
            {
              return false;
            }
        }
    }

  // Si tout est valide, retourner true
  return true;
}

bool
validerFormatFichier (std::istream& p_is)
{
  if (!p_is)
    {
      return false; // Fichier introuvable ou problème d'ouverture
    }

  string ligne;

  // **Lecture et validation des informations du client**

  // Nom
  if (!getline (p_is, ligne) || ligne.empty () || !validerFormatNom (ligne))
    {
      return false;
    }

  // Prénom
  if (!getline (p_is, ligne) || ligne.empty () || !validerFormatNom (ligne))
    {
      return false;
    }

  // Date de naissance (jj mm aaaa)
  if (!getline (p_is, ligne) || ligne.empty ())
    {
      return false;
    }

  istringstream is_naissance (ligne);
  int jour = 0, mois = 0, annee = 0;
  if (!(is_naissance >> jour >> mois >> annee) || jour <= 0 || mois <= 0 || annee <= 0)
    {
      return false;
    }

  // Téléphone
  if (!getline (p_is, ligne) || ligne.empty ())
    {
      return false;
    }

  // Numéro de folio bancaire
  if (!getline (p_is, ligne) || ligne.empty ())
    {
      return false;
    }

  // comptes bancaires
  while (getline (p_is, ligne))
    {
      if (ligne.empty ())
        {
          return false; //Ligne vide détectée (format incorrect)
        }

      istringstream is_ligne (ligne);
      string type_compte;
      is_ligne >> type_compte;

      //Si le compte est un **chèque**
      if (type_compte == "cheque")
        {
          int num_compte = 0, nb_transactions = 0;
          double taux_interet = 0, solde = 0, taux_interet_min = 0;
          string description;

          // Vérification des valeurs
          if (!(p_is >> num_compte >> taux_interet >> solde))
            {
              return false;
            }
          p_is.ignore (); // Ignorer la fin de ligne

          if (!getline (p_is, description) || description.empty ())
            {
              return false;
            }

          if (!(p_is >> nb_transactions >> taux_interet_min))
            {
              return false;
            }
          p_is.ignore (); // Ignorer la fin de ligne
        }

        //compte est un épargne
      else if (type_compte == "epargne")
        {
          int num_compte = 0, j = 0, m = 0, a = 0;
          double taux_interet = 0, solde = 0;
          string description, échéance;

          // Vérification des valeurs
          if (!(p_is >> num_compte >> taux_interet >> solde))
            {
              return false;
            }
          p_is.ignore ();

          if (!getline (p_is, description) || description.empty ())
            {
              return false;
            }

          if (!getline (p_is, échéance) || échéance.empty ())
            {
              return false;
            }

          istringstream is_échéance (échéance);
          if (!(is_échéance >> j >> m >> a) || j <= 0 || m <= 0 || a <= 0)
            {
              return false;
            }
        }

        //Cas où le type de compte est invalide
      else
        {
          return false;
        }
    }

  return true; //Le fichier est valide
}
}