#ifndef BALL_H
#define BALL_H

#include "collidable.h"

class Ball : public Collidable {
    
    Q_OBJECT
    public:
        Ball();
        bool collision(QRect);
    public slots:
        void reset();
};

#endif
