#include "mainwindow.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->resize(1200,730);
    this->setFixedSize(1200,730);
    scene = new QGraphicsScene(this);
    ui->graphicsView->resize(730,730);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    ui->graphicsView->setCacheMode(QGraphicsView::CacheBackground);
    ui->graphicsView->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    ui->Reset_scene->setStyleSheet(
                "QPushButton{"
                "background-color: rgb(235, 28, 28);"
                "border-radius: 4px transparent;"
                "border-bottom: 3px transparent;"
                "border-right: 2px transparent;"
                "border-left: 2px transparent;}"
                "QPushButton:pressed  {"
                "background-color: rgb(255,0,0); } "
                );
    scene->setSceneRect(0,0,700,700);

    paint_scene = new mypaint();
    ui->graphicLayout->addWidget(paint_scene);
    paint_scene->init();

    //paint_scene -> mypaint::init();
    //paint_scene->gr = ui->graphicsView_2;
}

MainWindow::~MainWindow()
{
    delete ui;
}

MainWindow::triple MainWindow::CalcCenter (QStringList str)
{
    int prX,prY,nxX,nxY,area = 0;
    triple ans = {0,0,0};
    for(int i = 0; i < str.length()-1; i+=2)
    {
        prX = str[i].toInt();
        prY = str[i+1].toInt();
        if (i==str.length()-2)
        {
        nxX = str[0].toInt();
        nxY = str[1].toInt();
        }
        else
        {
        nxX = str[i+2].toInt();
        nxY = str[i+3].toInt();
        }
        int x = prX * nxY - nxX * prY;
        area += x;
        ans.first += (prX + nxX) * x;
        ans.second += (prY + nxY) * x;
    }
    ans.first /= area*3;
    ans.second /= area*3;
    ans.third = abs(area/2);
    return ans;
}

void MainWindow::on_pushButton_rect_clicked()
{
    int x = ui->rect_x->text().toInt();
    int y = ui->rect_y->text().toInt();
    rectangle *item = new rectangle();
    item->setFlag(QGraphicsItem::ItemIsFocusable, true);
    item->setPos(x,y);
    item->w = ui->rect_w->text().toInt();
    item->h = ui->rect_h->text().toInt();
    item->R = ui->pen_color_R->text().toInt();
    item->G = ui->pen_color_G->text().toInt();
    item->B = ui->pen_color_B->text().toInt();
    item->PenSize = ui->pen_size->text().toInt();
    item->out_area = ui->area;
    item->out_perimeter = ui->perimeter;
    item->out_centerX = ui->center_x;
    item->out_centerY = ui->center_y;
    item->out_angle = ui->angle;
    item->Tgravity =ui->Tgravity;
    item->centergravity_x = ui->centergravity_x;
    item->centergravity_y = ui->centergravity_y;
    item -> rotate_angle = ui->rotate_angle;
    item -> change_size = ui->size;
    item->init();
    scene->addItem(item);
}

void MainWindow::on_pushButton_elips_clicked()
{
    int x = ui->elips_x->text().toInt();
    int y = ui->elips_y->text().toInt();
    ellipse *item = new ellipse();
    item->setFlag(QGraphicsItem::ItemIsFocusable, true);
    item->setPos(x,y);
    item->w = ui->elips_w->text().toInt();
    item->h = ui->elips_h->text().toInt();
    item->R = ui->pen_color_R->text().toInt();
    item->G = ui->pen_color_G->text().toInt();
    item->B = ui->pen_color_B->text().toInt();
    item->PenSize = ui->pen_size->text().toInt();
    item->out_area = ui->area;
    item->out_perimeter = ui->perimeter;
    item->out_centerX = ui->center_x;
    item->out_centerY = ui->center_y;
    item->out_angle = ui->angle;
    item->Tgravity =ui->Tgravity;
    item->centergravity_x = ui->centergravity_x;
    item->centergravity_y = ui->centergravity_y;
    item -> rotate_angle = ui->rotate_angle;
    item -> change_size = ui->size;
    item->init();
    scene->addItem(item);
}

void MainWindow::on_pushButton_polygon_clicked()
{
    polygon *item = new polygon();
    QPolygon poly;
    item->setFlag(QGraphicsItem::ItemIsFocusable, true);
    QStringList str = ui->polygon_xy->toPlainText().split(" ");
    triple center = CalcCenter(str);
    int maxX = 0,maxY = 0,minX = 2000000000,minY = 2000000000;
    double perimeter = 0;
    while (str[str.length()-1].toInt()==0) str.pop_back();
    for (int i = 0;i<str.length();i+=2)
    {
        poly << QPoint (str[i].toInt()-center.first,str[i+1].toInt()-center.second);
        minX = qMin(str[i].toInt(),minX);
        minY = qMin(str[i+1].toInt(),minY);
        maxX = qMax(str[i].toInt(),maxX);
        maxY = qMax(str[i+1].toInt(),maxY);
        perimeter += pow(pow(str[i].toInt()-str[(i+2)%str.length()].toInt(),2.)+pow(str[i+1].toInt()-str[(i+3)%str.length()].toInt(),2.),1/2.);
    }
    item -> poly = poly;
    item->w = qMax(maxX-center.first,center.first - minX)*2;
    item->h = qMax(maxY-center.second,center.second - minY)*2;
    item->R = ui->pen_color_R->text().toInt();
    item->G = ui->pen_color_G->text().toInt();
    item->B = ui->pen_color_B->text().toInt();
    item->PenSize = ui->pen_size->text().toInt();
    item->Center.first = center.first;
    item->Center.second = center.second;
    item->setPos(center.first,center.second);
    item->area = center.third;
    item->out_area = ui->area;
    item->out_perimeter = ui->perimeter;
    item->out_centerX = ui->center_x;
    item->out_centerY = ui->center_y;
    item->out_angle = ui->angle;
    item->Tgravity =ui->Tgravity;
    item->centergravity_x = ui->centergravity_x;
    item->centergravity_y = ui->centergravity_y;
    item -> rotate_angle = ui->rotate_angle;
    item -> change_size = ui->size;
    item->init();
    scene->addItem(item);
    str.clear();
}


void MainWindow::on_Tgravity_clicked()
{
   ui->Tgravity->setText("Choose object to move");
}

void MainWindow::on_Reset_scene_clicked()
{
    scene ->clear();
    scene->update();
}

void MainWindow::on_paint_figure_clicked()
{
    if (Fpaint==false)
    {
        Fpaint = true;
        ui->paint_figure->setText("Turn OFF Paint tool");
    }
    else
    {
        Fpaint = false;
        ui->paint_figure->setText("Turn ON Paint tool");
    }
}

/*void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    qDebug() << "Move";
    //scene->setPos(mapToScene(event->pos()));
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    //this->setCursor(QCursor(Qt::ClosedHandCursor));
    Q_UNUSED(event);
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
//    this->setCursor(QCursor(Qt::ArrowCursor));
    Q_UNUSED(event);
}*/
