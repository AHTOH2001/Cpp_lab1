#include "rectangle.h"
#include <QApplication>
#include <QKeyEvent>
rectangle::rectangle() :
    QObject(0), QGraphicsItem()
{
    //qDebug() << "this " << this->hasFocus();
    //this->setFocus(Qt::StrongFocus);
    //this->setFocusPolicy(Qt::TabFocus);
   //  qDebug() << "Widget have focus - " << qApp->focusWidget()->objectName();
   // this->setFocus(Qt::MouseFocusReason);
   // qDebug() << "Focus " << this->hasFocus();
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
    //painter->setPen(Qt::black);
    //painter->setBrush(Qt::green);
    painter->setPen(QPen(QColor(R,G,B),size));
    painter->rotate(45);
    painter->drawRect(-w/2,-h/2,w,h);
    painter-> setPen(QPen(Qt::red,3));
    painter->drawPoint(0,0);
    //int size = (static_cast<MainWindow*>(this->parent()))->ui->pen_size->text().toInt();
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

void rectangle::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    qDebug() << "Move";
    this->setPos(mapToScene(event->pos()));

}

void rectangle::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    this->setCursor(QCursor(Qt::ClosedHandCursor));
    qDebug() << "press";
    //this->setFocus();
    //this->setRotation(30);
    Q_UNUSED(event);
}

void rectangle::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    qDebug() << "Release";
    this->setCursor(QCursor(Qt::ArrowCursor));
     //this->setRotation(30);
    Q_UNUSED(event);
}

void rectangle::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
    qDebug()<<"doubleclick";
    //qDebug() << "Rect focus: " << this->hasFocus();
    //keyPressEvent();

}
/*void rectangle::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Escape)
    {
        //myLabel->setText("You pressed ESC");
        int b = 5;
    }
}*/
void rectangle::keyPressEvent(QKeyEvent *event)
{
    //qDebug() << "key! " << event->key();
    //qDebug() << "hig: " << this->h;

    /*if (event->key()==Qt::Key_Left)
    this->setRotation(30);
    else
        if (event->key()==Qt::Key_Right)
            this->setRotation(-30);*/
   /* QGraphicsScene scene;
  if(event->key() == Qt::Key_Left)
  {
      QGraphicsView view(&scene);
       view.rotate(1);
  }
    //rotate(1);
  else if(event->key() == Qt::Key_Right)
  {
      QGraphicsView view(&scene);
       view.rotate(-1);
  }*/

}

