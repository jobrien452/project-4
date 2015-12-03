#include "driver.h"

Driver :: Driver() {
    myModel = Model(x,y);
    gameEngine = Engine(&myModel);
    gameEngine.moveToThread(&engineThread);
    myView = View(0, &myModel);
}

void Driver :: start(){
    engineThread.start();
    myView.show();   
}

View& Driver :: getView() {
    return myView;
}

QPixmap Driver :: grabScreen() {
    return QPixmap::grabWidget(&myView, 
		QRect(QPoint(0,0),QPoint(x,y))
		); 
}