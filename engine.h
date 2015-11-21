#ifndef ENGINE_H
#define ENGINE_H

#include <QObject>
#include <QRect>
#include <QList>
#include <QKeyEvent>
#include <random>
#include <cmath>
#include <QPointF>
#include "model.h"

#define PI 3.14159265

class Engine : public QObject {

    Q_OBJECT
   
    const float vmin = 2.8; 
    const float vmax = 4.5;
    const int omin = 20;
    const int omax = 420;
    const int amin = 0.5;
    const int amax = 1.5 * PI;
 
    public:
        Engine(Model * );
    private:
    	Model* data;
    	QList<bool> repeat;
	QList<int> keys;
        int start;
	std::random_device rd;
        //all private methods go in update
        void setup();
        float randF(float, float);
        void pushEvents();
    	void checkCollision();//bounce ang in collisions
        void movePaddles();
        void bounce();
    	void bounceAng();//sub of collision
        bool checkWin();//sub of collision
        void ballStep();	
    public slots:
        void addEvent(QKeyEvent *); //easily recodable for other event types but we only need keyevents for this
    	void update();
        void reset();

    /*signals:
	    void */


};

#endif 
