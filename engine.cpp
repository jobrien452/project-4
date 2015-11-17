#include <QSize>
#include "engine.h"

Engine :: Engine(QWidget * view){
	QRect temp = view->rect();
	QSize rs(10, 30);
	paddles.append(new Racket(QRect(QPoint(temp.topLeft().x()+5,temp.center().y()),rs),"a","s", temp.bottom().y()));
	paddles.append(new Racket(QRect(QPoint(temp.topRight().x()-15, temp.center().y()),rs),"k","l",temp.bottom().y()));
	b = new Ball();// not implemented yet
}

void Engine :: paint(QPainter * p){

}

void Engine :: update(){

    
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

}

void addEvent(QEvent * e){
    events.append(e);
}
