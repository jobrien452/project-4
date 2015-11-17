#ifndef ENGINE_H
#define ENGINE_H

#include <QObject>
#include <QRect>

#include "racket.h"
#include "ball.h"

class Engine : public QObject {

    Q_OBJECT
    
    public:
        Engine();
        //create signals for model to update in real time
        //define view bounds, add hard coded size for ball and 
        //rackets in cpp file.
