#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "graphlib/arrow.h"
#include "graphlib/vertex.h"
#include "command.h"
#include "dom.h"
#include "dombackend.h"
#include "xmllib/xmlbackend.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::MainWindow *ui;
    QList<Vertex*> l_verts;
    QList<Arrow*> l_arrows;
    QGraphicsScene *m_scn;
    QGraphicsView *m_view;
    QList<Command*> l_commands;
};

#endif // MAINWINDOW_H
