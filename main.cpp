#include <QApplication>
#include <QThread>
#include "model.h"
#include "view.h"
#include "engine.h"
#include "driver.h"
    
int main(int argc, char **argv){

    QApplication app (argc, argv);
    QThread engineThread;
    Model myModel();
    Engine gameEngine(&myModel);
    gameEngine.moveToThread(&engineThread);
    View myView(0, &myModel);
    engineThread.start();
    myView.show();
    return app.exec();
}
