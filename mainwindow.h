#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>
#include <QtCore>
#include <polygon.h>
#include <rectangle.h>
#include <ellipse.h>
#include <mypaint.h>
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
    int p = 0;
    mypaint *paint_scene;

protected:

private slots:
    void on_pushButton_elips_clicked();
    void on_pushButton_polygon_clicked();
    void on_pushButton_rect_clicked();
    void on_Tgravity_clicked();
    void on_Reset_scene_clicked();
    void on_paint_figure_clicked();
    void on_undo_clicked();
    void on_reset_clicked();
};
#endif // MAINWINDOW_H
