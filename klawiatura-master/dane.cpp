#include "dane.h"
#include"klawiatura.h"
#include<QTime>
#include<QTextCursor>
#include<ctime>
#include <QInputDialog>
extern Klawiatura *w;
Dane::Dane(QTextStream *q,QGraphicsItem *parent):QGraphicsTextItem(parent)
{
    time=new QTime(QTime::currentTime());
    setDefaultTextColor(Qt::green);
    setFont(QFont("comic sans",20));
    setTextWidth(w->width());
    QInputDialog *a = new QInputDialog();
    QString user = a->getText(w,tr("Wprowadzanie nazwy"),tr("Podaj nazwe uzytkownika"));
    dane = q;
    t+=dane->readLine();
    setPlainText(t);
}

void Dane::keyPressEvent(QKeyEvent *event)
{
    Klawisz *klawisz=new Klawisz;
    klawisz->t[1]=event->key();
    klawisz->x=poprzedni-QTime::currentTime().msecsTo(*time);
    klawisz->t[0] = poprzedni_klawisz;
    poprzedni_klawisz = klawisz->t[1];
    poprzedni=QTime::currentTime().msecsTo(*time);
    klawisz->v=QTime::currentTime().msecsTo(*time);
    if(event->key()==Qt::Key_Backspace)
    {
        t=t.remove(t.size()-1,1);
        setPlainText(t);
    }
    else k.insert(k.end(),klawisz);
}

void Dane::keyReleaseEvent(QKeyEvent *event)
{
    for(Klawisz *kl:k)
        if(kl->t[1]==event->key())
        {
            kl->v-=QTime::currentTime().msecsTo(*time);
            t+=kl->t[0];
            t+=kl->t[1];
            t+=" "+QString::number(kl->v)+" "+QString::number(kl->x)+" ";
            setPlainText(t);
            Przechowywanie *nazwa = new Przechowywanie(user,kl->t,kl->x,kl->v,dane);
            lista_danych.insert(lista_danych.end(),nazwa);
            k.removeOne(kl);
        }
}

