#ifndef ENGINE_H
#define ENGINE_H

#include <QObject>
#include <QRect>
#include <QPainter>
#include <QPixmap>
#include <QWidget>
#include <QList>
#include <QKeyEvent>
#include <QKeySequence>

#include "racket.h"
#include "ball.h"
//canvas to record score???

class Engine : public QObject {

    Q_OBJECT
    
    public:
        Engine(QWidget *);
	void paint(QPainter*); 
        //create signals for model to update in real time
        //define view bounds, add hard coded size for ball and 
        //rackets in cpp file.
        //connect qtimer to view controller and put update method in qwidget
        //paint method
    private:
	QList<Racket*> paddles;
	QList<QEvent*> events;
	QList<Collidable*>  drawables;
	Ball * b;
	int s1,s2;
	QPixmap board;
    public slots:
        void addEvent(QEvent *) //easily recodable for other event types but we only need keyevents for this
	void update();
    /*signals:
	    void */


};

#endif 
