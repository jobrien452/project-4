#include "racket.h"

Racket :: Racket (QRect r, QString up, Qstring down, int m)
: Collidable ( r ){
    up = new QKeySequence(tr(up));
    down = new QKeySequence(tr(down));
    max = m;
    mstate = 0;
    lstate = 0;
}

&QRect Racket :: rRect(){
   return &shape;
}

&int Racket :: rstate(){
    return &mstate;
}

int Racket :: max(){
    return max;
}
/*
void Racket :: press(QKeySequence x){
    if(mstate == 0){ 
        if(up.matches(x) && shape.topLeft().y() >= 0){
            mstate = 1;
        }else if(down.matches(x) && shape.bottomLeft().y() <= max){
       		mstate = 2;
        }
    }
}

void Racket :: release(QKeySequence x){
    if(mstate != 0){
        if(up.matches(x) || down.matches(x)){
}
*/

