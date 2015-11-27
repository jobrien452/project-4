#include "model.h"

Model :: Model(int w, int h): mMutex(){
    maxh = h;
    maxw = w;
    frame = QSize(w,h);
    racket1 = QRect(QPoint(5, maxh/2),paddle);
    racket2 = QRect(QPoint(maxw-paddle.width()-5, maxh/2),paddle);
    ball = QRectF(QPoint(maxw/2, maxh/2),sball);//temp declaration
    score1 = 0;
    score2 = 0;
    balVel = 0; //temp declaration
    ballang = 0; //temp declaration
    r1state = Model::STOP;
    r2state = Model::STOP;
}

void Model :: setStateR1(int k, bool r){
    //qDebug()<<e->text();
    //QMutexLocker(&mMutex);
    if(r1state == Model::STOP && !r){
        if(k == Qt::Key_A){
            r1state = Model::UP;
            return;
        }else if(k == Qt::Key_S){
            r1state = Model::DOWN;
            return;
        }
    }else if(r1state != Model::STOP && !r){
        r1state = Model::STOP;
        return;
    }   	
}

void Model :: setStateR2(int k, bool r){
    //QMutexLocker(&mMutex);
    if(r2state == Model::STOP && !r){
        if(k == Qt::Key_K){
            r2state = Model::UP;
            return;
        }else if(k == Qt::Key_L){
            r2state = Model::DOWN;
            return;
        }
    }else if(r2state != Model::STOP && !r){
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

QRectF& Model :: rBall(){
    return ball;
}

QRect& Model :: rRacket1(){
    return racket1;
}

QRect& Model :: rRacket2(){
    return racket2;
}

QSize Model :: getSize(){
    return frame;
}

float& Model :: rBallvel(){
    return balVel;
}

int& Model :: rScore1(){
    return score1;
}

int& Model :: rScore2(){
    return score2;
}

float& Model :: rBallang(){
    return ballang;
}

int Model :: getHeight(){
    return maxh;
}

int Model :: getWidth(){
    return maxw;
}

QMutex& Model :: getMutex(){
    return mMutex;
}

void Model :: draw(QPainter * painter){
    //QMutexLocker(&mMutex);
    painter -> setPen(Qt::white);
    painter -> drawRect(racket1);
    painter -> drawRect(racket2);
    painter -> setBrush(Qt::white);
    painter -> drawEllipse(ball);
    painter -> setFont(QFont("Arial", 20, QFont::Bold));
    painter -> drawText(QPoint(maxw/2 - 25, 25), QString::number(score1));
    painter -> drawText(QPoint(maxw/2 + 12, 25), QString::number(score2));
    //qDebug() << "check " << ball;
}

void Model :: update() {
  //  qDebug() << "emitted\n";
    emit init();
}

void Model :: queEvent(QKeyEvent * e){
    //qDebug() << "emitted " << e->key() << "\n";
    emit pushEvent(e);
}
