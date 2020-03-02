#include "ellipse.h"
ellipse::ellipse() :
    QObject(0), QGraphicsItem()
{

}

ellipse::~ellipse()
{

}

QRectF ellipse::boundingRect() const
{
    return QRectF (-w/2-20,-h/2-20,w+40,h+40);
}
void ellipse::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    //painter->setPen(Qt::black);
    //painter->setBrush(Qt::green);
    painter->setPen(QPen(QColor(R,G,B),size));
    painter->drawEllipse(-w/2,-h/2,w,h);
    painter-> setPen(QPen(Qt::red,3));
    painter->drawPoint(0,0);
    //int size = (static_cast<MainWindow*>(this->parent()))->ui->pen_size->text().toInt();
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

void ellipse::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    this->setPos(mapToScene(event->pos()));
}

void ellipse::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    this->setCursor(QCursor(Qt::ClosedHandCursor));
    Q_UNUSED(event);
}

void ellipse::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    this->setCursor(QCursor(Qt::ArrowCursor));
    Q_UNUSED(event);
}
