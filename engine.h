#ifndef ENGINE_H
#define ENGINE_H

#include <QObject>
#include <QRect>
#include <QPainter>

#include "racket.h"
#include "ball.h"
//canvas to record score???

class Engine : public QObject {

    Q_OBJECT
    
    public:
        Engine();
	void update(QPainter*); 
        //create signals for model to update in real time
        //define view bounds, add hard coded size for ball and 
        //rackets in cpp file.
        //connect qtimer to view controller and put update method in qwidget
        //paint method
    public slots:
	void reset();
	void quit();
	
    private:
	Racket p1, p2;
	Ball b;
	int s1,s2;


};

#endif 
