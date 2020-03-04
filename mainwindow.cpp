#include "mainwindow.h"
#include "ui_mainwindow.h"
int p = 0;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->resize(1200,800);
    this->setFixedSize(1200,800);
    scene = new QGraphicsScene(this);
    ui->graphicsView->resize(730,730);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    ui->graphicsView->setCacheMode(QGraphicsView::CacheBackground);
    ui->graphicsView->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    ui->Reset_scene->setStyleSheet(
                "QPushButton{"
                "background-color: rgb(235, 23, 23);"
                "border-radius: 4px transparent;"
                "border-bottom: 3px transparent;"
                "border-right: 2px transparent;"
                "border-left: 2px transparent;}"
                "QPushButton:pressed  {"
                "background-color: rgb(232,95,76); } "
                );
    scene->setSceneRect(0,0,700,700);
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    if (p==1)
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
        item->rectangle::init();
        scene->addItem(item);
        p = 0;
    }
    else
    if (p==2)
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
        item->ellipse::init();
        scene->addItem(item);
        p = 0;
    }
    else
    if (p==3)
    {
        polygon *item = new polygon();
        item->setFlag(QGraphicsItem::ItemIsFocusable, true);
        QStringList str = ui->polygon_xy->toPlainText().split(" ");
        while (str[str.length()-1].toInt()==0) str.pop_back();
        for (int i = 0;i<str.length();i+=2)
        {
            item->cords.push_back( {str[i].toInt(),str[i+1].toInt()});
        }
        triple center = CalcCenter(str);
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
        item->polygon::init();
        scene->addItem(item);
        str.clear();
        p = 0;
    }

    Q_UNUSED(event);

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
    p = 1;
}

void MainWindow::on_pushButton_elips_clicked()
{
    p = 2;
}

void MainWindow::on_pushButton_polygon_clicked()
{
    p = 3;
}


void MainWindow::on_Tgravity_clicked()
{
   ui->Tgravity->setText("Choose object to move");
}
