#include "klawiatura.h"
#include<QBrush>
#include<QMediaPlayer>
#include<QFile>
Klawiatura::Klawiatura(QWidget *parent)
{
    QRect rec=QApplication::desktop()->screenGeometry();
    scene = new QGraphicsScene(this);
    scene->setSceneRect(0,0,rec.width(),rec.height());
    QImage image(":/images/keyboard.jpg");
    image=image.scaled(rec.width(),rec.height());
    setBackgroundBrush(QBrush(image));
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(rec.width(),rec.height());
    setScene(scene);
    muzyka = new QMediaPlayer();
    muzyka->setMedia(QUrl("qrc:/sounds/wiedmin.mp3"));
    QFile file;
    file.setFileName(":/text/dane.txt");
    file.open(QIODevice::WriteOnly | QIODevice::Text);

    plik = new QTextStream(&file);
    plik->seek(0);




}
void Klawiatura::displayMenu()
{
    clear();
    Przycisk *przycisk=new Przycisk(QString("Wyjscie"));
    przycisk->setX(this->width()/2-przycisk->boundingRect().width()/2);
    przycisk->setY(this->height()/2);
    connect(przycisk,SIGNAL(clicked()),this,SLOT(wyjscie()));
    scene->addItem(przycisk);
    przycisk=new Przycisk(QString("Dodaj nowego uzytkownika"));
    przycisk->setX(this->width()/2-przycisk->boundingRect().width()/2);
    przycisk->setY(this->height()/2-przycisk->boundingRect().height());
    connect(przycisk,SIGNAL(clicked()),this,SLOT(start()));
    scene->addItem(przycisk);
    //muzyka->play();
}

void Klawiatura::clear()
{
    dane.clear();
    for(QGraphicsItem *n:items())
        if(n->parentItem()==0) scene->removeItem(n);
}

void Klawiatura::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_Escape) displayMenu();
    for(Dane *d:dane) d->keyPressEvent(event);
}

void Klawiatura::keyReleaseEvent(QKeyEvent *event)
{
    for(Dane *d:dane) d->keyReleaseEvent(event);
}

void Klawiatura::start()
{
    clear();
    Dane *d=new Dane(plik);
    dane.insert(dane.end(),d);
    scene->addItem(d);
}
void Klawiatura::wyjscie()
{
    QApplication::quit();
}

