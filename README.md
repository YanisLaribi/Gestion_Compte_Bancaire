# Gestion de Comptes Bancaires

Projet C++ orienté objet pour la gestion de clients et de comptes bancaires avec validation, gestion d’exceptions et calcul d’intérêts.

## Fonctionnalités principales

- Création, gestion et suppression de clients et de comptes bancaires.
- Prise en charge de différents types de comptes : **Épargne** et **Chèque**.
- Calcul automatique des intérêts selon le type de compte.
- Validation stricte des entrées utilisateurs et des fichiers.
- Système d’exceptions personnalisées pour une meilleure robustesse.

## Interface graphique Qt

Une interface graphique moderne et intuitive a été développée avec **Qt** afin de faciliter l’utilisation du programme :

- Gestion des clients et comptes via des fenêtres et des formulaires interactifs.
- Affichage dynamique des informations et des relevés.
- Manipulation simplifiée (ajout, suppression, modification) via boutons et menus.

## Architecture du projet

- `Client` : Gère les informations personnelles et la liste des comptes d’un client.
- `Compte` : Classe de base abstraite. Permet l’extension vers :
    - `Epargne` : Calcul d’intérêts standard, gestion du solde.
    - `Cheque` : Gestion du nombre de transactions, taux d’intérêt minimum, règles spécifiques au compte chèque.
- `Date` : Outils pour la gestion et validation des dates, et le formatage.
- `validationFormat` : Fonctions pour valider les formats (nom, date, téléphone, fichier).
- `CompteException` : Gestion centralisée des erreurs spécifiques au métier bancaire.


##Projet développé dans un but d’apprentissage.
