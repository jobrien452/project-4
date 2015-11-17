#include "racket.h"

Racket :: Racket (QRect r, QString up, Qstring down, int m)
: Collidable ( r ){
    up = new QKeySequence(tr(up));
    down = new QKeySequence(tr(down));
    max = m;
    mstate = 0;
}

bool Racket :: collision(QRect r){
    return Collidable::collision(r);
}

int Racket :: pressed(){
    return mstate;
}

int& Racket :: rmax(){
    return &max;
}

void Racket :: press(QKeySequence x){
    if(up.matches(x) && shape.topLeft().y() >= 0){
        mstate = 1;
    }else if(down.matches(x) && shape.bottomLeft().y() <= max){
        mstate = 2;
    }else{
        mstate = 0; 
    }
}

void Racket :: moveUp(){
    shape.moveCenter(QPoint(shape.center().x(), shape.center().y()-1));
}

void Racket :: moveDown(){
    shape.moveCenter(QPoint(shape.center().x(), shape.center().y()+1));
}

void Racket :: draw()
