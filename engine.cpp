#include <QSize>
#include "engine.h"

Engine :: Engine(QWidget * view){
	//create pixmap with middle line
	//create
	QRect temp = view->rect();
	model1 = new Model(view->rect());
	QSize rs(10, 30);
	paddles.append(new Racket(QRect(QPoint(temp.topLeft().x()+5,temp.center().y()),rs),"a","s", temp.bottom().y()));
	paddles.append(new Racket(QRect(QPoint(temp.topRight().x()-15, temp.center().y()),rs),"k","l",temp.bottom().y()));
	b = new Ball();// not implemented yet
	drawables.append(b);
	drawables.append(paddles[0]);
	drawables.append(paddles[1]);
	pixInit(temp);
}

void Engine :: paint(QPainter * painter){
	model1 -> draw(painter);
	*/p->drawPixmap(0,0,bounds);
	foreach( Collidable c, drawables ){
	    c.draw(p);
	}*/
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

void Engine :: addEvent(QEvent * e){
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
