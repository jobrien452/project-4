#ifndef RACKET_H
#define RACKET_H

#include "collidable.h"
class Racket : public Collidable {

    Q_OBJECT

    public:
        Racket();
        bool collision(QRect);
    

    public slots:
        void moveUp();
        void moveDown();
};

#endif
