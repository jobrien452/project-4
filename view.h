#ifndef VIEW_H
#define VIEW_H

#include <QWidget>
#include <QObject>
#include <QTimer>
#include <QPainter>
#include <QShortcut>
#include "engine.h"

class View : public QWidget {

    Q_OBJECT

    public:
        explicit View(QWidget *parent = 0);
    protected:
        void paintEvent(QPaintEvent *);
    private:
        Engine * e;
	QTimer * timer;
    signals:
        void quit();

};

#endif
    
