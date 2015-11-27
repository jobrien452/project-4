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
