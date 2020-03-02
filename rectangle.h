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
class rectangle : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit rectangle();
    ~rectangle();
    int w,h,R,G,B,size;
signals:

private:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    void keyPressEvent(QKeyEvent *event);
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);
    //void keyReleaseEvent(QKeyEvent *event);
    //void keyPressEvent(QKeyEvent *event);

public slots:
};

#endif // rectangle_H
