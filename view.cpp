#include <QDebug>
#include "view.h"

View :: View ( QWidget * parent, Model* m))
: QWidget( parent ) {
   
    data = m; 
    setFixedSize(data->getSize());
    QPalette pal(palette());
    pal.setColor(QPalette::Background, Qt::black);
    setPalette(pal);
    setup();
    connect(this, SIGNAL(pushEvent(QKeyEvent *)), data, SLOT(queEvent(QKeyEvent *)));
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), data, SLOT(update()));
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer -> start(15);
    connect(new QShortcut(QKeySequence(tr("q", "quit")), this), SIGNAL(activated()),this,SLOT(close()));
}

void View :: paintEvent(QPaintEvent * event){
    //static int x = 0;
    QPainter paint(this);
    paint.drawPixmap(0,0,board);
    if(data->getMutex().tryLock()){
        data->draw(&paint);
        data->getMutex().unlock();
    }
    //if(x > 300 && x<311){
    //	qDebug() << "view: " << data->rBall().center();
    //}
    //x++;

}

void View :: keyPressEvent(QKeyEvent * event){
    //qDebug() << event->text();
    emit pushEvent(event);
}

void View :: keyReleaseEvent(QKeyEvent * event){
    emit pushEvent(event);
}

void View :: setup(){
    board = QPixmap(data->getWidth(), data->getHeight());
    board.fill(Qt::black);
    QPainter paint(&board);
    paint.setPen(Qt::white);
    for(int i = 0; i <= data->getHeight()-8; i+=8 ){
       	paint.drawLine(data->getWidth()/2,i, data->getWidth()/2,i+4);
    }
}
