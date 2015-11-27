#include <QApplication>
#include <QThread>
#include "model.h"
#include "view.h"
#include "engine.h"
#include "driver.h"
    
int main(int argc, char **argv){

    QApplication app (argc, argv);
    Driver d();
    d.start();
    return app.exec();
}
