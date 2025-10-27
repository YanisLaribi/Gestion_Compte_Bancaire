Gestion de Comptes Bancaires — README
Ce projet en C++ propose une modélisation complète pour gérer des clients et leurs comptes bancaires, incluant la gestion des exceptions, la validation des formats et le calcul d’intérêts selon différents types de comptes.

Fonctionnalités principales
Création, gestion et suppression de clients et de comptes bancaires.

Deux types de comptes : Epargne et Chèque, chacun avec ses propres règles et modes de calcul d’intérêt.​

Validation stricte des entrées (nom, date, téléphone, format du fichier).​

Gestion des erreurs et exceptions personnalisées (CompteException).​

Manipulation et formatage des informations de comptes et de clients.​

Structure du projet
Client : Représente une personne cliente avec ses informations et une liste de comptes.​

Compte : Classe de base pour les comptes bancaires, permettant l’extension vers Epargne ou Chèque.​

Epargne : Spécialisation de Compte pour modéliser un compte d’épargne avec calcul d’intérêt propre.​

Cheque : Spécialisation de Compte pour modéliser un compte chèque avec gestion du nombre de transactions, du taux d’intérêt minimal et du calcul d’intérêt adapté.​

Date : Utilitaire pour la gestion et la validation des dates, le formatage et les opérations calendaires.​

validationFormat : Fonctions utilitaires pour valider les formats de nom, de date, de téléphone, et de fichiers clients.​

CompteException : Gestion centralisée des exceptions métier pour la robustesse de l’application.​

Utilisation
Création de clients et de comptes via les constructeurs.

Ajout, modification, suppression de comptes pour chaque client.

Validation automatisée des données lors de la création des objets.

Affichage formaté des informations personnelles et des relevés de comptes.
