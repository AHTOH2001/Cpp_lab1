#include "polygon.h"
polygon::polygon() :
    QObject(0), QGraphicsItem()
{

}
polygon::~polygon()
{

}
void polygon::init()
{
    now_area = area;
    now_perimeter = perimeter;
}

QRectF polygon::boundingRect() const
{
    return QRectF (-w/2-20,-h/2-20,w+40,h+40);
}
void polygon::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
     if (this->hasFocus())
         painter-> setPen(QPen(Qt::red,3));
     else
         painter-> setPen(QPen(QColor(20,20,20),3));
        painter->drawPoint(0,0);
        painter->setPen(QPen(QColor(R,G,B),PenSize));
        painter->drawPolygon(poly);
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
        if (delta<0.002 && delta>-0.002) now_size = size;
        else
        if (delta<0.1 && delta>-0.1)
        {
        if (delta>0) now_size+=0.001;
        else now_size-=0.001;
        }
        else
            now_size+=delta/100;
        now_area = area*now_size*now_size;
        now_perimeter = perimeter*now_size;
        this->setScale(now_size);
        if (this->hasFocus()) Output();

    Q_UNUSED(option);
    Q_UNUSED(widget);
}
void polygon::Output()
{
out_area->setText(QString::number(now_area));
out_perimeter->setText(QString::number(now_perimeter));
out_centerX->setText(QString::number(this->pos().rx()));
out_centerY->setText(QString::number(this->pos().ry()));
out_angle->setText(QString::number(now_ang));
}

void polygon::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    this->setPos(mapToScene(event->pos()));
}

void polygon::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (Tgravity->text()=="Choose object to move")
    {
        Tgravity->setText("Set center of gravity:");
        this -> setPos(centergravity_x->text().toInt(),centergravity_y->text().toInt());
        this-> clearFocus();
        this-> ungrabMouse();
    }
    else
    this->setCursor(QCursor(Qt::ClosedHandCursor));
    Q_UNUSED(event);
}

void polygon::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    this->setCursor(QCursor(Qt::ArrowCursor));
    Q_UNUSED(event);
}

void polygon::keyPressEvent(QKeyEvent *event)
{


    if (event->key()==Qt::Key_Left) ang += rotate_angle->text().toInt();
    else
    if (event->key()==Qt::Key_Right) ang -= rotate_angle->text().toInt();
    else
    if (event->key()==Qt::Key_Down)
    {
        size-=change_size->text().toInt()/100.;
        now_area=area*size*size;
    }
    else
    if (event->key()==Qt::Key_Up)
    {
        size+=change_size->text().toInt()/100.;
        now_area=area*size*size;
    }
    else
    if (event->key()==Qt::Key_R) {
    ang = 0;
    size = 1;
    now_area = area;
    now_perimeter = perimeter;
    }

}

