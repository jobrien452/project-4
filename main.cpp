#include <QApplication>
#include "model.h"
#include "view.h"
#include "engine.h"

int main(int argc, char **argv){

    QApplication app (argc, argv);

    Model myModel(800, 600);
    Engine gameEngine(&myModel);
    View myView(0, &myModel);
    myView.show();
    return app.exec();
}
