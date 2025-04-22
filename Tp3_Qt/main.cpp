/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/qtFiles/main.cc to edit this template
 */

/*
 * File:   main.cpp
 * Author: etudiant
 *
 * Created on 21 avril 2025, 19 h 15
 */

#include "fenetrePrincipale.h"
#include <QApplication>

int
main (int argc, char *argv[])
{
  // initialize resources, if needed
  // Q_INIT_RESOURCE(resfile);

  QApplication app (argc, argv);
  

  // create and show your widgets here
  FenetrePrincipale Fenetre; 
  Fenetre.show();

  return app.exec ();
}
