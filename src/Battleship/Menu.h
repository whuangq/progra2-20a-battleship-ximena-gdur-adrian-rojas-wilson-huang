#ifndef MENU_H
#define MENU_H

#include <QGraphicsView>
#include <QGraphicsScene>

class Menu: public QGraphicsView{
    public:
        Menu(QWidget* parent=NULL);

        void start();
        void displayMenu();

        QGraphicsScene* scene;
};
#endif // MENU_H
