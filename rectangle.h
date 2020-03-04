#ifndef rectangle_H
#define rectangle_H
#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include <QCursor>
#include <QCoreApplication>
#include <QApplication>
#include <QKeyEvent>
#include <QWidget>
#include <QtGui>
#include <globalvar.h>
#include <QTimer>
#include <qglobal.h>
#include <QApplication>
#include <QKeyEvent>
#include <QVector>
#include <QtGlobal>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
class rectangle : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit rectangle();
    ~rectangle();
    void init();
    int R,G,B,PenSize,w,h;
    QLabel *out_area,*out_perimeter,*out_angle,*out_centerX,*out_centerY;
    QPushButton *Tgravity;
    QLineEdit *centergravity_x,*centergravity_y,*rotate_angle,*change_size;


signals:

private:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    void keyPressEvent(QKeyEvent *event);
    void Output();
    double ang = 0,now_ang = 0,size = 1,now_size = 1,perimeter = 0,now_perimeter = 0,area = 0,now_area = 0;
public slots:
};

#endif // rectangle_H
