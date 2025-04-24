/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include "CompteDejaPresentException.h"

namespace bancaire {
/**
 * \file CompteDejaPresentException.cpp
 * \brief implémentation des méthodes de l'exception CompteDejaPresentException
 */


/** \brief constructeur de l'exception CompteDejaPresentException */

CompteDejaPresentException::CompteDejaPresentException (const std::string& p_raison)
:CompteException(p_raison){};
}// namespace bancaire