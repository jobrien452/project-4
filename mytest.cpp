#include "engine.h"
#include "view.h"
#include "model.h"
#include "snapshot.h"

#include <QTest>
#include <QThread>
#include <QPixmap>
#include <QTimer>
#include <QDebug>
#include <QFile>
#include <QTextStream>
#include <QList>
class MyTest : public QObject
{
    Q_OBJECT
    
    const int snapInterval = 500; //2 snaps a second
    const int keyPressInterval = 1000; //1 keypress a second
    private:
	QList<Qt::Key> testKeys;
        QThread testThread;
        Engine * testEngine;
        View * testView;
        Model * testModel;
    	Snapshot * s;
	QTimer *timer;
	void loadKeys();
    private slots:
        void initTestCase();
        void testGame();
        void cleanupTestCase();

};

void MyTest :: initTestCase(){
    testModel = new Model();
    testEngine = new Engine(testModel);
    testEngine -> moveToThread(&testThread);
    testView = new View(0, testModel);
    timer = new QTimer(this);
    s = new Snapshot(testView, "test");
    connect(timer, SIGNAL(timeout()), s, SLOT(snap()));
    testThread.start();
    testView->show();
    QTest::qWaitForWindowShown(testView);
    timer->start(snapInterval);
    loadKeys();
}

void MyTest :: testGame(){
    while(!testKeys.empty()){
        QTest::keyClick(testView, testKeys.last());
	testKeys.pop_back();
        QTest::qWait(keyPressInterval);
    }
}

void MyTest :: cleanupTestCase(){
   //do nothing 
}
/*reads hex values of keys hard coded in
  keys.txt then parses them and puts them into
  Qt:Key array for testing
  Go to:
  http://doc.qt.io/qt-4.8/qt.html#Key-enum
  for information on what value maps to what key
*/
void MyTest :: loadKeys(){
    QFile file("keys.txt");
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QFAIL("Keys.txt not correctly loaded");
        return;
    }
    
    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        testKeys.append((Qt::Key)line.toInt(0, 16));
    }
    file.close();   	
}

QTEST_MAIN(MyTest);
#include "mytest.moc"
