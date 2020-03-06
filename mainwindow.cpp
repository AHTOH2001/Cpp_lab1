#include "mainwindow.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->resize(1200,756);
    this->setFixedSize(1200,756);
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
    scene->setSceneRect(0,0,720,720);

    paint_scene = new mypaint();
    paint_scene->R = ui->pen_color_R;
    paint_scene->G = ui->pen_color_G;
    paint_scene->B = ui->pen_color_B;
    paint_scene->PenSize = ui->pen_size;
    ui->graphicLayout->addWidget(paint_scene);
    paint_scene->out_area = ui->area;
    paint_scene->out_perimeter = ui->perimeter;
    paint_scene->out_centerX = ui->center_x;
    paint_scene->out_centerY = ui->center_y;
    paint_scene->out_angle = ui->angle;
    paint_scene->Tgravity =ui->Tgravity;
    paint_scene->centergravity_x = ui->centergravity_x;
    paint_scene->centergravity_y = ui->centergravity_y;
    paint_scene -> rotate_angle = ui->rotate_angle;
    paint_scene -> change_size = ui->size;
    paint_scene ->main_scene = scene;
    //paint_scene -> mypaint::init();
    //paint_scene->gr = ui->graphicsView_2;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_rect_clicked()
{
    int x = ui->rect_x->text().toInt();
    int y = ui->rect_y->text().toInt();
    auto *item = new rectangle();
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
    auto *item = new ellipse();
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
    auto *item = new polygon();
    item->setFlag(QGraphicsItem::ItemIsFocusable, true);
    QStringList str = ui->polygon_xy->toPlainText().split(" ");
    while (str[str.length()-1].toInt()==0) str.pop_back();
    for (int i = 0;i<str.length();i+=2)
    {
        item->cords.push_back( {str[i].toInt(),str[i+1].toInt()});
    }
    item->init();
    item->R = ui->pen_color_R->text().toInt();
    item->G = ui->pen_color_G->text().toInt();
    item->B = ui->pen_color_B->text().toInt();
    item->PenSize = ui->pen_size->text().toInt();
    item->setPos(item->Center.first,item->Center.second);
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
    if (str.length()>5)
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
    paint_scene->draw();
}

void MainWindow::on_undo_clicked()
{
    paint_scene->undo();
}

void MainWindow::on_reset_clicked()
{
    paint_scene->reset();
}
