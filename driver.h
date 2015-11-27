#ifndef DRIVER_H
#define DRIVER_H

#include <QThread>
#include <QObject>
#include "model.h"
#include "engine.h"
#include "view.h"

class Driver : public QObject {

    Q_OBJECT
    //consts for setting view size   
    const int x = 800;
    const int y = 600;

    public:
        Driver();
        void start();
//	void stop();
	View & getView();
    private:
        QThread engineThread;
        Model myModel;
        Engine gameEngine;
        View myView;
        
};

#endif
