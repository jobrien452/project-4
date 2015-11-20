#ifndef MODEL_H
#define MODEL_H

#include <QObject>
#include <QKeySequence>
#include <QPainter>
#include <QRect>
#include <QSize>

class Model : public QObject {
    
    Q_OBJECT

    enum rakState {
        UP = 1,
        DOWN = -1,
        STOP = 0
    };
    
    const int rakStep = 5;
    const QSize paddle(10,30);
    const QSize sball(5,5)

    public:
        Model(int w, int h);
        void setStateR1(QKeyEvent *);
        void setStateR2(QKeyEvent *);
        int nextStepR1();
        int nextStepR2();
        &QRect rBall();
        &QRect rRacket1();
        &QRect rRacket2();
        QSize getSize();
        &int  rBallvel();
        &int  rScore1();
        &int  rScore2();
        &float rBallang();
        bool release();
        void draw(QPainter *);
    private:
        QRect ball, racket1, racket2;
        QSize frame;
        QKeySequence r1up, r1down, r2up, r2down;
        int bVel, score1, score2;
        float ballang;
        rakState r1state, r2state;
        bool pressed;
    public slots:
        void reset();
    signals:
        void reinit();

};

#endif
