/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   CompteException.h
 * Author: etudiant
 *
 * Created on 20 avril 2025, 21 h 25
 */

#ifndef COMPTEEXCEPTION_H
#define COMPTEEXCEPTION_H

#include <string>
#include <stdexcept>

/**
 * \class CompteException
 * \brief Exception personnalisée pour les erreurs liées aux comptes bancaires.
 */

class CompteException : public std::runtime_error
{
public:
      /**
     * \brief Constructeur de l'exception
     * \param[in] p_raison La raison de l'exception
     */
  CompteException (const std::string& p_raison);
};

#endif /* COMPTEEXCEPTION_H */

