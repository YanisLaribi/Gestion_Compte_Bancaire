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
namespace bancaire
{

  class CompteException : public std::runtime_error
  {
  public:

    /**
     * \brief Constructeur de l'exception
     * \param[in] p_raison La raison de l'exception
     */

    CompteException (const std::string& p_raison)
    : std::runtime_error (p_raison) { };


  };

  /**
   *\class CompteDejaPresentException
   * \brief class qui vérifie si un compte est déjà présent
   */
  class CompteDejaPresentException : public CompteException
  {
  public:

    /**
     * \brief Constructeur de la class CompteDejaPresentException
     * param[in] p_raison La raison de l'exception
     */
    CompteDejaPresentException (const std::string& p_raison)
    : CompteException (p_raison) { };

  };


/**
   * \class CompteException
   * \brief Exception si le Compte est absent
   */

  class CompteAbsentException : public CompteException
  {
  public:
    /**
     * \brief Constructeur de la class CompteAbsentException
     * \param[in] p_raison La raison de l'exception
     */
      CompteAbsentException (const std::string& p_raison)
  : CompteException (p_raison) { };

  };
  
} //namespace bancaire

#endif /* COMPTEEXCEPTION_H */

