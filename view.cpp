#include "view.h"

View :: View ( QWidget * parent, Model m )
: QWidget( parent ) {
    
    setFixedSize(900, 630);
    QPallet pal(palette());
    pal.setColor(QPalette:Background, Qt::black);
    setPalette(pal);
    shortcuts.append(new QShortcut(QKeySequence(tr("a", "P1Up")), this));
    shortcuts.append(new QShortcut(QKeySequence(tr("s", "P1Down")), this));
    shortcuts.append(new QShortcut(QKeySequence(tr("k", "P2Up")), this));
    shortcuts.append(new QShortcut(QKeySequence(tr("l", "P2Down")), this));
    signalMapper = new QSignalMapper(this);
    for(int i = 0; i < shortcuts.size(); i++){
        signalMapper->setMapping(sht, sht.key().toString());
    }
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), m, SLOT(update()));
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer -> start(17);
    
    connect(new QShortcut(QKeySequence(tr("q", "quit")), this), SIGNAL(activated()),this,SLOT(close()));
    connect
    //in main create model
    //create view and engine that take model
    //model will have slots and signals for all
    //key press events will go to event que
    //event que will signal to engine for processing
    //engine will modify data in model if event is correct
    //model will signal to view to update
    //???
    //profit
}

void View :: paintEvent(QPaintEvent * event){
    
    m->draw();

}

void View :: keyPressEvent(QKeyEvent * event){

    queEvent(event);
}
