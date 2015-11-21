#include "model.h"

Model :: Model(int w, int h){
	maxh = h;
	maxw = w;
	frame(w,h);
	racket1(QPoint(5, maxh/2),paddle);
	racket2(QPoint(maxw-paddle.width()-5, maxh/2),paddle);
	ball(QPoint(maxw/2, maxh/2),sball);//temp declaration
	score1 = 0;
	score2 = 0;
	bVel = initBallVelocity; //temp declaration
	ballang = 0; //temp declaration
    r1state = Model::STOP;
}

void Model :: setStateR1(QKeyEvent * e){
    if(r1state == Model::STOP && !e->isAutoRepeat()){
        if(r1state == Model::UP && e->key() == Qt::Key_A){
            r1state = Model::UP;
            return;
        }else if(r1state == Model::Down && e->key() == Qt::Key_S){
            r1state = Model::DOWN;
            return;
        }
    }else if(r1state != Model::STOP && !e->isAutoRepeat()){
        r1state = Model::STOP;
        return;
    }   	
}

void Model :: setStateR2(QKeyEvent * e){
    if(r2state == Model::STOP && !e->isAutoRepeat()){
        if(r2state == Model::UP && e->key() == Qt::Key_K){
            r2state = Model::UP;
            return;
        }else if(r2state == Model::Down && e->key() == Qt::Key_L){
            r2state = Model::DOWN;
            return;
        }
    }else if(r2state != Model::STOP && !e->isAutoRepeat()){
        r2state = Model::STOP;
        return;
    }   	
}

int Model :: nextStepR1(){
    return rakStep * r1state;
}

int Model :: nextStepR2(){
    return rakStep * r2state;
}

QRect Model :: &rBall(){
    return &ball;
}

QRect Model :: &rRacket1(){
    return &racket1;
}

QRect Model :: &rRacket2(){
    return &racket2;
}

QSize Model :: getSize(){
    return frame;
}

float Model :: &rBallvel(){
    return &balVel;
}

int Model :: &rScore1(){
    return &score1;
}

int Model :: &rScore2(){
    return &score2;
}

float Model :: &rBallang(){
    return &ballang;
}

int Model :: getHeight(){
    return maxh;
}

int Model :: getWidth(){
    return maxw;
}

void Model :: draw(QPainter * painter){
    painter -> setPen(Qt::white);
    painter -> drawRect(racket1);
    painter -> drawRect(racket2);
    painter -> fillRect(ball, Qt::white);
    painter -> drawText(QPoint(maxw/2 - 10, 15), QString::number(score1));
    painter -> drawText(QPoint(maxw/2 + 10, 15), QString::number(score2));
}

void Model :: update() {
    emit init();
}

void Model :: queEvent(QKeyEvent * e){
    emit pushEvent(e);
}
