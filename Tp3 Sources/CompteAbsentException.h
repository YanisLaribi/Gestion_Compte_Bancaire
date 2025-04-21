/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   CompteAbsentException.h
 * Author: etudiant
 *
 * Created on 20 avril 2025, 22 h 21
 */

#ifndef COMPTEABSENTEXCEPTION_H
#define COMPTEABSENTEXCEPTION_H

#include "CompteException.h"

/**
 * \class CompteException
 * \brief Exception si le Compte est absent
 */

class CompteAbsentException : public CompteException
{
public:
  /**
   * \brief Constructeur de l'exception
   * \param[in] p_raison La raison de l'exception
   */
  CompteAbsentException (const std::string& p_raison);
};

#endif /* COMPTEABSENTEXCEPTION_H */