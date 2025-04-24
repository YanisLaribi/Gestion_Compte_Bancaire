/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

namespace bancaire{
#include "CompteAbsentException.h"

/**
 * \file CompteAbsentException
 * \brief Implémentation des méthode de l'exception CompteAbsentException
 */

/** \brief constructeur de l'exception CompteAbsentException */
CompteAbsentException::CompteAbsentException(const std::string& p_raison)
        :CompteException(p_raison){};
}// namespace bancaire