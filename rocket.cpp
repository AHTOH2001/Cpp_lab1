#include "rocket.h"

rocket::rocket(QObject *parent) :
    QObject(parent), QGraphicsItem()
{

}

rocket::~rocket()
{

}

QRectF rocket::boundingRect() const
{
    return QRectF (-105,-145,210,330);
}

void rocket::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(Qt::black);
    painter->setBrush(Qt::green);
    painter->drawRect(-25,-70,50,120);
    painter->drawPie(-25,-95,50,50,0,2880);
    QPolygon poly1,poly2;
    poly1 << QPoint(25,10);
    poly1 << QPoint(35,20);
    poly1 << QPoint(38,70);
    poly1 << QPoint(25,50);
    painter->drawPolygon(poly1);
    poly2 << QPoint(-25,10);
    poly2 << QPoint(-35,20);
    poly2 << QPoint(-38,70);
    poly2 << QPoint(-25,50);
    painter->drawPolygon(poly2);
    painter->setPen(Qt::red);
    painter->setBrush(Qt::red);
    painter->drawLine(-5,60,-20,120);
    painter->drawLine(0,60,0,120);
    painter->drawLine(5,60,20,120);
    for (int i = 0;i<11;i++)
    {
        painter->drawRect(qrand()%50-25,qrand()%80+50,qrand()%5+2,qrand()%5+2);
    }
   // painter->setPen(QPen(Qt::GlobalColor(254),6));
    //painter->setBrush(Qt::);
    for (int i = 0;i<5;i++)
    {
        painter->drawRect(qrand()%80-40,qrand()%50+120,qrand()%5+2,qrand()%5+2);
    }
    painter->setPen(QPen(Qt::GlobalColor(qrand()%20),3));
    painter->drawLine(0,-50,-10,-10);
    painter->drawLine(0,-50,10,-10);
    painter->drawLine(-5,-25,5,-25);
    painter->setPen(QPen(Qt::green,3));
    painter->drawLine(0,-97,0,-140);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

void rocket::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    this->setPos(mapToScene(event->pos()));
}

void rocket::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    this->setCursor(QCursor(Qt::ClosedHandCursor));
    Q_UNUSED(event);
}

void rocket::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    this->setCursor(QCursor(Qt::ArrowCursor));
    Q_UNUSED(event);
}
