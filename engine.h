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
#include "model.h"

class Engine : public QObject {

    Q_OBJECT
    
    public:
        Engine(Model);
    private:
    	Model * data;
    	QList<QKeyEvent *> kevents;
        //all private methods go in update
        void parseEvents();
        void pushEvents();
    	void checkCollison();//bounce ang in collisions
    	void bounceAng();//sub of collision
        void checkWin();//sub of collision
	
    public slots:
        void addEvent(QKeyEvent *) //easily recodable for other event types but we only need keyevents for this
    	void update();
    	void reset();

    /*signals:
	    void */


};

#endif 
