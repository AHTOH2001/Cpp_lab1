#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>
#include <QtCore>
#include <ellips.h>
#include <polygon.h>
#include <rectangle.h>
#include <ellipse.h>
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

   // void keyPressEvent(QKeyEvent *event);
protected:
    void paintEvent(QPaintEvent *event);
private slots:

    void on_pushButton_rect_2_clicked();
    void on_pushButton_elips_clicked();
    void on_pushButton_polygon_clicked();
};
#endif // MAINWINDOW_H
