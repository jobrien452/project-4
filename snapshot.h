#ifndef SNAPSHOT_H
#define SNAPSHOT_H

#include "view.h"

#include <QObject>
#include <QPixmap>
#include <QImage>
#include <QString>
class Snapshot : public QObject
{
    Q_OBJECT
    
    public:
        Snapshot(View * v, QString name)
        {
            myView = v;
	    l = name;
        }
    private:
        View * myView;
        QPixmap img;
	QString l;
	int count = 0;
    public slots:
        void snap()
        {
            img = QPixmap::gradWidget(myView);  
            img.toImage().save(l + "-" + QString::number(count), "PNG"); 
            count++;
        }
};

#endif
