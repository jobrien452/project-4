#ifndef VIEW_H
#define VIEW_H

#include <QWidget>
#include <QObject>
#include <QTimer>
#include <QPainter>
#include <QShortcut>
#include <QKeySequence>
#include <QPixmap>
#include "model.h"

class View : public QWidget {

    Q_OBJECT

    public:
        explicit View(QWidget *parent = 0, Model);
    protected:
        void paintEvent(QPaintEvent *);
    private:
        QTimer * timer;
        QPixmap board;
        void setup();
    signals:
        void pushEvent(QKeyEvent *);
};

#endif
    
