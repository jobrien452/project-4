#ifndef ENGINE_H
#define ENGINE_H

#include <QObject>
#include <QRect>
#include <QList>
#include <QKeyEvent>
#include <random>
#include <cmath>
#include "model.h"

#define PI 3.14159265

class Engine : public QObject {

    Q_OBJECT
   
    const float vmin = 1.0; 
    const float vmax = 4.0;
    const int omin = 20;
    const int omax = 420;
    const int amin = 0;
    const int amax = 2 * PI;
 
    public:
        Engine(Model);
    private:
    	Model * data;
    	QList<QKeyEvent *> events, pevents;
        int start;
        //all private methods go in update
        void setup();
        float randF(float, float);
        void parseEvents();
        void pushEvents();
    	void checkCollison();//bounce ang in collisions
        void movePaddles();
        void bounce();
    	void bounceAng();//sub of collision
        void checkWin();//sub of collision
        void ballStep();	
    public slots:
        void addEvent(QKeyEvent *) //easily recodable for other event types but we only need keyevents for this
    	void update();
        void reset();

    /*signals:
	    void */


};

#endif 
