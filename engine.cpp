#include <QSize>
#include <QDebug>
#include "engine.h"

Engine :: Engine(Model*  m){
    data = m;
    connect(data, SIGNAL(pushEvent(QKeyEvent *)), this, SLOT(addEvent(QKeyEvent *)));
    connect(data, SIGNAL(init()), this, SLOT(update()));
    setup();
}

void Engine :: setup(){
    start = 0;
    data->rBall().moveLeft(data->getWidth()/2);
    data->rBallvel() = randF(vmin, vmax);
    data->rBall().moveTop(randF(omin,omax));
    data->rBallang() = randF(amin, amax);
}

float Engine :: randF(float min, float max){
    std::default_random_engine el(rd());
    std::uniform_real_distribution<float> uniform_dist(min, max);
    return uniform_dist(el);
}

void Engine :: checkCollision(){
    if(checkWin())
        return;

    bounce();
    
}

bool Engine :: checkWin(){
    if(data->rBall().center().x()>data->getWidth()){
        data->rScore1()++;
        reset();
        return true;
    }else if(data->rBall().center().x()<0){
        data->rScore2()++;
        reset();
        return true;
    }
    return false;
}

void Engine :: pushEvents(){
    for(int i = 0; i < keys.size(); i++){
        data->setStateR1(keys[i], repeat[i]);
        data->setStateR2(keys[i], repeat[i]);
        movePaddles();
    }
    keys.clear();
    repeat.clear();
}

void Engine :: movePaddles(){
    if(data->nextStepR1() != 0){
        if(data->rRacket1().bottomLeft().y()+data->nextStepR1() < data->getHeight() &&
            data->rRacket1().topLeft().y()+data->nextStepR1() > 0){

            data->rRacket1().moveCenter(
                    QPoint(data->rRacket1().center().x(),
                    data->rRacket1().center().y()+data->nextStepR1())
            );
        }
    }

    if(data->nextStepR2() != 0){
        if(data->rRacket2().bottomLeft().y()+data->nextStepR2() < data->getHeight() &&
            data->rRacket2().topLeft().y()+data->nextStepR2() > 0){
        
            data->rRacket2().moveCenter(
                    QPoint(data->rRacket2().center().x(),
                    data->rRacket2().center().y()+data->nextStepR2())
            );
        }
    }
}

void Engine :: bounce(){
    ballStep();
    if(data->rBall().top() < 0){
        data->rBall().moveTop(0);
        data->rBallang() = fmodf(-data->rBallang(), 2 * PI);
    }else if(data->rBall().bottom() > data->getHeight()){
        data->rBall().moveBottom(data->getHeight());
        data->rBallang()= fmodf(-data->rBallang(), 2 * PI);
    }

    if(data->rBall().intersects(data->rRacket1()) && 
        data->rBall().intersected(data->rRacket1()).x() > 
        data->rRacket1().center().x()){

        data->rBall().moveLeft(data->rRacket1().topRight().x()+3);
        //data->rBallvel()= -data->rBallvel();
        bounceAng();
        return;
    }else if(data->rBall().intersects(data->rRacket2()) &&
        data->rBall().intersected(data->rRacket2()).x() < 
        data->rRacket2().center().x()){

        data->rBall().moveRight(data->rRacket2().topLeft().x()-3);
        //data->rBallvel()= -data->rBallvel(); 
        bounceAng();
        return;
    }
}

void Engine :: ballStep(){
    float xStep = data->rBallvel()* cos(data->rBallang());
    float yStep = data->rBallvel()* sin(data->rBallang());
    data->rBall().moveCenter(
        QPointF(data->rBall().center().x()+xStep,
        data->rBall().center().y()+yStep));
    
}

void Engine :: bounceAng(){
    float angle = fmodf(data->rBallang() + PI, 2 * PI);
    if(angle == 0 || abs(angle) == PI/2 || abs(angle) == PI
        || abs(angle) == PI + PI/2){

        angle += 1;
    }
    data->rBallang() = angle;
}
 
void Engine :: update(){
    if(start > 180){
        pushEvents();
        checkCollision();
    }else{
        start++;
    }
}

void Engine :: addEvent(QKeyEvent * e){
    //qDebug()<< "E:" << e->text();
    repeat.append(e->isAutoRepeat());
    keys.append(e->key());

}

void Engine :: reset(){
    setup();
}
