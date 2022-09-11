#ifndef REMINDER_KLASSE_H
#define REMINDER_KLASSE_H

#include "Nutzerprofil.h"
#include "Termin_Klasse.h"
#include <QMessageBox>

//Author André Zimmer

class Reminder{

public:

    void runReminer(){
        NProfil *NP = NProfil::getInstance();

        QDate date;
        date.currentDate();

        Termin R;
       QVector <Termin>  Rem =  R.TermineHeuteMitErinnerungen(NP->idNutzer);

       for(int i = 0; i < Rem.size(); i++)
       {
           QTime T;
           T = T.currentTime();
           QTime TIME(T.hour(),T.minute());

           if(TIME==Rem[i].Erinnerung){

               QMessageBox msgBox;
               QString str1("Nicht vergessen, es ist um ");
               QString str2(Rem[i].Beginn.toString());
               QString str3(" der Termin ");
               QString str4(Rem[i].TerminName);
               QString text (str1 + str2 + str3 + str4);


               msgBox.setText(text);

               msgBox.exec();

            R.Update_Erinnerung_NULL(Rem[i].idTermin);

           }
       }
    }
};

#endif // REMINDER_KLASSE_H
