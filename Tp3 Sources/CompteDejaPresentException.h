/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   CompteDejaPresentException.h
 * Author: etudiant
 *
 * Created on 20 avril 2025, 21 h 14
 */

#ifndef COMPTEDEJAPRESENTEXCEPTION_H
#define COMPTEDEJAPRESENTEXCEPTION_H

#include "CompteException.h"

class CompteDejaPresentException : public CompteException
{
public:
  CompteDejaPresentException (const std::string& p_raison);

};

#endif /* COMPTEDEJAPRESENTEXCEPTION_H */

