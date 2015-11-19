#ifndef MODEL_H
#define MODEL_H

#include <QObject>

#include "engine.h"
#include "view.h"
#include "racket.h"
#include "ball.h"

class Model : public QObject {
    
    Q_OBJECT

    public:
        Model();
        &Racket getRacket1();
        &Racket getRacket2();
        &Ball getBall();
        &QPixmap getPixmap();
    signals:
        void update();

};

#endif
