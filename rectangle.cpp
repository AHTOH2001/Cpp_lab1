#include "rectangle.h"
extern per global_per;
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
    //qDebug() << this->hasFocus();
    //painter->setPen(Qt::black);
    //painter->setBrush(Qt::green);
    painter->setPen(QPen(QColor(R,G,B),PenSize));
    //painter->rotate(10);
    painter->drawRect(-w/2,-h/2,w,h);
    if (this->hasFocus()) painter-> setPen(QPen(Qt::red,3));
    else
        painter-> setPen(QPen(QColor(20,20,20),3));
    painter->drawPoint(0,0);
    //int size = (static_cast<MainWindow*>(this->parent()))->ui->pen_size->text().toInt();
    //if (p==1)
    //{
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
        /*double x = delta / global_per.angle;
        if (trunc(x)+0.0000001>x) delta = trunc(x) * global_per.angle;
        else delta = trunc(x) * global_per.angle;*/
    //    if (delta==0) p = 0;
    //}

    Q_UNUSED(option);
    Q_UNUSED(widget);
}

void rectangle::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
  //  qDebug() << "Move";
    this->setPos(mapToScene(event->pos()));

}

void rectangle::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    this->setCursor(QCursor(Qt::ClosedHandCursor));
    //qDebug() << "press";
    //this->setFocus();
    //this->setRotation(30);
    Q_UNUSED(event);
}

void rectangle::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    //qDebug() << "Release";
    this->setCursor(QCursor(Qt::ArrowCursor));
     //this->setRotation(30);
    Q_UNUSED(event);
}

void rectangle::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
    //qDebug()<<"doubleclick";
    //per p;
   // qDebug()<<global_per.angle;
    //qDebug() << "Rect focus: " << this->hasFocus();
    //keyPressEvent();
    this->setScale(2);
    Q_UNUSED(event);
}
/*void rectangle::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Escape)
    {
        //myLabel->setText("You pressed ESC");
        int b = 5;
    }
}*/
/*void rectangle::myrotation (double ang,double delta)
{
//timer = new QTimer();
//timer->setInterval(10);
    delta=delta/100;
for (int i = 100;i>0;i--)
{
    QThread::msleep(10);
    //QTest::qWait (10);
    ang+=delta;
    //singleShot(10, , SLOT(slot()));
    this->setRotation(ang);
    //this->update();
    this->update();
    this->show();*/
    /*timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(paint));
    timer->start(1000);
}

//timer->start(10);
//this->setRotation(ang+delta);

}*/
void rectangle::keyPressEvent(QKeyEvent *event)
{
    //qDebug() << "key! " << event->key();
    //qDebug() << "hig: " << this->h;


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



    /*QGraphicsScene scene;
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

