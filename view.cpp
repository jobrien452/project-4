#include "view.h"

View :: View ( QWidget * parent )
: QWidget( parent ) {
    
    setFixedSize(900, 630);
    QPallet pal(palette());
    pal.setColor(QPalette:Background, Qt::black);
    setPalette(pal);
    e = new Engine(this);
    e->init();
    shortcuts.append(new QShortcut(QKeySequence(tr("a", "P1Up")), this));
    shortcuts.append(new QShortcut(QKeySequence(tr("s", "P1Down")), this));
    shortcuts.append(new QShortcut(QKeySequence(tr("k", "P2Up")), this));
    shortcuts.append(new QShortcut(QKeySequence(tr("l", "P2Down")), this));
    signalMapper = new QSignalMapper(this);
    for(int i = 0; i < shortcuts.size(); i++){
        signalMapper->setMapping(sht, sht.key().toString());
    }
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), e, SLOT(update()));
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer -> start(17);
    
    connect(new QShortcut(QKeySequence(tr("q", "quit")), this), SIGNAL(activated()),this,SLOT(close()));
    connect
    
}

void View :: paintEvent(QPaintEvent * event){
    
    e->update();
    e->repaint(&paint);

}

void View :: keyPressEvent(QKeyEvent * event){

    e->
}
