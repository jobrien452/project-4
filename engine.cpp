#include <QSize>
#include "engine.h"

Engine :: Engine(Model m){
    data = &m;
    connect(data, SIGNAL(pushEvent(QKeyEvent *)), this, SLOT(addEvent(QKeyEvent *)));
    connect(data, SIGNAL(init()), this, SLOT(update()));
    setup();
}

void Engine :: setup(){
    start = 0;
    data->rBallvel() = randF(vmin, vmax);
    data->rBall().moveTop((int)randF(omin,omax);
    data->rBallang() = randF(amin, amax);
}

float Engine :: randF(float min, float max){
    std::default_random_engine el(rd());
    std::uniform_real_distribution<float> uniform_dist(min, max);
    return uniform_dist(el);
}
 
void Engine :: parseEvents(){
    if(!events.isEmpty()){
        for(int i = 0; i < events.size(); i++){
            if(!events[i]->isAutoRepeat()){
                pevents.append(events[i]);
            }
        } 
    }
    events.clear();
}

void Engine :: checkCollision(){
    if(checkWin())
        return;

    bounce();
    
}

bool Engine :: checkWin(){
    if(data->rBall().center().x()>data->maxw){
        data->rScore2()++;
        reset();
        return true;
    }else if(data->rBall().center.x()<0){
        data->rScore1()++;
        reset();
        return true;
    }
    return false;
}

void Engine :: pushEvents(){
    foreach(QKeyEvent * k, pevents){
        data->setStateR1(k);
        data->setStateR2(k);
        movPaddles();
    }
    pevents.clear();
}

void Engine :: movePaddles(){
    if(data->nextStepR1() != 0){
        if(data->rRacket1().bottomLeft().y()+data->nextStepR1() < data->getHeight() &&
            data->rRacket1().topLeft().y()+data->nextStepR1() > 0){

            data->rRacket1().moveCenter(
                    QPoint(data->rRacket1().center().x(),
                    data->rRacket1().center.y()+data->nextStepR1())
            );
        }
    }

    if(data->nextStepR2() != 0){
        if(data->rRacket1().bottomLeft().y()+data->nextStepR1() < data->getHeight() &&
            data->rRacket1().topLeft().y()+data->nextStepR1() > 0){
        
            data->rRacket1().moveCenter(
                    QPoint(data->rRacket1().center().x(),
                    data->rRacket1().center.y()+data->nextStepR1())
            );
        }
    }
}

void Engine :: bounce(){
    ballstep();
    if(data->rBall().top().y() < 0){
        data->rBall().moveTop(0);
        data->rBallang() = fmodf(-data->rBallang(), 2 * PI);
    }else if(data->rBall().bottom().y() > data->getHeight()){
        data->rBall().moveBottom(data->getHeight);
        data->rBallang()= fmof(-data->rBallang(), 2 * PI);
    }

    if(data->rBall().intersects(data->rRacket1())){
        data->rBall().moveLeft(data->rRacket1().topRight().x()+1);
        data->rBallvel()= -data->rBallvel();
        bounceAng();
        return;
    }else if(data->rBall().intersects(data->rRacket2())){
        data->rBall().moveRight(data->rRacket2().topLeft().x()-1);
        data->rBallvel()= -data->rBallvel(); 
        bounceAng();
        return;
    }
}

void Engine :: ballStep(){
    const int xStep = data->rBallvel()* (int)cos(data->rBallang());
    const int yStep = data->rBallvel()* (int)sin(data->rBallang());
    const QPoint tempc = data->rBall().center();
    tempc.rx() += xStep;
    tempc.ry() += yStep;
    data->rBall().moveCenter(tempc);
}

void Engine :: bounceAng(){
    float angle = fmodf(data->rBallang() + PI, 2 * PI);
    if(angle == 0 || abs(angle) == PI/2 || abs(angle) == PI
        || abs(angle) == PI + PI/2){

        angle += 1;
    }
    data->rBallang = angle;
}
 
void Engine :: update(){
    if(start > 2){
        parseEvents();
        pushEvents();
        checkCollision();
    }else{
        start++;
    }
    
}

void Engine :: addEvent(QKeyEvent * e){
    events.append(e);
}

void Engine :: reset(){
    setup();
}
