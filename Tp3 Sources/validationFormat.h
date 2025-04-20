/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   validationFormatNom.h
 * Author: etudiant
 *
 * Created on 11 février 2025, 16 h 04
 */

#ifndef VALIDATIONFORMATNOM_H
#define VALIDATIONFORMATNOM_H
#include <cstdlib>
#include <iostream>

namespace util{
const char liste1[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNIOQRSTUVWXYZÀÁÂÃÄÅÆÇÈÉÊËÌÍÎÏÑÒÓÔÕÖÙÚÛÜÝàáâãäåæçèéêëìíîïñòóôõöùúûüýÿ -";
const char liste2[] = "ÀÁÂÃÄÅÆÇÈÉÊËÌÍÎÏÑÒÓÔÕÖÙÚÛÜÝàáâãäåæçèéêëìíîïñòóôõöùúûüýÿ -";

bool validerFormatNom (const std::string & p_nom);

bool validerFormatFichier (std::istream& p_is);
}
#endif

