#ifndef DANE_H
#define DANE_H
#include<QKeyEvent>
#include<QGraphicsItem>
#include<QTimer>
#include<QTime>
#include<QString>
#include"przechowywanie.h"
#include<QTextStream>

class Klawisz
{
public:
    char t[2];
    int v;
    int x;
};
class Dane: public QGraphicsTextItem
{
    Q_OBJECT
public:
    Dane(QTextStream*,QGraphicsItem *parent=0);
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
private:
    QTime *time;
    QList<Klawisz*> k;
    QString t;
    int poprzedni=0;
    char poprzedni_klawisz=0;
    QString user;
    QList<Przechowywanie*> lista_danych;
    QTextStream *dane;
};

#endif // DANE_H
