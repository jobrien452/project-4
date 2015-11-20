#include <QSize>
#include "engine.h"

Engine :: Engine(Model m){
    data = &m;
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
    parseEvents();
    pushEvents();
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

void Engine :: movPaddles(){
    if(data->nextStepR1() != 0){
        if(data->rRacket1().bottomLeft().y()+data->nextStepR1() < data->getHeight()
           && data->rRacket1().topLeft().y()+data->nextStepR1() > 0){

            data->rRacket1().center().ry()+=data->nextStepR1();
        }
    }

    if(data->nextStepR2() != 0){
        if(data->rRacket1().bottomLeft().y()+data->nextStepR1() < data->getHeight()
           && data->rRacket1().topLeft().y()+data->nextStepR1() > 0){
        
            data->rRacket2().center().ry()+=data->nextStepR1();
        }
    }
}

void Engine :: bounce(){
    if(data->rBall().intersects(data.rRacket1())){
        data-> 
    
        
    }
}

void Engine :: update(){

    //check for point here if point then call reset method, increment counter
    //handling for events
    while(!events.isEmpty()){
        QEvent current = events.pop_back();
        //code for keyevents but can handle and event type if code was added to check for it
        if(current == QEvent::KeyPress || current == QEvent::KeyRelease){
            QKeyEvent* temp = dynamic_cast<QKeyEvent*>(e);
            foreach( Racket r, paddles ){
                r->press(QKeySequence(temp->key()));
            }
        }
    }
	
    //checking for ball collision is here 
    //then movement if ther is no collision

}

void Engine :: addEvent(QKeyEvent * e){
    events.append(e);
}

void Engine :: pixInit(QRect bounds){
    board = QPixmap(bounds.bottomRight().x(), bounds.bottomRight().y());
    board.fill(Qt::black);
    QPainter PixmapPainter(&board);
    for(int i = 0; i <= bounds.bottomRight().y()-4, i+=4 ){	
    	PixmapPainter.drawLine(bounds.center().x(),i, bounds.center().x(),i+4);
    }
}
