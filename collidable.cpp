#include "collidable.h"

Collidable :: Collidable(){
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
