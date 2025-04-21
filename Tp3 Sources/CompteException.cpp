/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include "CompteException.h"

CompteException::CompteException (const std::string& p_raison)
: std::runtime_error (p_raison) { };