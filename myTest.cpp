#include "model.h"
#include "engine.h"
#include "view.h"

#include <QTest>
#include <QDebug>

class myTest : public QObject {
    
    Q_OBJECT
    
    //consts to set # of pixmaps saved to file during testing and the interval of snaps    
    const int snapshots = 60;// # of snapshots saved
    const int interval = 1000;//interval of snapshots in millisec.

    private slots:
        void initTestCase();
        void intervalTest();
        void cleanupTestCase();
    private:
        Engine myEngine;
        View myView;
        Model myModel;

};

void myTest :: initTestCase()
{

}

void myTest :: intervalTest()
{

}

void myTest :: cleanupTestCase()
{

}

QTEST_MAIN(myTest);
#include "myTest.moc"
