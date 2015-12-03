#ifndef MODEL_H
#define MODEL_H

#include <QObject>
#include <QKeySequence>
#include <QKeyEvent>
#include <QPainter>
#include <QRectF>
#include <QRect>
#include <QSize>
#include <QFont>
#include <QMutex>
#include <QMutexLocker>
#include <QDebug>

class Model : public QObject {
    
    Q_OBJECT

    enum rakState {
        UP = -1,
        DOWN = 1,
        STOP = 0
    };
    
    const int rakStep = 18;
    const QSize paddle = QSize(15,50);
    const QSize sball = QSize(8,8);
    const int maxh = 600;
    const int maxw = 800;

    public:
        Model();
        void setStateR1(int, bool);
        void setStateR2(int, bool);
        int nextStepR1();
        int nextStepR2();
        QRectF & rBall();
        QRect & rRacket1();
        QRect & rRacket2();
        QSize getSize();
        float & rBallvel();
        int & rScore1();
        int & rScore2();
        float & rBallang();
        int getHeight();
        int getWidth();
        void draw(QPainter *);
	QMutex & getMutex();
    private:
        QRectF ball;
        QRect racket1, racket2;
        QSize frame;
        QKeySequence r1up, r1down, r2up, r2down;
        int score1, score2;
        float ballang, balVel;
        rakState r1state, r2state;
        bool pressed;
	QMutex mMutex;
    public slots:
        void update();
        void queEvent(QKeyEvent *);
    signals:
        void init();
        void pushEvent(QKeyEvent *);

};

#endif
