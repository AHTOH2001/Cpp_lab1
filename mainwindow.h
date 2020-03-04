#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>
#include <QtCore>
#include <polygon.h>
#include <rectangle.h>
#include <ellipse.h>
#include <globalvar.h>
#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include <QCursor>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    struct triple
    {
        int first,second;
        double third;
    };

protected:
    void paintEvent(QPaintEvent *event);
private slots:
    void on_pushButton_elips_clicked();
    void on_pushButton_polygon_clicked();
    void on_pushButton_rect_clicked();
    triple CalcCenter (QStringList);
    void on_Tgravity_clicked();
};
#endif // MAINWINDOW_H
