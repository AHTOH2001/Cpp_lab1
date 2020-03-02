#ifndef ellipse_H
#define ellipse_H
#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include <QCursor>
#include <QCoreApplication>
class ellipse : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit ellipse();
    ~ellipse();
    int w,h,R,G,B,size;
signals:

private:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

public slots:
};

#endif // ellipse_H
