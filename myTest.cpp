<<<<<<< HEAD
 

=======
#include "driver.h"
#include <QTest>
#include <QDebug>
#include <QTimer> 

class myTest : public QObject {
    
    Q_OBJECT
    
    //consts to set # of pixmaps saved to file during testing and the interval of snaps    
    const int snapshots = 60;// # of snapshots saved
    const int interval = 1000;//interval of snapshots in millisec, right now its at
                           //about 1 snapshot per second 

    private slots:
        void initTestCase();
        void intervalTest();
        void cleanupTestCase();
    private:
        Driver m_driver;
        QTimer * timer;

};

void myTest :: initTestCase()
{
    m_driver = Driver();
    timer = new QTimer(this);   
    timer->setInterval(interval);
}

void myTest :: intervalTest()
{
    int x = 1;
    timer.start()
}

void myTest :: cleanupTestCase()
{

}

QTEST_MAIN(myTest);
#include "myTest.moc"
>>>>>>> 5606b7fdc7562b68e5c0bccd69e73d1340dbfec7
