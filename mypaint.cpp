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
    scene->setSceneRect(0,0,240,280);
}
mypaint::~mypaint()
{

}

void mypaint::mouseMoveEvent(QMouseEvent *event)
{
    cords.push_back({event->pos().rx(),event->pos().ry()});
    if (cords.length()>1)
    scene -> addLine(cords[cords.length()-2].first,cords[cords.length()-2].second,event->pos().rx(),event->pos().ry(),
            QPen(QColor(R->text().toInt(),G->text().toInt(),B->text().toInt()),PenSize->text().toInt()));
    scene ->update();
}

void mypaint::mousePressEvent(QMouseEvent *event)
{
    cords.push_back({event->pos().rx(),event->pos().ry()});
    if (cords.length()>1)
    scene -> addLine(cords[cords.length()-2].first,cords[cords.length()-2].second,event->pos().rx(),event->pos().ry(),
            QPen(QColor(R->text().toInt(),G->text().toInt(),B->text().toInt()),PenSize->text().toInt()));
    scene ->update();
}

void mypaint::draw()
{
    polygon *item = new polygon();
    item->setFlag(QGraphicsItem::ItemIsFocusable, true);
    item->cords = cords;
    item->init();
    item->R = R->text().toInt();
    item->G = G->text().toInt();
    item->B = B->text().toInt();
    item->PenSize = PenSize->text().toInt();
    item->setPos(item->Center.first,item->Center.second);
    item->out_area = out_area;
    item->out_perimeter = out_perimeter;
    item->out_centerX = out_centerX;
    item->out_centerY = out_centerY;
    item->out_angle = out_angle;
    item->Tgravity = Tgravity;
    item->centergravity_x = centergravity_x;
    item->centergravity_y = centergravity_y;
    item -> rotate_angle = rotate_angle;
    item -> change_size = change_size;
    main_scene->addItem(item);
    scene ->clear();
    scene->update();
    cords.clear();
}
/*
void mypaint::mouseReleaseEvent(QMouseEvent *event)
{

//    this->setCursor(QCursor(Qt::ArrowCursor));
    Q_UNUSED(event);
}*/


