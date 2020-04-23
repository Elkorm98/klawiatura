#include "przechowywanie.h"
#include <cmath>

Przechowywanie::Przechowywanie(QString a,char b[], int c, int t,QTextStream* d)
{
    user = a;
    sekwencja[0] = b[0];
    sekwencja[1] = b[1];
    pomiedzy = c;
    czas_wcisniecia = t;
    dowolne = d;
}

double Przechowywanie::odleglosc(Przechowywanie a)
{
    int x = a.pomiedzy-pomiedzy;
    int y = a.czas_wcisniecia-czas_wcisniecia;
    return sqrt(x*x+y*y);
}

void Przechowywanie::zapisywanie()
{
    *dowolne<<user<<'\n';
    *dowolne<<sekwencja[0]<<" "<<sekwencja[1]<<'\n';
    *dowolne<<pomiedzy<<'\n';
    *dowolne<<czas_wcisniecia<<'\n';
}
