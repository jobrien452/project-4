#ifndef DRIVER_H
#define DRIVER_H

#include <QThread>
#include <QObject>
#include <QPixmap>
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
	QPixmap grabScreen();
    private:
        QThread engineThread;
        Model myModel;
        Engine gameEngine;
        View myView;
        
};

#endif
