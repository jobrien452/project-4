#include <QApplication>
#include <QThread>
#include "model.h"
#include "view.h"
#include "engine.h"
#include "driver.h"
    
int main(int argc, char **argv){

    QApplication app (argc, argv);
<<<<<<< HEAD
    QThread engineThread;
    Model myModel();
    Engine gameEngine(&myModel);
    gameEngine.moveToThread(&engineThread);
    View myView(0, &myModel);
    engineThread.start();
    myView.show();
=======
    Driver d();
    d.start();
>>>>>>> 5606b7fdc7562b68e5c0bccd69e73d1340dbfec7
    return app.exec();
}
