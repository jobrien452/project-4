#include "view.h"

View :: View ( QWidget * parent, Model m )
: QWidget( parent ) {
   
    data = &m; 
    setFixedSize(data->getSize());
    QPallet pal(palette());
    pal.setColor(QPalette:Background, Qt::black);
    setPalette(pal);
    setup();
    connect(this, SIGNAL(pushEvent(QKeyEvent *)), data, SLOT(queEvent(QKeyEvent *)));
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), data, SLOT(update()));
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer -> start(17);
    connect(new QShortcut(QKeySequence(tr("q", "quit")), this), SIGNAL(activated()),this,SLOT(close()));
}

void View :: paintEvent(QPaintEvent * event){
    
    QPainter paint(this);
        paint.drawPixmap(0,0,board);
        m->draw(&paint);

}

void View :: keyPressEvent(QKeyEvent * event){
        emit pushEvent(event);
}

void View :: setup(){
    board = QPixmap(data->getWidth(), data->getHeight());
    board.fill(Qt::black);
    QPainter paint(&board);
    for(int i = 0; i <= data->getHeight()-4, i+=4 ){ 
        paint->drawLine(data->getWidth()/2,i, data->getWidth()/2,i+4);
    }
}
