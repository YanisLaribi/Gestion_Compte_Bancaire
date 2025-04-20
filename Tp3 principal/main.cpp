/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: etudiant
 *
 * Created on 2 avril 2025, 12 h 51
 */

#include <iostream>
#include <string>
#include <limits>
#include "Client.h"
#include "Cheque.h"
#include "Epargne.h"

using namespace std;
using namespace bancaire;
using namespace util;

bool validerNom(const string& nom) {
    return validerFormatNom(nom);
}

bool validerTelephone(const string& tel) {
    return !tel.empty();
}

int main() {
    cout << "-----------------------------------------------\n";
    cout << "   Bienvenue a l'outil de gestion de comptes\n";
    cout << "-----------------------------------------------\n\n";

    int folio;
    do {
        cout << "Folio (entier entre 1000 et 9999) : ";
        cin >> folio;
        if (folio < 1000 || folio >= 10000)
            cout << "numéro incorrect, doit être dans l’intervalle [1000, 10000[, recommencez\n";
    } while (folio < 1000 || folio >= 10000);

    string nom;
    do {
        cout << "Nom (lettres, espaces ou tirets, pas de caractères spéciaux) : ";
        cin >> nom;
        if (!validerNom(nom))
            cout << "nom invalide, recommencez\n";
    } while (!validerNom(nom));

    string prenom;
    do {
        cout << "Prénom (mêmes conditions que le nom) : ";
        cin >> prenom;
        if (!validerNom(prenom))
            cout << "prénom invalide, recommencez\n";
    } while (!validerNom(prenom));

    int jour, mois, annee;
    do {
        cout << "Date de naissance\n";
        cout << "Le jour [1...31] : "; cin >> jour;
        cout << "Le mois [1...12] : "; cin >> mois;
        cout << "L'année : "; cin >> annee;
        if (!Date::validerDate(jour, mois, annee))
            cout << "date invalide, recommencez\n";
    } while (!Date::validerDate(jour, mois, annee));

    Date dateNaissance(jour, mois, annee);

    string telephone;
    cin.ignore();
    do {
        cout << "Téléphone (ne doit pas être vide) : ";
        getline(cin, telephone);
        if (!validerTelephone(telephone))
            cout << "téléphone invalide, recommencez\n";
    } while (!validerTelephone(telephone));

    Client client(folio, nom, prenom, telephone, dateNaissance);

    // Saisie compte chèque
    cout << "\nSaisir les informations sur le nouveau compte Cheque\n";
    int noCheque, nbTrans;
    string descCheque;
    double tauxCheque, tauxMinCheque;
    float soldeCheque;

    do {
        cout << "numéro de compte (entier positif) : "; cin >> noCheque;
    } while (noCheque <= 0);

    cin.ignore();
    do {
        cout << "Description (non vide) : "; getline(cin, descCheque);
    } while (descCheque.empty());

    do {
        cout << "Taux d'Intéret (supérieur au taux minimum) : "; cin >> tauxCheque;
    } while (cin.fail());

    do {
        cout << "Solde : "; cin >> soldeCheque;
    } while (cin.fail());

    do {
        cout << "Nombre de transaction (entre 0 et 40) : "; cin >> nbTrans;
    } while (nbTrans < 0 || nbTrans > 40);

    do {
        cout << "Taux d'intérêt minimum (inférieur au taux d'intérêt) : "; cin >> tauxMinCheque;
    } while (tauxCheque <= tauxMinCheque);

    Cheque cheque(noCheque, tauxCheque, soldeCheque, nbTrans, tauxMinCheque, descCheque);
    client.ajouterCompte(cheque);

    // Saisie compte épargne
    cout << "\nSaisir les informations sur le nouveau compte Epargne\n";
    int noEpargne;
    string descEpargne;
    double tauxEpargne;
    float soldeEpargne;

    do {
        cout << "numéro de compte (entier positif) : "; cin >> noEpargne;
    } while (noEpargne <= 0);

    cin.ignore();
    do {
        cout << "Description (non vide) : "; getline(cin, descEpargne);
    } while (descEpargne.empty());

    do {
        cout << "Taux d'Intéret (entre 0.001 et 0.035) : "; cin >> tauxEpargne;
    } while (tauxEpargne < 0.001 || tauxEpargne > 0.035);

    do {
        cout << "Solde (positif ou nul) : "; cin >> soldeEpargne;
    } while (soldeEpargne < 0);

    Epargne epargne(noEpargne, tauxEpargne, soldeEpargne, descEpargne);
    client.ajouterCompte(epargne);

    // Affichage du relevé
    cout << "\nRelevé de compte\n";
    cout << "----------------\n";
    cout << client.reqReleves();

    return 0;
}
