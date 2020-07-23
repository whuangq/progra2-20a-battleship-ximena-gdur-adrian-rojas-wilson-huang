#include "Menu.h"
#include "Button.h"
#include <QGraphicsTextItem>

void Menu::displayMenu()
{
    QGraphicsTextItem* titleText = new QGraphicsTextItem(QString("Space Wars"));
    QFont titleFont("comic sans",50);
    titleText->setFont(titleFont);
    int txPos = this->width()/2 - titleText->boundingRect().width()/2;
    int tyPos = 150;
    titleText->setPos(txPos,tyPos);
    scene->addItem(titleText);

    Button* playButton = new Button(QString("Play"));
    int bxPos = this->width()/2 - titleText->boundingRect().width()/2;
    int byPos = 275;
    playButton->setPos(bxPos,byPos);
    //connect(playButton,SIGNAL(clicked()),this,SLOT(play()));
    scene->addItem(playButton);

}
