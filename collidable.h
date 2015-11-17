#ifndef COLLIDABLE_H
#define COLLIDABLE_H

#include <QObject>
#include <QPoint>
#include <QRect>
#include <QList>

class Collidable : public QObject {
    
    Q_OBJECT

    public:
        Collidable();
        void setRect(QRect);
        QRect getRect();
        virtual bool collision(QRect);
    private:
        QRect shape;

};

#endif
