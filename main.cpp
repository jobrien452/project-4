#include <QApplication>
#include <QThread>
#include "model.h"
#include "view.h"
#include "engine.h"
#include "driver.h"

class Driver : public QObject {

    Q_OBJECT
    //consts for setting view size   
    const int x = 800;
    const int y = 600;

    public:
        Driver();
        void start();
    private:
        QThread engineThread;
        Model myModel;
        Engine gameEngine;
        View myView;
        
};

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
     
int main(int argc, char **argv){

    QApplication app (argc, argv);
    Driver d();
    d.start();
    return app.exec();
}
