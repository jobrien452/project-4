#ifndef RACKET_H
#define RACKET_H

#include <QKeySequence>
#include <QString>
#include "collidable.h"
class Racket : public Collidable {

    Q_OBJECT

    public:
        Racket(QRect, QString, QString);
        bool collision(QRect);
        bool pressed();
        void press(bool);
	int& rmax();
    private:
	QKeySequence *  up, down;
        int mstate, lstate, max;
    public slots:
        void moveUp();
        void moveDown();
};

#endif
