#ifndef PRZECHOWYWANIE_H
#define PRZECHOWYWANIE_H
#include<QString>
#include<QTextStream>

class Przechowywanie
{
public:
    Przechowywanie(QString,char[],int,int,QTextStream*);
    double odleglosc(Przechowywanie);
    void zapisywanie();

private:
    QString user;
    char sekwencja[2];
    int pomiedzy;
    int czas_wcisniecia;
    QTextStream *dowolne;
};

#endif // PRZECHOWYWANIE_H
