#include "Datenbank.h"

Datenbank::Datenbank(){}

Datenbank * Datenbank::instance = 0;

Datenbank * Datenbank::getInstance(){
     if (instance == 0)
     {
         instance = new Datenbank();
     }

     return instance;
 }


