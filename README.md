# Gestion de Comptes Bancaires

Projet C++ orienté objet pour la gestion de clients et de comptes bancaires avec validation, gestion d’exceptions et calcul d’intérêts.

## Fonctionnalités principales

- Création, gestion et suppression de clients et de comptes bancaires.
- Prise en charge de différents types de comptes : **Épargne** et **Chèque**.
- Calcul automatique des intérêts selon le type de compte.
- Validation stricte des entrées utilisateurs et des fichiers.
- Système d’exceptions personnalisées pour une meilleure robustesse.

## Architecture du projet

- `Client` : Gère les informations personnelles et la liste des comptes d’un client.
- `Compte` : Classe de base abstraite. Permet l’extension vers :
    - `Epargne` : Calcul d’intérêts standard, gestion du solde.
    - `Cheque` : Gestion du nombre de transactions, taux d’intérêt minimum, règles spécifiques au compte chèque.
- `Date` : Outils pour la gestion et validation des dates, et le formatage.
- `validationFormat` : Fonctions pour valider les formats (nom, date, téléphone, fichier).
- `CompteException` : Gestion centralisée des erreurs spécifiques au métier bancaire.

## Utilisation

1. Création d’un client et de comptes associés via les constructeurs fournis.
2. Ajout, modification, ou suppression de comptes pour chaque client possible via des méthodes dédiées.
3. Validation automatique de toutes les données fournies.
4. Affichage des détails et relevés des comptes au format lisible.


Projet développé dans un but d’apprentissage, pensé pour garantir la cohérence et la sécurité des données bancaires à travers une architecture orientée objet rigoureuse.
