#include "mypaint.h"
mypaint::mypaint(QWidget *parent)
    : QGraphicsView(parent)
{

    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setAlignment(Qt::AlignCenter);
    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    this->setMinimumHeight(100);
    this->setMinimumWidth(100);
    scene = new QGraphicsScene();
    this->setScene(scene);
    QThread::msleep(10);
    scene->setSceneRect(0,0,240,280);
}
mypaint::~mypaint()
{

}

void mypaint::init()
{
    int x = 100;
    int y = 100;
    rectangle *item = new rectangle();
    item->setFlag(QGraphicsItem::ItemIsFocusable, true);
    item->setPos(x,y);
    item->w = 100;
    item->h = 100;
    item->R = 20;
    item->G = 60;
    item->B = 200;
    item->PenSize = 3;
   /* item->out_area = ui->area;
    item->out_perimeter = ui->perimeter;
    item->out_centerX = ui->center_x;
    item->out_centerY = ui->center_y;
    item->out_angle = ui->angle;
    item->Tgravity =ui->Tgravity;
    item->centergravity_x = ui->centergravity_x;
    item->centergravity_y = ui->centergravity_y;
    item -> rotate_angle = ui->rotate_angle;
    item -> change_size = ui->size;
    item->rectangle::init();*/
    //scene->addItem();
    scene->addLine(20,20, 200 - 20, 20);
    scene -> update();
    //scene = new QGraphicsScene(0);
    //gr -> setScene(scene);
}

void mypaint::mouseMoveEvent(QMouseEvent *event)
{
    poly << event->pos();
    //qDebug() << "Move";
    //scene->setPos(mapToScene(event->pos()));
}
/*
void mypaint::mousePressEvent(QMouseEvent *event)
{

    //this->setCursor(QCursor(Qt::ClosedHandCursor));
    Q_UNUSED(event);
}

void mypaint::mouseReleaseEvent(QMouseEvent *event)
{

//    this->setCursor(QCursor(Qt::ArrowCursor));
    Q_UNUSED(event);
}*/


