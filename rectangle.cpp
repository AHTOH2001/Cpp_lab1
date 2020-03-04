#include "rectangle.h"
extern per global_per;
rectangle::rectangle() :
    QObject(0), QGraphicsItem()
{

}
rectangle::~rectangle()
{

}

QRectF rectangle::boundingRect() const
{
    return QRectF (-w/2-20,-h/2-20,w+40,h+40);
}
void rectangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(QPen(QColor(R,G,B),PenSize));
    painter->drawRect(-w/2,-h/2,w,h);
    if (this->hasFocus()) painter-> setPen(QPen(Qt::red,3));
    else
        painter-> setPen(QPen(QColor(20,20,20),3));
    painter->drawPoint(0,0);
        QThread::msleep(10);
        double delta = ang-now_ang;
        if (delta<0.5 && delta>-0.5) now_ang=ang;
                else
        if (delta<20 && delta>-20)
        { if (delta>0) now_ang += 0.2;
            else now_ang -= 0.2;
        }
        else
        now_ang+=delta/100;
        this->setRotation(now_ang);

        delta = size - now_size;
        if (delta<0.00001 && delta>-0.00001) now_size = size;
        else
        if (delta<0.001 && delta>-0.001)
        {
        if (delta>0) now_size+=0.001;
        else now_size-=0.001;
        }
        else
            now_size+=delta/100;
        this->setScale(now_size);

    Q_UNUSED(option);
    Q_UNUSED(widget);
}

void rectangle::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    this->setPos(mapToScene(event->pos()));

}

void rectangle::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    this->setCursor(QCursor(Qt::ClosedHandCursor));
    Q_UNUSED(event);
}

void rectangle::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    this->setCursor(QCursor(Qt::ArrowCursor));
    Q_UNUSED(event);
}


void rectangle::keyPressEvent(QKeyEvent *event)
{

/*
    if (event->key()==Qt::Key_Left) ang += global_per.angle;
    else
    if (event->key()==Qt::Key_Right) ang -= global_per.angle;
    else
    if (event->key()==Qt::Key_Down) size-=global_per.Size;
    else
    if (event->key()==Qt::Key_Up) size+=global_per.Size;
    else
    if (event->key()==Qt::Key_R) {
    ang = 0;
    size = 1;
    }
*/
}

