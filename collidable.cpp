#include "collidable.h"

Collidable :: Collidable(QRect r){
    shape = r;
}

void Collidable :: setRect(QRect r){
    shape = r;
}

QRect Collidable :: getRect(){
    return shape;
}

bool Collidable :: collision(QRect r){
    return shape.intersects(r);
}
